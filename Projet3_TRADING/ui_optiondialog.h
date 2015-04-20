/********************************************************************************
** Form generated from reading UI file 'optiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupCheck;
    QGroupBox *groupBase;
    QPushButton *btnCocher;
    QPushButton *btnDecocher;
    QGroupBox *groupBase_2;
    QRadioButton *radioSiteFr;
    QRadioButton *radioSiteEn;
    QRadioButton *radioUrlPerso;
    QLineEdit *lineUrlPerso;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QStringLiteral("OptionDialog"));
        OptionDialog->resize(703, 371);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/Wrench.png"), QSize(), QIcon::Normal, QIcon::Off);
        OptionDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(330, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupCheck = new QGroupBox(OptionDialog);
        groupCheck->setObjectName(QStringLiteral("groupCheck"));
        groupCheck->setGeometry(QRect(10, 230, 681, 81));
        groupBase = new QGroupBox(OptionDialog);
        groupBase->setObjectName(QStringLiteral("groupBase"));
        groupBase->setGeometry(QRect(10, 100, 301, 141));
        btnCocher = new QPushButton(OptionDialog);
        btnCocher->setObjectName(QStringLiteral("btnCocher"));
        btnCocher->setGeometry(QRect(30, 320, 75, 23));
        btnDecocher = new QPushButton(OptionDialog);
        btnDecocher->setObjectName(QStringLiteral("btnDecocher"));
        btnDecocher->setGeometry(QRect(110, 320, 81, 23));
        groupBase_2 = new QGroupBox(OptionDialog);
        groupBase_2->setObjectName(QStringLiteral("groupBase_2"));
        groupBase_2->setGeometry(QRect(320, 100, 371, 141));
        radioSiteFr = new QRadioButton(groupBase_2);
        radioSiteFr->setObjectName(QStringLiteral("radioSiteFr"));
        radioSiteFr->setGeometry(QRect(30, 20, 141, 17));
        radioSiteEn = new QRadioButton(groupBase_2);
        radioSiteEn->setObjectName(QStringLiteral("radioSiteEn"));
        radioSiteEn->setGeometry(QRect(30, 50, 121, 17));
        radioUrlPerso = new QRadioButton(groupBase_2);
        radioUrlPerso->setObjectName(QStringLiteral("radioUrlPerso"));
        radioUrlPerso->setGeometry(QRect(30, 80, 121, 17));
        lineUrlPerso = new QLineEdit(groupBase_2);
        lineUrlPerso->setObjectName(QStringLiteral("lineUrlPerso"));
        lineUrlPerso->setGeometry(QRect(30, 110, 321, 20));

        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QApplication::translate("OptionDialog", "Bo\303\256te  de configuration", 0));
        groupCheck->setTitle(QApplication::translate("OptionDialog", "Couples Devises", 0));
        groupBase->setTitle(QApplication::translate("OptionDialog", "Base distante", 0));
        btnCocher->setText(QApplication::translate("OptionDialog", "Tout cocher", 0));
        btnDecocher->setText(QApplication::translate("OptionDialog", "Tout d\303\251cocher", 0));
        groupBase_2->setTitle(QApplication::translate("OptionDialog", "Url", 0));
        radioSiteFr->setText(QApplication::translate("OptionDialog", "URL du site fran\303\247ais .fr", 0));
        radioSiteEn->setText(QApplication::translate("OptionDialog", "URL du site anglais ", 0));
        radioUrlPerso->setText(QApplication::translate("OptionDialog", "URL personnalis\303\251e", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
