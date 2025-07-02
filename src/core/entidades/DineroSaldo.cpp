#include "DineroSaldo.h"
#include "ExcepcionesGenerales.h"
#include "ExcepcionesTransacciones.h"

DineroSaldo::DineroSaldo(Denominacion* denominacion, int cantidad, Saldo* saldo)
    : denominacion(denominacion), cantidad(cantidad), saldo(saldo) {
    if (!denominacion) {
        throw ArgumentoInvalidoException("denominacion es nulo.");
    }
    if (!saldo) {
        throw ArgumentoInvalidoException("saldo es nulo.");
    }
    if (cantidad < 0) {
        throw ArgumentoInvalidoException("cantidad inicial no puede ser negativa.");
    }
}

Denominacion* DineroSaldo::getDenominacion() const {
    return denominacion;
}

int DineroSaldo::getCantidad() const {
    return cantidad;
}

Saldo* DineroSaldo::getSaldo() const {
    return saldo;
}

void DineroSaldo::reducirCantidad(int cantidad) {
    if (cantidad <= 0) {
        throw ArgumentoInvalidoException("cantidad a reducir debe ser mayor que cero.");
    }
    if (this->cantidad < cantidad) {
        throw SaldoInsuficienteException();
    }
    this->cantidad -= cantidad;
}

void DineroSaldo::aumentarCantidad(int cantidad) {
    if (cantidad <= 0) {
        throw ArgumentoInvalidoException("cantidad a aumentar debe ser mayor que cero.");
    }
    this->cantidad += cantidad;
}
