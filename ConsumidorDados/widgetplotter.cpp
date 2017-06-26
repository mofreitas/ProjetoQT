#include "widgetplotter.h"
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QDebug>
#include <vector>
#include <QString>
#include <QDateTime>
#include <cmath>

using namespace std;


widgetPlotter::widgetPlotter(QWidget *parent) : QWidget(parent)
{

    horaFinal=2;
    horaInicial=1;
}

void widgetPlotter::paintEvent(QPaintEvent *e)
{    
    QPainter pintor(this);
    QBrush pincel(Qt::darkGray, Qt::SolidPattern);
    QPen caneta(Qt::darkGray);
    pintor.setRenderHint(QPainter::Antialiasing);

    pintor.setPen(caneta);
    pintor.setBrush(pincel);
    pintor.drawRect(0, 0, width(), height());

    caneta.setColor(Qt::green);
    caneta.setWidth(2);
    pintor.setPen(caneta);
    //numero de dados
    int z=eixoX.size()-1;

    for(int i=0;i<(z);i++)
    {
      /* qDebug() << QString::number(/*eixoX[i]*intervalo/width()-eixoX[i]) << " "
               << QString::number(height()*(1-(eixoY[i]/100.0))) << " "
                 << QString::number(width()-eixoX[i+1]) << " ";// << QString::number(intervalo);
                   << QString::number(height()*k);*/
        qDebug() << eixoX[i] << eixoX[i+1];

       pintor.drawLine(round(eixoX[i]*width()),height()*(1-(eixoY[i]/100.0)), round(eixoX[i+1]*width()), height()*(1-(eixoY[i+1]/100.0)));
    }    
}

void widgetPlotter::desenharGrafico(vector<float> &eX, vector<float> &eY)
{
    eixoX.clear();
    eixoY.clear();

    eixoY=eY;
    //Tem que receber qint64 para funcionar. Não converte para long int
    horaInicial=eX[0];
    //Já que lista_dados armazena x e y, respectivamente, o ultimo x é o ultimo
    //dado de lista_dados-1
    horaFinal=eX[29];
    qDebug() << eX[29] << eY[29];
    float intervalo=horaFinal-horaInicial;
    qDebug() << intervalo;
    for(unsigned int i =0;i<eX.size();i++)
    {
        eixoX.push_back(eX[i]/intervalo);
    }
    qDebug() << "eixos" << eixoX[29] << eixoY[29];
    repaint();
}




