#ifndef WIDGETPLOTTER_H
#define WIDGETPLOTTER_H

#include <QWidget>
#include <vector>
#include <QPaintEvent>
#include <QList>
#include <QString>

using namespace std;

class widgetPlotter : public QWidget
{
    Q_OBJECT
public:
    explicit widgetPlotter(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void desenharGrafico(const vector<float> &eX, const vector<float> &eY);

signals:

private:
    vector<float> eixoX;
    vector<float> eixoY;
};

#endif // WIDGETPLOTTER_H
