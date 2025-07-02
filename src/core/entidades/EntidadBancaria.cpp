#include "EntidadBancaria.h"
#include "ExcepcionesEntidades.h"
#include <iostream>
#include <iomanip>

using namespace std;

EntidadBancaria::EntidadBancaria(const string& nombre) : nombre(nombre) {}

void EntidadBancaria::agregarBoveda(shared_ptr<Boveda> b) {
    if (!b) {
        throw BovedaInvalidaException();
    }
    bovedas.push_back(b);
}