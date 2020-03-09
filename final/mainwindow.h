#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <QLabel>
#include <QFont>
#include <QTimer>
#include <QTIme>
#include "playpart.h"
#include "taku.h"
#include "point.h"
#include "compliment.h"
#include "easymusic.h"
#include "title.h"
#include "arrow.h"
#include "oni.h"
#include "score.h"
#include "set.h"
#include "dancer.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);    //繪製背景圖
    void mousePressEvent(QMouseEvent *event);	//滑鼠點下事件
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件
    
private slots:
    void pointAction();
    void titleAction();
private:
    void end();
    void down();             
    void down2();
    void down3();
    void up();
    void up2();
    void up3();

    void createscore();
    void scoreAction();
    void comboAction();
    void hitpoint();
    void createlist();
    void createtaku();
    void createpoint();
    void gamechoose();			 //遊戲結束
    void gameStart();			 //遊戲開始
    void gameRedy();             //遊戲預備
    void gameend();
    //dancer *girl;
    //
    oni *oniku;
//Label
    QLabel *disp;
    QLabel *disp2;
//title
    title *Title;
    QTimer *titletimer;
    int title_i=0;
    int title_count=0;
//Arrow
    Arrow *arrow;
    int position=400;
    //time
    QTime time;
//tont
    QTimer *tonttimer;
    point *tont[1000];
    double pointtime;
    int lastpoint;
    int nowpoint;
//list
    playpart *list;
//ku
    taku *ku;
//fon
    compliment *fon;
//score
    score *number[10];
    //score *combo[3];
    int scorenumber;
    int combonumber;
//set
    set *song_list[2];
    int now;

    int check;
    int flag=0;

    easyMusic *begin;
    easyMusic *dong;
    easyMusic *ka;
    easyMusic *song1;

    int win_height;
    int win_width;
    enum{redy=0,choose=1,start=2,endle=3};  // Enum三個參數, 代表遊戲狀態
    int gamemod;

};

#endif // MAINWINDOW_H
