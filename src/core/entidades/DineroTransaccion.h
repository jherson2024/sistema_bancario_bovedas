#ifndef DINEROTRANSACCION_H
#define DINEROTRANSACCION_H

#include "Denominacion.h"

// Forward declaration para evitar dependencias circulares
class Transaccion;

class DineroTransaccion {
public:
    DineroTransaccion(Denominacion* denominacion, int cantidad, Transaccion* transaccion);
    ~DineroTransaccion() = default; 

    Denominacion* getDenominacion() const;
    int getCantidad() const;
    Transaccion* getTransaccion() const;

    double getTotal() const;

private:
    Denominacion* denominacion;   // No se elimina aquí, no es dueño
    int cantidad;
    Transaccion* transaccion;     // Tampoco se elimina aquí
};

#endif // DINEROTRANSACCION_H
