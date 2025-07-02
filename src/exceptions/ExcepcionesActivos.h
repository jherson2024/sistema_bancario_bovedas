#pragma once
#include "ExcepcionOperacion.h"

class ActivoTransaccionInvalidoException : public ExcepcionOperacion {
public:
    ActivoTransaccionInvalidoException()
        : ExcepcionOperacion("ActivoTransaccion inválido") {}

    explicit ActivoTransaccionInvalidoException(const std::string& detalle)
        : ExcepcionOperacion("ActivoTransaccion inválido: " + detalle) {}
};

class ActivoInsuficienteException : public ExcepcionOperacion {
public:
    ActivoInsuficienteException()
        : ExcepcionOperacion("Activo insuficiente") {}

    ActivoInsuficienteException(const std::string& tipo, const std::string& moneda)
        : ExcepcionOperacion("Activo insuficiente: " + tipo + " en " + moneda) {}
};

class TipoActivoInvalidoException : public ExcepcionOperacion {
public:
    TipoActivoInvalidoException()
        : ExcepcionOperacion("Tipo de activo inválido") {}

    explicit TipoActivoInvalidoException(const std::string& mensaje)
        : ExcepcionOperacion("Error con tipo de activo: " + mensaje) {}
};
