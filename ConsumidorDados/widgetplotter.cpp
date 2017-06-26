#include "widgetplotter.h"
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QDebug>
#include <vector>
#include <QString>
#include <cmath>

using namespace std;


widgetPlotter::widgetPlotter(QWidget *parent) : QWidget(parent)
{
}

void widgetPlotter::paintEvent(QPaintEvent *e)
{    
    //Declaração das variaveis necessárias para desenhar o plotter
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


    int n_dados=eixoX.size()-1;
    for(int i=0;i<n_dados;i++)
    {
       pintor.drawLine(eixoX[i],height()*(1-(eixoY[i]/100.0)), eixoX[i+1], height()*(1-(eixoY[i+1]/100.0)));
    }    
}

void widgetPlotter::desenharGrafico(const vector<float> &eX, const vector<float> &eY)
{
    //limpa os vetores
    eixoX.clear();
    eixoY.clear();

    eixoY=eY;

    //Intervalo é a diferença entre as horas que indicam o fim e inicio da emissão de dados
    float intervalo=eX[29]-eX[0];

    for(int i =0;i<eX.size();i++)
    {
        //Divide os dados igualmente entre o espaço disponibilizado pelo plotter
        eixoX.push_back(round(eX[i]*width()/intervalo));
    }

    repaint();
}




