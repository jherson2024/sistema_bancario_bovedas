#include "Plaza.h"
#include "ExcepcionesEntidades.h"

Plaza::Plaza(const std::string& nombre) : nombre(nombre) {
    if (nombre.empty()) {
        throw PlazaInvalidaException();
    }
}
