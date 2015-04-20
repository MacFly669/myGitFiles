/********************************************************************************
** Form generated from reading UI file 'graphique.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIQUE_H
#define UI_GRAPHIQUE_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Graphique
{
public:
    QDialogButtonBox *buttonBox;
    QWebView *webView;

    void setupUi(QDialog *Graphique)
    {
        if (Graphique->objectName().isEmpty())
            Graphique->setObjectName(QStringLiteral("Graphique"));
        Graphique->resize(600, 498);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/3d bar chart.png"), QSize(), QIcon::Normal, QIcon::On);
        Graphique->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Graphique);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 460, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        webView = new QWebView(Graphique);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(0, 0, 600, 451));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        retranslateUi(Graphique);
        QObject::connect(buttonBox, SIGNAL(accepted()), Graphique, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Graphique, SLOT(reject()));

        QMetaObject::connectSlotsByName(Graphique);
    } // setupUi

    void retranslateUi(QDialog *Graphique)
    {
        Graphique->setWindowTitle(QApplication::translate("Graphique", "Graphique FOREX", 0));
    } // retranslateUi

};

namespace Ui {
    class Graphique: public Ui_Graphique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIQUE_H
