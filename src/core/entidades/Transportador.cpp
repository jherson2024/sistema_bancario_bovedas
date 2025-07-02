#include "Transportador.h"
#include "ExcepcionesEntidades.h"

Transportador::Transportador(const std::string& nombre) : nombre(nombre) {
    if (nombre.empty()) {
        throw TransportadorInvalidoException();
    }
}
