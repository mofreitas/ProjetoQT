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
    for(int i=0;i<z;i++)
    {
        qDebug() << QString::number(eixoX[i]*width()/30) << " "
               << QString::number(height()*(1-(eixoY[i]/100.0))) << " "
                 << QString::number(eixoX[i+1]*width()/30) << " "
                   << QString::number(height()*(1-(eixoY[i+1]/100)));

       pintor.drawLine(eixoX[i]*width()/(z-1),height()*(1-(eixoY[i]/100.0)), eixoX[i+1]*width()/(z-1), height()*(1-(eixoY[i+1]/100.0)));

    }

}

void widgetPlotter::desenharGrafico(QList<QString> &lista_dados)
{
    horaInicial=lista_dados.at(0).toLongLong();

    for(int i=0;i<lista_dados.size();i=i+2)
    {
        eixoX.push_back((lista_dados.at(i).toLongLong()-horaInicial)/1000);
        eixoY.push_back(lista_dados.at(i+1).toInt());
    }
    repaint();
}

/*
void widgetPlotter::setReta(QDateTime dT, int y0)
{
    if(dados.size()==0)
    {
        horaInicial=dT;
        dados.push_back(0);
        dados.push_back(y0);
    }
    else
    {
        dados.push_back(horaInicial.msecsTo(dT)/1000);
        dados.push_back(y0);
    }

    if(dados.size()%4==0)
    {
        repaint();
    }
}*/

void widgetPlotter::limparVetor()
{
    eixoX.clear();
    eixoY.clear();
}


