#pragma once
#include <QWidget>
#include <QPainter>
#include <QTimer>
class wyPipeProgress  : public QWidget
{
	Q_OBJECT

public:
//	wyPipeProgress(QWidget *parent);
	~wyPipeProgress();

public:
    explicit wyPipeProgress(QWidget* parent = nullptr);

    void setLineWidth(int width) { lineWidth = width; }
    void setBgLineWidth(int width) { bgLineWidth = width; }
    void setLineColor(QColor color) { lineColor = color; }
    void setBackgroundColor(QColor bgColor) { backgroundColor = bgColor; }
    void setDirect(bool directFlag) { directionFlag = directFlag; }
    void setPos(QPointF pos1, QPointF pos2) { startPos = pos1; endPos = pos2; }
    void setSpeed(int speed) { fluidSpeed = speed; }
    void setCapStyle(Qt::PenCapStyle style) { capStyle = style; }
    void setMulPolyLine(bool mulPolyLine) { mulPolyLineFlag = mulPolyLine; }  //设置是否为三折线，默认是两折线
    void setMulPolyLineDirect(bool virticleFlag) { mulPolyLineVirticleDirection = virticleFlag; }   //设置三折线方向，横向还是竖向

    int getLineWidth() { return lineWidth; }
    int getBgLineWidth() { return bgLineWidth; }
    QColor getLineColor() { return lineColor; }
    QColor getBgColor() { return backgroundColor; }
    bool getDirect() { return directionFlag; }
    int getSpeed() { return fluidSpeed; }
    Qt::PenCapStyle getCapStyle() { return capStyle; }
    QPointF getPos1() { return startPos; }
    QPointF getPos2() { return endPos; }
    bool getMulPolyLineFlag() { return mulPolyLineFlag; }
    bool getMulPolyLineDirect() { return mulPolyLineVirticleDirection; }
    void drawPolyLineWith4Points(QPointF points[4]);
    void run();

protected:
    void paintEvent(QPaintEvent* event);

public slots:
    void updateValue();

private:
    int lineWidth;
    int bgLineWidth;
    QColor  lineColor;
    QColor  backgroundColor;
    bool  directionFlag;
    QPointF startPos;
    QPointF endPos;
    int  fluidSpeed;
    Qt::PenCapStyle   capStyle;
    bool mulPolyLineFlag;
    bool mulPolyLineVirticleDirection;
    qreal m_offset;
    QTimer *timer;

};

