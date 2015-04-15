#include "graphique.h"
#include "ui_graphique.h"
#include "qcustomplot.h"
#include "mainwindow.h"

#include <QSqlQuery>

Graphique::Graphique(QSqlDatabase *_db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graphique)
{
    ui->setupUi(this);
    this->db = _db;
QVector<double> x(101);
QVector<double> y(101); // initialize with entries 0..100
    if(db) qDebug() << "connection ok Graph "; else  qDebug() << "connection PAS ok Graph ";

    QSqlQuery query;
        query.prepare("SELECT haut FROM couple WHERE nom='EUR/USD' ORDER BY timestamp");

        QSqlQuery xQuery("SELECT cours FROM couple WHERE nom='EUR/USD' ORDER BY timestamp");
        while (xQuery.next()) {
            double cours = xQuery.value(0).toDouble();
            x.push_back(cours);
        }

        QSqlQuery yQuery("SELECT date FROM couple WHERE nom='EUR/USD' ORDER BY timestamp");
        while (yQuery.next()) {
            double cours = yQuery.value(0).toDouble();
            y.push_back(cours);
        }


 // QCustomPlot* customPlot = new QCustomPlot;
    QCustomPlot* customPlot = ui->customPlot;
    // generate some data:
   // generate some data:
    customPlot->legend->setVisible(true);
    customPlot->legend->setFont(QFont("Helvetica", 9));
    QPen pen;
    QStringList lineNames;
    lineNames << "EUR" << "USD" << "CHF" << "CAD"
                 << "JPY" << "GBP";
    // add graphs with different line styles:
    for (int i=QCPGraph::lsNone; i<=QCPGraph::lsImpulse; ++i)
    {
      customPlot->addGraph();
      pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));
      customPlot->graph()->setPen(pen);
      customPlot->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
      customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);
      customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
      // generate data:
      QVector<double> x(15), y(15);
      for (int j=0; j<15; ++j)
      {
        x[j] = j/15.0 * 5*3.14 + 0.01;
        y[j] = 7*qSin(x[j])/x[j] - (i-QCPGraph::lsNone)*5 + (QCPGraph::lsImpulse)*5 + 2;
      }
      customPlot->graph()->setData(x, y);
      customPlot->graph()->rescaleAxes(true);
    }
    // zoom out a bit:
    customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
    customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
    // set blank axis lines:
    customPlot->xAxis->setTicks(false);
    customPlot->yAxis->setTicks(true);
    customPlot->xAxis->setTickLabels(false);
    customPlot->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
    customPlot->axisRect()->setupFullAxesBox();

}

Graphique::~Graphique()
{
    delete ui;
}




