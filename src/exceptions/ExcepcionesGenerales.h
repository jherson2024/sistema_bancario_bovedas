#pragma once
#include "ExcepcionOperacion.h"

class ArgumentoInvalidoException : public ExcepcionOperacion {
public:
    ArgumentoInvalidoException()
        : ExcepcionOperacion("Argumento inválido.") {}

    explicit ArgumentoInvalidoException(const std::string& detalle)
        : ExcepcionOperacion("Argumento inválido: " + detalle) {}
};

class CantidadInvalidaException : public ExcepcionOperacion {
public:
    CantidadInvalidaException()
        : ExcepcionOperacion("Cantidad inválida.") {}

    explicit CantidadInvalidaException(const std::string& mensaje)
        : ExcepcionOperacion("Error con cantidad: " + mensaje) {}
};

class FechaInvalidaException : public ExcepcionOperacion {
public:
    FechaInvalidaException()
        : ExcepcionOperacion("Fecha inválida.") {}

    explicit FechaInvalidaException(const std::string& mensaje)
        : ExcepcionOperacion("Error con fecha: " + mensaje) {}
};