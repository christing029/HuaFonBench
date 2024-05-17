#ifndef CUSTOMDOCKWIDGET_H
#define CUSTOMDOCKWIDGET_H

#include <QDockWidget>

class CustomDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit CustomDockWidget(QWidget *parent = nullptr);

signals:

public slots:

    // QObject interface
public:
    bool event(QEvent *event) override;
};

#endif // CUSTOMDOCKWIDGET_H
