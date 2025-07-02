#include "Activo.h"
#include "ExcepcionesActivos.h"
#include "ExcepcionesMoneda.h"  
#include <stdexcept>
Activo::Activo(std::shared_ptr<TipoActivo> tipo) : tipo(tipo) {}
void Activo::agregarValoracion(const Valoracion& v) {
    valoraciones.push_back(v);
}
std::map<std::string, double> Activo::obtenerValorPorMoneda() const {
    std::map<std::string, double> resultado;
    for (const auto& v : valoraciones) {
        resultado[v.tipoMoneda->nombre] += v.valor;
    }
    return resultado;
}
Valoracion Activo::valoracionMasFuerte(const std::vector<std::shared_ptr<TipoMoneda>>& ordenMonedas) const {
    for (const auto& moneda : ordenMonedas) {
        for (const auto& v : valoraciones) {
            if (v.tipoMoneda->nombre == moneda->nombre) {
                return v;
            }
        }
    }
    throw ValoracionNoDisponibleException();
}
