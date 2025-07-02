#pragma once
#include "ExcepcionOperacion.h"

class DineroInsuficienteException : public ExcepcionOperacion {
public:
    DineroInsuficienteException()
        : ExcepcionOperacion("Dinero insuficiente en la bóveda para completar la operación.") {}
};

class SaldoInsuficienteException : public ExcepcionOperacion {
public:
    SaldoInsuficienteException()
        : ExcepcionOperacion("No hay suficiente saldo para reducir la cantidad solicitada.") {}
};

class OperacionInvalidaException : public ExcepcionOperacion {
public:
    OperacionInvalidaException()
        : ExcepcionOperacion("Operación inválida.") {}

    explicit OperacionInvalidaException(const std::string& detalle)
        : ExcepcionOperacion("Operación inválida: " + detalle) {}
};
class TransaccionVaciaException : public ExcepcionOperacion {
public:
    explicit TransaccionVaciaException(const std::string& mensaje)
        : ExcepcionOperacion(mensaje) {}
};
