#ifndef SLAVEMNG_H
#define SLAVEMNG_H

#include <QMainWindow>
#include "src/public/json.h"
#include "src/slavemng/FaultInjection.h"
namespace Ui {
class SlaveMng;
}
class SlaveMng : public QMainWindow
{
    Q_OBJECT

private :
       // QList<QString>     t_groupName={ "产品序列号","硬件版本号", "产品名称","电池电压采集线束","电流节数","电池温度采集线束","温度个数","电压上限门限","电压下限门限","温度上限门限","电池温度采集线束","电池温度采集线束","电池温度采集线束","电池温度采集线束","电池温度采集线束","电池温度采集线束 "};
    QList<QString>     t_groupName = { "产品序列号 " };
public:
    explicit SlaveMng(QWidget *parent = nullptr);
    ~SlaveMng();

private:
    Ui::SlaveMng *ui;

private:
    void InitUi(QString JsonFile);
    void SlaveCanReadDataSnd(int row);
    void SlaveCanWriteDataSnd(int row);
    QByteArray m_recByte;
    uint16_t m_dataTotalLen = 0;
    uint16_t m_remdataLen = 8;
    uint16_t m_indexcurr = 1;
    uint16_t m_currentrow = 0;
    bool headflag = false;
    FaultInjection* faultInj;
protected slots:
   void on_button_clicked();
   void on_readbutton_clicked();
   void SlotsCanUpBMUMsg(QString str, QByteArray data);;
};
#endif // SLAVEMNG_H
