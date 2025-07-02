#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {
    // Soporte para pantallas HiDPI (escalado visual)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    // Cargar archivo de estilo externo
    QFile file("estilo.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        app.setStyleSheet(styleSheet);
        file.close();
    }

    MainWindow w;
    w.setWindowTitle("Sistema Bancario");
    w.setFixedSize(1100, 800); // Ventana con tamaño fijo
    w.show();

    return app.exec();
}
