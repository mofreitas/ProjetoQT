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
    int intervalo = round(1000.0*width()/(horaFinal-horaInicial));
    qDebug() << QString::number(intervalo);
    for(int i=0;i<(z-1);i++)
    {
       qDebug() << QString::number(/*eixoX[i]*intervalo*/width()-eixoX[i]) << " "
               << QString::number(height()*(1-(eixoY[i]/100.0))) << " "
                 << QString::number(width()-eixoX[i+1]) << " ";// << QString::number(intervalo);
                  // << QString::number(height()*k);


       pintor.drawLine(width()-eixoX[i+1]*intervalo,height()*(1-(eixoY[i+1]/100.0)), width()-eixoX[i]*intervalo, height()*(1-(eixoY[i]/100.0)));
    }
    /*for(int i=0;i<(29-z);i++)
    {
        if(!i)
        {
            pintor.drawLine(width()+eixoX[i-1]*intervalo,height()*(1-(eixoY[i-1]/100.0)), width()+eixoX[i]*intervalo, height()*(1-(eixoY[i]/100.0)));
        }
    }*/
}

void widgetPlotter::desenharGrafico(const vector<float> &eX, const vector<float> &eY)
{
    eixoX=eX;
    eixoY=eY;
    //Tem que receber qint64 para funcionar. Não converte para long int
    horaInicial=eixoX.at(0);
    //Já que lista_dados armazena x e y, respectivamente, o ultimo x é o ultimo
    //dado de lista_dados-1
    horaFinal=eixoX.at(29);
    //qDebug() << QString::number(horaFinal) << QString::number(horaInicial);
    repaint();
}




