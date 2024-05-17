#include "skinclass.h"

#include <QFile>

SkinClass::SkinClass(QWidget *parent)
{
    QFile file(":/qss/HF.qss");
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    QString qss = QLatin1String(file.readAll());
    QString paletteColor = qss.mid(20, 7);
    // this->setPalette(QPalette(QColor(paletteColor)));
    this->setStyleSheet(qss);
    // this->setStyleSheet(file.readAll());
    file.close();
}
