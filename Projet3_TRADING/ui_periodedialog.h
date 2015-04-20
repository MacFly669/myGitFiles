/********************************************************************************
** Form generated from reading UI file 'periodedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERIODEDIALOG_H
#define UI_PERIODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PeriodeDialog
{
public:
    QTableView *ptableView;
    QLabel *labelMessage;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QGridLayout *gridLayout;
    QLabel *labelDebut;
    QLabel *labelFin;
    QDateEdit *dateDebut;
    QPushButton *btn_valider_date;
    QDateEdit *dateFin;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnFermer;

    void setupUi(QDialog *PeriodeDialog)
    {
        if (PeriodeDialog->objectName().isEmpty())
            PeriodeDialog->setObjectName(QStringLiteral("PeriodeDialog"));
        PeriodeDialog->resize(880, 470);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/Calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        PeriodeDialog->setWindowIcon(icon);
        ptableView = new QTableView(PeriodeDialog);
        ptableView->setObjectName(QStringLiteral("ptableView"));
        ptableView->setGeometry(QRect(20, 50, 671, 381));
        labelMessage = new QLabel(PeriodeDialog);
        labelMessage->setObjectName(QStringLiteral("labelMessage"));
        labelMessage->setGeometry(QRect(30, 440, 491, 21));
        verticalLayoutWidget = new QWidget(PeriodeDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(710, 50, 160, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelDebut = new QLabel(verticalLayoutWidget);
        labelDebut->setObjectName(QStringLiteral("labelDebut"));
        labelDebut->setFocusPolicy(Qt::TabFocus);
        labelDebut->setLayoutDirection(Qt::LeftToRight);
        labelDebut->setTextFormat(Qt::PlainText);
        labelDebut->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelDebut, 0, 0, 1, 1);

        labelFin = new QLabel(verticalLayoutWidget);
        labelFin->setObjectName(QStringLiteral("labelFin"));
        labelFin->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelFin, 1, 0, 1, 1);

        dateDebut = new QDateEdit(verticalLayoutWidget);
        dateDebut->setObjectName(QStringLiteral("dateDebut"));

        gridLayout->addWidget(dateDebut, 0, 1, 1, 1);

        btn_valider_date = new QPushButton(verticalLayoutWidget);
        btn_valider_date->setObjectName(QStringLiteral("btn_valider_date"));
        btn_valider_date->setFlat(false);

        gridLayout->addWidget(btn_valider_date, 2, 1, 1, 1);

        dateFin = new QDateEdit(verticalLayoutWidget);
        dateFin->setObjectName(QStringLiteral("dateFin"));

        gridLayout->addWidget(dateFin, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        btnFermer = new QPushButton(verticalLayoutWidget);
        btnFermer->setObjectName(QStringLiteral("btnFermer"));

        verticalLayout->addWidget(btnFermer);


        retranslateUi(PeriodeDialog);

        QMetaObject::connectSlotsByName(PeriodeDialog);
    } // setupUi

    void retranslateUi(QDialog *PeriodeDialog)
    {
        PeriodeDialog->setWindowTitle(QApplication::translate("PeriodeDialog", "Filtre Calendaire", 0));
        labelMessage->setText(QString());
        labelDebut->setText(QApplication::translate("PeriodeDialog", "D\303\251but", 0));
        labelFin->setText(QApplication::translate("PeriodeDialog", "Fin", 0));
        btn_valider_date->setText(QApplication::translate("PeriodeDialog", "Valider", 0));
        btnFermer->setText(QApplication::translate("PeriodeDialog", "&Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class PeriodeDialog: public Ui_PeriodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIODEDIALOG_H
