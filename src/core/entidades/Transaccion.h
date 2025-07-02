#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Transportador.h"
#include "TipoOperacion.h"
#include "Denominacion.h"
#include "Boveda.h"
#include "Activo.h"
enum class EstadoTransaccion {
    PENDIENTE,
    EN_PROCESO,
    COMPLETADA,
    CANCELADA
};
class Transaccion {
public:
    // Constructor
    Transaccion(std::shared_ptr<Transportador> transportador,
                std::shared_ptr<TipoOperacion> tipoOperacion,
                const std::string& fechaInicio,
                const std::string& fechaFin,
                std::shared_ptr<Boveda> origen,
                std::shared_ptr<Boveda> destino);
    // Métodos de modificación
    void agregarDinero(std::shared_ptr<Denominacion> denominacion, int cantidad);
    void agregarActivoParcial(const Activo& activo, const std::string& moneda, double valorParcial);  
    // Operaciones
    void ejecutar();
    void cancelar();
    std::pair<std::string, std::string> obtenerPlazas() const;
    std::string estadoTexto() const;
    // Atributos públicos
    std::shared_ptr<Transportador> transportador;
    std::shared_ptr<TipoOperacion> tipoOperacion;
    std::string fechaInicio;
    std::string fechaFin;
    std::shared_ptr<Boveda> origen;
    std::shared_ptr<Boveda> destino;
    EstadoTransaccion estado;
    std::string toString() const;
    std::map<std::shared_ptr<Denominacion>, int> dineroTransferido;
    struct ParcialActivo {
        Activo activoOriginal;
        std::string monedaElegida;
        double cantidadElegida;
    };
    std::vector<ParcialActivo> activosTransferidos;
private:
    bool fechaPaso(const std::string& fecha) const;
};
#endif // TRANSACCION_H