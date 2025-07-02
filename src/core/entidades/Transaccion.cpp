#include "Transaccion.h"
#include "ExcepcionesGenerales.h"
#include "ExcepcionesEntidades.h"
#include "ExcepcionesTransacciones.h"
#include "ExcepcionesMoneda.h"
#include "ExcepcionesActivos.h"
#include <ctime>
#include <algorithm>
#include <sstream>
Transaccion::Transaccion(std::shared_ptr<Transportador> t,
                         std::shared_ptr<TipoOperacion> op,
                         const std::string& fInicio,
                         const std::string& fFin,
                         std::shared_ptr<Boveda> origen,
                         std::shared_ptr<Boveda> destino)
    : transportador(t),
      tipoOperacion(op),
      fechaInicio(fInicio),
      fechaFin(fFin),
      origen(origen),
      destino(destino),
      estado(EstadoTransaccion::PENDIENTE) {
    
    if (!t) throw TransportadorInvalidoException();
    if (!op) throw ArgumentoInvalidoException("Tipo de operación no puede ser nulo.");
    if (!origen || !destino) throw ArgumentoInvalidoException("Origen y destino deben ser válidos.");
    if (origen == destino) throw OperacionInvalidaException("Origen y destino no pueden ser iguales.");
    if (fInicio.empty() || fFin.empty()) throw FechaInvalidaException();
}

bool Transaccion::fechaPaso(const std::string& fecha) const {
    if (fecha.empty()) return false;

    std::time_t t = std::time(nullptr);
    std::tm now{};
    localtime_s(&now, &t);

    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &now);

    return fecha <= buffer;
}

void Transaccion::agregarDinero(std::shared_ptr<Denominacion> d, int cantidad) {
    if (!d) throw DenominacionInvalidaException();
    if (cantidad <= 0) throw CantidadInvalidaException();

    int disponible = origen->dinero[d];
    if (disponible < cantidad) {
        throw DineroInsuficienteException();
    }

    dineroTransferido[d] += cantidad;
}

void Transaccion::agregarActivoParcial(const Activo& a, const std::string& moneda, double valorParcial) {
    if (valorParcial <= 0) {
        throw ArgumentoInvalidoException("El valor parcial debe ser mayor que cero.");
    }

    for (const auto& activo : origen->activos) {
        if (activo.tipo->nombre == a.tipo->nombre) {
            double disponible = activo.obtenerValorPorMoneda()[moneda];
            if (disponible >= valorParcial) {
                activosTransferidos.push_back({a, moneda, valorParcial});
            } else {
                throw ActivoInsuficienteException(a.tipo->nombre, moneda);
            }
            return;
        }
    }
    throw OperacionInvalidaException("Activo no encontrado en bóveda origen: " + a.tipo->nombre);
}

void Transaccion::ejecutar() {
    if (estado == EstadoTransaccion::COMPLETADA || estado == EstadoTransaccion::CANCELADA) {
        throw OperacionInvalidaException("No se puede ejecutar una transacción finalizada.");
    }

    if (!fechaPaso(fechaInicio)) {
        throw FechaInvalidaException();
    }

    estado = EstadoTransaccion::EN_PROCESO;

    // Transferencia de dinero
    for (const auto& d : dineroTransferido) {
        auto it = origen->dinero.find(d.first);
        if (it != origen->dinero.end() && it->second >= d.second) {
            it->second -= d.second;
            if (it->second <= 0) origen->dinero.erase(it);
        } else {
            throw DineroInsuficienteException();
        }
    }

    // Transferencia de activos
    for (const auto& pa : activosTransferidos) {
        for (auto it = origen->activos.begin(); it != origen->activos.end(); ++it) {
            if (it->tipo->nombre == pa.activoOriginal.tipo->nombre) {
                double total = it->obtenerValorPorMoneda()[pa.monedaElegida];
                if (total < pa.cantidadElegida || total == 0) {
                    throw ActivoInsuficienteException(pa.activoOriginal.tipo->nombre, pa.monedaElegida);
                }

                double propor = pa.cantidadElegida / total;
                Activo parcial(it->tipo);

                for (auto& val : it->valoraciones) {
                    double parte = val.valor * propor;
                    parcial.agregarValoracion({val.tipoMoneda, parte});
                    val.valor *= (1.0 - propor);
                }

                it->valoraciones.erase(
                    std::remove_if(it->valoraciones.begin(), it->valoraciones.end(),
                                   [](const Valoracion& v) { return v.valor < 0.0001; }),
                    it->valoraciones.end()
                );

                if (it->valoraciones.empty()) {
                    origen->activos.erase(it);
                }

                bool consolidado = false;
                for (auto& a : destino->activos) {
                    if (a.tipo->nombre == parcial.tipo->nombre) {
                        for (const auto& val : parcial.valoraciones) {
                            auto found = std::find_if(a.valoraciones.begin(), a.valoraciones.end(),
                                                      [&](const Valoracion& v) {
                                                          return v.tipoMoneda->nombre == val.tipoMoneda->nombre;
                                                      });
                            if (found != a.valoraciones.end()) {
                                found->valor += val.valor;
                            } else {
                                a.valoraciones.push_back(val);
                            }
                        }
                        consolidado = true;
                        break;
                    }
                }

                if (!consolidado) {
                    destino->activos.push_back(parcial);
                }

                break;
            }
        }
    }

    // Completar si fecha final ha pasado
    if (fechaPaso(fechaFin)) {
        for (const auto& d : dineroTransferido) {
            destino->dinero[d.first] += d.second;
        }
        estado = EstadoTransaccion::COMPLETADA;
    }
}

std::pair<std::string, std::string> Transaccion::obtenerPlazas() const {
    return { origen->plaza->nombre, destino->plaza->nombre };
}

void Transaccion::cancelar() {
    if (estado == EstadoTransaccion::PENDIENTE || estado == EstadoTransaccion::EN_PROCESO)
        estado = EstadoTransaccion::CANCELADA;
    else
        throw OperacionInvalidaException("Solo se pueden cancelar transacciones pendientes o en proceso.");
}

std::string Transaccion::estadoTexto() const {
    switch (estado) {
        case EstadoTransaccion::PENDIENTE: return "Pendiente";
        case EstadoTransaccion::EN_PROCESO: return "En Proceso";
        case EstadoTransaccion::COMPLETADA: return "Completada";
        case EstadoTransaccion::CANCELADA: return "Cancelada";
        default: return "Desconocido";
    }
}
std::string Transaccion::toString() const {
    std::ostringstream oss;

    oss << "🚚 Transportador: " << transportador->nombre << "\n";
    oss << "🔁 Operación: " << tipoOperacion->nombre << "\n";
    oss << "📅 Fecha inicio: " << fechaInicio << "\n";
    oss << "📅 Fecha fin: " << fechaFin << "\n";
    oss << "🏦 Origen: " << origen->plaza->nombre << "\n";
    oss << "🏦 Destino: " << destino->plaza->nombre << "\n";
    oss << "📌 Estado: " << estadoTexto() << "\n\n";
    oss << "💸 Dinero transferido:\n";
    for (const auto& [denom, cant] : dineroTransferido) {
        oss << "  - " << cant << " x " << denom->valor << " " << denom->tipoMoneda->nombre << "\n";
    }

    oss << "\n📦 Activos transferidos:\n";
    for (const auto& activo : activosTransferidos) {
        oss << "  - " << activo.activoOriginal.tipo->nombre
            << " → " << activo.cantidadElegida
            << " " << activo.monedaElegida << "\n";
    }

    return oss.str();
}
