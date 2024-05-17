#pragma once

#include <QWidget>
#include "ui_QRImage.h"

class QRImage : public QWidget
{
	Q_OBJECT

public:
	QRImage(QWidget *parent = nullptr);
	~QRImage();

private:
	Ui::QRImageClass ui;
public slots:
	void slots_showQR(QString);
};
