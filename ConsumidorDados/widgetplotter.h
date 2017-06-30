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
    /**
     * @brief paintEvent Função responsável pelo desenho do plotter e pela representação dos dados
     * @param e Ponteiro para a classe QPaintEvent, responsável por acessar os métodos da mesma para realizar pinturas e desenhos no programa
     */
    void paintEvent(QPaintEvent *e);
    /**
     * @brief desenharGrafico Função responsável por normalizar os dados de acordo com o intervalo de tempo em que os mesmos foram produzidos
     * @param eX Vetor que contém os valores do eixo X recebidos pelo servidor
     * @param eY Vetor que contém os valores do eixo Y recebidos pelo servidor
     */
    void desenharGrafico(const vector<float> &eX, const vector<float> &eY);

signals:

private:
    /**
     * @brief eixoX Vetor para representar os valores do eixo X do plotter
     */
    vector<float> eixoX;
    /**
     * @brief eixoY Vetor para representar os valores do eixo Y do plotter
     */
    vector<float> eixoY;
};

#endif // WIDGETPLOTTER_H
