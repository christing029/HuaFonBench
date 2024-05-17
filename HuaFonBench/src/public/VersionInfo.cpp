#include "VersionInfo.h"
#include "QDateTime.h"

VersionInfo::VersionInfo(QWidget *parent)
	: QMainWindow(parent)
{
	 ui.setupUi(this);

     ui.label_2->setText("华峰储能通用上位机平台系统");
     ui.label_2->setFont(QFont("Microsoft YaHei", 20));
     ui.label->setText("警告:本计算机程序受著作权法和国际条约保护,如未经授权而擅自复制或传播本程序,将受到严厉的民事制裁和刑事制裁,并将在法律许可的最大程度内受到起诉");  
     ui.plainTextEdit->appendPlainText("编译时间:");
     ui.plainTextEdit->setFont(QFont("Microsoft YaHei", 10));
     QString buildtime = buildDateTime().toString("yyyy-MM-dd hh:mm:ss");     
     ui.plainTextEdit->appendPlainText(buildtime);
     ui.plainTextEdit->appendPlainText("版本信息 :");
     ui.plainTextEdit->appendPlainText(VerInfo);
     this->setAttribute(Qt::WA_DeleteOnClose);
}
const QDateTime VersionInfo::buildDateTime()
{
    QString dateTime;
    dateTime.clear();
    dateTime += __DATE__;
    dateTime += __TIME__;
    dateTime.replace("  ", " 0");
    return QLocale(QLocale::English).toDateTime(dateTime, "MMM dd yyyyhh:mm:ss");
}

VersionInfo::~VersionInfo()
{
    deleteLater();
}
