#include "BCUCalibration.h"


BCUCalibration::BCUCalibration(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    InitChart();

    //CALIBRATION_RANGE_s  current[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  batteryVoltage[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  packVoltage[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  temperatureCurrentSensor[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  temperatureExternEnv[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  temperaturePackMinus[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  temperaturePackPlus[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  temperatureBatteryMinus[CALIBRATION_RANGE_MAX_COUNT];
    //CALIBRATION_RANGE_s  temperatureBatteryPlus[CALIBRATION_RANGE_MAX_COUNT];
    connect(ui.comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index)
        {
         switch (index)
              {
                    case 0:
                        BitMap_StartAddress= MODBUS_CALIBRATION_BASE+GET_OFFSET(SENSOR_CALIBRATION_s, currentMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, current[0]);
                        break;
                    case 1:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, batteryVoltageMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, batteryVoltage);
                        break;
                    case 2:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, packVoltageMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, packVoltage);
                        break;
                    case 3:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureCurrentSensorMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureCurrentSensor);
                        break;
                    case 4:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureExternEnvMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureExternEnv);
                        break;
                    case 5:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperaturePackMinusMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperaturePackMinus);
                        break;
                    case 6:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperaturePackPlusMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperaturePackPlus);
                        break;
                    case 7:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureBatteryMinusMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureBatteryMinus);
                        break;
                    case 8:
                        BitMap_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureBatteryPlusMask);
                        WriteData_StartAddress = MODBUS_CALIBRATION_BASE + GET_OFFSET(SENSOR_CALIBRATION_s, temperatureBatteryPlus);
                        break;
                    default:
                        break;
                    }

        });
}

BCUCalibration::~BCUCalibration()
{


}

void BCUCalibration::Float_to_Byte(float f)
{
    uint16_t byte1[2];
    uint8_t *pf8 = (uint8_t*)&f;
    uint16_t * pf = (uint16_t*)&f;       
    byte1[1] = pf8[0]<<8 | pf8[1] ;
    byte1[0] = pf8[2]<<8  | pf8[3];
    writeDataValue.append(byte1[0]);
    writeDataValue.append(byte1[1]);
}


void BCUCalibration::Uint_to_Byte(uint32_t f)
{

    uint16_t* pf = (uint16_t*)&f;
    //unsigned long longdata = 0;
    //longdata = *(unsigned long*)&f;           //注意，会丢失精度
   // byte1[0] = *((uint16_t)pf);  // ((longdata & 0xFF000000) >> 16) >>8 | ((longdata & 0x00FF0000) >> 16) <<8;
   // byte1[1] = pf[1]//(longdata & 0x0000FF00) >> 8 | (longdata & 0x000000FF)<<8;
    pf[0] = 0x3412;
    pf[1] = 0x7856;
    writeDataValue.append(pf[0]);
    writeDataValue.append(pf[1]);
}



void BCUCalibration::InitChart()
{
    Float_to_Byte(1.123);
    // init chart
    spline[0].setColor(Qt::red);     //设置折线颜色
    spline[0].setWidth(2);           //设置折线宽度
    m_series[0].setPen(spline[0]);
    spline[1].setColor(Qt::blue);
    spline[1].setWidth(2);
    m_series[1].setPen(spline[1]);
    m_series[1].setPointLabelsVisible(false);
    //  m_series[0].setUseOpenGL(true);
    m_series[0].setPointLabelsVisible(false);
    m_chart = new QChart();
    m_chart->setTheme(QChart::ChartThemeBlueCerulean); //设置系统主题
    m_chart->legend()->hide();                         //设置图例
 //   m_chart->setAnimationOptions(QChart::SeriesAnimations);// 设置曲线动画显示
    X_axis.setTitleText("电流校准");
    Y_axis.setTitleText("校准参数");
    for (int i = 0; i < CHANNEL_NUMBER; i++)
    {
        m_chart->addSeries(&m_series[i]);
        m_chart->setAxisX(&X_axis, &m_series[i]);
        m_chart->setAxisY(&Y_axis, &m_series[i]);

        for (int j = 0; j < POINT_NUMBER; j++)
        {
            //  m_series[i].append(j, 0);
        }
    }
    /// X轴参数设置
    X_axis.setRange(0, POINT_NUMBER);        //设置范围
    X_axis.setLabelFormat("%d");            //设置刻度的格式
    X_axis.setTickCount(20 + 1);              //设置X轴刻度线数目
    X_axis.setGridLineVisible(true);        //设置是否显示网格线
    X_axis.setLabelsVisible(true);          //设置刻度是否显示

    /// Y轴参数设置
    // Y_axis.setLabelFormat("%g");
    Y_axis.setLabelFormat("%.0f");
    Y_axis.setTickCount(15 + 1);             //设置Y轴刻度线数目
    Y_axis.setGridLineVisible(true);        //设置是否显示网格线
    Y_axis.setLabelsVisible(true);          //设置刻度是否显示
    Y_axis.setRange(AXIS_MIN_Y, AXIS_MAX_Y);
    m_chartView = new ChartView(m_chart);
    ui.gridLayout->addWidget(m_chartView);             //将图表显示添加到layout控件
    m_chartView->setRenderHint(QPainter::Antialiasing);     //启动反走样 Antialiasing反混
    connect(&m_series[0], &QSplineSeries::pointAdded, [=](int index) {
        qreal y = m_series[0].at(index).y();
        if (y > Y_axis.max())
        {
            Y_axis.setMax(y + AXIS_STEP_Y);
        }
        if (y < Y_axis.min())
        {
            Y_axis.setMin(y - AXIS_STEP_Y);
        }
        }
    );
    connect(&m_series[0], SIGNAL(hovered(QPointF, bool)), this, SLOT(showPointData(QPointF, bool)));
    tip = new Callout(m_chart);
    tip->hide();

}

void BCUCalibration::UpDateChart(float startPoint, float endPoint, float K, float B)
{
    QVector<QPointF> list;
    float Y1 = 0;
    float Y2 = 0;
    Y1 = K * startPoint + B;
    Y2 = K * endPoint + B;
    X_axis.setRange(0, endPoint);        //设置范围
    Y_axis.setRange(0, 10);
    m_series[0].append(QPointF(startPoint, Y1));//最后补上新的数据
    m_series[0].append(QPointF(endPoint, Y2));//最后补上新的数据
}

void BCUCalibration::on_bt_clear_clicked()
{
    m_series[0].clear();
    while (ui.tableWidget->rowCount() > 0) {
        ui.tableWidget->removeRow(0);
    }
}

void BCUCalibration::on_bt_read_all_clicked()
{
}

void BCUCalibration::on_bt_write_clicked()
{
    QVector<quint16> BitMapValue;
    BitMapValue.append(BitMap_Val);
    // 写BIT位
    emit signalDownMsg("Write", BitMap_StartAddress, BitMapValue);
    // 写表值
    emit signalDownMsg("Write", WriteData_StartAddress, writeDataValue);
}



void BCUCalibration::on_bt_add_clicked()
{
    static uint8_t cnt = 0;
    float Y1 = 0;
    float Y2 = 0;
    float startPoint;
    float endPoint;
    float K;
    float B;
 /*   uint32_t U32_startPoint;
    uint32_t U32_endPoint;
    uint32_t U32_K;
    uint32_t U32_B;*/
    int t_rowCount = ui.tableWidget->rowCount();
    if (t_rowCount > 9)
    {
        return;
    }
    startPoint=   ui.lE_Start->text().toFloat();
    endPoint=   ui.lE_End->text().toFloat();
    K=  ui.lE_K->text().toFloat();
    B= ui.lE_B->text().toFloat();
    Y1 = K * startPoint + B;
    Y2 = K * endPoint + B;
    ui.tableWidget->insertRow(t_rowCount);
    ui.tableWidget->setItem(t_rowCount, 0, new QTableWidgetItem(ui.lE_Start->text()));
    ui.tableWidget->setItem(t_rowCount, 1, new QTableWidgetItem(QString::number(Y1)));

    ui.tableWidget->setItem(t_rowCount, 2, new QTableWidgetItem(ui.lE_End->text()));
    ui.tableWidget->setItem(t_rowCount, 3, new QTableWidgetItem(QString::number(Y2)));

    ui.tableWidget->setItem(t_rowCount, 4, new QTableWidgetItem(ui.lE_K->text()));
    ui.tableWidget->setItem(t_rowCount, 5, new QTableWidgetItem(ui.lE_B->text()));

    UpDateChart(ui.lE_Start->text().toFloat(), ui.lE_End->text().toFloat(), ui.lE_K->text().toFloat(), ui.lE_B->text().toFloat());
    ui.lE_Start->setText( ui.lE_End->text());
    ui.lE_Start->setReadOnly(true);
    cnt++;
    BitMap_Val = qPow(2,cnt) - 1;

 
    //U32_startPoint = ui.lE_Start->text().toUInt();
    //U32_endPoint = ui.lE_End->text().toUInt();
    //U32_K = ui.lE_K->text().toUInt();
    //U32_K = ui.lE_B->text().toUInt();
    //Uint_to_Byte(U32_startPoint);
    //Uint_to_Byte(U32_endPoint);
    //Uint_to_Byte(U32_K);
    //Uint_to_Byte(U32_K);
    //return;
    // 写数据
    Float_to_Byte(startPoint);
    Float_to_Byte(endPoint);
    Float_to_Byte(K);
    Float_to_Byte(B);
}