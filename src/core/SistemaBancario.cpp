#include "SistemaBancario.h"
#include <iostream>
// ---------- MONEDAS ----------
void SistemaBancario::registrarMoneda(const std::string& nombre) {
    if (nombre.empty()) {
        throw MonedaInvalidaException("El nombre de la moneda no puede estar vacío");
    }
    if (monedas.count(nombre)) {
        throw MonedaInvalidaException("Moneda ya registrada");
    }
    try {
        auto moneda = std::make_shared<TipoMoneda>(nombre);  // puede lanzar TipoMonedaInvalidaException
        monedas[nombre] = moneda;
        ordenMonedas.push_back(moneda);
    } catch (const TipoMonedaInvalidaException& e) {
        throw MonedaInvalidaException(std::string("Error al registrar moneda: ") + e.what());
    }
}
std::vector<std::string> SistemaBancario::listarMonedas() const {
    std::vector<std::string> resultado;
    for (const auto& [nombre, _] : monedas) {
        resultado.push_back(nombre);
    }
    return resultado;
}
// ---------- BANCOS ----------
void SistemaBancario::registrarBanco(const std::string& nombre) {
    if (nombre.empty()) {
        throw EntidadInvalidaException("El nombre del banco no puede estar vacío");
    }
    if (bancos.count(nombre)) {
        throw EntidadInvalidaException("Banco ya registrado");
    }
    try {
        bancos[nombre] = std::make_shared<EntidadBancaria>(nombre);  // puede lanzar excepción
    } catch (const std::exception& e) {
        throw EntidadInvalidaException(std::string("Error al registrar banco: ") + e.what());
    }
}
std::vector<std::string> SistemaBancario::listarBancos() const {
    std::vector<std::string> resultado;
    for (const auto& [nombre, _] : bancos) {
        resultado.push_back(nombre);
    }
    return resultado;
}


// ---------- PLAZAS ----------
void SistemaBancario::registrarPlaza(const std::string& nombre) {
    if (nombre.empty()) {
        throw PlazaInvalidaException("El nombre de la plaza no puede estar vacío");
    }

    if (plazas.count(nombre)) {
        throw PlazaInvalidaException("Plaza ya registrada");
    }

    try {
        plazas[nombre] = std::make_shared<Plaza>(nombre);  // puede lanzar PlazaInvalidaException
    } catch (const PlazaInvalidaException& e) {
        throw;  // se relanza tal cual
    } catch (const std::exception& e) {
        throw PlazaInvalidaException(std::string("Error al registrar plaza: ") + e.what());
    }
}

std::vector<std::string> SistemaBancario::listarPlazas() const {
    std::vector<std::string> resultado;
    for (const auto& [nombre, _] : plazas) {
        resultado.push_back(nombre);
    }
    return resultado;
}

// ---------- TIPOS DE ACTIVO ----------
void SistemaBancario::registrarTipoActivo(const std::string& nombre) {
    if (nombre.empty()) {
        throw TipoActivoInvalidoException("El nombre del tipo de activo no puede estar vacío");
    }

    if (tiposActivos.count(nombre)) {
        throw TipoActivoInvalidoException("Tipo de activo ya registrado");
    }

    try {
        tiposActivos[nombre] = std::make_shared<TipoActivo>(nombre);  // puede lanzar
    } catch (const TipoActivoInvalidoException& e) {
        throw;  // re-lanzar tal cual
    } catch (const std::exception& e) {
        throw TipoActivoInvalidoException(std::string("Error al registrar tipo de activo: ") + e.what());
    }
}

std::vector<std::string> SistemaBancario::listarTiposActivo() const {
    std::vector<std::string> resultado;
    for (const auto& [nombre, _] : tiposActivos) {
        resultado.push_back(nombre);
    }
    return resultado;
}


// ---------- TIPOS DE OPERACIÓN ----------
void SistemaBancario::registrarTipoOperacion(const std::string& nombre) {
    if (nombre.empty()) {
        throw TipoOperacionInvalidaException("El nombre del tipo de operación no puede estar vacío");
    }

    if (tiposOperaciones.count(nombre)) {
        throw TipoOperacionInvalidaException("Tipo de operación ya registrado");
    }

    try {
        tiposOperaciones[nombre] = std::make_shared<TipoOperacion>(nombre);  // puede lanzar
    } catch (const TipoOperacionInvalidaException& e) {
        throw;  // relanza si es específica
    } catch (const std::exception& e) {
        throw TipoOperacionInvalidaException(std::string("Error al registrar tipo de operación: ") + e.what());
    }
}

std::vector<std::string> SistemaBancario::listarTiposOperacion() const {
    std::vector<std::string> resultado;
    for (const auto& [nombre, _] : tiposOperaciones) {
        resultado.push_back(nombre);
    }
    return resultado;
}


// ---------- DENOMINACIONES ----------
void SistemaBancario::registrarDenominacion(const std::string& moneda, double valor) {
    if (moneda.empty()) {
        throw MonedaInvalidaException("El nombre de la moneda no puede estar vacío");
    }

    if (valor <= 0.0) {
        throw DenominacionInvalidaException("El valor de la denominación debe ser positivo");
    }

    if (!monedas.count(moneda)) {
        throw MonedaInvalidaException("Moneda no registrada");
    }

    std::string clave = moneda + std::to_string(valor);

    if (denominaciones.count(clave)) {
        throw DenominacionInvalidaException("Denominación ya registrada");
    }

    try {
        auto denom = std::make_shared<Denominacion>(monedas[moneda], valor);  // puede lanzar
        denominaciones[clave] = denom;
    } catch (const DenominacionInvalidaException& e) {
        throw;
    } catch (const std::exception& e) {
        throw DenominacionInvalidaException(std::string("Error al registrar denominación: ") + e.what());
    }
}

std::vector<double> SistemaBancario::listarDenominaciones(const std::string& moneda) const {
    std::vector<double> resultado;
    for (const auto& [clave, denom] : denominaciones) {
        if (denom->tipoMoneda && denom->tipoMoneda->nombre == moneda) {
            resultado.push_back(denom->valor);
        }
    }
    return resultado;
}

// ---------- BÓVEDAS ----------
void SistemaBancario::registrarBoveda(const std::string& banco, const std::string& plaza, const std::string& idBoveda) {
    if (banco.empty() || plaza.empty() || idBoveda.empty()) {
        throw EntidadInvalidaException("Banco, plaza o ID de bóveda no pueden estar vacíos");
    }

    // Verificar existencia de banco y que el puntero sea válido
    auto itBanco = bancos.find(banco);
    if (itBanco == bancos.end() || !itBanco->second) {
        throw EntidadInvalidaException("Banco no existe o está mal inicializado");
    }

    // Verificar existencia de plaza usando .at()
    if (!plazas.count(plaza)) {
        throw PlazaInvalidaException("Plaza no existe");
    }

    // Verificar si la bóveda ya existe
    if (obtenerBovedaPorId(idBoveda)) {
        throw EntidadInvalidaException("Ya existe una bóveda con ese ID");
    }

    try {
        auto boveda = std::make_shared<Boveda>(idBoveda, plazas.at(plaza), ordenMonedas);
        itBanco->second->agregarBoveda(boveda);
    } catch (const std::exception& e) {
        throw EntidadInvalidaException(std::string("Error al registrar bóveda: ") + e.what());
    }
}



std::vector<std::string> SistemaBancario::listarBovedas(const std::string& banco) const {
    if (banco.empty()) {
        throw EntidadInvalidaException("El nombre del banco no puede estar vacío");
    }

    if (!bancos.count(banco)) {
        throw EntidadInvalidaException("Banco no existe");
    }

    std::vector<std::string> resultado;
    for (const auto& b : bancos.at(banco)->bovedas) {
        resultado.push_back(b->idBoveda);
    }
    return resultado;
}

std::shared_ptr<Boveda> SistemaBancario::obtenerBovedaPorId(const std::string& idBoveda) const {
    if (idBoveda.empty()) return nullptr;

    for (const auto& [_, banco] : bancos) {
        for (const auto& b : banco->bovedas) {
            if (b->idBoveda == idBoveda) return b;
        }
    }
    return nullptr;
}


// ---------- DEPÓSITOS ----------
void SistemaBancario::depositarDinero(const std::string& idBoveda, const std::string& moneda, double valor, int cantidad) {
    if (idBoveda.empty()) {
        throw EntidadInvalidaException("ID de bóveda no puede estar vacío");
    }

    if (moneda.empty()) {
        throw MonedaInvalidaException("El nombre de la moneda no puede estar vacío");
    }

    if (valor <= 0.0) {
        throw DenominacionInvalidaException("El valor de la denominación debe ser positivo");
    }

    if (cantidad <= 0) {
        throw CantidadInvalidaException("La cantidad debe ser positiva");
    }

    auto boveda = obtenerBovedaPorId(idBoveda);
    if (!boveda) {
        throw EntidadInvalidaException("Bóveda no encontrada");
    }

    std::string clave = moneda + std::to_string(valor);
    if (!denominaciones.count(clave)) {
        throw DenominacionInvalidaException("Denominación no existe");
    }

    try {
        boveda->agregarDinero(denominaciones[clave], cantidad);  // puede lanzar
    } catch (const CantidadInvalidaException& e) {
        throw;
    } catch (const DenominacionInvalidaException& e) {
        throw;
    } catch (const std::exception& e) {
        throw ExcepcionOperacion(std::string("Error al depositar dinero: ") + e.what());
    }
}

// ---------- ACTIVOS ----------
void SistemaBancario::agregarActivo(const std::string& tipo, const std::string& idBoveda,
                                    const std::vector<std::pair<std::string, double>>& valoraciones) {
    if (tipo.empty()) {
        throw TipoActivoInvalidoException("El tipo de activo no puede estar vacío");
    }
    if (idBoveda.empty()) {
        throw EntidadInvalidaException("El ID de la bóveda no puede estar vacío");
    }
    if (valoraciones.empty()) {
        throw ExcepcionOperacion("Se requiere al menos una valoración para el activo");
    }
    auto boveda = obtenerBovedaPorId(idBoveda);
    if (!boveda) {
        throw EntidadInvalidaException("Bóveda no encontrada");
    }
    if (!tiposActivos.count(tipo)) {
        throw TipoActivoInvalidoException("Tipo de activo no registrado");
    }
    try {
        Activo activo(tiposActivos[tipo]);
        for (const auto& [moneda, valor] : valoraciones) {
            if (valor <= 0.0) {
                throw DenominacionInvalidaException("Valoración con monto no positivo");
            }
            if (!monedas.count(moneda)) {
                throw MonedaInvalidaException("Moneda no registrada en valoración: " + moneda);
            }
            activo.agregarValoracion({monedas[moneda], valor});
        }
        boveda->agregarActivo(activo);  // puede lanzar
    } catch (const std::exception& e) {
        throw ExcepcionOperacion(std::string("Error al agregar activo: ") + e.what());
    }
}
// ---------- ESTADO DE BÓVEDA ----------
Saldo SistemaBancario::consultarEstadoBoveda(const std::string& idBoveda) const {
    if (idBoveda.empty()) {
        throw EntidadInvalidaException("El ID de la bóveda no puede estar vacío");
    }
    auto boveda = obtenerBovedaPorId(idBoveda);
    if (!boveda) {
        throw EntidadInvalidaException("Bóveda no encontrada");
    }
    Saldo saldo("2025-06-30");  // Reemplazar con fecha dinámica si querés
    // Dinero físico
    for (const auto& [denom, cantidad] : boveda->dinero) {
        if (!denom || !denom->tipoMoneda) {
            throw DenominacionInvalidaException("Denominación nula encontrada en bóveda");
        }

        double valor = denom->valor;
        std::string moneda = denom->tipoMoneda->nombre;
        double total = valor * cantidad;

        saldo.dineroPorMoneda[moneda] += total;
        saldo.billetesPorMoneda[moneda][valor] += cantidad;
    }
    // Activos con valoración
    for (const auto& activo : boveda->activos) {
        try {
            Valoracion val = activo.valoracionMasFuerte(boveda->ordenMonedas);
            const std::string& tipo = activo.tipo->nombre;
            const std::string& moneda = val.tipoMoneda->nombre;
            double monto = val.valor;

            saldo.activosPorTipo[tipo][moneda] += monto;

        } catch (const ValoracionNoDisponibleException& e) {
            // Podés registrar un log o ignorar silenciosamente según convención
        } catch (const std::exception& e) {
            throw ExcepcionOperacion(std::string("Error al valorar activo: ") + e.what());
        }
    }

    return saldo;
}
// ---------- TRANSPORTADORES ----------
void SistemaBancario::registrarTransportador(const std::string& nombre) {
    if (nombre.empty()) {
        throw TransportadorInvalidoException("El nombre del transportador no puede estar vacío");
    }

    if (transportadores.count(nombre)) {
        throw TransportadorInvalidoException("Transportador ya registrado");
    }

    try {
        transportadores[nombre] = std::make_shared<Transportador>(nombre);  // puede lanzar
    } catch (const TransportadorInvalidoException& e) {
        throw;  // relanza directamente si es específica
    } catch (const std::exception& e) {
        throw TransportadorInvalidoException(std::string("Error al registrar transportador: ") + e.what());
    }
}

std::vector<std::string> SistemaBancario::listarTransportadores() const {
    std::vector<std::string> resultado;
    for (const auto& [nombre, _] : transportadores) {
        resultado.push_back(nombre);
    }
    return resultado;
}


// ---------- TRANSACCIONES ----------
void SistemaBancario::registrarTransaccion(const Transaccion& t) {
    if (!t.transportador) {
        throw TransportadorInvalidoException("Transportador no definido en la transacción");
    }
    if (!t.tipoOperacion) {
        throw TipoOperacionInvalidaException("Tipo de operación no definido en la transacción");
    }
    if (!t.origen || !t.destino) {
        throw EntidadInvalidaException("Bóveda origen o destino inválida");
    }
    if (t.fechaInicio.empty() || t.fechaFin.empty()) {
        throw FechaInvalidaException("Fechas de la transacción no pueden estar vacías");
    }
    if (t.fechaFin < t.fechaInicio) {
        throw FechaInvalidaException("La fecha de fin no puede ser anterior a la fecha de inicio");
    }
    if (t.dineroTransferido.empty() && t.activosTransferidos.empty()) {
        throw TransaccionVaciaException("La transacción no contiene dinero ni activos a transferir");
    }
    // Opcional: validar que la fechaInicio <= fechaFin si tienes lógica para eso
    transacciones.push_back(std::make_shared<Transaccion>(t));
}
void SistemaBancario::ejecutarTransaccion(int id) {
    if (id < 0 || id >= static_cast<int>(transacciones.size())) {
        throw std::out_of_range("ID de transacción inválido");
    }

    try {
        transacciones[id]->ejecutar();  // puede lanzar
    } catch (const std::exception& e) {
        throw ExcepcionOperacion(std::string("Error al ejecutar transacción: ") + e.what());
    }
}

Transaccion SistemaBancario::detalleTransaccion(int id) const {
    if (id < 0 || id >= static_cast<int>(transacciones.size())) {
        throw std::out_of_range("ID de transacción inválido");
    }

    return *(transacciones[id]);  // copia defensiva
}
Transaccion SistemaBancario::construirTransaccionDesdeDatos(
    const std::string& transportador,
    const std::string& tipoOperacion,
    const std::string& fechaInicio,
    const std::string& fechaFin,
    const std::string& idOrigen,
    const std::string& idDestino,
    const std::vector<std::tuple<std::string, double, int>>& dinero,
    const std::vector<std::tuple<std::string, std::string, double>>& activos
) {
    if (transportador.empty()) throw TransportadorInvalidoException("Nombre del transportador vacío");
    if (tipoOperacion.empty()) throw TipoOperacionInvalidaException("Tipo de operación vacío");
    if (fechaInicio.empty() || fechaFin.empty()) throw FechaInvalidaException("Fechas no pueden estar vacías");

    auto origen = obtenerBovedaPorId(idOrigen);
    auto destino = obtenerBovedaPorId(idDestino);
    if (!origen || !destino) {
        throw EntidadInvalidaException("Bóveda origen o destino no encontrada");
    }

    if (!tiposOperaciones.count(tipoOperacion)) {
        throw TipoOperacionInvalidaException("Tipo de operación no registrado");
    }

    if (!transportadores.count(transportador)) {
        throw TransportadorInvalidoException("Transportador no registrado");
    }

    auto trans = Transaccion(
        transportadores[transportador],
        tiposOperaciones[tipoOperacion],
        fechaInicio,
        fechaFin,
        origen,
        destino
    );

    // Agregar dinero
    for (const auto& [moneda, valor, cantidad] : dinero) {
        std::string clave = moneda + std::to_string(valor);
        if (!denominaciones.count(clave)) {
            throw DenominacionInvalidaException("Denominación no registrada: " + clave);
        }
        trans.agregarDinero(denominaciones.at(clave), cantidad);
    }

    // Agregar activos parciales
    for (const auto& [tipoActivo, moneda, cantidad] : activos) {
        if (!tiposActivos.count(tipoActivo)) {
            throw TipoActivoInvalidoException("Tipo de activo inválido: " + tipoActivo);
        }

        Activo dummy(tiposActivos.at(tipoActivo));
        trans.agregarActivoParcial(dummy, moneda, cantidad);
    }

    return trans;
}
std::vector<int> SistemaBancario::listarTransacciones() const {
    std::vector<int> ids;
    for (size_t i = 0; i < transacciones.size(); ++i) {
        ids.push_back(static_cast<int>(i));
    }
    return ids;
}

// ---------- SALDOS ----------
void SistemaBancario::registrarSaldoDiario(const std::string& idBoveda, const std::string& fecha) {
    if (idBoveda.empty()) {
        throw EntidadInvalidaException("El ID de la bóveda no puede estar vacío");
    }

    if (fecha.empty()) {
        throw FechaInvalidaException("La fecha no puede estar vacía");
    }

    auto boveda = obtenerBovedaPorId(idBoveda);
    if (!boveda) {
        throw EntidadInvalidaException("Bóveda no encontrada");
    }

    try {
        boveda->registrarSaldoDiario(fecha);  // puede lanzar FechaInvalidaException
    } catch (const FechaInvalidaException& e) {
        throw;
    } catch (const std::exception& e) {
        throw ExcepcionOperacion(std::string("Error al registrar saldo: ") + e.what());
    }
}

Saldo SistemaBancario::consultarSaldoPorFecha(const std::string& idBoveda, const std::string& fecha) const {
    if (idBoveda.empty()) {
        throw EntidadInvalidaException("El ID de la bóveda no puede estar vacío");
    }

    if (fecha.empty()) {
        throw FechaInvalidaException("La fecha no puede estar vacía");
    }

    auto boveda = obtenerBovedaPorId(idBoveda);
    if (!boveda) {
        throw EntidadInvalidaException("Bóveda no encontrada");
    }

    for (const auto& s : boveda->saldos) {
        if (s.fecha == fecha) return s;
    }

    throw FechaInvalidaException("No hay saldo registrado para esa fecha");
}
