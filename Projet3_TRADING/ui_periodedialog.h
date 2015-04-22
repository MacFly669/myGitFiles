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
    QPushButton *btn_valider_date;
    QLabel *labelDebut;
    QDateEdit *dateDebut;
    QDateEdit *dateFin;
    QLabel *labelFin;
    QLabel *label_2;
    QPushButton *btnFermer;
    QLabel *label;

    void setupUi(QDialog *PeriodeDialog)
    {
        if (PeriodeDialog->objectName().isEmpty())
            PeriodeDialog->setObjectName(QStringLiteral("PeriodeDialog"));
        PeriodeDialog->resize(860, 475);
        PeriodeDialog->setMinimumSize(QSize(835, 475));
        PeriodeDialog->setMaximumSize(QSize(1000, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/Calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        PeriodeDialog->setWindowIcon(icon);
        ptableView = new QTableView(PeriodeDialog);
        ptableView->setObjectName(QStringLiteral("ptableView"));
        ptableView->setGeometry(QRect(10, 50, 621, 381));
        labelMessage = new QLabel(PeriodeDialog);
        labelMessage->setObjectName(QStringLiteral("labelMessage"));
        labelMessage->setGeometry(QRect(30, 440, 651, 21));
        verticalLayoutWidget = new QWidget(PeriodeDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(640, 50, 201, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(100, 20));
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setAutoFillBackground(true);

        verticalLayout->addWidget(comboBox);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btn_valider_date = new QPushButton(verticalLayoutWidget);
        btn_valider_date->setObjectName(QStringLiteral("btn_valider_date"));
        btn_valider_date->setFlat(false);

        gridLayout->addWidget(btn_valider_date, 2, 1, 1, 1);

        labelDebut = new QLabel(verticalLayoutWidget);
        labelDebut->setObjectName(QStringLiteral("labelDebut"));
        labelDebut->setFocusPolicy(Qt::TabFocus);
        labelDebut->setLayoutDirection(Qt::LeftToRight);
        labelDebut->setTextFormat(Qt::PlainText);
        labelDebut->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelDebut, 0, 0, 1, 1);

        dateDebut = new QDateEdit(verticalLayoutWidget);
        dateDebut->setObjectName(QStringLiteral("dateDebut"));

        gridLayout->addWidget(dateDebut, 0, 1, 1, 1);

        dateFin = new QDateEdit(verticalLayoutWidget);
        dateFin->setObjectName(QStringLiteral("dateFin"));

        gridLayout->addWidget(dateFin, 1, 1, 1, 1);

        labelFin = new QLabel(verticalLayoutWidget);
        labelFin->setObjectName(QStringLiteral("labelFin"));
        labelFin->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelFin, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/images/index.jpg")));

        verticalLayout->addWidget(label_2);

        btnFermer = new QPushButton(verticalLayoutWidget);
        btnFermer->setObjectName(QStringLiteral("btnFermer"));

        verticalLayout->addWidget(btnFermer);

        label = new QLabel(PeriodeDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-15, 0, 971, 45));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/banner_1035.jpg")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        ptableView->raise();
        labelMessage->raise();
        verticalLayoutWidget->raise();
        label->raise();
        labelFin->raise();

        retranslateUi(PeriodeDialog);

        QMetaObject::connectSlotsByName(PeriodeDialog);
    } // setupUi

    void retranslateUi(QDialog *PeriodeDialog)
    {
        PeriodeDialog->setWindowTitle(QApplication::translate("PeriodeDialog", "Filtre Calendaire", 0));
        labelMessage->setText(QString());
        btn_valider_date->setText(QApplication::translate("PeriodeDialog", "Valider", 0));
        labelDebut->setText(QApplication::translate("PeriodeDialog", "D\303\251but", 0));
        labelFin->setText(QApplication::translate("PeriodeDialog", "Fin", 0));
        label_2->setText(QString());
        btnFermer->setText(QApplication::translate("PeriodeDialog", "&Fermer", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PeriodeDialog: public Ui_PeriodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIODEDIALOG_H
