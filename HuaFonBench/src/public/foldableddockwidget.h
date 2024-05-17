#ifndef FOLDABLEDDOCKWIDGET_H
#define FOLDABLEDDOCKWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QSpacerItem>
#include <QListWidget>
#include <QWidget>
#include <QSize>

enum FoldDirection{
    FoldLeft = 0,
    FoldRight
};

class FoldabledDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit FoldabledDockWidget(QMainWindow *parent, FoldDirection direction = FoldLeft, const QString& title = "", Qt::WindowFlags flags = Qt::WindowFlags());
    ~FoldabledDockWidget();
    //设置titleBar的样式
    void setTitleBarStyleSheet(const QString& styleSheet);

signals:

public slots:

private:
    //包含 成员变量 foldContentWidget 的那个dockwidget
    QDockWidget *m_verticalFoldDockWidget;
    //该dockwidget是靠左还是靠右
  //  FoldDirection m_direction;
    //自定义dockwidget的titleBar
    QWidget *m_titleBar;
    QHBoxLayout *m_hboxLayout;
    //折叠按钮
    QPushButton *m_foldButton;
    //标题label
    QLabel *m_label;
    QSpacerItem *spaceItem;
    //折叠后显示的窗体
    VerticalFoldableWidget *foldContentWidget;
};

#endif // FOLDABLEDDOCKWIDGET_H
