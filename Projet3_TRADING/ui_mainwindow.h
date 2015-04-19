/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionCours_devises;
    QAction *actionGraphique;
    QAction *actionSimulation;
    QAction *actionOptions;
    QAction *actionAbout;
    QAction *action_Rafraichir;
    QWidget *centralWidget;
    QFrame *frameTable;
    QPushButton *btn_valider_date;
    QTableView *tableView;
    QDateEdit *dateFin;
    QDateEdit *dateDebut;
    QLabel *labelDebut;
    QLabel *labelFin;
    QComboBox *comboDevises;
    QFrame *frame;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menu_Affiche;
    QMenu *menuA_propos;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(894, 700);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/Dollar.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/icons/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon1);
        actionCours_devises = new QAction(MainWindow);
        actionCours_devises->setObjectName(QStringLiteral("actionCours_devises"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/icons/oeil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCours_devises->setIcon(icon2);
        actionGraphique = new QAction(MainWindow);
        actionGraphique->setObjectName(QStringLiteral("actionGraphique"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/icons/3d bar chart.png"), QSize(), QIcon::Normal, QIcon::On);
        actionGraphique->setIcon(icon3);
        actionSimulation = new QAction(MainWindow);
        actionSimulation->setObjectName(QStringLiteral("actionSimulation"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/icons/Calculator.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSimulation->setIcon(icon4);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/icons/Wrench.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon5);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/icons/About.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAbout->setIcon(icon6);
        action_Rafraichir = new QAction(MainWindow);
        action_Rafraichir->setObjectName(QStringLiteral("action_Rafraichir"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/icons/Sync.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Rafraichir->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frameTable = new QFrame(centralWidget);
        frameTable->setObjectName(QStringLiteral("frameTable"));
        frameTable->setGeometry(QRect(10, 40, 871, 291));
        frameTable->setFrameShape(QFrame::StyledPanel);
        frameTable->setFrameShadow(QFrame::Raised);
        btn_valider_date = new QPushButton(frameTable);
        btn_valider_date->setObjectName(QStringLiteral("btn_valider_date"));
        btn_valider_date->setGeometry(QRect(760, 250, 75, 23));
        btn_valider_date->setFlat(false);
        tableView = new QTableView(frameTable);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 0, 700, 300));
        tableView->setMinimumSize(QSize(700, 0));
        tableView->setMaximumSize(QSize(700, 16777215));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        tableView->setFont(font);
        tableView->setLayoutDirection(Qt::LeftToRight);
        tableView->setSortingEnabled(true);
        dateFin = new QDateEdit(frameTable);
        dateFin->setObjectName(QStringLiteral("dateFin"));
        dateFin->setGeometry(QRect(750, 210, 110, 22));
        dateDebut = new QDateEdit(frameTable);
        dateDebut->setObjectName(QStringLiteral("dateDebut"));
        dateDebut->setGeometry(QRect(750, 160, 110, 22));
        labelDebut = new QLabel(frameTable);
        labelDebut->setObjectName(QStringLiteral("labelDebut"));
        labelDebut->setGeometry(QRect(750, 140, 47, 13));
        labelFin = new QLabel(frameTable);
        labelFin->setObjectName(QStringLiteral("labelFin"));
        labelFin->setGeometry(QRect(750, 190, 47, 13));
        comboDevises = new QComboBox(frameTable);
        comboDevises->setObjectName(QStringLiteral("comboDevises"));
        comboDevises->setGeometry(QRect(740, 10, 111, 22));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 380, 700, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 894, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menu_Affiche = new QMenu(menuBar);
        menu_Affiche->setObjectName(QStringLiteral("menu_Affiche"));
        menuA_propos = new QMenu(menuBar);
        menuA_propos->setObjectName(QStringLiteral("menuA_propos"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menu_Affiche->menuAction());
        menuBar->addAction(menuA_propos->menuAction());
        menuMenu->addAction(actionQuitter);
        menu_Affiche->addAction(actionCours_devises);
        menu_Affiche->addAction(actionGraphique);
        menu_Affiche->addAction(actionSimulation);
        menu_Affiche->addAction(actionOptions);
        menuA_propos->addAction(actionAbout);
        mainToolBar->addAction(actionQuitter);
        mainToolBar->addAction(actionCours_devises);
        mainToolBar->addAction(actionGraphique);
        mainToolBar->addAction(actionSimulation);
        mainToolBar->addAction(action_Rafraichir);
        mainToolBar->addAction(actionOptions);
        mainToolBar->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TRADING PLUS 2015", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "&Quitter", 0));
#ifndef QT_NO_TOOLTIP
        actionQuitter->setToolTip(QApplication::translate("MainWindow", "Fermer l'application", 0));
#endif // QT_NO_TOOLTIP
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionCours_devises->setText(QApplication::translate("MainWindow", "&Cours devises", 0));
        actionCours_devises->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionGraphique->setText(QApplication::translate("MainWindow", "&Graphique", 0));
        actionGraphique->setShortcut(QApplication::translate("MainWindow", "Alt+G", 0));
        actionSimulation->setText(QApplication::translate("MainWindow", "&Simulation", 0));
        actionSimulation->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "&Options", 0));
        actionOptions->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+W", 0));
        action_Rafraichir->setText(QApplication::translate("MainWindow", "&Rafraichir", 0));
#ifndef QT_NO_TOOLTIP
        action_Rafraichir->setToolTip(QApplication::translate("MainWindow", "Recharge la page", 0));
#endif // QT_NO_TOOLTIP
        action_Rafraichir->setShortcut(QApplication::translate("MainWindow", "Alt+R", 0));
        btn_valider_date->setText(QApplication::translate("MainWindow", "Valider", 0));
        labelDebut->setText(QApplication::translate("MainWindow", "D\303\251but", 0));
        labelFin->setText(QApplication::translate("MainWindow", "Fin", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        menu_Affiche->setTitle(QApplication::translate("MainWindow", "&Affichage", 0));
        menuA_propos->setTitle(QApplication::translate("MainWindow", "A propos", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
