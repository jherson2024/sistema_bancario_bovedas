#pragma once

#include <stdexcept>
#include <string>

/**
 * @brief Clase base para todas las excepciones del sistema de bóvedas.
 */
class ExcepcionOperacion : public std::runtime_error {
public:
    explicit ExcepcionOperacion(const std::string& mensaje)
        : std::runtime_error(mensaje) {}
};

// Argumentos inválidos generales
class ArgumentoInvalidoException : public ExcepcionOperacion {
public:
    explicit ArgumentoInvalidoException(const std::string& detalle)
        : ExcepcionOperacion("Argumento inválido: " + detalle) {}
};

// Errores de dominio específicos

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

class CantidadInvalidaException : public ExcepcionOperacion {
public:
    CantidadInvalidaException()
        : ExcepcionOperacion("La cantidad debe ser mayor que cero.") {}
};

class ValoracionNoDisponibleException : public ExcepcionOperacion {
public:
    ValoracionNoDisponibleException()
        : ExcepcionOperacion("No hay valoración disponible para la moneda solicitada.") {}
};

class ActivoInsuficienteException : public ExcepcionOperacion {
public:
    ActivoInsuficienteException()
        : ExcepcionOperacion("Activo insuficiente") {}

    ActivoInsuficienteException(const std::string& tipo, const std::string& moneda)
        : ExcepcionOperacion("Activo insuficiente: " + tipo + " en " + moneda) {}
};

class DenominacionInvalidaException : public ExcepcionOperacion {
public:
    DenominacionInvalidaException()
        : ExcepcionOperacion("La denominación es inválida: tipo nulo o valor no positivo.") {}
};

class FechaInvalidaException : public ExcepcionOperacion {
public:
    FechaInvalidaException()
        : ExcepcionOperacion("La fecha es inválida o inconsistente.") {}
};

class OperacionInvalidaException : public ExcepcionOperacion {
public:
    explicit OperacionInvalidaException(const std::string& detalle)
        : ExcepcionOperacion("Operación inválida: " + detalle) {}
};

class TransportadorInvalidoException : public ExcepcionOperacion {
public:
    TransportadorInvalidoException()
        : ExcepcionOperacion("El transportador no es válido o no fue asignado.") {}
};

class PlazaInvalidaException : public ExcepcionOperacion {
public:
    PlazaInvalidaException()
        : ExcepcionOperacion("El nombre de la plaza no puede estar vacío.") {}
};

class TipoActivoInvalidoException : public ExcepcionOperacion {
public:
    TipoActivoInvalidoException()
        : ExcepcionOperacion("El nombre del tipo de activo no puede estar vacío.") {}

    explicit TipoActivoInvalidoException(const std::string& mensaje)
        : ExcepcionOperacion("Error con tipo de activo: " + mensaje) {}
};

class TipoMonedaInvalidaException : public ExcepcionOperacion {
public:
    TipoMonedaInvalidaException()
        : ExcepcionOperacion("El nombre del tipo de moneda no puede estar vacío.") {}
};

class TipoOperacionInvalidaException : public ExcepcionOperacion {
public:
    TipoOperacionInvalidaException()
        : ExcepcionOperacion("El nombre del tipo de operación no puede estar vacío.") {}

    explicit TipoOperacionInvalidaException(const std::string& detalle)
        : ExcepcionOperacion("Tipo de operación inválido: " + detalle) {}
};

class BovedaInvalidaException : public ExcepcionOperacion {
public:
    BovedaInvalidaException()
        : ExcepcionOperacion("La bóveda es nula o inválida.") {}
};

class ActivoTransaccionInvalidoException : public ExcepcionOperacion {
public:
    ActivoTransaccionInvalidoException()
        : ExcepcionOperacion("ActivoTransaccion inválido.") {}

    explicit ActivoTransaccionInvalidoException(const std::string& detalle)
        : ExcepcionOperacion("ActivoTransaccion inválido: " + detalle) {}
};
