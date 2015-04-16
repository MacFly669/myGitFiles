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
<<<<<<< HEAD
    QString gPairs = ui->comboBox->currentText();
    QDateTime timestamp;
    QVector<int> xTimestampLabel(0);
     my = new QVector<double>(0); // initialize with entries 0..100
     mx = new QVector<double> (0);
    if(db) qDebug() << "connection ok Graph "; else  qDebug() << "connection PAS ok Graph ";


        QSqlQuery yQuery("SELECT cours FROM couples WHERE nom='" + gPairs + "' ORDER BY timestamp DESC LIMIT 50");
        while (yQuery.next())
        {
            double cours = yQuery.value(0).toDouble();

            if(cours == 0 || cours == NULL) yQuery.next();
            else my->append( cours );

            qDebug() << " Y --> " <<  my;
          //  qDebug() << "x[0] : " << x[0] << "x[50] : " << x[50];
        }
=======


   // QVector<double> y(101); // initialize with entries 0..100
    if(db) qDebug() << "connection ok Graph "; else  qDebug() << "connection PaS ok Graph ";

//    QSqlQuery query;
//        query.prepare("SELECT haut FROM couple WHERE nom='EUR/USD' ORDER BY timestamp");

//        QSqlQuery xQuery("SELECT cours FROM couple WHERE nom='EUR/USD' ORDER BY timestamp DESC LIMIT 50");
//        while (xQuery.next()) {
//            double cours = xQuery.value(0).toDouble();
//            x->push_back(cours);
//        }

//        QSqlQuery yQuery("SELECT date FROM couple WHERE nom='EUR/USD' ORDER BY timestamp DESC LIMIT 50");
//        while (yQuery.next()) {
//            double cours = yQuery.value(0).toDouble();
//            y.push_back(cours);
//        }
>>>>>>> 474b7504d319558134a66d1fe4ce382f11bb031e

        QSqlQuery tsQuery("SELECT timestamp FROM couples WHERE nom='EUR/USD' ORDER BY timestamp DESC LIMIT 50");
        while (tsQuery.next())
        {
            double ts = tsQuery.value(0).toDouble();
            mx->push_back(ts);

            qDebug() << " timestamp --> " <<  ts;


            timestamp.setTime_t(ts);
            qDebug() << "timestamp to string -> " <<  timestamp.toString(Qt::SystemLocaleShortDate);
        }

  //  for(double i(0); i<50; i++){ x.append(i);}
 // QCustomPlot* customPlot = new QCustomPlot;
    QCustomPlot* customPlot = ui->customPlot;
    customPlot->legend->setVisible(true);
    customPlot->legend->setFont(QFont("Helvetica", 9));
    QPen pen;
    // add graphs with different line styles:
<<<<<<< HEAD
      QCPGraph::lsLine;
      customPlot->addGraph();
      pen.setColor(QColor(qSin(1.2)*80+80));
      customPlot->graph()->setPen(pen);
      customPlot->graph()->setName("EUR/USD");
      customPlot->graph()->setLineStyle((QCPGraph::LineStyle)1);
      customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
      // generate data:
      QVector<double> x(50), y(50);
      for (int j=0; j<50; ++j)
      {
        x[j] = 50.0 * 5*3.14 + 0.01;
        y[j] = 7*qSin(mx->at(j))/mx->at(j) - (QCPGraph::lsLine)*5 + (QCPGraph::lsImpulse)*5 + 2;
      }
      customPlot->graph()->setData(*mx, *my);
      customPlot->graph()->rescaleAxes(true);
  //  }
=======

      customPlot->addGraph();
      pen.setColor(QColor(qSin(1+1.2)*80+80));
      customPlot->graph()->setPen(pen);
      customPlot->graph()->setName("C pas Graph");
      customPlot->graph()->setLineStyle((QCPGraph::LineStyle)1);
      customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
      // generate data:
     QVector<double> x(50);
     QVector<double> y(50);
      QCPGraph::lsLine;

          QSqlQuery xQuery("SELECT cours FROM couple WHERE nom='EUR/USD' ORDER BY timestamp DESC LIMIT 50");
          while (xQuery.next()) {
              double cours = xQuery.value(0).toDouble();
              y.push_back(cours);
          }

          QSqlQuery yQuery("SELECT date FROM couple WHERE nom='EUR/USD' ORDER BY timestamp DESC LIMIT 50");
          while (yQuery.next()) {
              double cours = yQuery.value(0).toDouble();
              x.push_back(cours);
          }



          for (int j=0; j<50; ++j)
          {
            x[j] = j/15.0 * 5*3.14 + 0.01;
            y[j] =  y[j]*qSin(x[j])/x[j] - ( QCPGraph::lsLine)*5  + 2;
          }
      customPlot->graph()->setData(x, y);
      customPlot->graph()->rescaleAxes(true);

>>>>>>> 474b7504d319558134a66d1fe4ce382f11bb031e
    // zoom out a bit:



    customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
    customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
   // customPlot->xAxis->setRange(x[0], x[49]);
    // set blank axis lines:
    customPlot->xAxis->setTicks(true);
    customPlot->yAxis->setTicks(true);
    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    customPlot->xAxis->setTickLabels(true);
    customPlot->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
 //   customPlot->axisRect()->setupFullAxesBox();


}

Graphique::~Graphique()
{
    delete ui;
}


