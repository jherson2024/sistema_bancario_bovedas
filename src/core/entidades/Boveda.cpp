#include "Boveda.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "ExcepcionesGenerales.h"
#include "ExcepcionesMoneda.h"
using namespace std;

Boveda::Boveda(std::string idBoveda,
               std::shared_ptr<Plaza> plaza,
               const std::vector<std::shared_ptr<TipoMoneda>>& ordenMonedasRef)
    : idBoveda(idBoveda),
      plaza(plaza),
      ordenMonedas(ordenMonedasRef) {
}
void Boveda::agregarSaldo(const Saldo& s) {
    saldos.push_back(s);
}
void Boveda::agregarDinero(shared_ptr<Denominacion> d, int cantidad) {
    if (!d) {
        throw DenominacionInvalidaException();
    }
    if (cantidad <= 0) {
        throw CantidadInvalidaException();
    }
    dinero[d] += cantidad;
}
void Boveda::agregarActivo(const Activo& a) {
    activos.push_back(a);
}
void Boveda::registrarSaldoDiario(const std::string& fecha) {
    Saldo nuevoSaldo(fecha);

    // Dinero por tipo de moneda
    for (const auto& par : dinero) {
        auto denom = par.first;
        int cantidad = par.second;
        double total = denom->valor * cantidad;
        nuevoSaldo.dineroPorMoneda[denom->tipoMoneda->nombre] += total;
    }

    // Activos con valoración más fuerte
    for (const auto& activo : activos) {
        try {
            Valoracion val = activo.valoracionMasFuerte(ordenMonedas);
            const std::string& tipo = activo.tipo->nombre;
            const std::string& moneda = val.tipoMoneda->nombre;
            double monto = val.valor;
            nuevoSaldo.activosPorTipo[tipo][moneda] += monto;
        } catch (const ValoracionNoDisponibleException& e) {
            std::cerr << "Advertencia: activo sin valoración válida - " << e.what() << std::endl;
        }
    }

    saldos.push_back(nuevoSaldo);
}

map<string, double> Boveda::obtenerDineroPorMoneda() const {
    map<string, double> resultado;
    for (const auto& par : dinero) {
        resultado[par.first->tipoMoneda->nombre] += par.first->valor * par.second;
    }
    return resultado;
}

map<string, map<string, double>> Boveda::obtenerActivosPorTipoYMoneda() const {
    map<string, map<string, double>> resultado;
    for (const auto& a : activos) {
        auto valoraciones = a.obtenerValorPorMoneda();
        for (const auto& v : valoraciones) {
            resultado[a.tipo->nombre][v.first] += v.second;
        }
    }
    return resultado;
}
