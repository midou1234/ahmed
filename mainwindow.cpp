#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&thedon,SIGNAL(dataReadyRead(QByteArray)),this,SLOT(DatainDaHouse(QByteArray)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::DatainDaHouse(QByteArray data)
{
  QString dataString ;
  dataString=data;
   ui->pp1->setText(dataString);
}


void MainWindow::on_pp1_clicked()
{
    thedon.makeRequest("https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=MSFT&interval=15min&outputsize=full&apikey=demo");

}


