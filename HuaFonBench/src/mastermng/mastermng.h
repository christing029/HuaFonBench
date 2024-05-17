#ifndef MASTERMNG_H
#define MASTERMNG_H

#include <QMainWindow>
#include "BCUBaseInfo.h"
#include "src/public/json.h"
#include <QMessageBox>
#include <QTranslator>
//#include <src/mastermng/BCUCalibration.h>
//#include <QValueAxis>
#include "BCUCalibration.h"
namespace Ui {
class MasterMng;
}

class MasterMng : public QMainWindow
{
    Q_OBJECT

public:
    explicit MasterMng(QWidget *parent = nullptr);
    ~MasterMng();
private:
    Ui::MasterMng *ui;
private:
    void InitUi(QString JsonFile);
    void SlaveCanDataSnd(int row);
    BCUCalibration* bcucal;
protected slots:
    void on_button_clicked();
    void on_readbutton_clicked();
    void on_bt_write_all_clicked();
    void on_bt_read_all_clicked();
    void slotsUpReadHolding(uint startAddress, QVector<quint16> val);
    void SlotsCalDownMsgComing(QString str, uint address, QVector<quint16> val);

signals:
    void signalDownMsg(QString  str,uint address, QVector<quint16> val);


};

#endif // MASTERMNG_H
