#ifndef DENOMINACION_H
#define DENOMINACION_H

#include <memory>
#include "TipoMoneda.h"

class Denominacion {
public:
    std::shared_ptr<TipoMoneda> tipoMoneda;
    double valor;

    Denominacion(std::shared_ptr<TipoMoneda> tipoMoneda, double valor);
};

#endif // DENOMINACION_H
