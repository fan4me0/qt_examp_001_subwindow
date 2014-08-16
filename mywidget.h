#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit mywidget(QWidget *parent = 0);
    void closeEvent( QCloseEvent * event );
signals:

public slots:

};

#endif // MYWIDGET_H
