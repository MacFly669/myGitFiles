#include "aboutdialog.h"
#include "ui_aboutdialog.h"
//!
//! \author HENQUEZ
//! \file aboutdialog.cpp
//! \brief AboutDialog::AboutDialog
//! Class de la boite d'info Abo
//!
//! \param parent
//! \date Avril 2015
//!
//! \details
//! Génére la \e boite de dialogue About avec
//! les infos de la société
//!
//!
//!
//!
//!
//!
//!
//!
//!

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(close()));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
