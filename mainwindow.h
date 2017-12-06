#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void DatainDaHouse(QByteArray data);

    void on_pp1_clicked();

    void on_pp2_clicked();

private:
    Ui::MainWindow *ui;
    network thedon;

};

#endif // MAINWINDOW_H
