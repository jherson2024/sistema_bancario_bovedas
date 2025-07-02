#pragma once
#include "ExcepcionOperacion.h"

class TransportadorInvalidoException : public ExcepcionOperacion {
public:
    TransportadorInvalidoException()
        : ExcepcionOperacion("Error con transportador desconocido") {}

    explicit TransportadorInvalidoException(const std::string& mensaje)
        : ExcepcionOperacion("Error con transportador: " + mensaje) {}
};

class BovedaInvalidaException : public ExcepcionOperacion {
public:
    BovedaInvalidaException()
        : ExcepcionOperacion("La bóveda es nula o inválida.") {}
};

class EntidadInvalidaException : public ExcepcionOperacion {
public:
    EntidadInvalidaException()
        : ExcepcionOperacion("Entidad bancaria inválida.") {}

    explicit EntidadInvalidaException(const std::string& mensaje)
        : ExcepcionOperacion("Error con entidad bancaria: " + mensaje) {}
};

class PlazaInvalidaException : public ExcepcionOperacion {
public:
    PlazaInvalidaException()
        : ExcepcionOperacion("Plaza inválida.") {}

    explicit PlazaInvalidaException(const std::string& mensaje)
        : ExcepcionOperacion("Error con plaza: " + mensaje) {}
};

class TipoOperacionInvalidaException : public ExcepcionOperacion {
public:
    TipoOperacionInvalidaException()
        : ExcepcionOperacion("Tipo de operación inválido.") {}

    explicit TipoOperacionInvalidaException(const std::string& mensaje)
        : ExcepcionOperacion("Error con tipo de operación: " + mensaje) {}
};
