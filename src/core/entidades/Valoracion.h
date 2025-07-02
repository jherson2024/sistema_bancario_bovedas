#ifndef VALORACION_H
#define VALORACION_H

#include <memory>
#include "TipoMoneda.h"

class Valoracion {
public:
    std::shared_ptr<TipoMoneda> tipoMoneda;
    double valor;

    Valoracion(std::shared_ptr<TipoMoneda> tipoMoneda, double valor);
};

#endif // VALORACION_H
