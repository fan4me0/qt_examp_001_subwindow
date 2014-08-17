#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// C++ std includes
#include <memory>

#include <QMainWindow>
#include "mywidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private Q_SLOTS:
    void closeEvent( QCloseEvent * ); // reimplementation of virtual
    void actionButton1();
    void mainCloseEvent();

private:
    QWidget * m_infoWindow;
    mywidget * mywidgetclose;
    std::unique_ptr < mywidget > unik_prt;
};

#endif // MAINWINDOW_H
