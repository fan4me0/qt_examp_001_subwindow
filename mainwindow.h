#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    QWidget * m_infoWindow;
    mywidget * mywidgetclose;
};

#endif // MAINWINDOW_H
