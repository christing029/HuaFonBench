#ifndef SKINCLASS_H
#define SKINCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class SkinClass :public QWidget
{
    Q_OBJECT
public:
    explicit SkinClass(QWidget *parent = nullptr);

};

#endif // SKINCLASS_H
