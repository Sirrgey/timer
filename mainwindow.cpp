#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this); //Создаем экземпляр таймера
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_tick())); //Соединили событие с таймером
    counter=0;

    timer2 = new QTimer(this); //Создаем экземпляр таймера
    connect(timer2,SIGNAL(timeout()),this,SLOT(timer_tick2())); //Соединили событие с таймером
    pluser=0;


    down_counter=60;
    ui->label->setVisible(false);

    down_timer =  new QTimer(this);
    connect(down_timer,SIGNAL(timeout()),this,SLOT(down_timer_tick())); //Соединили событие с таймером

    down_timer->setInterval(1000); //интервал счета
    flag=false;
    flag2=false;
    QString str=("00:00:00.00");
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
    ui->lcdNumber_Down->display("00:01");
    ui->pushButton_Stop->hide();
    ui->pushButton_Pause->hide();
    setFixedSize(size());
    timing=false;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timer_tick() //то, что будет вызыватся по таймеру
{
    if(!flag2)
    {
        counter++; //Увеличили счетчик
        QString str;
        int h,m,sec,s_sec; //часы, минуты, секунды, сотые секунд

        s_sec=counter%100;
        sec=counter/100;
        m=sec/60;
        sec=sec%60;
        h=m/60;
        m=m%60;

        if (h<10)
            str.append("0");
        str.append(QString::number(h));
        str.append(":");
        if (m<10)
            str.append("0");
        str.append(QString::number(m));
        str.append(":");
        if (sec<10)
            str.append("0");
        str.append(QString::number(sec));
        str.append(".");
        if (s_sec<10)
            str.append("0");
        str.append(QString::number(s_sec));

        ui->lcdNumber->display(str);

    }
    else
    {
        if (secundor/100<proper)
            secundor++;
        if (secundor/100>=proper)
        {
            counter++; //Увеличили счетчик
            QString str;
            int h,m,sec,s_sec; //часы, минуты, секунды, сотые секунд

            s_sec=counter%100;
            sec=counter/100;
            m=sec/60;
            sec=sec%60;
            h=m/60;
            m=m%60;

            if (h<10)
                str.append("0");
            str.append(QString::number(h));
            str.append(":");
            if (m<10)
                str.append("0");
            str.append(QString::number(m));
            str.append(":");
            if (sec<10)
                str.append("0");
            str.append(QString::number(sec));
            str.append(".");
            if (s_sec<10)
                str.append("0");
            str.append(QString::number(s_sec));

            ui->lcdNumber->display(str);
        }
        if (counter/100==stoper)
        {
            ui->pushButton_Pause->click();
            ui->pushButton_Pause->setEnabled(1);
        }
    }
}
void MainWindow::on_pushButton_Start_clicked()//кнопка старт
{
    flag2=true;
    ui->pushButton_Stop->show();
    ui->pushButton_Pause->show();
    flag=true;
    if(timing)
        flag2=true;
    else
        flag2=false;
    counter=0;
    timer->start(10); //10 мсек (0,01 сек)
    timing=false;
}

void MainWindow::on_pushButton_Stop_clicked()//кнопка старта
{
    timing=false;
    ui->pushButton_Stop->hide();
    ui->pushButton_Pause->hide();
    timer->stop();
    counter=0;
    QString str=("00:00:00.00");
    ui->lcdNumber->display(str);
    flag=false;
}

void MainWindow::on_pushButton_Pause_clicked()//кнопка паузы
{
    timing=false;
    if(flag)
    {
        if (timer->isActive())
            timer->stop();
        else
        {
            timer->start();
        }
    }
}

void MainWindow::on_pushButton_clicked()//кнопка армагедона
{
    ui->horizontalSlider->setEnabled(0);
    ui->pushButton->setEnabled(false);
    down_counter=ui->horizontalSlider->value();
    down_timer->start();
}

void MainWindow::down_timer_tick()//то, что будет вызыватся по таймеру армагедона
{
    down_counter--;

    QString str;
    int m,sec; //часы, минуты, секунды

    sec=down_counter%60;
    m=down_counter/60;
    sec=sec%60;
    m=m%60;

    //    if (h<10)
    //        str.append("0");
    //    str.append(QString::number(h));
    //    str.append(":");
    if (m<10)
        str.append("0");
    str.append(QString::number(m));
    str.append(":");
    if (sec<10)
        str.append("0");
    str.append(QString::number(sec));


    if (down_counter==0)
    {
        down_timer->stop();
        ui->label->setVisible(true);
        timer2->stop();
        timer->stop();
        ui->pushButton_Stop->setEnabled(false);
        ui->pushButton_Start->setEnabled(false);
        ui->pushButton_Pause->setEnabled(false);
        ui->pushButton_sta->setEnabled(false);
        ui->spinBox_st->setEnabled(false);
        ui->spinBox_pause->setEnabled(false);
    }
}
void MainWindow::timer_tick2() //то, что будет вызыватся по таймеру 2
{

        pluser++; //Увеличили счетчик
        QString str;
        int h,m,sec,s_sec; //часы, минуты, секунды, сотые секунд

        s_sec=pluser%100;
        sec=pluser/100;
        m=sec/60;
        sec=sec%60;
        h=m/60;
        m=m%60;

        if (h<10)
            str.append("0");
        str.append(QString::number(h));
        str.append(":");
        if (m<10)
            str.append("0");
        str.append(QString::number(m));
        str.append(":");
        if (sec<10)
            str.append("0");
        str.append(QString::number(sec));
        str.append(".");
        if (s_sec<10)
            str.append("0");
        str.append(QString::number(s_sec));

        ui->lcdNumber_2->display(str);
    if (pluser/100==stoper+proper)
    {
        timer2->stop();
        ui->spinBox_st->setEnabled(1);
        ui->spinBox_pause->setEnabled(1);
    }
}

void MainWindow::on_pushButton_sta_clicked()//кнопка старт
{
    timing=true;
    ui->pushButton_Stop->show();
    flag2=true;
    ui->pushButton_Start->click();
    proper=ui->spinBox_st->value();
    counter=pluser=secundor=0;
    stoper=ui->spinBox_pause->value();
    timer2->start(10); //10 мсек (0,01 сек)
    timer->start(10); //10 мсек (0,01 сек)
    ui->spinBox_st->setEnabled(0);
    ui->spinBox_pause->setEnabled(0);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)//слайдер
{
    QString str;
    if (value>=10 && value<60)
    {
        {
            str="00:"+QString::number(value);
            ui->lcdNumber_Down->display(str);
        }
    }
    else
    {
        str="00:0"+QString::number(value);
        ui->lcdNumber_Down->display(str);
    }
    if(value>=60)
    {
        str.clear();
        int sec=0;
        sec=value%60;
        value/=60;
        str.append("0"+QString::number(value));
        str.append(":");
        if (sec<10)
            str+="0"+QString::number(sec);
        else
            str+=QString::number(sec);
        ui->lcdNumber_Down->display(str);
    }
}
