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
      /*,unik_prt( nullptr )*/
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
    if( m_infoWindow != nullptr )
    {
        m_infoWindow->close();
        delete m_infoWindow;
    }
    if( mywidgetclose != nullptr )
    {
        mywidgetclose->close();
        delete mywidgetclose;
    }
    if( unik_prt != nullptr )
    {
        unik_prt->close();
    }

}

void MainWindow::mainCloseEvent()
{
    mywidgetclose = nullptr;
}

void MainWindow::actionButton1()
{
    if( m_infoWindow == nullptr ) // create only one subwindow
    {
        QVBoxLayout * vbl = new QVBoxLayout();
        vbl->addWidget( new QLabel( "Subwindow, if closed never shoven again!" ) );

        m_infoWindow = new QWidget();
        m_infoWindow->setLayout( vbl );
        m_infoWindow->move( 100, 300 );
        m_infoWindow->show();
    }

    if( mywidgetclose == nullptr )
    {
        QVBoxLayout * vbl = new QVBoxLayout();
        vbl->addWidget( new QLabel( "Subwindow_Close" ) );

        mywidgetclose = new mywidget("mywidgetclose");
        mywidgetclose->move( 300, 200 );
        mywidgetclose->setLayout( vbl );
        mywidgetclose->setAttribute( Qt::WA_DeleteOnClose );
        connect ( mywidgetclose, SIGNAL( destroyed() ), this, SLOT( mainCloseEvent() ) );

        mywidgetclose->show();
    }

    if( unik_prt == nullptr )
    {
        QVBoxLayout * vbl = new QVBoxLayout();
        vbl->addWidget( new QLabel( "Subwindow_UnikPtr" ) );

        unik_prt.reset( new mywidget("unik_prt") );
        unik_prt->move(500,500);
        unik_prt->setLayout( vbl );
        unik_prt->show();
    }

}
