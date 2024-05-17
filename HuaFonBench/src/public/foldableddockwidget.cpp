#include "foldableddockwidget.h"

FoldabledDockWidget::FoldabledDockWidget(QMainWindow *parent, FoldDirection direction, const QString& title, Qt::WindowFlags flags)
    : QDockWidget(title, parent, flags),
      m_direction(direction)
{
    m_titleBar = new QWidget(this);
    m_hboxLayout = new QHBoxLayout;
    m_hboxLayout->setMargin(0);
    m_foldButton = new QPushButton;
    m_foldButton->setFlat(true);
    m_label = new QLabel(m_titleBar);
    m_label->setText(title);
    spaceItem = new QSpacerItem(30, 10, QSizePolicy::Expanding, QSizePolicy::Preferred);

    m_verticalFoldDockWidget = new QDockWidget;
    QWidget *emptyWidget = new QWidget(m_verticalFoldDockWidget);
    m_verticalFoldDockWidget->setTitleBarWidget(emptyWidget);
    m_verticalFoldDockWidget->hide();
    foldContentWidget = new VerticalFoldableWidget(direction, title, this);
    foldContentWidget->setControlWidget(m_verticalFoldDockWidget);
    foldContentWidget->setParternWidget(this);
    m_verticalFoldDockWidget->setWidget(foldContentWidget);
    foldContentWidget->hide();

    m_hboxLayout->addWidget(m_label);
    m_hboxLayout->addItem(spaceItem);
    m_hboxLayout->addWidget(m_foldButton);
    m_titleBar->setLayout(m_hboxLayout);
    this->setTitleBarWidget(m_titleBar);

    connect(m_foldButton, &QPushButton::clicked, this, [=](){
        this->hide();
        m_verticalFoldDockWidget->show();
        foldContentWidget->show();
    });


    //根据不同的方向，设置折叠后的dockwidget显示在mainwidnow的那个区域。此选项应该和折叠前的dockwidget设置一样的位置
    switch(m_direction)
    {
    case FoldLeft:
        m_foldButton->setIcon(QIcon(":/pic/fold_left.png"));
        parent->addDockWidget(Qt::LeftDockWidgetArea, m_verticalFoldDockWidget);
        break;
    case FoldRight:
        m_foldButton->setIcon(QIcon(":/pic/fold_right.png"));
        parent->addDockWidget(Qt::RightDockWidgetArea, m_verticalFoldDockWidget);
    }

    //测试使用
    QListWidget *listWidget = new QListWidget;
    this->setWidget(listWidget);
}

FoldabledDockWidget::~FoldabledDockWidget()
{

}

void FoldabledDockWidget::setTitleBarStyleSheet(const QString &styleSheet)
{
    m_titleBar->setStyleSheet(styleSheet);
}
