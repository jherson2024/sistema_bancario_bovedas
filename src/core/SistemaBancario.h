#pragma once

#include <map>
#include <vector>
#include <memory>
#include <string>
#include "ExcepcionesActivos.h"
#include "ExcepcionesEntidades.h"
#include "ExcepcionesGenerales.h"
#include "ExcepcionesMoneda.h"
#include "ExcepcionesTransacciones.h"
#include "Transaccion.h"
#include "Saldo.h"
#include "EntidadBancaria.h"
#include "TipoMoneda.h"
#include "Denominacion.h"
#include "Plaza.h"
#include "TipoActivo.h"
#include "TipoOperacion.h"
#include "Transportador.h"

class SistemaBancario {
public:
    Transaccion construirTransaccionDesdeDatos(
        const std::string& transportador,
        const std::string& tipoOperacion,
        const std::string& fechaInicio,
        const std::string& fechaFin,
        const std::string& idOrigen,
        const std::string& idDestino,
        const std::vector<std::tuple<std::string, double, int>>& dinero,
        const std::vector<std::tuple<std::string, std::string, double>>& activos
    );
    void registrarMoneda(const std::string& nombre);
    std::vector<std::string> listarMonedas() const;

    void registrarBanco(const std::string& nombre);
    std::vector<std::string> listarBancos() const;

    void registrarPlaza(const std::string& nombre);
    std::vector<std::string> listarPlazas() const;

    void registrarTipoActivo(const std::string& nombre);
    std::vector<std::string> listarTiposActivo() const;

    void registrarTipoOperacion(const std::string& nombre);
    std::vector<std::string> listarTiposOperacion() const;

    void registrarDenominacion(const std::string& moneda, double valor);
    std::vector<double> listarDenominaciones(const std::string& moneda) const;

    void registrarBoveda(const std::string& banco, const std::string& plaza, const std::string& idBoveda);
    std::vector<std::string> listarBovedas(const std::string& banco) const;

    void depositarDinero(const std::string& idBoveda, const std::string& moneda, double valor, int cantidad);
    
    void agregarActivo(const std::string& tipo, const std::string& idBoveda,
                       const std::vector<std::pair<std::string, double>>& valoraciones);

    Saldo consultarEstadoBoveda(const std::string& idBoveda) const;

    void registrarTransportador(const std::string& nombre);
    std::vector<std::string> listarTransportadores() const;

    void registrarTransaccion(const Transaccion& t);
    void ejecutarTransaccion(int id);
    Transaccion detalleTransaccion(int id) const;

    void registrarSaldoDiario(const std::string& idBoveda, const std::string& fecha);
    Saldo consultarSaldoPorFecha(const std::string& idBoveda, const std::string& fecha) const;

    std::shared_ptr<Boveda> obtenerBovedaPorId(const std::string& idBoveda) const;
    std::vector<int> listarTransacciones() const;

private:
    std::map<std::string, std::shared_ptr<EntidadBancaria>> bancos;
    std::map<std::string, std::shared_ptr<TipoMoneda>> monedas;
    std::vector<std::shared_ptr<TipoMoneda>> ordenMonedas;
    std::map<std::string, std::shared_ptr<Denominacion>> denominaciones;
    std::map<std::string, std::shared_ptr<Plaza>> plazas;
    std::map<std::string, std::shared_ptr<TipoActivo>> tiposActivos;
    std::map<std::string, std::shared_ptr<TipoOperacion>> tiposOperaciones;
    std::vector<std::shared_ptr<Transaccion>> transacciones;
    std::map<std::string, std::shared_ptr<Transportador>> transportadores;
};
