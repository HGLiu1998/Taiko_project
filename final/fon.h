#ifndef FON_H
#define FON_H

#include <QWidget>
#include <cmath>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class fon : public QWidget
{
    Q_OBJECT
public:
    explicit fon(QWidget *parent = 0);
    QString gb[3];
    int i;
    ~fon();
protected:
    void paintEvent(QPaintEvent *event);
private:

signals:

public slots:
};

#endif // FON_H
