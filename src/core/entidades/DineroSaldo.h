#ifndef DINEROSALDO_H
#define DINEROSALDO_H

#include "Denominacion.h"
#include "Saldo.h"
#include <stdexcept>

class DineroSaldo {
public:
    DineroSaldo(Denominacion* denominacion, int cantidad, Saldo* saldo);
    ~DineroSaldo() = default;

    Denominacion* getDenominacion() const;
    int getCantidad() const;
    Saldo* getSaldo() const;

    void reducirCantidad(int cantidad);
    void aumentarCantidad(int cantidad);

private:
    Denominacion* denominacion;
    int cantidad;
    Saldo* saldo;
};

#endif // DINEROSALDO_H
