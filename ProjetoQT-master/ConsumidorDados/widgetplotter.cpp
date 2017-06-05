#include "widgetplotter.h"
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QDebug>
#include <vector>
#include <QString>

using namespace std;


widgetPlotter::widgetPlotter(QWidget *parent) : QWidget(parent)
{
    dados.resize(0);
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
    int z= dados.size()-2;

    for(int i=0;i<z;i=i+2)
    {
        pintor.drawLine(2*dados[i]*width()/z, height()*(1-(dados[i+1]/100.0)), 2*dados[i+2]*width()/z, height()*(1-(dados[i+3]/100.0)));
    }
}

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
}

void widgetPlotter::limparVetor()
{
    dados.clear();
}


/*
void widgetPlotter::converterDados(QStringList &lista_dados)
{
    for(int i=0;i<lista_dados.size();i++)
    {
        dados.push_back(lista_dados.at(i).toInt());
    }
}*/

