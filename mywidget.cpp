// C++ standard includes
#include <iostream>

// Qt includes
#include <QEvent>

// App includes
#include "mywidget.h"

mywidget::mywidget(QWidget *parent ) :
    QWidget(parent)
{

}

mywidget::mywidget( QString wdgName, QWidget *parent ) :
    QWidget(parent)
{
    widgetName = wdgName;
}

mywidget::~mywidget()
{

}

void mywidget::changeEvent( QEvent * event )
{
    QEvent::Type eventtype = event->type();
    switch (eventtype)
    {
        case QEvent::WindowStateChange:
        {
            Qt::WindowStates winSt = windowState();
            switch (winSt)
            {
                case Qt::WindowMaximized:
                {
                    std::cout << "Widget: " << widgetName.toStdString() << ", Qt::WindowMaximized event" << std::endl;
                    break;
                }
                case Qt::WindowMinimized:
                {
                    std::cout << "Widget: " << widgetName.toStdString() << ", Qt::WindowMinimized event" << std::endl;
                    break;
                }
                case Qt::WindowNoState:
                {
                    std::cout << "Widget: " << widgetName.toStdString() << ", Qt::WindowNoState event" << std::endl;
                    break;
                }

            }

            break;
        }
        default:
        {
            break;
        }
    }
}

void mywidget::closeEvent( QCloseEvent * event )
{
    std::cout << "Widget: " << widgetName.toStdString() << ", pressed \"x\" button" << std::endl;
}
