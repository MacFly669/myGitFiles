#include "graphique.h"
#include "ui_graphique.h"
#include "qcustomplot.h"
#include "mainwindow.h"

Graphique::Graphique(QSqlDatabase *_db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graphique)
{
    ui->setupUi(this);
    this->db = _db;

    if(db) qDebug() << "connection ok Graph "; else  qDebug() << "connection PAS ok Graph ";

   QCustomPlot* customPlot = new QCustomPlot;
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("date");
    customPlot->yAxis->setLabel("cotation");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();

}

Graphique::~Graphique()
{
    delete ui;
}
