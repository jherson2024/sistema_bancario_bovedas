#ifndef BOVEDA_H
#define BOVEDA_H

#include <memory>
#include <vector>
#include <map>
#include <string>
#include "Plaza.h"
#include "Saldo.h"
#include "Denominacion.h"
#include "Activo.h"
class Boveda {
public:
    std::string idBoveda;
    std::shared_ptr<Plaza> plaza;
    std::vector<Saldo> saldos;
    std::map<std::shared_ptr<Denominacion>, int> dinero;
    std::vector<Activo> activos;
    const std::vector<std::shared_ptr<TipoMoneda>>& ordenMonedas;
    Boveda(std::string idBoveda, std::shared_ptr<Plaza> plaza,
       const std::vector<std::shared_ptr<TipoMoneda>>& ordenMonedasRef);
    void agregarSaldo(const Saldo& s);
    void agregarDinero(std::shared_ptr<Denominacion> d, int cantidad);
    void agregarActivo(const Activo& a);
    void registrarSaldoDiario(const std::string& fecha);
    std::map<std::string, double> obtenerDineroPorMoneda() const;
    std::map<std::string, std::map<std::string, double>> obtenerActivosPorTipoYMoneda() const;
};
#endif // BOVEDA_H
