#include "ShowBMUNetItem.h"
#include <QtWidgets/qpushbutton.h>
#include <QTimer>
ShowBMUNetItem::ShowBMUNetItem(uint ID,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.groupBox->setTitle(QStringLiteral("电池信息ID:" )+ QString::number(ID+1,10));
	ui.label->setText(QStringLiteral("均衡"));
	//QPixmap arrowPixmap(":/arrow.png");
	ui.label_2->setMaximumSize(16, 16);
	ui.label_2->setScaledContents(true);
	ui.label_2->setPixmap(QPixmap(":/icon/globes_grey.png"));
	ui.label_3->setText(QStringLiteral("断线"));
	ui.label_4->setPixmap(QPixmap(":/icon/globes_red.png"));
	ui.label_4->setMaximumSize(16, 16);
	ui.label_4->setScaledContents(true);
	ui.label_6->setText(QStringLiteral("0°"));
	ui.label_7->setText(QStringLiteral("0V"));
	ui.label_7->setMaximumSize(QSize(200, 200));
	ui.label_6->setMaximumSize(QSize(200, 200));

}



ShowBMUNetItem::~ShowBMUNetItem()
{

}

void ShowBMUNetItem::SetVoltageVal(float val)
{
	//ui.label_7
	if (MaxVolt)
	{
		ui.label_7->setStyleSheet("QLabel{background-color:rgb(200,101,102);}");
	}
	else if (MinVolt)
	{
		ui.label_7->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");
	}
	else
	{
		ui.label_7->setStyleSheet("QLabel{background-color:#267400;}");
	}
	ui.label_7->setText(QString::number(val*0.001)+ QStringLiteral("V"));
}

void ShowBMUNetItem::SetTempVal(float val)
{
	if (MaxTemp)
	{
		ui.label_6->setStyleSheet("QLabel{background-color:rgb(200,101,102);}");
	}
	else if (MinTemp)
	{
		ui.label_6->setStyleSheet("QLabel{background-color:rgb(255,255,255);}");
	}
	else
	{
		ui.label_6->setStyleSheet("QLabel{background-color:#267400;}");
	}
	ui.label_6->setText(QString::number(val*0.1) + QStringLiteral("°"));
}

void ShowBMUNetItem::SetCnnVal(bool val)
{
	if (val==false)
	ui.label_4->setPixmap(QPixmap(":/icon/globes_green.png"));
	else
    ui.label_4->setPixmap(QPixmap(":/icon/globes_red.png"));
}

void ShowBMUNetItem::SetBlanceVal(bool val)
{
	if (val == false)
		ui.label_2->setPixmap(QPixmap(":/icon/globes_grey.png"));
	else
		ui.label_2->setPixmap(QPixmap(":/icon/globes_green.png"));
}
