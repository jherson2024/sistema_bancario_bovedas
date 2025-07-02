#include "Saldo.h"
#include "ExcepcionesGenerales.h"
#include <sstream>

Saldo::Saldo(const std::string& fecha) : fecha(fecha) {
    if (fecha.empty()) {
        throw FechaInvalidaException();
    }

    // Opcional: validar formato "YYYY-MM-DD" mínimamente
    if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-') {
        throw FechaInvalidaException();
    }
    
}

std::string Saldo::toString() const {
    std::ostringstream oss;
    oss << "📅 Fecha: " << fecha << "\n\n";

    oss << "💰 Dinero:\n";
    for (const auto& [moneda, cantidad] : dineroPorMoneda) {
        oss << "  - " << moneda << ": " << cantidad << "\n";
    }
    oss << "\n🧾 Billetes o monedas por denominación:\n";
    for (const auto& [moneda, mapaDenominaciones] : billetesPorMoneda) {
        oss << "  - " << moneda << ":\n";
        for (const auto& [denominacion, cantidad] : mapaDenominaciones) {
            oss << "      * " << denominacion << ": " << cantidad << " billete(s)\n";
        }
    }

    oss << "\n📦 Activos:\n";
    for (const auto& [tipo, mapaMoneda] : activosPorTipo) {
        oss << "  - " << tipo << ":\n";
        for (const auto& [moneda, valor] : mapaMoneda) {
            oss << "      * " << moneda << ": " << valor << "\n";
        }
    }
    return oss.str();
}
