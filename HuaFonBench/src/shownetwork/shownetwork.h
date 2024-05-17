#ifndef SHOWNETWORK_H
#define SHOWNETWORK_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>
#include <QTimer>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <src/shownetwork/GaugeWidgets.h>
#include <src/shownetwork/wyPipeProgress.h>
#include "QRImage.h"
namespace Ui {
class shownetwork;
}

class shownetwork : public QWidget
{
    Q_OBJECT

public:
    explicit shownetwork(QWidget *parent = nullptr);
    ~shownetwork();
private:
    Ui::shownetwork *ui;
    public:
    signals:
        void lightStrip();
  //  void chargeAnimation();
private:
    QPropertyAnimation* m_animation;        //动画对象指针
private slots:
    void chargeAnimation();
    void can_rec_data(QString str);
private:
    void ArrowInit();
    void updateArrowsPositions();
    QGraphicsScene* m_scene;
    /// test git
    void GrawPipe();
    wyPipeProgress* pipe1;
    void InitTableWidget();
    void TestData();


};
#endif // SHOWNETWORK_H