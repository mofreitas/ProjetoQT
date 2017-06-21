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
    void desenharGrafico(vector<float> &eX, vector<float> &eY);

signals:

private:
    vector<float> eixoX;
    vector<float> eixoY;
    float horaInicial;
    float horaFinal;
};

#endif // WIDGETPLOTTER_H
