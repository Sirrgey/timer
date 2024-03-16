#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer> //Подключили класс
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void timer_tick(void); //слот обработки события таймера

    void timer_tick2(void); //слот обработки события таймера

    void down_timer_tick(void); //слот обработки события таймера

    void on_pushButton_Start_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_clicked();

    void on_pushButton_sta_clicked();

    void on_horizontalSlider_valueChanged(int value);



private:
    Ui::MainWindow *ui;

    QTimer * timer; //Указатель на класс Таймер
    QTimer * timer2; //Указатель на класс Таймер
    QTimer * down_timer;
    int pluser; //счетчик для второго
    int counter; //счетчик
    int down_counter;
    bool flag;
    int proper;
    int secundor;
    int stoper;
    bool flag2;
    bool timing;
};

#endif // MAINWINDOW_H
