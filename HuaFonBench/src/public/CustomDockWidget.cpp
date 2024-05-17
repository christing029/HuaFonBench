#include "CustomDockWidget.h"

#include <QEvent>

CustomDockWidget::CustomDockWidget(QWidget *parent) : QDockWidget(parent)
{
}

bool CustomDockWidget::event(QEvent *event)
{
    if (QEvent::ZOrderChange == event->type()) {
        if (windowFlags() & Qt::WindowMaximizeButtonHint) {
            return QDockWidget::event(event);
        } else {
            QWidget w;
            setMaximumSize(w.maximumSize());
            setWindowFlags(Qt::Dialog
                           | Qt::WindowCloseButtonHint
                           | Qt::WindowMaximizeButtonHint
                           | Qt::WindowMinimizeButtonHint);
            show();
        }
    }

    return QDockWidget::event(event);
}
