#include "TipoActivo.h"
#include "ExcepcionesActivos.h"

TipoActivo::TipoActivo(const std::string& nombre) : nombre(nombre) {
    if (nombre.empty()) {
        throw TipoActivoInvalidoException();
    }
}
