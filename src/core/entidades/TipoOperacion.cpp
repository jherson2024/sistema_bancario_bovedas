#include "TipoOperacion.h"
#include "ExcepcionesEntidades.h"

TipoOperacion::TipoOperacion(const std::string& nombre) : nombre(nombre) {
    if (nombre.empty()) {
        throw TipoOperacionInvalidaException();
    }
}
