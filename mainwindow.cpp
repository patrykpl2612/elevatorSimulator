#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QThread>

using namespace QtCharts;

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    series1->setName("spline1");
    chart1->legend()->hide();
    chart1->addSeries(series1);
    chart1->setTitle("Pierwszy wykres");
    chart1->createDefaultAxes();
    QChartView *chartView1 = new QChartView(chart1);
    chartView1->setRenderHint(QPainter::Antialiasing);



    series2->setName("spline2");
    chart2->legend()->hide();
    chart2->addSeries(series2);
    chart2->setTitle("Drugi wykres");
    chart2->createDefaultAxes();
    QChartView *chartView2 = new QChartView(chart2);
    chartView2->setRenderHint(QPainter::Antialiasing);

    series3->setName("spline3");
    chart3->legend()->hide();
    chart3->addSeries(series3);
    chart3->setTitle("Trzeci wykres");
    chart3->createDefaultAxes();
    QChartView *chartView3 = new QChartView(chart3);
    chartView3->setRenderHint(QPainter::Antialiasing);


    chart1->axes(Qt::Horizontal).first()->setRange(time_min1, time_max1);
    chart2->axes(Qt::Horizontal).first()->setRange(time_min2, time_max2);
    chart3->axes(Qt::Horizontal).first()->setRange(time_min3, time_max3);

    chart1->axes(Qt::Vertical).first()->setRange(amp_min1, amp_max1);
    chart2->axes(Qt::Vertical).first()->setRange(amp_min2, amp_max2);
    chart3->axes(Qt::Vertical).first()->setRange(amp_min3, amp_max3);


    ui->verticalLayout->addWidget(chartView1);
    ui->verticalLayout->addWidget(chartView2);
    ui->verticalLayout->addWidget(chartView3);


}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    time_max1 -= 5;
    chart1->axes(Qt::Horizontal).first()->setRange(time_min1, time_max1); //czas -
}


void MainWindow::on_pushButton_2_clicked()
{
    time_max1 += 5;
    chart1->axes(Qt::Horizontal).first()->setRange(time_min1, time_max1); //czas +
}


void MainWindow::on_pushButton_3_clicked()
{
    amp_min1--;
    amp_max1++;
    chart1->axes(Qt::Vertical).first()->setRange(amp_min1, amp_max1); //amplituda -
}


void MainWindow::on_pushButton_4_clicked()
{
    amp_min1++;
    amp_max1--;
    chart1->axes(Qt::Vertical).first()->setRange(amp_min1, amp_max1);//amplituda +
}



void MainWindow::on_pushButton_5_clicked()
{

    series1->clear();
    series2->clear();
    series3->clear();

    QString filter = "All File (*.*) ;; Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this,"open a file", "C://", filter);
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"title","file not open");
    }

    QTextStream in(&file);

    double data[10000];

    int tmp = 0;
    while ( !in.atEnd() ) {
        double d;
        in >> d;
        data[tmp] = d;
        tmp++;
    }

    double data1[10000];
    double data2[10000];
    double data3[10000];




    int j=0; // działa :D
    for(int i = 0; i < tmp; i += 12){
        data1[j] = data[i];
        j++;
    }
    for(int i = 3; i < tmp; i += 12){
        data1[j] = data[i];
        j++;
    }
    for(int i = 6; i < tmp; i += 12){
        data1[j] = data[i];
        j++;
    }
    for(int i = 9; i < tmp; i += 12){
        data1[j] = data[i];
        j++;
    }
    float k=0;
    for(int i=0; i < tmp/3; i++){
        series1->append(k, data1[i]);
        k += 0.04;
        //Sleeper::msleep(10);
    }




    j=0;
    for(int i = 1; i < tmp; i += 12){
        data2[j] = data[i];
        j++;
    }
    for(int i = 4; i < tmp; i += 12){
        data2[j] = data[i];
        j++;
    }
    for(int i = 7; i < tmp; i += 12){
        data2[j] = data[i];
        j++;
    }
    for(int i = 10; i < tmp; i += 12){
        data2[j] = data[i];
        j++;
    }
    k=0;
    for(int i=0; i < tmp/3; i++){
        series2->append(k, data2[i]);
        k += 0.04;
        //Sleeper::msleep(10);
    }




    j=0;
    for(int i = 2; i < tmp; i += 12){
        data3[j] = data[i];
        j++;
    }
    for(int i = 5; i < tmp; i += 12){
        data3[j] = data[i];
        j++;
    }
    for(int i = 8; i < tmp; i += 12){
        data3[j] = data[i];
        j++;
    }
    for(int i = 11; i < tmp; i += 12){
        data3[j] = data[i];
        j++;
    }
    k=0;
    for(int i=0; i < tmp/3; i++){
        series3->append(k, data3[i]);
        k += 0.04;
        //Sleeper::msleep(10);
    }

    file.close();
}


void MainWindow::on_pushButton_6_clicked()
{
    time_max2 -= 5;
    chart2->axes(Qt::Horizontal).first()->setRange(time_min2, time_max2); //czas -
}


void MainWindow::on_pushButton_7_clicked()
{
    time_max2 += 5;
    chart2->axes(Qt::Horizontal).first()->setRange(time_min2, time_max2); //czas +
}


void MainWindow::on_pushButton_8_clicked()
{
    amp_min2--;
    amp_max2++;
    chart2->axes(Qt::Vertical).first()->setRange(amp_min2, amp_max2); //amplituda -
}


void MainWindow::on_pushButton_9_clicked()
{
    amp_min2++;
    amp_max2--;
    chart2->axes(Qt::Vertical).first()->setRange(amp_min2, amp_max2);//amplituda +
}


void MainWindow::on_pushButton_10_clicked()
{
    time_max3 -= 5;
    chart3->axes(Qt::Horizontal).first()->setRange(time_min3, time_max3); //czas -
}


void MainWindow::on_pushButton_11_clicked()
{
    time_max3 += 5;
    chart3->axes(Qt::Horizontal).first()->setRange(time_min3, time_max3); //czas +
}


void MainWindow::on_pushButton_12_clicked()
{
    amp_min3--;
    amp_max3++;
    chart3->axes(Qt::Vertical).first()->setRange(amp_min3, amp_max3); //amplituda -
}


void MainWindow::on_pushButton_13_clicked()
{
    amp_min3++;
    amp_max3--;
    chart3->axes(Qt::Vertical).first()->setRange(amp_min3, amp_max3);//amplituda +
}

