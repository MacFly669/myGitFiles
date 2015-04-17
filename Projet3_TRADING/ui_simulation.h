/********************************************************************************
** Form generated from reading UI file 'simulation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION_H
#define UI_SIMULATION_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Simulation
{
public:
    QDialogButtonBox *buttonBox;
    QWebView *webView;

    void setupUi(QDialog *Simulation)
    {
        if (Simulation->objectName().isEmpty())
            Simulation->setObjectName(QStringLiteral("Simulation"));
        Simulation->resize(489, 528);
        buttonBox = new QDialogButtonBox(Simulation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(110, 470, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        webView = new QWebView(Simulation);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(20, 10, 451, 451));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        retranslateUi(Simulation);
        QObject::connect(buttonBox, SIGNAL(accepted()), Simulation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Simulation, SLOT(reject()));

        QMetaObject::connectSlotsByName(Simulation);
    } // setupUi

    void retranslateUi(QDialog *Simulation)
    {
        Simulation->setWindowTitle(QApplication::translate("Simulation", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Simulation: public Ui_Simulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_H
