// C++ standard includes
#include <iostream>

// App includes
#include "mywidget.h"

mywidget::mywidget(QWidget *parent) :
    QWidget(parent)
{

}

void mywidget::closeEvent( QCloseEvent * event )
{
    std::cout << "Pressed \"x\" for mywidget subwindow" << std::endl;
}
