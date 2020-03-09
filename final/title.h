#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>

class title : public QWidget
{
    Q_OBJECT
public:
    explicit title(QWidget *parent = 0);
    ~title();
protected:
    void paintEvent(QPaintEvent *);
private:
    QTimer  *titleTimer;
signals:

public slots:
};

#endif // TITLE_H
