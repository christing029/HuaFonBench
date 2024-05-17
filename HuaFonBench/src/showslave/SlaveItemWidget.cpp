#include "SlaveItemWidget.h"

SlaveItemWidget::SlaveItemWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ui.label = new QPixmap(":/icon/globes_red.png");
	ui.label->setText(QStringLiteral("均衡"));
	//QPixmap arrowPixmap(":/arrow.png");
	ui.label_2->setMaximumSize(16, 16);
	ui.label_2->setScaledContents(true);

	ui.label_2->setPixmap(QPixmap(":/icon/globes_red.png"));
	ui.label_3->setText(QStringLiteral("设备"));
	ui.label_4->setPixmap(QPixmap(":/icon/globes_green.png"));
	ui.label_4->setMaximumSize(16, 16);
	ui.label_4->setScaledContents(true);
	ui.label_5->setText(QStringLiteral("ID:1 "));
	setMouseTracking(true);
}

SlaveItemWidget::~SlaveItemWidget()
{


}


//bool SlaveItemWidget::event(QEvent* e)
//{
//	int i = e->type();
//	if (e->type() == QEvent::Enter)
//	{
//		this->setToolTip(QString::number(1));
//	}
//	return QWidget::event(e);
//}
//
//void SlaveItemWidget::mousePressEvent(QMouseEvent* event)
//{
//}
//
//void SlaveItemWidget::enterEvent(QMouseEvent* event)
//{
//
//}
//
//void SlaveItemWidget::leaveEvent(QMouseEvent* event)
//{
//	SlaveItemWidget::leaveEvent(event);
//}
