#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QVBoxLayout>

using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    QChart *chart1 = new QChart();
    QChart *chart2 = new QChart();
    QChart *chart3 = new QChart();
    QSplineSeries *series1 = new QSplineSeries();
    QSplineSeries *series2 = new QSplineSeries();
    QSplineSeries *series3 = new QSplineSeries();
    float time_min1=0, time_max1=110, amp_min1=-3, amp_max1=13;
    float time_min2=0, time_max2=110, amp_min2=-3, amp_max2=13;
    float time_min3=0, time_max3=110, amp_min3=-3, amp_max3=13;
};
#endif // MAINWINDOW_H
