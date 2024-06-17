#include "loadfrm.h"
#include "ui_loadfrm.h"
#include <QDebug>
#include <QMessageBox>
#include <QProgressDialog>
#include "MainWindow.h"
#include <QFileDialog>
#include <src/public/json.h>
#include <src/public/skinclass.h>
#include <QSettings>

QApplication* App;
loadfrm::loadfrm(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::loadfrm)
{
	ui->setupUi(this);

	QFile file(":/qss/HF.qss");
	if (!file.open(QIODevice::ReadOnly))
	{
		qWarning("Can't open the style sheet file.");
		return;
	}
	QString qss = QLatin1String(file.readAll());
	this->setStyleSheet(qss);
	CreatDataBase();
	//    json js;
	//js.creatslavecfg();
}

loadfrm::~loadfrm()
{
	delete ui;
}

uint loadfrm::LanguageSelect()
{
	return ui->comboBox->currentIndex();
}

void loadfrm::setLanguage(LANGUAGE currentLanguage)
{
	_currentLanguage = currentLanguage;
}

void loadfrm::setTranslator(QTranslator* translator)
{
	_translator = translator;
}

void loadfrm::switchLanguage(LANGUAGE language)
{
	QString language_qm;
	switch (language)
	{
	case UI_ZH:
		language = UI_ZH;
		language_qm = QString(":/language/tr_zh.qm");
		break;
	case UI_EN:
		language = UI_EN;
		language_qm = QString(":/language/tr_en.qm");
		break;
	default:
		language = UI_ZH;
		language_qm = QString(":/language/tr_zh.qm");
	}
	if (_currentLanguage != language)
	{
		_currentLanguage = language;
		bool ret = _translator->load(language_qm);
		if (!ret) {
			//PLOG_ERROR << "语音配置读取错误!";
		}
		else {
			QVariant var = QString::number(language, 10);
			std::shared_ptr<QSettings> iniFile = std::make_shared<QSettings>("config.ini", QSettings::IniFormat);
			iniFile->beginGroup("Language");
			iniFile->setValue("english", var);
			iniFile->endGroup();
		}
	}
}

void loadfrm::CreatDataBase()
{
	//if (QSqlDatabase::contains("my_sql_connection"))
	//{
	//	database = QSqlDatabase::database("my_sql_connection");
	//}
	//else {
	//	database = QSqlDatabase::addDatabase("QSQLITE", "my_sql_connection");
	//	database.setDatabaseName("E:/Qt/HuaFonBench/db/HFDB.db");
	//	            database.setUserName("admin");
	//	            database.setPassword("111");
	//}
}


void loadfrm::OpenDataBase()
{
//	if (!database.open())
//	{
//		qDebug() << "open err!";
//	}
//	else
//	{
//		ExecDataBase();
//		//        QString insert_sql = "insert into student values (?, ?, ?)";
//		//        sql_query.prepare(insert_sql);
//		//        sql_query.addBindValue(max_id+1);
//		//        sql_query.addBindValue("Wang");
//		//        sql_query.addBindValue(25);
//		//        if(!sql_query.exec())
//		//        {
//		//            qDebug() << sql_query.lastError();
//		//        }
//		//        else
//		//        {
//		//            qDebug() << "inserted Wang!";
//		//        }
//		//        if(!sql_query.exec("INSERT INTO student VALUES(3, \"Li\", 23)"))
//		//        {
//		//            qDebug() << sql_query.lastError();
//		//        }
//		//        else
//		//        {
//		//            qDebug() << "inserted Li!";
//		//        }
//				// do something
//	}
}



void loadfrm::ExecDataBase()
{
	//QString create_sql = "create table student (id int primary key, name varchar(30), age int)";
	//sql_query.prepare(create_sql);
	//if (!sql_query.exec())
	//{
	//	qDebug() << "Error: Fail to create table." << sql_query.lastError();
	//}
	//else
	//{
	//	qDebug() << "Table created!";
	//}
}




void loadfrm::changeEvent(QEvent* event)
{
	switch (event->type())
	{
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		QWidget::changeEvent(event);
	}
}
void loadfrm::on_yesorno_clicked(QAbstractButton* button)
{

	QString name, pass;
	name = this->ui->work_name->text();
	pass = this->ui->passward->text();
	if (name == "" | pass == "")
	{
	    QMessageBox::warning(this, tr(" 警告 "), tr(" 输入不能为空！ "), QMessageBox::Ok);
		return;
	}
	if (ui->comboBox->currentIndex() == 0)
	{
		bool ret = _translator->load(":/language/tr_zh.qm");
	}
	else
	{
		bool ret = _translator->load(":/language/tr_en.qm");
	}
	ui->retranslateUi(this);
	QProgressDialog dialog(tr(" 正在登录 "), tr(" 取消 "), 0, 80000, this);
	dialog.setWindowTitle(tr(" 进度    "));
	dialog.setWindowModality(Qt::WindowModal);
	dialog.show();
	for (int k = 0; k < 410000; k++)
	{
		dialog.setValue(k);
		QCoreApplication::processEvents();
		if (dialog.wasCanceled())
		{
			break;
		}
	}
	dialog.setValue(10000);
	this->close();
	//MainWindow* w = new MainWindow();
	//w->show();
	InitPage();
}



QWizardPage* loadfrm::createIntroPage()
{
	QWizardPage* page = new QWizardPage;
	page->setTitle((" 选择设备类型 "));

	QLabel* label = new QLabel("设备类型"
		".");
	QComboBox* cmb = new QComboBox();
	cmb->addItem(("家庭储能"));
	cmb->addItem("大型储能");
	cmb->addItem("工商业储能");
	label->setWordWrap(true);
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(label);
	layout->addWidget(cmb);
	page->setLayout(layout);
	return page;
}
    
QWizardPage* loadfrm::createRegistrationPage()
{
	
	page1 = new QWizardPage();
	page1->setTitle("选择设备型号");
	QLabel* label1 = new QLabel("设备型号"
		".");
	QComboBox* cmb = new QComboBox();
	cmb->addItem(("CA215液冷-C"));
	cmb->addItem(" CA215风冷-C");
	cmb->addItem(" CA100风冷-C");
	label1->setWordWrap(true);

	QVBoxLayout* layout1 = new QVBoxLayout;
	layout1->addWidget(label1);
	layout1->addWidget(cmb);
	page1->setLayout(layout1);
	QObject::connect(page1, SIGNAL(completeChanged()), this, SLOT(completeChanged1()));
	return page1;
}

void loadfrm::InitPage()
{
	QWizardPage* page = new QWizardPage;
	QWizard* wizard;
   wizard = new QWizard();
   wizard->addPage(createIntroPage());
   wizard->addPage(createRegistrationPage());;
   wizard->setWindowTitle("华峰储能设备向导 ");
   wizard->show();
   wizard->setButtonText(QWizard::BackButton, "返回");
   wizard->setButtonText(QWizard::NextButton, "下一页");
   wizard->setButtonText(QWizard::CancelButton, "取消");
   wizard->setButtonText(QWizard::FinishButton, "完成");
   connect(wizard->button(QWizard::FinishButton), SIGNAL(clicked()), this, SLOT(completeChanged1())); 
}

void  loadfrm::completeChanged1()
{
	MainWindow* w = new MainWindow();
	w->show();
}