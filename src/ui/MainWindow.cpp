    #include "mainwindow.h"
#include <random>

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
            auto centerLayout = [](QWidget *widget) {
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addStretch();
        layout->addWidget(widget);
        layout->addStretch();
        return layout;
    };
        tabWidget = new QTabWidget(this);
        setCentralWidget(tabWidget);
  // === Monedas ===
QWidget *tabMonedas = new QWidget;
QVBoxLayout *layoutMonedas = new QVBoxLayout;

// === Widgets: Ingreso y registro de moneda ===
lineMoneda = new QLineEdit;
lineMoneda->setPlaceholderText("Ingrese nombre de la moneda (ej. USD)");
lineMoneda->setMaximumWidth(400);

btnRegistrarMoneda = new QPushButton("Registrar Moneda");
btnRegistrarMoneda->setMaximumWidth(250);
btnRegistrarMoneda->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

listMonedas = new QListWidget;

// Layouts centrados
QHBoxLayout *lineLayoutMonedas = new QHBoxLayout;
lineLayoutMonedas->addStretch();
lineLayoutMonedas->addWidget(lineMoneda);
lineLayoutMonedas->addStretch();

QHBoxLayout *btnLayoutMonedas = new QHBoxLayout;
btnLayoutMonedas->addStretch();
btnLayoutMonedas->addWidget(btnRegistrarMoneda);
btnLayoutMonedas->addStretch();

QHBoxLayout *listLayoutMonedas = new QHBoxLayout;
listLayoutMonedas->addStretch();
listLayoutMonedas->addWidget(listMonedas);
listLayoutMonedas->addStretch();

layoutMonedas->addLayout(lineLayoutMonedas);
layoutMonedas->addLayout(btnLayoutMonedas);
layoutMonedas->addLayout(listLayoutMonedas);

// === Widgets: Listar denominaciones ===
// ⚠️ Renombrados para evitar conflicto con Activos
lineDenomListaMonedaMonedas = new QLineEdit;
lineDenomListaMonedaMonedas->setPlaceholderText("Ingrese moneda para listar denominaciones");
lineDenomListaMonedaMonedas->setMaximumWidth(400);

QPushButton *btnListarDenominacionesMonedas = new QPushButton("Listar Denominaciones");
btnListarDenominacionesMonedas->setMaximumWidth(250);

listDenominacionesMonedas = new QListWidget;

// Layouts centrados
QHBoxLayout *lineLayoutDenom = new QHBoxLayout;
lineLayoutDenom->addStretch();
lineLayoutDenom->addWidget(lineDenomListaMonedaMonedas);
lineLayoutDenom->addStretch();

QHBoxLayout *btnLayoutDenom = new QHBoxLayout;
btnLayoutDenom->addStretch();
btnLayoutDenom->addWidget(btnListarDenominacionesMonedas);
btnLayoutDenom->addStretch();

QHBoxLayout *listLayoutDenom = new QHBoxLayout;
listLayoutDenom->addStretch();
listLayoutDenom->addWidget(listDenominacionesMonedas);
listLayoutDenom->addStretch();

layoutMonedas->addSpacing(30);
layoutMonedas->addLayout(lineLayoutDenom);
layoutMonedas->addLayout(btnLayoutDenom);
layoutMonedas->addLayout(listLayoutDenom);

// === Scroll y tab ===
QWidget *containerMonedas = new QWidget;
containerMonedas->setLayout(layoutMonedas);

QScrollArea *scrollMonedas = new QScrollArea;
scrollMonedas->setWidgetResizable(true);
scrollMonedas->setWidget(containerMonedas);

tabWidget->addTab(scrollMonedas, "Monedas");

// === Conexiones ===
connect(btnRegistrarMoneda, &QPushButton::clicked, this, &MainWindow::registrarMoneda);

// Redirigir el botón a una función específica si vas a usar nombres distintos
connect(btnListarDenominacionesMonedas, &QPushButton::clicked, this, &MainWindow::listarDenominacionesMonedas);

// Autocompletar denominación al seleccionar moneda
connect(listMonedas, &QListWidget::itemClicked, this, [=](QListWidgetItem *item){
    lineDenomListaMonedaMonedas->setText(item->text());
});



// === Bancos ===
QWidget *tabBancos = new QWidget;
QVBoxLayout *layoutBancos = new QVBoxLayout;

// Crear widgets
lineBanco = new QLineEdit;
lineBanco->setPlaceholderText("Ingrese nombre del banco");
lineBanco->setMaximumWidth(400);
//lineBanco->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

btnRegistrarBanco = new QPushButton("Registrar Banco");
btnRegistrarBanco->setMaximumWidth(200);
btnRegistrarBanco->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

listBancos = new QListWidget;

// Centrado horizontal con nombres únicos
QHBoxLayout *lineLayoutBancos = new QHBoxLayout;
lineLayoutBancos->addStretch();
lineLayoutBancos->addWidget(lineBanco);
lineLayoutBancos->addStretch();

QHBoxLayout *btnLayoutBancos = new QHBoxLayout;
btnLayoutBancos->addStretch();
btnLayoutBancos->addWidget(btnRegistrarBanco);
btnLayoutBancos->addStretch();

QHBoxLayout *listLayoutBancos = new QHBoxLayout;
listLayoutBancos->addStretch();
listLayoutBancos->addWidget(listBancos);
listLayoutBancos->addStretch();

// Agregar a layout vertical
layoutBancos->addLayout(lineLayoutBancos);
layoutBancos->addLayout(btnLayoutBancos);
layoutBancos->addLayout(listLayoutBancos);

// Widget contenedor
QWidget *containerBancos = new QWidget;
containerBancos->setLayout(layoutBancos);

// ScrollArea
QScrollArea *scrollBancos = new QScrollArea;
scrollBancos->setWidgetResizable(true);
scrollBancos->setWidget(containerBancos);

// Agregar a tabWidget
tabWidget->addTab(scrollBancos, "Bancos");

// Conexión
connect(btnRegistrarBanco, &QPushButton::clicked, this, &MainWindow::registrarBanco);

   // === Plazas ===
QWidget *tabPlazas = new QWidget;
QVBoxLayout *layoutPlazas = new QVBoxLayout;

// Crear widgets
linePlaza = new QLineEdit;
linePlaza->setPlaceholderText("Ingrese nombre de la plaza");
linePlaza->setMaximumWidth(400);
//linePlaza->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

btnRegistrarPlaza = new QPushButton("Registrar Plaza");
btnRegistrarPlaza->setMaximumWidth(200);
btnRegistrarPlaza->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

listPlazas = new QListWidget;

// Layouts centrados con nombres únicos
QHBoxLayout *lineLayoutPlazas = new QHBoxLayout;
lineLayoutPlazas->addStretch();
lineLayoutPlazas->addWidget(linePlaza);
lineLayoutPlazas->addStretch();

QHBoxLayout *btnLayoutPlazas = new QHBoxLayout;
btnLayoutPlazas->addStretch();
btnLayoutPlazas->addWidget(btnRegistrarPlaza);
btnLayoutPlazas->addStretch();

QHBoxLayout *listLayoutPlazas = new QHBoxLayout;
listLayoutPlazas->addStretch();
listLayoutPlazas->addWidget(listPlazas);
listLayoutPlazas->addStretch();

// Ensamblar layout vertical
layoutPlazas->addLayout(lineLayoutPlazas);
layoutPlazas->addLayout(btnLayoutPlazas);
layoutPlazas->addLayout(listLayoutPlazas);

// Contenedor con layout
QWidget *containerPlazas = new QWidget;
containerPlazas->setLayout(layoutPlazas);

// ScrollArea
QScrollArea *scrollPlazas = new QScrollArea;
scrollPlazas->setWidgetResizable(true);
scrollPlazas->setWidget(containerPlazas);

// Agregar a pestaña
tabWidget->addTab(scrollPlazas, "Plazas");

// Conexión
connect(btnRegistrarPlaza, &QPushButton::clicked, this, &MainWindow::registrarPlaza);


    // === Activos ===
QWidget *tabActivos = new QWidget;
QVBoxLayout *layoutActivos = new QVBoxLayout;

// === Tipo de Activo ===
lineTipoActivo = new QLineEdit;
lineTipoActivo->setPlaceholderText("Ingrese tipo de activo (ej. Lingote)");
lineTipoActivo->setMaximumWidth(400);
//lineTipoActivo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

btnRegistrarTipoActivo = new QPushButton("Registrar Tipo de Activo");
btnRegistrarTipoActivo->setMaximumWidth(300);
btnRegistrarTipoActivo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

listTiposActivo = new QListWidget;

// === Denominación ===
lineDenomMoneda = new QLineEdit;
lineDenomMoneda->setPlaceholderText("Ingrese nombre de la moneda");
lineDenomMoneda->setMaximumWidth(400);
//lineDenomMoneda->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

spinDenomValor = new QDoubleSpinBox;
spinDenomValor->setMaximum(1000000);
spinDenomValor->setMaximumWidth(200);
spinDenomValor->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

btnRegistrarDenominacion = new QPushButton("Registrar Denominación");
btnRegistrarDenominacion->setMaximumWidth(300);
btnRegistrarDenominacion->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

listDenominaciones = new QListWidget;

// === Armar layout vertical ===
layoutActivos->addLayout(centerLayout(lineTipoActivo));
layoutActivos->addLayout(centerLayout(btnRegistrarTipoActivo));
layoutActivos->addLayout(centerLayout(listTiposActivo));

layoutActivos->addLayout(centerLayout(lineDenomMoneda));
layoutActivos->addLayout(centerLayout(spinDenomValor));
layoutActivos->addLayout(centerLayout(btnRegistrarDenominacion));
layoutActivos->addLayout(centerLayout(listDenominaciones));

// Contenedor con layout
QWidget *containerActivos = new QWidget;
containerActivos->setLayout(layoutActivos);

// ScrollArea
QScrollArea *scrollActivos = new QScrollArea;
scrollActivos->setWidgetResizable(true);
scrollActivos->setWidget(containerActivos);

// Agregar al tabWidget
tabWidget->addTab(scrollActivos, "Activos");

// Conexiones
connect(btnRegistrarTipoActivo, &QPushButton::clicked, this, &MainWindow::registrarTipoActivo);
connect(btnRegistrarDenominacion, &QPushButton::clicked, this, &MainWindow::registrarDenominacion);


// === Operaciones ===
QWidget *tabOperaciones = new QWidget;
QVBoxLayout *layoutOperaciones = new QVBoxLayout;

lineTipoOperacion = new QLineEdit;
lineTipoOperacion->setPlaceholderText("Ingrese tipo de operación");
lineTipoOperacion->setMaximumWidth(400);
//lineTipoOperacion->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

btnRegistrarTipoOperacion = new QPushButton("Registrar Tipo de Operación");
btnRegistrarTipoOperacion->setMaximumWidth(350);
btnRegistrarTipoOperacion->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

listTiposOperacion = new QListWidget;

// Centrado
layoutOperaciones->addLayout(centerLayout(lineTipoOperacion));
layoutOperaciones->addLayout(centerLayout(btnRegistrarTipoOperacion));
layoutOperaciones->addLayout(centerLayout(listTiposOperacion));

// Contenedor con scroll
QWidget *containerOperaciones = new QWidget;
containerOperaciones->setLayout(layoutOperaciones);

QScrollArea *scrollOperaciones = new QScrollArea;
scrollOperaciones->setWidgetResizable(true);
scrollOperaciones->setWidget(containerOperaciones);

tabWidget->addTab(scrollOperaciones, "Operaciones");

// Conexión
connect(btnRegistrarTipoOperacion, &QPushButton::clicked, this, &MainWindow::registrarTipoOperacion);


// === Transportadores ===
QWidget *tabTransportadores = new QWidget;
QVBoxLayout *layoutTransportadores = new QVBoxLayout;

// Widgets
lineTransportador = new QLineEdit;
lineTransportador->setPlaceholderText("Ingrese nombre del transportador");
lineTransportador->setMaximumWidth(400);
//lineTransportador->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

btnRegistrarTransportador = new QPushButton("Registrar Transportador");
btnRegistrarTransportador->setMaximumWidth(300);
btnRegistrarTransportador->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

listTransportadores = new QListWidget;

// Estructura del layout
layoutTransportadores->addLayout(centerLayout(lineTransportador));
layoutTransportadores->addLayout(centerLayout(btnRegistrarTransportador));
layoutTransportadores->addLayout(centerLayout(listTransportadores));

// Contenedor con layout
QWidget *containerTransportadores = new QWidget;
containerTransportadores->setLayout(layoutTransportadores);

// ScrollArea
QScrollArea *scrollTransportadores = new QScrollArea;
scrollTransportadores->setWidgetResizable(true);
scrollTransportadores->setWidget(containerTransportadores);

// Agregar a pestaña
tabWidget->addTab(scrollTransportadores, "Transportadores");

// Conexión
connect(btnRegistrarTransportador, &QPushButton::clicked, this, &MainWindow::registrarTransportador);


// === Bóvedas ===
QWidget *tabBovedas = new QWidget;
QVBoxLayout *layoutBovedas = new QVBoxLayout;

// === Registro de Bóveda ===
comboBovedaBanco = new QComboBox;
comboBovedaBanco->setMaximumWidth(400);
comboBovedaBanco->addItem("Seleccione un banco");
comboBovedaBanco->setItemData(0, 0, Qt::UserRole - 1);

try {
    for (const std::string& banco : sistema.listarBancos()) {
        comboBovedaBanco->addItem(QString::fromStdString(banco));
    }
} catch (const std::exception& e) {
    QMessageBox::critical(this, "Error", QString("Error al listar bancos: ") + e.what());
}

lineIdBoveda = new QLineEdit;
lineIdBoveda->setPlaceholderText("ID de la bóveda");
lineIdBoveda->setMaximumWidth(400);

lineBovedaPlaza = new QLineEdit;
lineBovedaPlaza->setPlaceholderText("Plaza de ubicación");
lineBovedaPlaza->setMaximumWidth(400);

btnRegistrarBoveda = new QPushButton("Registrar Bóveda");
btnRegistrarBoveda->setMaximumWidth(250);

layoutBovedas->addLayout(centerLayout(lineIdBoveda));
layoutBovedas->addLayout(centerLayout(comboBovedaBanco));
layoutBovedas->addLayout(centerLayout(lineBovedaPlaza));
layoutBovedas->addLayout(centerLayout(btnRegistrarBoveda));
connect(btnRegistrarBoveda, &QPushButton::clicked, this, &MainWindow::registrarBoveda);

// === Depósito de dinero ===
comboIdBovedaDep = new QComboBox;
comboIdBovedaDep->setMaximumWidth(400);
comboIdBovedaDep->addItem("Seleccione una bóveda");
comboIdBovedaDep->setItemData(0, 0, Qt::UserRole - 1);

try {
    for (const std::string& banco : sistema.listarBancos()) {
        for (const std::string& id : sistema.listarBovedas(banco)) {
            comboIdBovedaDep->addItem(QString::fromStdString(id));
        }
    }
} catch (const std::exception& e) {
    QMessageBox::critical(this, "Error", QString("Error al listar bóvedas: ") + e.what());
}

comboMoneda = new QComboBox;
comboMoneda->setMaximumWidth(400);
comboMoneda->addItem("Seleccione una moneda");
comboMoneda->setItemData(0, 0, Qt::UserRole - 1);

try {
    for (const std::string& moneda : sistema.listarMonedas()) {
        comboMoneda->addItem(QString::fromStdString(moneda));
    }
} catch (const std::exception& e) {
    QMessageBox::critical(this, "Error", QString("Error al listar monedas: ") + e.what());
}

comboValor = new QComboBox;
comboValor->setMaximumWidth(200);
comboValor->addItem("Seleccione un valor");
comboValor->setItemData(0, 0, Qt::UserRole - 1);

connect(comboMoneda, &QComboBox::currentTextChanged, this, [=](const QString &moneda) {
    comboValor->clear();
    comboValor->addItem("Seleccione un valor");
    if (moneda == "Seleccione una moneda") return;

    try {
        for (double v : sistema.listarDenominaciones(moneda.toStdString()))
            comboValor->addItem(QString::number(v));
    } catch (...) {
        comboValor->addItem("[Error al cargar]");
    }
});

spinDepCantidad = new QSpinBox;
spinDepCantidad->setMaximum(1000000);
spinDepCantidad->setMaximumWidth(200);

btnDepositarDinero = new QPushButton("Depositar Dinero");
btnDepositarDinero->setMaximumWidth(250);

layoutBovedas->addSpacing(30); // separación visual
layoutBovedas->addLayout(centerLayout(comboIdBovedaDep));
layoutBovedas->addLayout(centerLayout(comboMoneda));
layoutBovedas->addLayout(centerLayout(comboValor));
layoutBovedas->addLayout(centerLayout(spinDepCantidad));
layoutBovedas->addLayout(centerLayout(btnDepositarDinero));
connect(btnDepositarDinero, &QPushButton::clicked, this, &MainWindow::depositarDinero);

// === Agregar Activo ===
comboIdBovedaAct = new QComboBox;
comboIdBovedaAct->setMaximumWidth(400);
comboIdBovedaAct->addItem("Seleccione una bóveda");
comboIdBovedaAct->setItemData(0, 0, Qt::UserRole - 1);

try {
    for (const std::string& banco : sistema.listarBancos()) {
        for (const std::string& id : sistema.listarBovedas(banco)) {
            comboIdBovedaAct->addItem(QString::fromStdString(id));
        }
    }
} catch (const std::exception& e) {
    QMessageBox::critical(this, "Error", QString("Error al cargar bóvedas para activos: ") + e.what());
}

comboTipoActivo = new QComboBox;
comboTipoActivo->setMaximumWidth(400);
comboTipoActivo->addItem("Seleccione tipo de activo");
comboTipoActivo->setItemData(0, 0, Qt::UserRole - 1);

try {
    for (const std::string& tipo : sistema.listarTiposActivo()) {
        comboTipoActivo->addItem(QString::fromStdString(tipo));
    }
} catch (const std::exception& e) {
    QMessageBox::critical(this, "Error", QString("Error al listar tipos de activo: ") + e.what());
}

btnAgregarCampoValoracion = new QPushButton("+ Añadir valoración");
btnAgregarCampoValoracion->setMaximumWidth(250);

btnAgregarActivo = new QPushButton("Agregar Activo");
btnAgregarActivo->setMaximumWidth(250);

// === Agrega widgets al layout ===
layoutBovedas->addSpacing(30);
layoutBovedas->addLayout(centerLayout(comboIdBovedaAct));
int indexComboTipoActivo = layoutBovedas->count();
layoutBovedas->addLayout(centerLayout(comboTipoActivo));
layoutBovedas->addLayout(centerLayout(btnAgregarCampoValoracion));
layoutBovedas->addLayout(centerLayout(btnAgregarActivo));

// === Slot para añadir campo de valoración ===
connect(btnAgregarCampoValoracion, &QPushButton::clicked, this, [=]() {
    QHBoxLayout* layoutValoracion = new QHBoxLayout;

    QComboBox* comboMoneda = new QComboBox;
    comboMoneda->setMaximumWidth(200);
    comboMoneda->addItem("Seleccione moneda");
    comboMoneda->setItemData(0, 0, Qt::UserRole - 1);

    try {
        for (const std::string& moneda : sistema.listarMonedas()) {
            comboMoneda->addItem(QString::fromStdString(moneda));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(nullptr, "Error", QString("Error al cargar monedas: ") + e.what());
        return;
    }

    QDoubleSpinBox* spinValor = new QDoubleSpinBox;
    spinValor->setDecimals(2);
    spinValor->setMinimum(0.01);
    spinValor->setMaximum(1000000.00);
    spinValor->setValue(0.00);
    spinValor->setMaximumWidth(120);
    spinValor->setSingleStep(1.00);

    layoutValoracion->addWidget(comboMoneda);
    layoutValoracion->addWidget(spinValor);
    layoutValoracion->addStretch();
    layoutBovedas->insertLayout(indexComboTipoActivo + valoraciones.size() + 1, layoutValoracion);

    valoraciones.append(qMakePair(comboMoneda, spinValor));
});
connect(btnAgregarActivo, &QPushButton::clicked, this, &MainWindow::agregarActivo);

// === Listar bóvedas ===
lineListaBovedasBanco = new QLineEdit;
lineListaBovedasBanco->setPlaceholderText("Nombre del banco");
lineListaBovedasBanco->setMaximumWidth(400);

btnListarBovedas = new QPushButton("Listar Bóvedas");
btnListarBovedas->setMaximumWidth(250);

listBovedas = new QListWidget;

layoutBovedas->addSpacing(30);
layoutBovedas->addLayout(centerLayout(lineListaBovedasBanco));
layoutBovedas->addLayout(centerLayout(btnListarBovedas));
layoutBovedas->addLayout(centerLayout(listBovedas));

connect(btnListarBovedas, &QPushButton::clicked, this, &MainWindow::listarBovedas);

// === Ver estado de bóveda ===
lineEstadoIdBoveda = new QLineEdit;
lineEstadoIdBoveda->setPlaceholderText("ID de la bóveda");
lineEstadoIdBoveda->setMaximumWidth(400);

btnVerEstadoBoveda = new QPushButton("Ver Estado");
btnVerEstadoBoveda->setMaximumWidth(250);

outputEstadoBoveda = new QTextEdit;
outputEstadoBoveda->setReadOnly(true);
outputEstadoBoveda->setMinimumHeight(600);
outputEstadoBoveda->setMaximumWidth(600);

layoutBovedas->addSpacing(30);
layoutBovedas->addLayout(centerLayout(lineEstadoIdBoveda));
layoutBovedas->addLayout(centerLayout(btnVerEstadoBoveda));
layoutBovedas->addLayout(centerLayout(outputEstadoBoveda));

connect(btnVerEstadoBoveda, &QPushButton::clicked, this, &MainWindow::verEstadoBoveda);

// === Contenedor y Scroll ===
QWidget *containerBovedas = new QWidget;
containerBovedas->setLayout(layoutBovedas);

QScrollArea *scrollBovedas = new QScrollArea;
scrollBovedas->setWidgetResizable(true);
scrollBovedas->setWidget(containerBovedas);

// === Agregar al tabWidget ===
tabWidget->addTab(scrollBovedas, "Bóvedas");
    // === Transacciones ===
QWidget *tabTrans = new QWidget;
QVBoxLayout *layoutTrans = new QVBoxLayout;
// === Datos generales de la transacción ===
comboTransTransportador = new QComboBox;
comboTransTransportador->setMaximumWidth(400);
comboTransTransportador->addItem("Seleccione un transportador");
comboTransTransportador->setItemData(0, 0, Qt::UserRole - 1);

for (const std::string& t : sistema.listarTransportadores()) {
    comboTransTransportador->addItem(QString::fromStdString(t));
}
comboTransOperacion = new QComboBox;
comboTransOperacion->setMaximumWidth(400);
comboTransOperacion->addItem("Seleccione tipo de operación");
comboTransOperacion->setItemData(0, 0, Qt::UserRole - 1);

for (const std::string& op : sistema.listarTiposOperacion()) {
    comboTransOperacion->addItem(QString::fromStdString(op));
}
dateTransFechaInicio = new QDateEdit;
dateTransFechaInicio->setDisplayFormat("yyyy-MM-dd");
dateTransFechaInicio->setCalendarPopup(true);
dateTransFechaInicio->setMaximumWidth(400);

dateTransFechaFin = new QDateEdit;
dateTransFechaFin->setDisplayFormat("yyyy-MM-dd");
dateTransFechaFin->setCalendarPopup(true);
dateTransFechaFin->setMaximumWidth(400);

comboTransBovedaInicio = new QComboBox;
comboTransBovedaInicio->setMaximumWidth(400);
comboTransBovedaInicio->addItem("Seleccione bóveda origen");
comboTransBovedaInicio->setItemData(0, 0, Qt::UserRole - 1);

comboTransBovedaFin = new QComboBox;
comboTransBovedaFin->setMaximumWidth(400);
comboTransBovedaFin->addItem("Seleccione bóveda destino");
comboTransBovedaFin->setItemData(0, 0, Qt::UserRole - 1);

for (const std::string& banco : sistema.listarBancos()) {
    for (const std::string& idBoveda : sistema.listarBovedas(banco)) {
        QString bovedaStr = QString::fromStdString(idBoveda);
        comboTransBovedaInicio->addItem(bovedaStr);
        comboTransBovedaFin->addItem(bovedaStr);
    }
}
layoutTrans->addLayout(centerLayout(comboTransTransportador));
layoutTrans->addLayout(centerLayout(comboTransOperacion));
layoutTrans->addLayout(centerLayout(dateTransFechaInicio));
layoutTrans->addLayout(centerLayout(dateTransFechaFin));
layoutTrans->addLayout(centerLayout(comboTransBovedaInicio));
layoutTrans->addLayout(centerLayout(comboTransBovedaFin));

// === Dinero ===
comboTransMonedaDinero = new QComboBox;
comboTransMonedaDinero->setMaximumWidth(400);
comboTransMonedaDinero->addItem("Seleccione moneda");
comboTransMonedaDinero->setItemData(0, 0, Qt::UserRole - 1);

comboTransValor = new QComboBox;
comboTransValor->setMaximumWidth(400);
comboTransValor->addItem("Seleccione denominación");
comboTransValor->setItemData(0, 0, Qt::UserRole - 1);
connect(comboTransMonedaDinero, &QComboBox::currentTextChanged, this, [=](const QString &moneda) {
    actualizarComboDenominaciones(moneda);
});

spinTransCantidad = new QSpinBox;
spinTransCantidad->setMaximum(1000000);
spinTransCantidad->setMaximumWidth(200);

btnAgregarDineroTrans = new QPushButton("Agregar Dinero");
btnAgregarDineroTrans->setMaximumWidth(250);

listTransDinero = new QListWidget;

layoutTrans->addLayout(centerLayout(comboTransMonedaDinero));
layoutTrans->addLayout(centerLayout(comboTransValor));
layoutTrans->addLayout(centerLayout(spinTransCantidad));
layoutTrans->addLayout(centerLayout(btnAgregarDineroTrans));
layoutTrans->addLayout(centerLayout(listTransDinero));

// ⬇️ PEGA AQUÍ el bloque para eliminar dinero
btnEliminarDineroTrans = new QPushButton("Eliminar Dinero Seleccionado");
btnEliminarDineroTrans->setMaximumWidth(350);
layoutTrans->addLayout(centerLayout(btnEliminarDineroTrans));
connect(btnEliminarDineroTrans, &QPushButton::clicked, this, &MainWindow::eliminarDineroTrans);

connect(btnAgregarDineroTrans, &QPushButton::clicked, this, &MainWindow::agregarDineroTrans);

// === Activos ===
comboTransActivoMoneda = new QComboBox;
comboTransActivoMoneda->setMaximumWidth(400);
comboTransActivoMoneda->addItem("Seleccione moneda");
comboTransActivoMoneda->setItemData(0, 0, Qt::UserRole - 1);

spinTransActivoCantidad = new QSpinBox;
spinTransActivoCantidad->setMaximum(1000000);
spinTransActivoCantidad->setMaximumWidth(200);

btnAgregarActivoTrans = new QPushButton("Agregar Activo");
btnAgregarActivoTrans->setMaximumWidth(250);

listTransActivos = new QListWidget;

comboTransTipoActivo = new QComboBox;
comboTransTipoActivo->setMaximumWidth(400);
comboTransTipoActivo->addItem("Seleccione tipo de activo");
comboTransTipoActivo->setItemData(0, 0, Qt::UserRole - 1);

layoutTrans->addLayout(centerLayout(comboTransTipoActivo));
layoutTrans->addLayout(centerLayout(comboTransActivoMoneda));
layoutTrans->addLayout(centerLayout(spinTransActivoCantidad));
layoutTrans->addLayout(centerLayout(btnAgregarActivoTrans));
layoutTrans->addLayout(centerLayout(listTransActivos));

// ⬇️ PEGA AQUÍ el bloque para eliminar activo
btnEliminarActivoTrans = new QPushButton("Eliminar Activo Seleccionado");
btnEliminarActivoTrans->setMaximumWidth(350);
layoutTrans->addLayout(centerLayout(btnEliminarActivoTrans));
connect(btnEliminarActivoTrans, &QPushButton::clicked, this, &MainWindow::eliminarActivoTrans);

connect(btnAgregarActivoTrans, &QPushButton::clicked, this, &MainWindow::agregarActivoTrans);

// === Registro de transacción ===
btnRegistrarTransaccion = new QPushButton("Registrar Transacción");
btnRegistrarTransaccion->setMaximumWidth(250);

labelTransRespuesta = new QLabel;

layoutTrans->addLayout(centerLayout(btnRegistrarTransaccion));
layoutTrans->addLayout(centerLayout(labelTransRespuesta));
connect(btnRegistrarTransaccion, &QPushButton::clicked, this, &MainWindow::registrarTransaccion);

// === Ejecutar transacción ===
comboTransaccionId = new QComboBox;
comboTransaccionId->setMaximumWidth(300);
actualizarComboTransacciones(comboTransaccionId); // <-- ver paso 4

btnEjecutarTransaccion = new QPushButton("Ejecutar");
btnEjecutarTransaccion->setMaximumWidth(200);

layoutTrans->addLayout(centerLayout(comboTransaccionId));
layoutTrans->addLayout(centerLayout(btnEjecutarTransaccion));
connect(btnEjecutarTransaccion, &QPushButton::clicked, this, &MainWindow::ejecutarTransaccion);

// === Ver detalle ===
comboDetalleId = new QComboBox;
comboDetalleId->setMaximumWidth(300);
actualizarComboTransacciones(comboDetalleId); // <-- ver paso 4
btnVerDetalleTransaccion = new QPushButton("Ver Detalle");
btnVerDetalleTransaccion->setMaximumWidth(200);
outputDetalleTransaccion = new QTextEdit;
outputDetalleTransaccion->setReadOnly(true);
outputDetalleTransaccion->setMinimumHeight(400);
outputDetalleTransaccion->setMaximumWidth(600);
layoutTrans->addLayout(centerLayout(comboDetalleId));
layoutTrans->addLayout(centerLayout(btnVerDetalleTransaccion));
layoutTrans->addLayout(centerLayout(outputDetalleTransaccion));
connect(btnVerDetalleTransaccion, &QPushButton::clicked, this, &MainWindow::verDetalleTransaccion);
// Contenedor
QWidget *containerTrans = new QWidget;
containerTrans->setLayout(layoutTrans);
// ScrollArea
QScrollArea *scrollTrans = new QScrollArea;
scrollTrans->setWidgetResizable(true);
scrollTrans->setWidget(containerTrans);
tabWidget->addTab(scrollTrans, "Transacciones");
    // === Saldos ===
QWidget *tabSaldos = new QWidget;
QVBoxLayout *layoutSaldos = new QVBoxLayout;
// === Registrar saldo ===
lineSaldoIdBoveda = new QLineEdit;
lineSaldoIdBoveda->setPlaceholderText("ID de la bóveda");
lineSaldoIdBoveda->setMaximumWidth(400);
lineSaldoFecha = new QLineEdit;
lineSaldoFecha->setPlaceholderText("Fecha (YYYY-MM-DD)");
lineSaldoFecha->setMaximumWidth(400);
btnRegistrarSaldo = new QPushButton("Registrar Saldo");
btnRegistrarSaldo->setMaximumWidth(250);
layoutSaldos->addLayout(centerLayout(lineSaldoIdBoveda));
layoutSaldos->addLayout(centerLayout(lineSaldoFecha));
layoutSaldos->addLayout(centerLayout(btnRegistrarSaldo));
connect(btnRegistrarSaldo, &QPushButton::clicked, this, &MainWindow::registrarSaldo);
// === Consultar saldo ===
lineConsultaIdBoveda = new QLineEdit;
lineConsultaIdBoveda->setPlaceholderText("ID de la bóveda");
lineConsultaIdBoveda->setMaximumWidth(400);

lineConsultaFecha = new QLineEdit;
lineConsultaFecha->setPlaceholderText("Fecha (YYYY-MM-DD)");
lineConsultaFecha->setMaximumWidth(400);

btnVerSaldo = new QPushButton("Ver Saldo");
btnVerSaldo->setMaximumWidth(200);

outputSaldo = new QTextEdit;
outputSaldo->setReadOnly(true);
outputSaldo->setMinimumHeight(100);
outputSaldo->setMaximumWidth(600);

layoutSaldos->addLayout(centerLayout(lineConsultaIdBoveda));
layoutSaldos->addLayout(centerLayout(lineConsultaFecha));
layoutSaldos->addLayout(centerLayout(btnVerSaldo));
layoutSaldos->addLayout(centerLayout(outputSaldo));
connect(btnVerSaldo, &QPushButton::clicked, this, &MainWindow::verSaldoPorFecha);
// Contenedor con layout
QWidget *containerSaldos = new QWidget;
containerSaldos->setLayout(layoutSaldos);
// ScrollArea
QScrollArea *scrollSaldos = new QScrollArea;
scrollSaldos->setWidgetResizable(true);
scrollSaldos->setWidget(containerSaldos);
tabWidget->addTab(scrollSaldos, "Saldos");
simularSistema();
}

MainWindow::~MainWindow() {}
void MainWindow::agregarDineroTrans() {
    QString monedaQStr = comboTransMonedaDinero->currentText();
    QString valorQStr = comboTransValor->currentText();
    int cantidad = spinTransCantidad->value();

    if (comboTransMonedaDinero->currentIndex() <= 0 || 
        comboTransValor->currentIndex() <= 0 || 
        cantidad <= 0) {
        QMessageBox::warning(this, "Entrada inválida", "Debe seleccionar una moneda, una denominación y una cantidad válida.");
        return;
    }

    std::string moneda = monedaQStr.toStdString();
    double valor = valorQStr.toDouble();

    transDinero.emplace_back(moneda, valor, cantidad);

    QString texto = QString("%1 x %2 %3")
                        .arg(cantidad)
                        .arg(valor)
                        .arg(monedaQStr);

    listTransDinero->addItem(texto);
}

void MainWindow::agregarActivoTrans() {
    std::string tipo = comboTransTipoActivo->currentText().toStdString();
    std::string moneda = comboTransActivoMoneda->currentText().toStdString();
    double cantidad = static_cast<double>(spinTransActivoCantidad->value());

    // Validaciones
    if (tipo == "Seleccione tipo de activo" || moneda == "Seleccione moneda" || cantidad <= 0) return;

    // Registrar en la lista local
    transActivos.emplace_back(tipo, moneda, cantidad);

    // Mostrar en la lista visual
    QString texto = QString("%1 → %2 %3")
                        .arg(QString::fromStdString(tipo))
                        .arg(cantidad)
                        .arg(QString::fromStdString(moneda));

    listTransActivos->addItem(texto);
}

void MainWindow::registrarTransaccion() {
    try {
        std::string transportador = comboTransTransportador->currentText().toStdString();
        std::string tipoOperacion = comboTransOperacion->currentText().toStdString();
        std::string fechaInicio = dateTransFechaInicio->date().toString("yyyy-MM-dd").toStdString();
        std::string fechaFin = dateTransFechaFin->date().toString("yyyy-MM-dd").toStdString();

        std::string idOrigen = comboTransBovedaInicio->currentText().toStdString();
        std::string idDestino = comboTransBovedaFin->currentText().toStdString();
        // Validaciones básicas (opcional pero recomendable)
        if (transportador == "Seleccione un transportador" ||
            tipoOperacion == "Seleccione tipo de operación" ||
            idOrigen == "Seleccione bóveda origen" ||
            idDestino == "Seleccione bóveda destino" ||
            fechaInicio.empty() || fechaFin.empty()) {
            labelTransRespuesta->setText("❌ Faltan datos obligatorios.");
            return;
        }
        Transaccion t = sistema.construirTransaccionDesdeDatos(
            transportador,
            tipoOperacion,
            fechaInicio,
            fechaFin,
            idOrigen,
            idDestino,
            transDinero,
            transActivos
        );
        sistema.registrarTransaccion(t);
        actualizarComboTransacciones(comboTransaccionId);
        actualizarComboTransacciones(comboDetalleId);
        labelTransRespuesta->setText("✅ Transacción registrada con éxito.");
        actualizarComboBovedasTransaccion();
        // Limpiar listas y datos temporales
        transDinero.clear();
        transActivos.clear();
        listTransDinero->clear();
        listTransActivos->clear();
    } catch (const std::exception& e) {
        labelTransRespuesta->setText(QString("❌ Error: ") + e.what());
    }
}

void MainWindow::ejecutarTransaccion() {
    try {
        int id = comboTransaccionId->currentData().toInt();
        sistema.ejecutarTransaccion(id);
        QMessageBox::information(this, "Éxito", "✅ Transacción ejecutada correctamente.");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("❌ Error: ") + e.what());
    }
}
void MainWindow::verDetalleTransaccion() {
    try {
        int id = comboDetalleId->currentData().toInt();
        Transaccion t = sistema.detalleTransaccion(id);
        outputDetalleTransaccion->setText(QString::fromStdString(t.toString()));
    } catch (const std::exception& e) {
        outputDetalleTransaccion->setText(QString("❌ Error: ") + e.what());
    }
}
void MainWindow::registrarSaldo() {
    try {
        std::string idBoveda = lineSaldoIdBoveda->text().toStdString();
        std::string fecha = lineSaldoFecha->text().toStdString();

        sistema.registrarSaldoDiario(idBoveda, fecha);
        QMessageBox::information(this, "Éxito", "✅ Saldo diario registrado.");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("❌ Error: ") + e.what());
    }
}
void MainWindow::verSaldoPorFecha() {
    try {
        std::string idBoveda = lineConsultaIdBoveda->text().toStdString();
        std::string fecha = lineConsultaFecha->text().toStdString();

        Saldo saldo = sistema.consultarSaldoPorFecha(idBoveda, fecha);
        outputSaldo->setText(QString::fromStdString(saldo.toString()));
    } catch (const std::exception& e) {
        outputSaldo->setText(QString("❌ Error: ") + e.what());
    }
}
void MainWindow::registrarMoneda() {
    try {
        std::string nombre = lineMoneda->text().toStdString();
        sistema.registrarMoneda(nombre);
        listarMonedas();
        actualizarComboMonedas();
        actualizarComboMonedasTransaccion();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::listarMonedas() {
    listMonedas->clear();
    try {
        auto monedas = sistema.listarMonedas();
        for (const auto& m : monedas) {
            listMonedas->addItem(QString::fromStdString(m));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::registrarBanco() {
    try {
        sistema.registrarBanco(lineBanco->text().toStdString());
        listarBancos();
        actualizarComboBancos();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::listarBancos() {
    listBancos->clear();
    try {
        auto bancos = sistema.listarBancos();
        for (const auto& b : bancos) {
            listBancos->addItem(QString::fromStdString(b));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::registrarPlaza() {
    try {
        sistema.registrarPlaza(linePlaza->text().toStdString());
        listarPlazas();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::listarPlazas() {
    listPlazas->clear();
    try {
        auto plazas = sistema.listarPlazas();
        for (const auto& p : plazas) {
            listPlazas->addItem(QString::fromStdString(p));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::registrarTipoActivo() {
    try {
        sistema.registrarTipoActivo(lineTipoActivo->text().toStdString());
        listarTiposActivo();
        actualizarComboTiposActivoTransaccion();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::listarTiposActivo() {
    listTiposActivo->clear();
    try {
        auto tipos = sistema.listarTiposActivo();
        for (const auto& t : tipos) {
            listTiposActivo->addItem(QString::fromStdString(t));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::registrarTipoOperacion() {
    try {
        sistema.registrarTipoOperacion(lineTipoOperacion->text().toStdString());
        listarTiposOperacion();
        actualizarComboTiposOperacion();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::listarTiposOperacion() {
    listTiposOperacion->clear();
    try {
        auto tipos = sistema.listarTiposOperacion();
        for (const auto& t : tipos) {
            listTiposOperacion->addItem(QString::fromStdString(t));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::registrarDenominacion() {
    try {
        QString monedaQString = lineDenomMoneda->text();
        std::string moneda = monedaQString.toStdString();
        double valor = spinDenomValor->value();

        sistema.registrarDenominacion(moneda, valor);

        QMessageBox::information(this, "Éxito", "Denominación registrada.");

        actualizarComboDenominaciones(monedaQString); // ✔️ Usamos QString como se espera
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::listarDenominaciones() {
    listDenominaciones->clear();
    try {
        std::string moneda = lineDenomListaMoneda->text().toStdString();
        auto valores = sistema.listarDenominaciones(moneda);
        for (double v : valores) {
            listDenominaciones->addItem(QString("%1").arg(v));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::listarDenominacionesMonedas() {
    listDenominacionesMonedas->clear();
    try {
        std::string moneda = lineDenomListaMonedaMonedas->text().toStdString();
        auto valores = sistema.listarDenominaciones(moneda);
        for (double v : valores) {
            listDenominacionesMonedas->addItem(QString("%1").arg(v));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::registrarTransportador() {
    try {
        sistema.registrarTransportador(lineTransportador->text().toStdString());
        listarTransportadores();
        actualizarComboTransportadores();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::listarTransportadores() {
    listTransportadores->clear();
    try {
        auto lista = sistema.listarTransportadores();
        for (const auto& nombre : lista) {
            listTransportadores->addItem(QString::fromStdString(nombre));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::registrarBoveda() {
    try {
        // Verificación de punteros críticos
        if (!lineIdBoveda || !lineBovedaPlaza || !comboBovedaBanco) {
            QMessageBox::critical(this, "Error crítico", "Los campos de entrada no están inicializados correctamente.");
            return;
        }

        std::string id = lineIdBoveda->text().toStdString();
        std::string plaza = lineBovedaPlaza->text().toStdString();

        // Validación de campos vacíos
        if (id.empty() || plaza.empty()) {
            QMessageBox::warning(this, "Advertencia", "Todos los campos deben estar completos.");
            return;
        }

        // Validar selección del banco
        if (comboBovedaBanco->currentIndex() == 0) {
            QMessageBox::warning(this, "Advertencia", "Por favor, selecciona un banco válido.");
            return;
        }

        std::string banco = comboBovedaBanco->currentText().toStdString();

        // Registro de la bóveda
        sistema.registrarBoveda(banco, plaza, id);
        QMessageBox::information(this, "Éxito", "Bóveda registrada exitosamente.");

        // Limpiar campos
        lineIdBoveda->clear();
        lineBovedaPlaza->clear();
        comboBovedaBanco->setCurrentIndex(0);

        // Actualizar combos dependientes
        if (comboBovedaBanco) {
            actualizarComboBovedas(comboIdBovedaAct);
            actualizarComboBovedas(comboIdBovedaDep);
        }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("Se produjo un error al registrar la bóveda:\n") + e.what());
    } catch (...) {
        QMessageBox::critical(this, "Error desconocido", "Se produjo un error inesperado al registrar la bóveda.");
    }
}

void MainWindow::depositarDinero() {
    try {
        if (comboIdBovedaDep->currentIndex() == 0) {
            QMessageBox::warning(this, "Advertencia", "Seleccione una bóveda válida.");
            return;
        }

        if (comboMoneda->currentIndex() == 0) {
            QMessageBox::warning(this, "Advertencia", "Seleccione una moneda válida.");
            return;
        }

        if (comboValor->currentIndex() == 0) {
            QMessageBox::warning(this, "Advertencia", "Seleccione un valor válido.");
            return;
        }

        std::string id = comboIdBovedaDep->currentText().toStdString();
        std::string moneda = comboMoneda->currentText().toStdString();
        double valor = comboValor->currentText().toDouble();
        int cantidad = spinDepCantidad->value();

        if (valor <= 0 || cantidad <= 0) {
            QMessageBox::warning(this, "Advertencia", "El valor y la cantidad deben ser mayores a cero.");
            return;
        }

        sistema.depositarDinero(id, moneda, valor, cantidad);
        QMessageBox::information(this, "Depósito", "Dinero depositado correctamente.");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


void MainWindow::agregarCampoValoracion() {
    auto *combo = new QComboBox;
    combo->setMaximumWidth(200);
    combo->addItem("Seleccione moneda");
    combo->setItemData(0, 0, Qt::UserRole - 1);

    try {
        for (const std::string& moneda : sistema.listarMonedas()) {
            combo->addItem(QString::fromStdString(moneda));
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", QString("No se pudieron cargar las monedas: ") + e.what());
        return;
    }

    auto *spin = new QDoubleSpinBox;
    spin->setMaximum(1e9);
    spin->setMinimum(0.01);
    spin->setDecimals(2);
    spin->setMaximumWidth(120);

    QHBoxLayout* layoutValoracion = new QHBoxLayout;
    layoutValoracion->addWidget(combo);
    layoutValoracion->addWidget(spin);

    valoraciones.append(qMakePair(combo, spin));  // ✔️ Ahora sí coincide con la declaración

    layout()->addItem(layoutValoracion);  // o layout()->addLayout(layoutValoracion);
}

void MainWindow::agregarActivo() {
    try {
        if (comboIdBovedaAct->currentIndex() == 0) {
            QMessageBox::warning(this, "Advertencia", "Seleccione una bóveda válida.");
            return;
        }

        if (comboTipoActivo->currentIndex() == 0) {
            QMessageBox::warning(this, "Advertencia", "Seleccione un tipo de activo válido.");
            return;
        }

        std::string idBoveda = comboIdBovedaAct->currentText().toStdString();
        std::string tipo = comboTipoActivo->currentText().toStdString();

        std::vector<std::pair<std::string, double>> val;
        for (const auto& par : valoraciones) {
            std::string moneda = par.first->currentText().toStdString();
            double monto = par.second->value();
            if (moneda != "Seleccione moneda" && !moneda.empty() && monto > 0.0)
                val.emplace_back(moneda, monto);
        }

        if (val.empty()) {
            QMessageBox::warning(this, "Advertencia", "Debe ingresar al menos una valoración válida.");
            return;
        }

        sistema.agregarActivo(tipo, idBoveda, val);
        actualizarComboTiposActivo();
        QMessageBox::information(this, "Activo", "Activo agregado correctamente.");

        // Limpiar campos
        for (auto& par : valoraciones) {
            par.first->setCurrentIndex(0);  // Reset combo
            par.second->setValue(0.0);      // Reset valor
        }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::listarBovedas() {
    listBovedas->clear();
    try {
        std::string banco = lineListaBovedasBanco->text().toStdString();
        auto bovedas = sistema.listarBovedas(banco);

        if (bovedas.empty()) {
            listBovedas->addItem("No se encontraron bóvedas.");
            return;
        }

        for (const auto& id : bovedas) {
            listBovedas->addItem(QString::fromStdString(id));
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}
void MainWindow::verEstadoBoveda() {
    outputEstadoBoveda->clear();
    try {
        std::string idBoveda = lineEstadoIdBoveda->text().toStdString();
        Saldo saldo = sistema.consultarEstadoBoveda(idBoveda);
        outputEstadoBoveda->setPlainText(QString::fromStdString(saldo.toString()));
    } catch (const std::exception& e) {
        outputEstadoBoveda->setText(QString("❌ Error: ") + e.what());
    }
}
void MainWindow::actualizarComboBancos() {
    comboBovedaBanco->clear();
    comboBovedaBanco->addItem("Seleccione un banco");
    comboBovedaBanco->setItemData(0, 0, Qt::UserRole - 1);

    std::vector<std::string> bancos = sistema.listarBancos();
    for (const std::string& banco : bancos) {
        comboBovedaBanco->addItem(QString::fromStdString(banco));
    }
}
void MainWindow::actualizarComboBovedas(QComboBox* combo) {
    if (!combo) return;
    combo->clear();
    combo->addItem("Seleccione una bóveda");
    combo->setItemData(0, 0, Qt::UserRole - 1);

    for (const std::string& banco : sistema.listarBancos()) {
        for (const std::string& id : sistema.listarBovedas(banco)) {
            combo->addItem(QString::fromStdString(id));
        }
    }
}
void MainWindow::actualizarComboMonedas() {
    comboMoneda->clear();
    comboMoneda->addItem("Seleccione una moneda");
    comboMoneda->setItemData(0, 0, Qt::UserRole - 1);

    std::vector<std::string> monedas = sistema.listarMonedas();
    for (const std::string& moneda : monedas) {
        comboMoneda->addItem(QString::fromStdString(moneda));
    }
}
void MainWindow::actualizarComboTiposActivo() {
    if (!comboTipoActivo) return;

    comboTipoActivo->clear();
    comboTipoActivo->addItem("Seleccione tipo de activo");
    comboTipoActivo->setItemData(0, 0, Qt::UserRole - 1);

    try {
        std::vector<std::string> tipos = sistema.listarTiposActivo();
        for (const std::string& tipo : tipos) {
            comboTipoActivo->addItem(QString::fromStdString(tipo));
        }
    } catch (const std::exception& e) {
        comboTipoActivo->addItem("[Error al cargar]");
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::actualizarComboTransportadores() {
    if (!comboTransTransportador) return;

    comboTransTransportador->clear();
    comboTransTransportador->addItem("Seleccione un transportador");
    comboTransTransportador->setItemData(0, 0, Qt::UserRole - 1);

    try {
        std::vector<std::string> transportadores = sistema.listarTransportadores();
        for (const auto& t : transportadores) {
            comboTransTransportador->addItem(QString::fromStdString(t));
        }
    } catch (const std::exception& e) {
        comboTransTransportador->addItem("[Error al cargar]");
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::actualizarComboTiposOperacion() {
    if (!comboTransOperacion) return;

    comboTransOperacion->clear();
    comboTransOperacion->addItem("Seleccione tipo de operación");
    comboTransOperacion->setItemData(0, 0, Qt::UserRole - 1);

    try {
        std::vector<std::string> tipos = sistema.listarTiposOperacion();
        for (const std::string& tipo : tipos) {
            comboTransOperacion->addItem(QString::fromStdString(tipo));
        }
    } catch (const std::exception& e) {
        comboTransOperacion->addItem("[Error al cargar]");
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::actualizarComboBovedasTransaccion() {
    if (!comboTransBovedaInicio || !comboTransBovedaFin) return;

    QStringList ids;
    try {
        for (const auto& banco : sistema.listarBancos()) {
            for (const auto& boveda : sistema.listarBovedas(banco)) {
                ids << QString::fromStdString(boveda);
            }
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
        return;
    }

    auto cargar = [&](QComboBox* combo, const QString& placeholder) {
        combo->clear();
        combo->addItem(placeholder);
        combo->setItemData(0, 0, Qt::UserRole - 1);
        combo->addItems(ids);
    };

    cargar(comboTransBovedaInicio, "Seleccione bóveda origen");
    cargar(comboTransBovedaFin, "Seleccione bóveda destino");
}
void MainWindow::actualizarComboMonedasTransaccion() {
    if (!comboTransMonedaDinero || !comboTransActivoMoneda) return;

    QStringList monedas;
    try {
        for (const auto& m : sistema.listarMonedas()) {
            monedas << QString::fromStdString(m);
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
        return;
    }

    auto cargar = [&](QComboBox* combo, const QString& placeholder) {
        combo->clear();
        combo->addItem(placeholder);
        combo->setItemData(0, 0, Qt::UserRole - 1);
        combo->addItems(monedas);
    };

    cargar(comboTransMonedaDinero, "Seleccione moneda");
    cargar(comboTransActivoMoneda, "Seleccione moneda");
}
void MainWindow::actualizarComboDenominaciones(const QString& monedaQString) {
    comboTransValor->clear();
    comboTransValor->addItem("Seleccione denominación");
    comboTransValor->setItemData(0, 0, Qt::UserRole - 1);

    if (monedaQString == "Seleccione moneda") return;

    try {
        std::string moneda = monedaQString.toStdString();
        std::vector<double> denominaciones = sistema.listarDenominaciones(moneda);

        for (double valor : denominaciones) {
            comboTransValor->addItem(QString::number(valor));
        }
    } catch (...) {
        comboTransValor->addItem("[Error al cargar]");
    }
}


void MainWindow::actualizarComboTiposActivoTransaccion() {
    if (!comboTransTipoActivo) return;

    comboTransTipoActivo->clear();
    comboTransTipoActivo->addItem("Seleccione tipo de activo");
    comboTransTipoActivo->setItemData(0, 0, Qt::UserRole - 1);

    try {
        for (const std::string& tipo : sistema.listarTiposActivo()) {
            comboTransTipoActivo->addItem(QString::fromStdString(tipo));
        }
    } catch (const std::exception& e) {
        comboTransTipoActivo->addItem("[Error al cargar]");
        QMessageBox::warning(this, "Error", e.what());
    }
}
void MainWindow::actualizarComboTransacciones(QComboBox* combo) {
    combo->clear();
    combo->addItem("Seleccione ID de transacción");
    combo->setItemData(0, 0, Qt::UserRole - 1);

    std::vector<int> ids = sistema.listarTransacciones();
    for (int id : ids) {
        combo->addItem(QString("ID: %1").arg(id), id);
    }
}

void MainWindow::simularSistema() {
    const std::vector<std::string> monedas = {"USD", "GBP", "JPY", "PEN", "EUR"};
    const std::vector<std::string> tiposActivo = {"bonos", "joyas", "obras de arte", "criptomonedas", "terrenos"};
    const std::vector<std::string> bancos = {"BCP", "INTERBANK", "SCOTIABANK", "BBVA"};
    const std::vector<std::string> plazas = {"Lima", "Arequipa", "Cusco", "Trujillo"};
    const std::vector<std::string> transportadores = {"FlashCargo", "TransExpress", "SafeMove", "MoneyRun", "FortiTrans"};
    const std::vector<std::string> tiposOperacion = {
        "traslado", "ingreso", "retiro", "custodia", "reubicación",
        "transferencia", "devolución", "incautación", "auditoría"
    };

    for (const auto& nombre : transportadores) sistema.registrarTransportador(nombre);
    for (const auto& nombre : monedas) sistema.registrarMoneda(nombre);
    for (const auto& moneda : monedas)
        for (double valor : {10, 20, 50, 100, 200})
            sistema.registrarDenominacion(moneda, valor);
    for (const auto& nombre : tiposActivo) sistema.registrarTipoActivo(nombre);
    for (const auto& nombre : tiposOperacion) sistema.registrarTipoOperacion(nombre);
    for (const auto& nombre : bancos) sistema.registrarBanco(nombre);
    for (const auto& nombre : plazas) sistema.registrarPlaza(nombre);

    int bovedaId = 1;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> randBool(0, 1);
    std::uniform_int_distribution<> randValor(1000, 9999);
    std::uniform_int_distribution<> randCantidad(1, 49);
    std::uniform_int_distribution<> randDenomIndex(0, 4);

    for (const auto& banco : bancos) {
        for (const auto& plaza : plazas) {
            int numBovedas = 1 + randBool(rng); // 1 a 2
            for (int i = 0; i < numBovedas; ++i) {
                std::string idBoveda = "B" + std::to_string(bovedaId++);
                sistema.registrarBoveda(banco, plaza, idBoveda);

                std::vector<std::string> activosShuffled = tiposActivo;
                std::shuffle(activosShuffled.begin(), activosShuffled.end(), rng);
                int numActivos = 2 + randBool(rng) + randBool(rng);
                for (int j = 0; j < numActivos; ++j) {
                    std::string tipo = activosShuffled[j];
                    std::string moneda = (randBool(rng) == 0) ? "PEN" : "USD";
                    double tasaCambio = 3.7;
                    double valor = randValor(rng);
                    if (moneda == "USD") valor = valor / tasaCambio;

                    sistema.agregarActivo(tipo, idBoveda, {{moneda, valor}});
                }

                for (const auto& moneda : monedas) {
                    int cantidad = randCantidad(rng);
                    double valor = std::vector<double>{10, 20, 50, 100, 200}[randDenomIndex(rng)];
                    sistema.depositarDinero(idBoveda, moneda, valor, cantidad);
                }
            }
        }
    }

    listarMonedas();
    listarBancos();
    listarPlazas();
    listarTiposActivo();
    listarTiposOperacion();
    listarTransportadores();
    listarBovedas();
    actualizarComboBancos();
    actualizarComboMonedas();
    actualizarComboTiposActivo();
    actualizarComboBovedas(comboIdBovedaDep);
    actualizarComboBovedas(comboIdBovedaAct);
    actualizarComboTransportadores();
    actualizarComboTiposOperacion();
    actualizarComboBovedasTransaccion();
    actualizarComboMonedasTransaccion();
    actualizarComboTiposActivoTransaccion();
}
void MainWindow::eliminarDineroTrans() {
    int index = listTransDinero->currentRow();
    if (index >= 0 && index < transDinero.size()) {
        transDinero.erase(transDinero.begin() + index);
        delete listTransDinero->takeItem(index);
    }
}
void MainWindow::eliminarActivoTrans() {
    int index = listTransActivos->currentRow();
    if (index >= 0 && index < transActivos.size()) {
        transActivos.erase(transActivos.begin() + index);
        delete listTransActivos->takeItem(index);
    }
}
