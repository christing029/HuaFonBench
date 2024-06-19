#include "deviceFind.h"
#include <QFile>
#include <QMessageBox>
#include <QNetworkDatagram>
#include <QPainter>
#include <QtMath>
#include "src/public/SearchAnimationWidget.h"
deviceFind::deviceFind(QWidget *parent)
	: QWidget(parent)
{
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
   this->setStyleSheet(qss);
	ui.setupUi(this);
    udpSocket = new QUdpSocket(this);
    // 在Qt中发送UDP广播的例子
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateSnd()));
    timer->stop();
    timer->setInterval(100);
    connect(udpSocket, &QUdpSocket::readyRead, this, &deviceFind::readPendingDatagrams);
    if (!udpSocket->bind(QHostAddress::Any, 50022)) {
        // handle the error
    }
    ui.tableWidget->insertRow(ui.tableWidget->rowCount());
    connect(ui.pushButton, &QPushButton::clicked, this, [=]() {
        while (ui.tableWidget->rowCount() > 0)
        {
            ui.tableWidget->removeRow(0);
        }
        timer->start();
        deviceCount = 0;
        for (int i = 0; i < 10; i++)
            UUID[i] = "";
        });
    connect(ui.pushButton_2, &QPushButton::clicked, this, [=]() {
        timer->stop();
        deviceCount = 0;
    for (int i=0;i<10;i++)
        UUID[i] = "" ;
        });
}

deviceFind::~deviceFind()
{

}

void deviceFind::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        processDatagram(datagram);
    }
}

void deviceFind::processDatagram(const QNetworkDatagram& datagram) {
    // Process the datagram as required, for example:
    QByteArray data = datagram.data();
    // do something with the data
    QString str = data.toStdString().c_str();
    QStringList strlist = str.split(";");
    if (strlist.count() == 2)
    {
        return;
    }
    for (int i= 0; i < 10; i++)
    {
        if (UUID[i] == strlist[7])
        {
            return;
        }
    }

    int rowIndex = ui.tableWidget->rowCount();
    ui.tableWidget->setRowCount(rowIndex);
    deviceCount++;
    UUID[deviceCount-1] = strlist[7];
    ui.tableWidget->insertRow(ui.tableWidget->rowCount());
    for (int i = 0; i < strlist.count(); i++)
    {
        ui.tableWidget->setItem(deviceCount-1, i, new QTableWidgetItem(strlist[i]));
    }
}


void deviceFind::updateSnd()
{
    static int x = 0;
    if (x!=100)
    {
    x++;
    ui.progressBar->setValue(x);
    QByteArray datagram = "HF_ESS_FINDreq=?;";
    udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 50022);
    }
    else
    {
        x = 0;
        timer->stop();
    }
    }