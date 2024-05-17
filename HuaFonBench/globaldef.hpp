#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP
#include <QString>
#include <QDebug>
#include <QFile>

#ifndef LOADQSS
#define LOADQSS(qssFile)                        \
{                                               \
    QFile file(qssFile);                        \
    file.open(QFile::ReadOnly);                 \
    if(file.isOpen())                           \
{                                           \
    qApp->setStyleSheet(file.readAll());    \
    file.close();                           \
    }                                           \
    }
#endif

#ifndef SAFEDELETE
#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
{                       \
    delete pointer;     \
    }                       \
    pointer = nullptr;          \
    }
#endif

enum WidgetTabType
{
    TAB_BAUINFO,
    TAB_BCUINFO,
    TAB_BMUINFO,
    TAB_USERMng,
    TAB_BCUMNG,
    TAB_MAX,
};
namespace GlobalSpace
{
const QString STYLE_QSS_FILE_PATH = ":/qss/HF.qss";
const QString LOGO_PATH = ":/res/image/image.png";

const int INT_DOUBLE_TIMES = 2;
const float FLOAT_DOUBLE_TIMES = 2.0f;

// 根据控件位置获取控件中心点位置
inline QPoint GetCenterPosition(const QWidget *controlWidget)
{
    QPoint centerPos;
    if(nullptr != controlWidget)
    {
        centerPos.setX(controlWidget->x() + controlWidget->width() / INT_DOUBLE_TIMES);
        centerPos.setY(controlWidget->y() + controlWidget->height() / INT_DOUBLE_TIMES);
    }
    return centerPos;
}

// 获取控件中心点位置
inline QPointF GetCenterPoint(const QWidget *controlWidget)
{
    QPointF centerPoint;
    if(nullptr != controlWidget)
    {
        centerPoint.setX(controlWidget->width() / 2.0);
        centerPoint.setY(controlWidget->height() / 2.0);
    }
    return centerPoint;
}

// 获取图片中心点位置
inline QPointF GetCenterPoint(const QImage &image)
{
    QPointF centerPoint;
    centerPoint.setX(image.width() / 2.0);
    centerPoint.setY(image.height() / 2.0);
    return centerPoint;
}
}
#endif // GLOBALDEF_HPP
