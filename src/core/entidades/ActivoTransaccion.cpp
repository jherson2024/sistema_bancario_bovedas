#include "ActivoTransaccion.h"
#include "ExcepcionesActivos.h"

ActivoTransaccion::ActivoTransaccion(TipoActivo* tipoActivo, int cantidad, Transaccion* transaccion)
    : tipoActivo(tipoActivo), cantidad(cantidad), transaccion(transaccion) {
    if (tipoActivo == nullptr) {
        throw ActivoTransaccionInvalidoException("tipoActivo es nulo.");
    }
    if (cantidad <= 0) {
        throw ActivoTransaccionInvalidoException("La cantidad debe ser mayor que cero.");
    }
    if (transaccion == nullptr) {
        throw ActivoTransaccionInvalidoException("transaccion es nulo.");
    }
}

TipoActivo* ActivoTransaccion::getTipoActivo() const {
    return tipoActivo;
}

int ActivoTransaccion::getCantidad() const {
    return cantidad;
}

Transaccion* ActivoTransaccion::getTransaccion() const {
    return transaccion;
}
