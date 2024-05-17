    #include "shownetwork.h"
    #include "ui_shownetwork.h"
    #include <QFile>
    #include <src/public/ToolTip/CuteToolTip.h>
    #include <src/drvmng/modbus_params.h>
    #include <src/drvmng/drvmng.h>
    extern MOBUS_RUN_STATE_BASE_s m_run_state_base ;

    shownetwork::shownetwork(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::shownetwork)
    {
        QPixmap  m_pixmap;
        QFile file(":/qss/HF.qss");
        if (!file.open(QIODevice::ReadOnly))
        {
            qWarning("Can't open the style sheet file.");
            return;
        }
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
         this->setPalette(QPalette(QColor(paletteColor)));
        this->setStyleSheet(qss);
        file.close();
        ui->setupUi(this);
        QTimer* timer = new QTimer(this);
        timer->setInterval(3000);
         connect(timer, SIGNAL(timeout()), this, SLOT(chargeAnimation()));timer->start();
         // 影响鼠标事件?
         GrawPipe();
         GaugeWidgets w;
         w.show();
         InitTableWidget();
      //   TestData();
      //   InitHover();
         //ui->widget_9->setMouseTracking(true);
         //ui->widget_9->setTabletTracking(true);
         //ui->widget_8->setMouseTracking(true);
         //ui->widget->setMouseTracking(true);
         //ui->groupBox->setMouseTracking(false);
         //ui->groupBox->setTabletTracking(false);
         //ui->groupBox_2->setMouseTracking(false);
         connect(this, SIGNAL(signalUpMasterMsg(QString)), this, SLOT(can_rec_data(QString)));

    }

    void shownetwork::can_rec_data(QString str)//槽函数//子线程(run()函数)结束后由子线程的信号函数(my_signal(QString))触发该函数
    {
        // ui->textEdit->append(str);//将接收到的内容进行显示
    }

    shownetwork::~shownetwork()
    {
        //quit();  // 请求线程退出
        //wait();  // 等待线程完成
        delete ui;
    }
    void shownetwork::GrawPipe()
    {
        // widget------widget_9
        pipe1 = new wyPipeProgress;
        pipe1->setParent(ui->groupBox);

        wyPipeProgress* pipe2 = new wyPipeProgress;
         pipe2->setParent(ui->groupBox);

      //  wyPipeProgress* pipe3 = new wyPipeProgress;
      ////  pipe3->setParent(ui->groupBox);

      //  wyPipeProgress* pipe4 = new wyPipeProgress;
      ////  pipe4->setParent(ui->groupBox);

      //  wyPipeProgress* pipe5 = new wyPipeProgress;
      //pipe5->setParent(ui->groupBox);

      //  wyPipeProgress* pipe6 = new wyPipeProgress;
      // pipe6->setParent(ui->groupBox);

      //  wyPipeProgress* pipe7 = new wyPipeProgress;
      //pipe7->setParent(ui->groupBox);

      //  wyPipeProgress* pipe8 = new wyPipeProgress;
      //  pipe8->setParent(ui->groupBox);

        ////widget左中点
        QPointF sBnt1Pos1((ui->widget->geometry().x())+ ui->widget->size().width()-30,(ui->widget->geometry().y() + ui->widget->size().height() /2));
        QPointF sBnt1Pos3(ui->widget_9->geometry().x(),(ui->widget_9->geometry().y() + ui->widget_9->size().height() / 2-80));

        QPointF sBnt1Pos21(ui->widget_9->geometry().x()+ ui->widget_9->size().width(), (ui->widget_9->geometry().y() + ui->widget_9->size().height() / 2 - 80));

      //  QPointF sBnt1Pos23((ui->widget_8->geometry().x()) + ui->widget_8->size().width() - 30, (ui->widget_8->geometry().y() + ui->widget_8->size().height() / 2));

        QPointF sBnt1Pos23(50, 500);

        pipe1->setPos(sBnt1Pos1, sBnt1Pos3);
        pipe1->setDirect(false);
        pipe1->setCapStyle(Qt::FlatCap);
        pipe1->setLineColor(Qt::yellow);
        pipe1->setBackgroundColor(Qt::green);
        pipe1->run();
        pipe1->lower();


        pipe2->setPos(sBnt1Pos21, sBnt1Pos23);
        pipe2->setSpeed(500);
        pipe2->setDirect(false);
        pipe2->setCapStyle(Qt::FlatCap);
        pipe2->setLineColor(Qt::yellow);
        pipe2->setBackgroundColor(Qt::blue);
        //pipe2->run();
        pipe2->lower();

    }

    void shownetwork::InitTableWidget()
    {
        QList<QString>  status_reg_nametable =
        {
            "总电压",
            "电流",
           "电池状态",
            "接触器状态",
            "輸入信號状态",
                "SOC",
                "SOH",
                "SOE",
            "循环次数",
            "最大允许充电电压",
        "最小允许放电电压",
                    "最大允许充电电流",
                    "最大允许放电电流",
                    "最大单体电压",
                        "最小单体电压",
                        "平均单体电压",
                        "最大单体温度",
                    "最小单体电压",
                        "平均单体电压",
                        "最大模组电压",
                        "最小模组电压",
                        "平均模组电压",
        };

        QStringList headlist;
        headlist << "序号 ";
        for each (QString var in status_reg_nametable)
        {
            headlist << var;
        }
        
        headlist << "采集时间 ";
        ui->tableWidget->setColumnCount(headlist.count());
        ui->tableWidget->setHorizontalHeaderLabels(headlist);

    }

    void shownetwork::TestData()
    {
        //ui->widget_15->setValues(qrand() % 100, 0, 200, 0);
        //ui->widget_12->setValues(qrand() % 100, 0, 200, 0);
        QDateTime time = QDateTime::currentDateTime();
        QString    curTime = time.toString("yyyy-MM-dd hh:mm:ss");

        int rowCount = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowCount);
        //uint16_t soc = m_holding_reg_params.MODBUS_SOC;
        uint16_t data[50];

        memcpy(&data, &m_run_state_base, sizeof(m_run_state_base));

        for (int i = 0; i < ui->tableWidget->columnCount()-1;i++)
        {
            ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(QString::number(rowCount,10))); //序号
            ui->tableWidget->setItem(rowCount, i+1, new QTableWidgetItem(QString::number(data[i], 10))); //序号
        }
        ui->tableWidget->setItem(rowCount, ui->tableWidget->columnCount()-1, new QTableWidgetItem(curTime));   //采集时间

        ui->widget_9->setValue(m_run_state_base.MODBUS_SOC);

      //  ui-> ->setValue(m_holding_reg_params.MODBUS_SOC);

    }
    void shownetwork::chargeAnimation()
    {
        int t_groupName[10] = { 1,2,3,4 };
        //创建动画对象空间（初始化可以指定动画控件和动画需使用的动画属性名）
        m_animation = new QPropertyAnimation();
        m_animation->setTargetObject(ui->label);    //设置使用动画的控件
        m_animation->setEasingCurve(QEasingCurve::Linear); //设置动画效果
        //QWidget wid;
        //wid.setGeometry(1000, 1000, 2000, 2000);
        //wid.show();

        m_animation->setPropertyName("pos");
        m_animation->setDuration(3000);
        m_animation->setStartValue(ui->widget_5->pos()+ QPoint(200, 0));
        ui->label->setStyleSheet("QLabel{background-color:rgb(200,101,102);}");
        m_animation->setEndValue(ui->widget_9->pos());
        m_animation->setLoopCount(-1);
        m_animation->start();

        // TEST DATA
        //设置表格列数
        TestData();

    }

    //void run() override 
    //{
    //    QTimer timer3;
    //    connect(&timer3, &QTimer::timeout, this, &shownetwork::lightStrip);
    //    timer3.start(200); // 设置定时器间隔，单位为毫秒
    //    exec();
    //}



    #if 0

    void shownetwork::lightStrip()
    {

        int imageCount = 11;
        int imageSpacing = 5; // 图片间距，-85

        qDebug() << "lightStrip2";
        QLabel* labelName = ui.label_4;

        int labelWidth = labelName->width();
        int labelHeight = labelName->height();
        qDebug() << "labelWidth: " << labelWidth;
        qDebug() << "labelHeight: " << labelHeight;
        qDebug() << "";

        labelName->clear();

        // 创建画布，与label_3一样大小
        QPixmap canvas(labelName->size());
        canvas.fill(Qt::transparent);

        // 创建画家并将画布设置为绘制目标
        QPainter painter(&canvas);

        // 计算每个加载的图片y坐标
        int y = yPos1;

        // 计算每个图片的总高度（包括间距）
        //int totalHeight = imageCount * (labelName->height() + imageSpacing) - imageSpacing - 80;
       //  int totalHeight = 100;
        int totalHeight = labelName->height();
        qDebug() << "totalHeight: " << totalHeight;

        // 同时绘制多个图片
        for (int i = 0; i < imageCount; i++) {
            // 加载当前图片
            QString imagePath = QString("./imgLightStrip/%1.png").arg(i + 1);
            QPixmap image(imagePath);

            // 定义新的尺寸
            int newWidth = 30;  // 替换为所需的宽度
            int newHeight = 100;  // 替换为所需的高度
            // 调整图片尺寸
            QPixmap resizedImage = image.scaled(newWidth, newHeight);


            int imageWidth = resizedImage.width();
            int imageHeight = resizedImage.height();
            qDebug() << "imageWidth: " << imageWidth;
            qDebug() << "imageHeight: " << imageHeight;
            qDebug() << "";

            int imageWidthT = labelName->width() * 0.3; //用label宽度的0.3比例作为图片宽度
            int imageHeightT = imageHeight * (labelName->width() * 0.3) / imageWidth;
            qDebug() << "imageWidthT: " << imageWidthT;
            qDebug() << "imageHeightT: " << imageHeightT;
            qDebug() << "";



            // 调整图片尺寸以适应label_3的宽度
            QPixmap scaledImage = resizedImage.scaledToWidth(labelName->width() * 0.3);

            // 计算水平居中的x坐标
            int x = (labelName->width() - scaledImage.width()) / 2;

            // 更新y坐标，实现图片向下流动的效果
            //y += totalHeight + 5; // 5是每个图片之间的间隔
            //int y = yPos + i * (labelName->height() + imageSpacing);
            int y = yPos1 + i * (imageHeightT + imageSpacing);
            if (y >= labelName->height()) { // 图片完全超出上方可视区域时，重新调整y坐标
                y -= totalHeight;
            }
            // 将图片绘制到画布上
            painter.drawPixmap(x, y, scaledImage);

            // 如果图片完全超出下方可视区域时，重新调整y坐标
            //if (y >= labelHeight + imageHeightT + 5) {
            //    y = yPos;
            //}
        }
    }
    #endif

