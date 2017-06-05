#ifndef WIDGETPLOTTER_H
#define WIDGETPLOTTER_H

#include <QWidget>
#include <vector>
#include <QPaintEvent>
#include <QDateTime>

using namespace std;

class widgetPlotter : public QWidget
{
    Q_OBJECT
public:
    explicit widgetPlotter(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    //void converterDados(QStringList &lista_dados);
    void setReta(QDateTime dT, int y0);
    void limparVetor();

signals:

private:
    vector<int> dados;
    QDateTime horaInicial;
};

#endif // WIDGETPLOTTER_H
