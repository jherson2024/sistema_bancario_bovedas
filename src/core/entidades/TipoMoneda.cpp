#include "TipoMoneda.h"
#include "ExcepcionesMoneda.h"

TipoMoneda::TipoMoneda(const std::string& nombre) : nombre(nombre) {
    if (nombre.empty()) {
        throw TipoMonedaInvalidaException();
    }
}
