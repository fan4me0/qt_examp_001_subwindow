#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit mywidget( QWidget *parent = 0 );
    explicit mywidget( QString widgName = "", QWidget *parent = 0 );

    void closeEvent( QCloseEvent * event );
    void changeEvent( QEvent * event );
    ~mywidget();
signals:

public slots:
private:
    QString widgetName;
};

#endif // MYWIDGET_H
