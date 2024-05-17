#ifndef LOADFRM_H
#define LOADFRM_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTranslator>
#include <qwizard.h>
typedef enum {
    UI_ZH,
    UI_EN
}LANGUAGE;

Q_DECLARE_METATYPE(LANGUAGE)

namespace Ui {
class loadfrm;
}

class loadfrm : public QMainWindow
{

    Q_OBJECT

public:
    explicit loadfrm(QWidget *parent = nullptr);
    ~loadfrm();
    uint LanguageSelect();

private slots:
    void on_yesorno_clicked(QAbstractButton *button);

private:
    LANGUAGE _currentLanguage;
    QTranslator* _translator = nullptr;
    QString m_user; //初始化用户名
    QString m_pswd;//初始化密码，未加密的
    int m_tryCount; //试错次数
    QSqlQuery sql_query;
    QSqlDatabase database;
    int max_id = 0;
public:
    void setLanguage(LANGUAGE currentLanguage);
    void setTranslator(QTranslator* translator);
private:
    void changeEvent(QEvent* event);
    void switchLanguage(LANGUAGE language);
    //void    readSettings(); //读取设置,从注册表
    //void    writeSettings();//写入设置，从注册表
  //  QString encrypt(const QString& str);//字符串加密
    void CreatDataBase();
    void OpenDataBase();
    void ExecDataBase();
    void InsertDataBase();
    void UpdataDataBase();
    void QueryDataBase();
    void  SelectAllDataBase();
    void  DelDataBase();
    QWizardPage* createIntroPage();
    QWizardPage* createRegistrationPage();
    void InitPage();
private:
    Ui::loadfrm *ui;
    QWizardPage* page1;
private slots:
    void completeChanged1();

};

#endif // LOADFRM_H
