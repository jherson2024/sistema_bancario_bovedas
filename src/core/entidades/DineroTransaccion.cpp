#include "DineroTransaccion.h"
#include "ExcepcionesGenerales.h"

DineroTransaccion::DineroTransaccion(Denominacion* denominacion, int cantidad, Transaccion* transaccion)
    : denominacion(denominacion), cantidad(cantidad), transaccion(transaccion) {

    if (!denominacion) {
        throw ArgumentoInvalidoException("denominacion es nulo.");
    }
    if (cantidad <= 0) {
        throw ArgumentoInvalidoException("cantidad debe ser mayor que cero.");
    }
    if (!transaccion) {
        throw ArgumentoInvalidoException("transaccion es nulo.");
    }
}

Denominacion* DineroTransaccion::getDenominacion() const {
    return denominacion;
}

int DineroTransaccion::getCantidad() const {
    return cantidad;
}

Transaccion* DineroTransaccion::getTransaccion() const {
    return transaccion;
}

double DineroTransaccion::getTotal() const {
    if (!denominacion) {
        throw ArgumentoInvalidoException("No se puede calcular el total: denominacion es nulo.");
    }
    return denominacion->valor * cantidad;
}
