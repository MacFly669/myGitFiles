/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QTextBrowser *textBrowser;
    QPushButton *btnFermerAbout;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(410, 450);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/About.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        textBrowser = new QTextBrowser(AboutDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(5, 5, 400, 410));
        textBrowser->setMinimumSize(QSize(400, 350));
        textBrowser->setMaximumSize(QSize(400, 410));
        btnFermerAbout = new QPushButton(AboutDialog);
        btnFermerAbout->setObjectName(QStringLiteral("btnFermerAbout"));
        btnFermerAbout->setGeometry(QRect(167, 420, 75, 23));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "A propos", 0));
        textBrowser->setHtml(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/images/mid_trading_small_new.png\" />	</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">TRADING PLUS 2015 \302\251 </span>	<span style=\" font-size:10pt;\">version 1.0</span>	</p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p align=\"ju"
                        "stify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Trading Plus </span><span style=\" font-size:10pt;\">est une application con\303\247u par </span><span style=\" font-size:10pt; font-weight:600;\">DevHopla</span><span style=\" font-size:10pt;\"> soci\303\251t\303\251 de d\303\251velopement de logiciels informatiques.<br />Pour de plus amples informations sur les conditions d'utilisations veuillez consulter les</span><span style=\" font-size:10pt; font-weight:600;\"> </span><a href=\"conditions.pdf\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">conditions g\303\251n\303\251rales</span></a><span style=\" font-size:10pt;\">.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Vous pouvez \303\251galement consulter la </span><a"
                        " href=\"file:///doc.pdf\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">documentation</span></a><span style=\" font-size:10pt;\"> de l'utilisateur (anglais) , ou la </span><a href=\"qrc:/html/index.html\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">documentation d\303\251veloppeur</span></a><span style=\" font-size:10pt;\">.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Si vous avec des probl\303\250mes ou des questions concernant nos produits, vous pouvez nous \303\251crire \303\240 </span><a href=\"mailto:www.info@devhopla.com\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">www.info@devhopla.com</span></a></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-s"
                        "ize:10pt; text-decoration: underline; color:#0000ff;\"><br /></p></body></html>", 0));
        btnFermerAbout->setText(QApplication::translate("AboutDialog", "Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
