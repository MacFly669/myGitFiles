#include "mainwindow.h"
//import de la class MainWindow
#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QSqlDatabase>

#define QCUSTOMPLOT_COMPILE_LIBRARY

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase* db = MainWindow::connectToDB( "Projet3_Trading.db" ) ;

    MainWindow w(db);
    w.show();
    w.setFixedSize(1000,700);

    return a.exec();
}
