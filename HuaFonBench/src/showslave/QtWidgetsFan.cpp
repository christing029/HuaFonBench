#include "QtWidgetsFan.h"

QtWidgetsFan::QtWidgetsFan(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    tim = new QTimer(this);
	connect(tim, SIGNAL(timeout()), this, SLOT(update()));
	tim->start(30);
	checkrat =1;

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
    //update();//�������򿪷��Ȳ���ת��ȡ����ע��

}

void QtWidgetsFan::start()
{
    checkrat = 1;
}

void QtWidgetsFan::stop()
{
    checkrat = 0;
}
