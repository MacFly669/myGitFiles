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

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupCheck;
    QGroupBox *groupBase;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QStringLiteral("OptionDialog"));
        OptionDialog->resize(703, 371);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/Repair.png"), QSize(), QIcon::Normal, QIcon::On);
        OptionDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 300, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupCheck = new QGroupBox(OptionDialog);
        groupCheck->setObjectName(QStringLiteral("groupCheck"));
        groupCheck->setGeometry(QRect(30, 230, 641, 61));
        groupBase = new QGroupBox(OptionDialog);
        groupBase->setObjectName(QStringLiteral("groupBase"));
        groupBase->setGeometry(QRect(30, 140, 641, 80));

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
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
