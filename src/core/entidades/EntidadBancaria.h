#ifndef ENTIDADBANCARIA_H
#define ENTIDADBANCARIA_H

#include <string>
#include <vector>
#include <memory>
#include "Boveda.h"

class EntidadBancaria {
public:
    std::string nombre;
    std::vector<std::shared_ptr<Boveda>> bovedas;

    EntidadBancaria(const std::string& nombre);
    void agregarBoveda(std::shared_ptr<Boveda> b);
};

#endif // ENTIDADBANCARIA_H
