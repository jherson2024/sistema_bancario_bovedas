#include "Denominacion.h"
#include "ExcepcionesMoneda.h"

Denominacion::Denominacion(std::shared_ptr<TipoMoneda> tipoMoneda, double valor)
    : tipoMoneda(tipoMoneda), valor(valor) {
    if (!tipoMoneda || valor <= 0) {
        throw DenominacionInvalidaException("Tipo de moneda nulo o valor inválido para la denominación.");
    }
}
