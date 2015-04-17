/********************************************************************************
** Form generated from reading UI file 'cotationsview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COTATIONSVIEW_H
#define UI_COTATIONSVIEW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CotationsView
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QWebView *webView;

    void setupUi(QWidget *CotationsView)
    {
        if (CotationsView->objectName().isEmpty())
            CotationsView->setObjectName(QStringLiteral("CotationsView"));
        CotationsView->resize(800, 270);
        horizontalLayoutWidget = new QWidget(CotationsView);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 50, 631, 201));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        webView = new QWebView(frame);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(0, 0, 631, 201));
        webView->setAutoFillBackground(true);
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        horizontalLayout->addWidget(frame);


        retranslateUi(CotationsView);

        QMetaObject::connectSlotsByName(CotationsView);
    } // setupUi

    void retranslateUi(QWidget *CotationsView)
    {
        CotationsView->setWindowTitle(QApplication::translate("CotationsView", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class CotationsView: public Ui_CotationsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COTATIONSVIEW_H
