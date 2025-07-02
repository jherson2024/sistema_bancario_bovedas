#pragma once
#include "ExcepcionOperacion.h"

class DenominacionInvalidaException : public ExcepcionOperacion {
public:
    DenominacionInvalidaException()
        : ExcepcionOperacion("Denominación inválida.") {}

    explicit DenominacionInvalidaException(const std::string& mensaje)
        : ExcepcionOperacion("Error con denominación: " + mensaje) {}
};

class TipoMonedaInvalidaException : public ExcepcionOperacion {
public:
    TipoMonedaInvalidaException()
        : ExcepcionOperacion("El nombre del tipo de moneda no puede estar vacío.") {}
};

class MonedaInvalidaException : public ExcepcionOperacion {
public:
    MonedaInvalidaException()
        : ExcepcionOperacion("Moneda inválida.") {}

    explicit MonedaInvalidaException(const std::string& mensaje)
        : ExcepcionOperacion("Error con moneda: " + mensaje) {}
};

class ValoracionNoDisponibleException : public ExcepcionOperacion {
public:
    ValoracionNoDisponibleException()
        : ExcepcionOperacion("No hay valoración disponible para la moneda solicitada.") {}
};
