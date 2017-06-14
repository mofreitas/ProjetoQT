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
    //relacionar com eixo.size() para adaptar a quantidade de dados na tela
    //caclcualrquantos dados precisam ser pegos calculando o tamanho e arredondando para cima
    //qDebug() << QString::number(width()) << QString::number(1000.0*width()*29.0/(z*(horaInicial-horaFinal)));
    int intervalo = 1000.0*width()/(horaFinal-horaInicial);
    //qDebug() << QString::number(intervalo);
    for(int i=z;i>0;i--)
    {
       qDebug() << QString::number(/*eixoX[i]*intervalo*/width()+eixoX[i-1]*intervalo) << " "
               << QString::number(height()*(1-(eixoY[i]/100.0))) << " "
                 << QString::number(width()+eixoX[i]*intervalo) << " " << QString::number(intervalo) << QString::number(z);
                  // << QString::number(height()*k);


       pintor.drawLine(width()+eixoX[i-1]*intervalo,height()*(1-(eixoY[i-1]/100.0)), width()+eixoX[i]*intervalo, height()*(1-(eixoY[i]/100.0)));
    }
    /*for(int i=0;i<(29-z);i++)
    {
        if(!i)
        {
            pintor.drawLine(width()+eixoX[i-1]*intervalo,height()*(1-(eixoY[i-1]/100.0)), width()+eixoX[i]*intervalo, height()*(1-(eixoY[i]/100.0)));
        }
    }*/
}

void widgetPlotter::desenharGrafico(QList<QString> &lista_dados)
{
    eixoX.clear();
    eixoY.clear();

    //Tem que receber qint64 para funcionar. Não converte para long int
    horaInicial=lista_dados.at(0).toLongLong();
    //Já que lista_dados armazena x e y, respectivamente, o ultimo x é o ultimo
    //dado de lista_dados-1
    horaFinal=lista_dados.at(lista_dados.size()-2).toLongLong();
    //qDebug() << QString::number(horaFinal) << QString::number(horaInicial);

    for(int i=0;i<lista_dados.size();i=i+2)
    {
        eixoX.push_back((lista_dados.at(i).toLongLong()-horaFinal)/1000);
        eixoY.push_back(lista_dados.at(i+1).toInt());
    }

    for(int i =eixoX.size(); i<30;i++)
    {
        eixoX[i].push_back();
        eixoY[i].push_back(0);
    }

    repaint();
}




