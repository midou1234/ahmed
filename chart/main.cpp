#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QHorizontalBarSeries>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QBarSet *set0 = new QBarSet("12-06 and 12-05");
    QBarSet *set1 = new QBarSet("12-04 and 12-01");
    QBarSet *set2 = new QBarSet("11-30 and 11-29");
    QBarSet *set3 = new QBarSet("11-28 and 11-27");
    QBarSet *set4 = new QBarSet("11-24 and 11-22");


       *set0 << 1 << 2 << 3 << 4 << 5 << 6;
       *set1 << 5 << 5 <<7 << 4 << 8 << 7;
       *set2 << 3 << 5 << 8 << 13 << 8 << 5;
       *set3 << 5 << 6 << 7 << 3 << 4 << 5;
       *set4 << 9 << 7 << 5 << 3 << 1 << 2;


    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("time series");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QStringList categories;
    categories << "open" << "low" << "high" << "close" ;
    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(categories);
    chart->setAxisY(axisY, series);
    QValueAxis *axisX = new QValueAxis();
    chart->setAxisX(axisX, series);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    return a.exec();
}
