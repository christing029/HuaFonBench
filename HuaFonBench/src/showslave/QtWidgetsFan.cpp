#include "QtWidgetsFan.h"

QtWidgetsFan::QtWidgetsFan(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    tim = new QTimer(this);
	connect(tim, SIGNAL(timeout()), this, SLOT(update()));
	tim->start(30);
	checkrat =1;

    tip_b = new CuteToolTip("Tip B", this);
    tip_b->setObjectName("tipB");
    tip_b->anchorTarget(this);
    // 自适应的尺寸
    tip_b->setStyleSheet(R"(
    .CuteToolTip#tipB{
    qproperty-xOffset:"20";
    qproperty-yOffset:"3";
    }
    .CuteToolTip#tipB QLabel{
    padding:10px 30px;
    color:white;
    border:1px solid white;
    background-color:rgb(20,50,90);
    }
)");

    tip_b->setText("风扇转速:1000RPM");

}

QtWidgetsFan::~QtWidgetsFan()
{
}

void QtWidgetsFan::paintEvent(QPaintEvent*)
{
    static int rat = 0;
    if (checkrat == 1) {
        rat = rat >= 360 ? 0 : rat + 20;//旋转
    }

    else {
        rat = 0;//不旋转
    }
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //设置颜色
    QColor quadColor(60, 60, 120);
    painter.setBrush(quadColor);
    //设置旋转图片时的中心点
    painter.translate(200, 200);

    //设置图片旋转角度
    painter.rotate(rat);

    //画风扇 4个三角形构成
    QPolygon triangle;
    //以( 200, 200 )坐标原点
    //第一个三角形三点坐标(0,0) (100,0) (100,100)
    triangle.setPoints(3, 0, 0, 100, 0, 100, 100);
    painter.drawPolygon(triangle);

    triangle.setPoints(3, 0, 0, 0, -100, 100, -100);
    painter.drawPolygon(triangle);

    triangle.setPoints(3, 0, 0, -100, 0, -100, -100);;
    painter.drawPolygon(triangle);

    triangle.setPoints(3, 0, 0, 0, 100, -100, 100);
    painter.drawPolygon(triangle);
    update();//如果点击打开风扇不旋转就取消该注释
    tip_b->setText(tipMessage);
}

void QtWidgetsFan::start()
{
    checkrat = 1;
}

void QtWidgetsFan::stop()
{
    checkrat = 0;
}

bool QtWidgetsFan::event(QEvent* e)
{
//    tip_b->setText(tipMessage);
    if (e->type() == QEvent::HoverEnter || e->type() == QEvent::HoverLeave || e->type() == QEvent::HoverMove)
    {
        //....一些操作
        setCursor(Qt::WhatsThisCursor);
        // tip_b->setText("从机1信息\n电压：59V\n温度：80°\n
        tip_b->setText(tipMessage);

    }
    return QWidget::event(e);
}