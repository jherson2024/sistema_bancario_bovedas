#include "Valoracion.h"
#include "ExcepcionesMoneda.h"
#include "ExcepcionesGenerales.h"
Valoracion::Valoracion(std::shared_ptr<TipoMoneda> tipoMoneda, double valor)
    : tipoMoneda(tipoMoneda), valor(valor) {
    if (!tipoMoneda) {
        throw TipoMonedaInvalidaException();
    }
    if (valor < 0.0) {
        throw ArgumentoInvalidoException("El valor de una valoración no puede ser negativo.");
    }
}