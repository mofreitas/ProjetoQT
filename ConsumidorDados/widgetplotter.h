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
    void desenharGrafico(QList<QString> &lista_dados);

signals:

private:
    vector<qint64> eixoX;
    vector<int> eixoY;
    qint64 horaInicial;
    qint64 horaFinal;
};

#endif // WIDGETPLOTTER_H
