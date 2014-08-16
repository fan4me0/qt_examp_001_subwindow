// C++ standard includes
#include <iostream>

// Qt includes
#include <qlayout.h>
#include <QPushButton>
#include <QLabel>

// App includes
#include "mainwindow.h"
#include "mywidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_infoWindow(nullptr),mywidgetclose(nullptr)
{
    QPushButton * button1 = new QPushButton( "Press to show subwindow" );
    setCentralWidget( button1 );
    connect( button1, SIGNAL( clicked() ), SLOT( actionButton1() ) );
    move( 100, 100 );
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent( QCloseEvent * )
{
    std::cout << "Pressed \"x\" for main window" << std::endl;
    m_infoWindow->close();
    delete m_infoWindow;
    mywidgetclose->close();
    delete mywidgetclose;
}

void MainWindow::actionButton1()
{
    if( m_infoWindow == nullptr ) // create only one subwindow
    {
        QVBoxLayout * vbl = new QVBoxLayout();
        vbl->addWidget( new QLabel( "Subwindow" ) );

        m_infoWindow = new QWidget();
        m_infoWindow->setLayout( vbl );
        m_infoWindow->move( 100, 300 );
        m_infoWindow->show();
    }
    if( mywidgetclose == nullptr )
    {
        QVBoxLayout * vbl = new QVBoxLayout();
        vbl->addWidget( new QLabel( "Subwindow_Close" ) );

        mywidgetclose = new mywidget();
        mywidgetclose->move( 300, 200 );
        mywidgetclose->setLayout( vbl );
        mywidgetclose->show();
    }
}
