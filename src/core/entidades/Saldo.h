#ifndef SALDO_H
#define SALDO_H

#include <string>
#include <map>

class Saldo {
public:
    std::string fecha;
    std::map<std::string, double> dineroPorMoneda;              // Ej: "USD" -> 500.0
    std::map<std::string, std::map<double, int>> billetesPorMoneda;  
    std::map<std::string, std::map<std::string, double>> activosPorTipo;  // Ej: "Joya" -> { "USD" -> 200.0 }

    Saldo(const std::string& fecha);
    std::string toString() const;
};

#endif // SALDO_H
