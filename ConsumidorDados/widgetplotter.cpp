#include "widgetplotter.h"
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QDebug>
#include <vector>
#include <QString>
#include <QDateTime>

using namespace std;


widgetPlotter::widgetPlotter(QWidget *parent) : QWidget(parent)
{
}

void widgetPlotter::paintEvent(QPaintEvent *e)
{    
    QPainter pintor(this);
    QBrush pincel(Qt::gray, Qt::SolidPattern);
    QPen caneta(Qt::gray);
    pintor.setRenderHint(QPainter::Antialiasing);

    pintor.setPen(caneta);
    pintor.setBrush(pincel);
    pintor.drawRect(0, 0, width(), height());

    caneta.setColor(Qt::green);
    caneta.setWidth(2);
    pintor.setPen(caneta);
    int z=eixoX.size()-1;
    int k;
    for(int i=0;i<z;i++)
    {
        k=i+1;
        qDebug() << QString::number(eixoX[i]*width()/(z-1)) << " "
               << QString::number(height()*(1-(eixoY[i]/100.0))) << " "
                 << QString::number(eixoX[k]*width()/(z-1)) << " "
                   << QString::number(height()*(1-(eixoY[k]/100)));

       pintor.drawLine(eixoX[i]*width()/(z-1),height()*(1-(eixoY[i]/100.0)), eixoX[k]*width()/(z-1), height()*(1-(eixoY[k]/100.0)));
    }
}

void widgetPlotter::desenharGrafico(QList<QString> &lista_dados)
{
    eixoX.clear();
    eixoY.clear();

    horaInicial=lista_dados.at(0).toLongLong();

    for(int i=0;i<lista_dados.size();i=i+2)
    {
        eixoX.push_back((lista_dados.at(i).toLongLong()-horaInicial)/1000);
        eixoY.push_back(lista_dados.at(i+1).toInt());
    }
    repaint();
}




