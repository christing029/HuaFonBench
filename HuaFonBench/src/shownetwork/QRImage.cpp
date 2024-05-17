#include "QRImage.h"

QRImage::QRImage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);//无边框
}

QRImage::~QRImage()
{
	//delete ui;
}

void QRImage::slots_showQR(QString mes)
{
	if (mes == "quit")
		this->close();
	else if (mes == "BAIDU")
		//this->close();
	{

	}
}