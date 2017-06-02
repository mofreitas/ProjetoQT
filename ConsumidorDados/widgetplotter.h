#ifndef WIDGETPLOTTER_H
#define WIDGETPLOTTER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class widgetPlotter : public QWidget
{
    Q_OBJECT
public:
    explicit widgetPlotter(QWidget *parent = 0);

signals:

public slots:
};

#endif // WIDGETPLOTTER_H