#ifndef ACTIVO_H
#define ACTIVO_H
#include <memory>
#include <vector>
#include <map>
#include <string>
#include "TipoActivo.h"
#include "Valoracion.h"
#include "Activo.h"
class Activo {
public:
    std::shared_ptr<TipoActivo> tipo;
    std::vector<Valoracion> valoraciones;
    Activo(std::shared_ptr<TipoActivo> tipo);
    void agregarValoracion(const Valoracion& v);
    std::map<std::string, double> obtenerValorPorMoneda() const;
   Valoracion valoracionMasFuerte(const std::vector<std::shared_ptr<TipoMoneda>>& ordenMonedas) const;
};
#endif 
