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
