#include "MainWindow.h"
#include <QApplication>
#include <QElapsedTimer>
#include <QDebug>
#include <src/loadfrm/loadfrm.h>
#include <src/public/json.h>
#include <QTranslator>
#include <QSettings>
#include <src/drvmng/drvmng.h>
#include <qwizard.h>
#include <QLabel>
#include <QtGui>
#include "QObject"
#include <globaldef.hpp>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QElapsedTimer cost;
    cost.start();
    //读取语言配置
    QString language_value = "0";
    QString language_suffix = QString("zh");
    LANGUAGE language = UI_ZH;
#if 0
    QTranslator translator;
    bool  ret = translator.load(":/language/tr_en.qm");
    if (!ret) {
      //  std::cout << "语音配置读取错误!" << std::endl;
    }
    a.installTranslator(&translator);
    loadfrm mw;
    mw.setTranslator(&translator);  
    mw.setLanguage(language);
    mw.show();
#else
    MainWindow w;
    w.show();
 //   LOADQSS(GlobalSpace::STYLE_QSS_FILE_PATH);
#endif
    return a.exec();
}
