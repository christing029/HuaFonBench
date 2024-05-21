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
    // ����Ӧ�ĳߴ�
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

    tip_b->setText("����ת��:1000RPM");

}

QtWidgetsFan::~QtWidgetsFan()
{
}

void QtWidgetsFan::paintEvent(QPaintEvent*)
{
    static int rat = 0;
    if (checkrat == 1) {
        rat = rat >= 360 ? 0 : rat + 20;//��ת
    }

    else {
        rat = 0;//����ת
    }
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //������ɫ
    QColor quadColor(60, 60, 120);
    painter.setBrush(quadColor);
    //������תͼƬʱ�����ĵ�
    painter.translate(200, 200);

    //����ͼƬ��ת�Ƕ�
    painter.rotate(rat);

    //������ 4�������ι���
    QPolygon triangle;
    //��( 200, 200 )����ԭ��
    //��һ����������������(0,0) (100,0) (100,100)
    triangle.setPoints(3, 0, 0, 100, 0, 100, 100);
    painter.drawPolygon(triangle);

    triangle.setPoints(3, 0, 0, 0, -100, 100, -100);
    painter.drawPolygon(triangle);

    triangle.setPoints(3, 0, 0, -100, 0, -100, -100);;
    painter.drawPolygon(triangle);

    triangle.setPoints(3, 0, 0, 0, 100, -100, 100);
    painter.drawPolygon(triangle);
    update();//�������򿪷��Ȳ���ת��ȡ����ע��
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
        //....һЩ����
        setCursor(Qt::WhatsThisCursor);
        // tip_b->setText("�ӻ�1��Ϣ\n��ѹ��59V\n�¶ȣ�80��\n
        tip_b->setText(tipMessage);

    }
    return QWidget::event(e);
}