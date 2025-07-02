#ifndef ACTIVOTRANSACCION_H
#define ACTIVOTRANSACCION_H

#include "TipoActivo.h"
#include "Transaccion.h"

class ActivoTransaccion {
public:
    ActivoTransaccion(TipoActivo* tipoActivo, int cantidad, Transaccion* transaccion);
    ~ActivoTransaccion() = default;

    TipoActivo* getTipoActivo() const;
    int getCantidad() const;
    Transaccion* getTransaccion() const;

private:
    TipoActivo* tipoActivo;
    int cantidad;
    Transaccion* transaccion;
};



#endif // ACTIVOTRANSACCION_H
