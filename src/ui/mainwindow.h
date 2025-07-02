#pragma once

#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QListWidget>
#include <QTextEdit>
#include <QDateEdit>
#include <QMessageBox>
#include <QScrollArea>

#include "SistemaBancario.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // === Monedas ===
    void registrarMoneda();
    void listarMonedas();
    void listarDenominacionesMonedas();

    // === Bancos ===
    void registrarBanco();
    void listarBancos();

    // === Plazas ===
    void registrarPlaza();
    void listarPlazas();

    // === Activos ===
    void registrarTipoActivo();
    void listarTiposActivo();
    void registrarDenominacion();
    void listarDenominaciones();

    // === Operaciones ===
    void registrarTipoOperacion();
    void listarTiposOperacion();

    // === Transportadores ===
    void registrarTransportador();
    void listarTransportadores();

    // === Bóvedas ===
    void registrarBoveda();
    void depositarDinero();
    void agregarCampoValoracion();
    void agregarActivo();
    void listarBovedas();
    void verEstadoBoveda();

    // === Transacciones ===
    void agregarDineroTrans();
    void agregarActivoTrans();
    void registrarTransaccion();
    void ejecutarTransaccion();
    void verDetalleTransaccion();

    // === Saldos ===
    void registrarSaldo();
    void verSaldoPorFecha();

private:
    std::vector<std::tuple<std::string, double, int>> transDinero;
    std::vector<std::tuple<std::string, std::string, double>> transActivos;

    SistemaBancario sistema;

    QTabWidget *tabWidget;
// === Monedas ===
QLineEdit *lineMoneda;
QPushButton *btnRegistrarMoneda;
QListWidget *listMonedas;
QLineEdit *lineDenomListaMonedaMonedas;
QListWidget *listDenominacionesMonedas;



    // === Bancos ===
    QLineEdit *lineBanco;
    QPushButton *btnRegistrarBanco;
    QListWidget *listBancos;

    

    // === Plazas ===
    QLineEdit *linePlaza;
    QPushButton *btnRegistrarPlaza;
    QListWidget *listPlazas;

    // === Activos ===
    QLineEdit *lineTipoActivo;
    QPushButton *btnRegistrarTipoActivo;
    QListWidget *listTiposActivo;

    QLineEdit *lineDenomMoneda;
    QDoubleSpinBox *spinDenomValor;
    QPushButton *btnRegistrarDenominacion;
    QLineEdit *lineDenomListaMoneda;
    QPushButton *btnListarDenominaciones;
    QListWidget *listDenominaciones;

    // === Operaciones ===
    QLineEdit *lineTipoOperacion;
    QPushButton *btnRegistrarTipoOperacion;
    QListWidget *listTiposOperacion;

    // === Transportadores ===
    QLineEdit *lineTransportador;
    QPushButton *btnRegistrarTransportador;
    QListWidget *listTransportadores;

// === Bóvedas ===
QLineEdit *lineIdBoveda;
QLineEdit *lineBovedaPlaza;
QPushButton *btnRegistrarBoveda;
QComboBox* comboBovedaBanco;

// === Para depósito de dinero ===
QComboBox* comboIdBovedaDep;
QComboBox* comboMoneda;
QComboBox* comboValor;
QSpinBox* spinDepCantidad;
QPushButton* btnDepositarDinero;

// === Para agregar activos ===
QComboBox* comboIdBovedaAct;
QComboBox* comboTipoActivo;
QList<QPair<QComboBox*, QDoubleSpinBox*>> valoraciones;
QPushButton* btnAgregarCampoValoracion;
QPushButton* btnAgregarActivo;
QVBoxLayout* layoutBovedas;

// === Listar bóvedas ===
QLineEdit *lineListaBovedasBanco;
QPushButton *btnListarBovedas;
QListWidget *listBovedas;

// === Ver estado de bóveda ===
QLineEdit *lineEstadoIdBoveda;
QPushButton *btnVerEstadoBoveda;
QTextEdit *outputEstadoBoveda;


    // === Transacciones ===
   QComboBox *comboTransTransportador;
    QComboBox *comboTransOperacion;
    QDateEdit* dateTransFechaInicio;
    QDateEdit* dateTransFechaFin;
    QComboBox *comboTransBovedaInicio;
   QComboBox *comboTransBovedaFin;

   QComboBox *comboTransMonedaDinero;      
    QComboBox *comboTransValor;
    QSpinBox *spinTransCantidad;
    QPushButton *btnAgregarDineroTrans;
    QListWidget *listTransDinero;

    QPushButton *btnEliminarActivoTrans;
    QPushButton *btnEliminarDineroTrans;

  QComboBox *comboTransTipoActivo;
   QComboBox *comboTransActivoMoneda;
    QSpinBox *spinTransActivoCantidad;
    QPushButton *btnAgregarActivoTrans;
    QListWidget *listTransActivos;

    QPushButton *btnRegistrarTransaccion;
    QLabel *labelTransRespuesta;

    QComboBox *comboTransaccionId;
    QPushButton *btnEjecutarTransaccion;

    QComboBox *comboDetalleId;
    QPushButton *btnVerDetalleTransaccion;
    QTextEdit *outputDetalleTransaccion;

    // === Saldos ===
    QLineEdit *lineSaldoIdBoveda;
    QLineEdit *lineSaldoFecha;
    QPushButton *btnRegistrarSaldo;

    QLineEdit *lineConsultaIdBoveda;
    QLineEdit *lineConsultaFecha;
    QPushButton *btnVerSaldo;
    QTextEdit *outputSaldo;

    void actualizarComboBancos();
   void actualizarComboBovedas(QComboBox* combo);
    void actualizarComboMonedas();
    void actualizarComboTiposActivo();
    void actualizarComboDenominaciones(const QString& moneda);
    void simularSistema();
    void eliminarDineroTrans();
    void eliminarActivoTrans();
    void actualizarComboTransportadores();
    void actualizarComboTiposOperacion();
    void actualizarComboBovedasTransaccion();
    void actualizarComboMonedasTransaccion();
    void actualizarComboTiposActivoTransaccion();
    void actualizarComboTransacciones(QComboBox* combo);
};