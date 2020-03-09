#include "mainwindow.h"
#include "QDockWidget"
#include "QToolBar"
#include "QAction"
#include "QMenuBar"
#include <ctime>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#define max 1000
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    win_width = 1300;
    win_height = 700;
    /*win_width = 512;
    win_height = 384;*/
    this->setFixedSize(win_width,win_height);
    this->setWindowIcon(QIcon(":/Image/111.ico"));
    this->setWindowTitle("太鼓達人");
    //oni
    oniku = new oni(this);
    oniku ->move(-1000,-1000);
//title
    Title = new title(this);
    titletimer = new QTimer(this);
    connect(titletimer,SIGNAL(timeout()),this,SLOT(titleAction()));
//arrow
    arrow = new Arrow(this);
//label
    disp = new QLabel(this);
    QFont serifFont("Consolas", 34, QFont::Bold);
    disp->setFont(serifFont);
    disp->setText("1P\n2P\ntmp\nExit");
    disp->setGeometry(900,290,300,400);
//list
    list = new playpart(this);
//tont
   /* for(int i=0;i<32;i++)
        tont[i] = new point(this);
    for(int i=0;i<32;i++)
        tont[i]->move(-1000,-1000);
    for(int i=0;i<32;i+=2)
        tont[i]->i=0;
    for(int i=3;i<32;i+=4)
        tont[i]->i=2;
    for(int i=1;i<32;i+=4)
        tont[i]->i=1;*/
    int i;
        for( i=0;i<max;i++)
            tont[i] = new point(this);
        for( i=0;i<max;i++)
            tont[i]->move(-1000,-1000);
        for(i = 0;i<max;i++)
            tont[i]->i = 0;

        for(i= 0;i<11;i++)
            tont[i]->i = 2;
        for( i = 9;i<18;i++)
            tont[i]->i = 0;
            tont[i]->i = 2;i++;
        ////////////////////////
        for(i=22;i<23;i++)
            tont[i]->i = 2;i++;
            tont[i]->i = 1;i++;
            tont[i]->i = 2;i=32;
            tont[i]->i = 1;i=35;
            tont[i]->i = 1;i++;
            tont[i]->i = 2;i++;
            tont[i]->i = 1;i++;
            //tont[i]->i = 2;i++;
        for(i=38;i<56;i+=2)
            tont[i]->i = 2;
        i=57;
        tont[i]->i = 1;
        i=60;
        tont[i]->i = 1;i+=3;
        for(i=63;i<70;i++)
            tont[i]->i = 2;
        for(;i<130;i+=2)
            tont[i]->i = 2;
        i=96;
        tont[i]->i = 1;
        i=130;

        for(i=130;i<500;i+=2)
            tont[i]->i =1;
    ku = new taku(this);
    fon = new compliment (this);
    fon->move(-1000,-1000);
//score
    for(int i=0;i<10;i++)
        number[i]=new score(this);
    /*for(int i=0;i<3;i++)
        combo[i]= new score(this);*/
//set
    song_list[0] = new set(this);
    song_list[1] = new set(this);
    song_list[0]->move(-1000,-1000);
    song_list[1]->move(-1000,-1000);
    song_list[0]->i=0;
    song_list[1]->i=1;

    /*girl = new dancer(this);
    girl->move(-1000,-1000);*/
    dong =new easyMusic("music/dong.wav",100,0);
    ka = new easyMusic("music/ka.wav",100,0);
    song1 = new easyMusic("music/song831.mp3",80,0);
    begin = new easyMusic("music/begin.mp3",80,1);
    gameRedy();
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap background;
    if(gamemod==start){
        background.load(":/Image/game_bg1.png");
        painter.drawPixmap(0,0,1300,700,background);
    }
    if(gamemod==redy)
    {
        update();
        background.load(":/Image/start.png");
        painter.drawPixmap(0,0,1300,700,background);
    }
    if(gamemod==choose)
    {
        update();
        background.load(":/Image/mode.png");
        painter.drawPixmap(0,0,1300,700,background);
    }
    if(gamemod==endle)
    {
        update();
        background.load(":/Image/end.jpg");
        painter.drawPixmap(0,0,1300,700,background);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    dong->stop();
    ka->stop();
    if((event->button()==Qt::LeftButton)&&gamemod==choose)
    {
        ka->play();
        if(now==0)
        {
            now=1;
            song_list[0]->move(600,290);
            song_list[1]->move(300,430);
        }
        else if(now==1)
        {
            now=0;
            song_list[0]->move(300,290);
            song_list[1]->move(600,430);
        }
    }
    else if((event->button()==Qt::RightButton)&&gamemod==choose)
    {
        ka->play();
        if(now==0)
        {
            now=1;
            song_list[0]->move(600,290);
            song_list[1]->move(300,430);
        }
        else if(now==1)
        {
            now=0;
            song_list[0]->move(300,290);
            song_list[1]->move(600,430);
        }
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{

    dong->stop();
    ka->stop();
    if ((event->key()==Qt::Key_Down)&&(position==400)&&gamemod==redy){
        down();
    }
    else if((event->key()==Qt::Key_Down)&&(position==450)&&gamemod==redy){
        down2();
    }
    else if((event->key()==Qt::Key_Down)&&(position==500)&&gamemod==redy){
        down3();
    }
    else if ((event->key()==Qt::Key_Up)&&(position==550)&&gamemod==redy){
        up();
    }
    else if((event->key()==Qt::Key_Up)&&(position==500)&&gamemod==redy){
        up2();
    }
    else if((event->key()==Qt::Key_Up)&&(position==450)&&gamemod==redy){
        up3();
    }
    else if((event->key()==Qt::Key_Space)&&(position==400)&&gamemod==redy){
        gamechoose();
    }
    else if((event->key()==Qt::Key_Space)&&(position==450)&&gamemod==redy){

    }
    else if((event->key()==Qt::Key_Space)&&(position==500)&&gamemod==redy){

    }
    else if((event->key()==Qt::Key_Space)&&(position==550)&&gamemod==redy){
         exit(1);
    }
    else if((event->key()==Qt::Key_Space)&&gamemod==choose&&now==0 ){
         dong->play();
         gameStart();
    }
    else if((event->key()==Qt::Key_Up)&&gamemod==choose)
    {
        ka->play();
        if(now==0)
        {
            now=1;
            song_list[0]->move(600,290);
            song_list[1]->move(300,430);
        }
        else if(now==1)
        {
            now=0;
            song_list[0]->move(300,290);
            song_list[1]->move(600,430);
        }
    }
    else if((event->key()==Qt::Key_Down)&&gamemod==choose)
    {
        ka->play();
        if(now==0)
        {
            now=1;
            song_list[0]->move(600,290);
            song_list[1]->move(300,430);
        }
        else if(now==1)
        {
            now=0;
            song_list[0]->move(300,290);
            song_list[1]->move(600,430);
        }
    }
    if(event->key()== Qt::Key_J&&gamemod==start)
    {
        dong->play();
        if(gamemod==start){
            ku->i=1;
            ku->j=0;
            check = 1;
            oniku->i=1;
            hitpoint();
        }
    }
    if(event->key()== Qt::Key_F&&gamemod==start)
    {
        dong->play();
        if(gamemod==start){
            ku->i=2;
            ku->j=0;
            check = 1;
            oniku->i=1;
            hitpoint();
        }
    }
    if(event->key()== Qt::Key_I&&gamemod==start)
    {
        ka->play();
        if(gamemod==start){
            ku->i=3;
            ku->j=0;
            check = 2;
            oniku->i=1;
            hitpoint();
        }
    }
    if(event->key()== Qt::Key_E&&gamemod==start)
    {
        ka->play();
        if(gamemod==start){
            ku->i=4;
            ku->j=0;
            check = 2;
            oniku->i=1;
            hitpoint();
        }
    }
    if(event->key()==Qt::Key_P&&gamemod==start)
    {
        if(flag==0){
            tonttimer->stop();
            song1->pause();
            flag=1;
        }
        else{
            tonttimer->start(pointtime);
            song1->play();
            flag = 0;
        }
    }
}
void MainWindow::down(){
    arrow->move(800,445);
    position=450;
}
void MainWindow::down2(){
    arrow->move(800,510);
    position=500;
}
void MainWindow::down3(){
    arrow->move(800,577);
    position=550;
}
void MainWindow::up(){
    arrow->move(800,510);
    position=500;
}
void MainWindow::up2(){
    arrow->move(800,445);
    position=450;
}
void MainWindow::up3(){
    arrow->move(800,378);
    position=400;
}
void MainWindow::createlist()
{
    list->move(-1000,-1000);
}
void MainWindow::createtaku()
{
    ku->move(-1000,-1000);
}
void MainWindow::createpoint()
{
    for(int i=0;i<max;i++){
        tont[i]->move(600+100*i,220);//135
        lastpoint=i;
        nowpoint = 0;
    }
    tonttimer = new QTimer(this);
    connect(tonttimer,SIGNAL(timeout()),this,SLOT(pointAction()));
    //connect(tonttimer,SIGNAL(timeout()),this,SLOT(hitpoint()));
    pointtime = 8;
}
void MainWindow::pointAction()
{
    for(int i=0;i<max;i++)
    {
        tont[i]->move(tont[i]->pos().x()-3,tont[i]->pos().y());
        if(tont[i]->pos().x()<280)//tont[i]->pos().x()<90
        {
            tont[i]->move(tont[lastpoint]->pos().x()+100,tont[lastpoint]->pos().y());
            lastpoint = i;
            if(i!=max-1)nowpoint = i+1;
            else nowpoint = i;
            if(tont[i]->i!=2){
                fon->i=0;
                fon->move(350,140);
                combonumber=0;
                //comboAction();
            }

        }
    }
    end();
}
void MainWindow::hitpoint()
{
    //tont[nowpoint]->pos().x()>=320&&tont[nowpoint]->pos().x()<=400
    //tont[nowpoint]->pos().x()>=96&&tont[nowpoint]->pos().x()<=170
    if (tont[nowpoint]->i==2){
        tont[nowpoint]->move(tont[lastpoint]->pos().x()+100,tont[lastpoint]->pos().y());
        lastpoint = nowpoint;
        if(nowpoint!=max-1)nowpoint = nowpoint +1;
        else nowpoint =0;
    }
    if(tont[nowpoint]->pos().x()>=280&&tont[nowpoint]->pos().x()<500){
        int index= check;
        if(tont[nowpoint]->pos().x()>=310&&tont[nowpoint]->pos().x()<410){
            if(tont[nowpoint]->i==index-1){
                fon->i=2;
                fon->move(370,140);
                scorenumber+=2250;
                combonumber++;
                scoreAction();
                //comboAction();
            }
             else{
                fon->i=0;
                fon->move(350,140);
                combonumber=0;
                //comboAction();
            }
        }
        if((tont[nowpoint]->pos().x()<310&&tont[nowpoint]->pos().x()>=280)||(tont[nowpoint]->pos().x()<500&&tont[nowpoint]->pos().x()>=410))
        {
            if(tont[nowpoint]->i==index-1){
                fon->i=1;
                fon->move(370,140);
                scorenumber+=1900;
                combonumber++;
                scoreAction();
                //comboAction();
            }
            else{
                fon->i=0;
                combonumber=0;
                fon->move(350,140);
                //comboAction();
            }
        }
        tont[nowpoint]->move(tont[lastpoint]->pos().x()+100,tont[lastpoint]->pos().y());
        lastpoint = nowpoint;
        if(nowpoint!=max-1)nowpoint = nowpoint +1;
        else nowpoint =0;
    }

}
void MainWindow::titleAction()
{
    int step_length = 20;
    if(title_count<=1)
    {
        if(title_i<=step_length*40)
        {
            Title->move(title_i,-title_i);
            title_i = title_i+1;

        }
        else
        {
            title_i = 0;
            title_count++;
        }
    }
    else
    {
        Title->move(500,-500);
    }
}
void MainWindow::createscore(){
    for(int i =0;i<10;i++)
        number[i]->i=0;
    for(int i=0;i<10;i++)
        number[i]->move(-50,-50);
}
void MainWindow::scoreAction()
{
    number[0]->i=scorenumber%10;
    if(scorenumber>=10&&scorenumber<100)
    {
        number[1]->i=scorenumber/10;
        number[1]->move(1230,130);
    }
    if(scorenumber>=100&&scorenumber<1000)
    {
        number[1]->i=(scorenumber%100)/10;
        number[1]->move(1230,130);
        number[2]->i=scorenumber/100;
        number[2]->move(1195,130);
    }
    if(scorenumber>=1000&&scorenumber<10000)
    {
        number[1]->i=(scorenumber%100)/10;
        number[1]->move(1230,130);
        number[2]->i=(scorenumber/100)%10;
        number[2]->move(1195,130);
        number[3]->i=scorenumber/1000;
        number[3]->move(1160,130);
    }
    if(scorenumber>=10000&&scorenumber<1000000)
    {
        number[1]->i=(scorenumber%100)/10;
        number[1]->move(1230,130);
        number[2]->i=(scorenumber%1000)/100;
        number[2]->move(1195,130);
        number[3]->i=(scorenumber%10000)/1000;
        number[3]->move(1160,130);
        number[4]->i=scorenumber/10000;
        number[4]->move(1125,130);
    }
    if(scorenumber>=100000&&scorenumber<1000000)
    {
        number[1]->i=(scorenumber%100)/10;
        number[1]->move(1230,130);
        number[2]->i=(scorenumber%1000)/100;
        number[2]->move(1195,130);
        number[3]->i=(scorenumber%10000)/1000;
        number[3]->move(1160,130);
        number[4]->i=(scorenumber%100000)/10000;
        number[4]->move(1125,130);
        number[5]->i=scorenumber/100000;
        number[5]->move(1090,130);
    }
    if(scorenumber>=1000000&&scorenumber<10000000)
    {
        number[1]->i=(scorenumber%100)/10;
        number[1]->move(1230,130);
        number[2]->i=(scorenumber%1000)/100;
        number[2]->move(1195,130);
        number[3]->i=(scorenumber%10000)/1000;
        number[3]->move(1160,130);
        number[4]->i=(scorenumber%100000)/10000;
        number[4]->move(1125,130);
        number[5]->i=(scorenumber%1000000)/100000;
        number[5]->move(1090,130);
        number[6]->i=scorenumber/1000000;
        number[6]->move(1055,130);
    }
    if(scorenumber>=10000000&&scorenumber<100000000)
    {
        number[1]->i=(scorenumber%100)/10;
        number[1]->move(1230,130);
        number[2]->i=(scorenumber%1000)/100;
        number[2]->move(1195,130);
        number[3]->i=(scorenumber%10000)/1000;
        number[3]->move(1160,130);
        number[4]->i=(scorenumber%100000)/10000;
        number[4]->move(1125,130);
        number[5]->i=(scorenumber%1000000)/100000;
        number[5]->move(1090,130);
        number[6]->i=(scorenumber%10000000)/1000000;
        number[6]->move(1055,130);
        number[7]->i=scorenumber/10000000;
        number[7]->move(1020,130);
    }
}
void MainWindow::comboAction()
{
    /*combo[0]->i=combonumber%10;
    if(combonumber>=10&&combonumber<100)
    {
        combo[0]->move(50,185);
        combo[1]->i=combonumber/10;
        combo[1]->move(25,185);
    }
    if(combonumber>=100&&combonumber<1000)
    {
        combo[0]->move(75,185);
        combo[1]->i=(combonumber%100)/10;
        combo[1]->move(40,185);
        combo[2]->i=combonumber/100;
        combo[2]->move(5,185);
    }*/
}
void MainWindow::gameRedy()
{
    begin->play();
    arrow->move(800,378);
    titletimer->start(1);
    gamemod=redy;
    createlist();
    createtaku();
    createscore();
    /*for(int i =0;i<3;i++)
        combo[i]->i=0;
    for(int i=0;i<3;i++)
        combo[i]->move(-50,-50);*/
}
void MainWindow::gamechoose()
{
    //處理
    begin->stop();
    titletimer->stop();
    Title->move(-1000,-1000);
    disp->move(-1000,-1000);
    arrow->move(-1000,-1000);
    gamemod=choose;
    song_list[0]->move(300,290);
    song_list[1]->move(600,430);
    now = 0;
}
void MainWindow::gameStart()
{
    song_list[0]->move(-1000,-1000);
    song_list[1]->move(-1000,-1000);
    //遊戲前置
    number[0]->move(1265,130);
    /*combo[0]->move(30,185);
    combonumber = 0;*/
    scorenumber = 0;

    song1->play();
    time.start();

    gamemod=start;
    //girl->move(650,500);
    oniku->move(220,-50);
    list->move(300,175);
    ku->move(0,175);
    /*ku->move(0,120);
    list->move(94,128);*/
    createpoint();
    tonttimer->start(pointtime);
}
void MainWindow::gameend()
{
    gamemod = endle;
    song1->stop();
    tonttimer->stop();
    list->move(-1000,-1000);
    ku->move(-1000,-1000);
    oniku->move(-1000,-1000);
    fon->move(-1000,-1000);
    //girl->move(-1000,-1000);
    for(int i=0;i<max;i++)
        tont[i]->move(-1000,-1000);
    number[7]->move(710,217);
    number[6]->move(745,217);
    number[5]->move(780,217);
    number[4]->move(815,217);
    number[3]->move(850,217);
    number[2]->move(885,217);
    number[1]->move(920,217);
    number[0]->move(955,217);
}

void MainWindow::end()
{
    if(time.elapsed()/1000>100)
        gameend();
}

MainWindow::~MainWindow(){}


