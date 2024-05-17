#include "wyPipeProgress.h"



wyPipeProgress::~wyPipeProgress()
{
}
void wyPipeProgress::paintEvent(QPaintEvent*)
{
    //    qInfo()<<"startX:"<<startPos.x()<<"startY:"<<startPos.y()<<"endX:"<<endPos.x()<<"endY:"<<endPos.y();
        //根据起始点与终点判断是需要折线还是直线，亦或是三折线
    if (startPos.x() == endPos.x() || startPos.y() == endPos.y())    //直线
    {
        QPainter painter(this);
        //        painter.setRenderHints(QPainter::Antialiasing);

        QPen pen(backgroundColor);
        pen.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(bgLineWidth);
        pen.setCapStyle(capStyle);      // FlatCap, SquareCap, RoundCap
        painter.setPen(pen);
        painter.drawLine(startPos, endPos);

        //        QPen pen1(lineColor);
        QPen pen1(Qt::blue);
        QVector<qreal> dashes;
        qreal space = 2;
        dashes << 3 << space << 3 << space;
        pen1.setDashPattern(dashes);
        pen1.setWidth(lineWidth);
        pen1.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
        pen1.setCapStyle(capStyle);      // FlatCap, SquareCap, RoundCap
        pen1.setDashOffset(m_offset);
        painter.setPen(pen1);
        painter.drawLine(startPos, endPos);
    }
    else
    {
        if (!mulPolyLineFlag)    //两折线
        {
            QPointF pos1 = startPos;
            QPointF pos2(endPos.x(), startPos.y());
            QPointF pos3 = endPos;
            QPointF points[3] = { pos1,pos2,pos3 };

            QPainter painter(this);
            //        painter.setRenderHints(QPainter::Antialiasing);

            QPen pen(backgroundColor);
            pen.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
            pen.setStyle(Qt::SolidLine);
            pen.setWidth(bgLineWidth);
            pen.setCapStyle(capStyle);      // FlatCap, SquareCap, RoundCap
            painter.setPen(pen);
            painter.drawPolyline(points, 3);

            QPen pen1(lineColor);
            QVector<qreal> dashes;
            qreal space = 2;
            dashes << 3 << space << 3 << space;
            pen1.setDashPattern(dashes);
            pen1.setWidth(lineWidth);
            pen1.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
            pen1.setCapStyle(capStyle);      // FlatCap, SquareCap, RoundCap
            pen1.setDashOffset(m_offset);
            painter.setPen(pen1);
            painter.drawPolyline(points, 3);
        }
        else    //三折线
        {
            if (mulPolyLineVirticleDirection)    //垂直
            {
                QPointF pos1 = startPos;
                QPointF pos2(startPos.x(), startPos.y() + (endPos.y() - startPos.y()) / 2);
                QPointF pos3(endPos.x(), startPos.y() + (endPos.y() - startPos.y()) / 2);
                QPointF pos4 = endPos;
                QPointF points[4] = { pos1,pos2,pos3,pos4 };
                drawPolyLineWith4Points(points);
            }
            else    //横向
            {
                QPointF pos1 = startPos;
                QPointF pos2(startPos.x() + (endPos.x() - startPos.x()) / 2, startPos.y());
                QPointF pos3(startPos.x() + (endPos.x() - startPos.x()) / 2, endPos.y());
                QPointF pos4 = endPos;
                QPointF points[4] = { pos1,pos2,pos3,pos4 };
                drawPolyLineWith4Points(points);
            }
        }

    }


    this->setFixedSize(this->window()->width(), this->window()->height());

}

wyPipeProgress::wyPipeProgress(QWidget* parent)
    : QWidget(parent)
{

    lineWidth = 5;  //线条宽度
    bgLineWidth = 10;    //背景线宽度
    lineColor = Qt::red;   //线条颜色
    backgroundColor = Qt::gray; //背景线条颜色
    directionFlag = true; //流动方向
//    startPos = QPointF(0, 0);
//    endPos = QPointF(0, 0);   //起始点，结束点
    fluidSpeed = 10; //流动速度
    capStyle = Qt::RoundCap;  //填充模式  FlatCap, SquareCap, RoundCap

    mulPolyLineFlag = false;
    mulPolyLineVirticleDirection = false;   //默认横向

    m_offset = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    timer->stop();
    //   timer->start(fluidSpeed);


}

void wyPipeProgress::drawPolyLineWith4Points(QPointF points[4])
{
    QPainter painter(this);
    //        painter.setRenderHints(QPainter::Antialiasing);

    QPen pen(backgroundColor);
    pen.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(bgLineWidth);
    pen.setCapStyle(capStyle);      // FlatCap, SquareCap, RoundCap
    painter.setPen(pen);
    painter.drawPolyline(points, 4);

    QPen pen1(lineColor);
    QVector<qreal> dashes;
    qreal space = 2;
    dashes << 3 << space << 3 << space;
    pen1.setDashPattern(dashes);
    pen1.setWidth(lineWidth);
    pen1.setJoinStyle(Qt::RoundJoin);    // MiterJoin, BevelJoin, RoundJoin
    pen1.setCapStyle(capStyle);      // FlatCap, SquareCap, RoundCap
    pen1.setDashOffset(m_offset);
    painter.setPen(pen1);
    painter.drawPolyline(points, 4);
}

void wyPipeProgress::run()
{
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    timer->start(fluidSpeed);
}

void wyPipeProgress::updateValue()
{
    //    qInfo()<<"111";

    if (directionFlag)
    {
        m_offset += 0.5;
    }
    else
    {
        m_offset -= 0.5;
    }

    update();
}