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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionShowHideView;
    QAction *actionGraphique;
    QAction *actionSimulation;
    QAction *actionOptions;
    QAction *actionAbout;
    QAction *action_Rafraichir;
    QAction *actionCalendrier;
    QWidget *centralWidget;
    QFrame *frameTable;
    QTableView *tableView;
    QComboBox *comboDevises;
    QLabel *label;
    QLabel *label_2;
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
        MainWindow->resize(875, 654);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/Dollar.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon1);
        actionShowHideView = new QAction(MainWindow);
        actionShowHideView->setObjectName(QStringLiteral("actionShowHideView"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/oeil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowHideView->setIcon(icon2);
        actionGraphique = new QAction(MainWindow);
        actionGraphique->setObjectName(QStringLiteral("actionGraphique"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/3d bar chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/images/icons/3d bar chart.png"), QSize(), QIcon::Normal, QIcon::On);
        actionGraphique->setIcon(icon3);
        actionSimulation = new QAction(MainWindow);
        actionSimulation->setObjectName(QStringLiteral("actionSimulation"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/Calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/images/icons/Calculator.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSimulation->setIcon(icon4);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/Wrench.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon5);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/About.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/images/icons/About.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAbout->setIcon(icon6);
        action_Rafraichir = new QAction(MainWindow);
        action_Rafraichir->setObjectName(QStringLiteral("action_Rafraichir"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/Sync.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Rafraichir->setIcon(icon7);
        actionCalendrier = new QAction(MainWindow);
        actionCalendrier->setObjectName(QStringLiteral("actionCalendrier"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/Calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalendrier->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frameTable = new QFrame(centralWidget);
        frameTable->setObjectName(QStringLiteral("frameTable"));
        frameTable->setGeometry(QRect(10, 9, 851, 321));
        frameTable->setMinimumSize(QSize(830, 290));
        frameTable->setMaximumSize(QSize(900, 400));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(246, 246, 246, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        frameTable->setPalette(palette);
        frameTable->setFrameShape(QFrame::Panel);
        frameTable->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frameTable);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 10, 631, 300));
        tableView->setMinimumSize(QSize(0, 0));
        tableView->setMaximumSize(QSize(700, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        tableView->setPalette(palette1);
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        tableView->setFont(font);
        tableView->setLayoutDirection(Qt::LeftToRight);
        tableView->setSortingEnabled(true);
        comboDevises = new QComboBox(frameTable);
        comboDevises->setObjectName(QStringLiteral("comboDevises"));
        comboDevises->setGeometry(QRect(710, 40, 81, 22));
        label = new QLabel(frameTable);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(655, 95, 191, 221));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/index.jpg")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        label->setMargin(-8);
        label->setIndent(11);
        label_2 = new QLabel(frameTable);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(689, 10, 101, 20));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 350, 841, 211));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 21));
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
        menu_Affiche->addAction(actionShowHideView);
        menu_Affiche->addAction(actionGraphique);
        menu_Affiche->addAction(actionSimulation);
        menu_Affiche->addAction(actionOptions);
        menuA_propos->addAction(actionAbout);
        mainToolBar->addAction(actionQuitter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShowHideView);
        mainToolBar->addAction(action_Rafraichir);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionGraphique);
        mainToolBar->addAction(actionSimulation);
        mainToolBar->addAction(actionCalendrier);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionOptions);
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();

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
        actionShowHideView->setText(QApplication::translate("MainWindow", "& FOREX Live", 0));
        actionShowHideView->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
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
        actionCalendrier->setText(QApplication::translate("MainWindow", "Calendrier", 0));
#ifndef QT_NO_TOOLTIP
        actionCalendrier->setToolTip(QApplication::translate("MainWindow", "Affichage par p\303\251riode entre 2 dates", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Couples Devises", 0));
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
