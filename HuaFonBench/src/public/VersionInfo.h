#pragma once

#include <QMainWindow>
#include "ui_VersionInfo.h"

class VersionInfo : public QMainWindow
{
	Q_OBJECT

public:
	VersionInfo(QWidget *parent = nullptr);
	~VersionInfo();

private:
	Ui::VersionInfoClass ui;
	QString VerInfo = "T 0.0.2";
private:
	const QDateTime buildDateTime();



};
