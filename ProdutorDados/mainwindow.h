#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QString>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    /**
     * @brief enviarDados É o slot responsável pelo envio dos dados.
     *
     * É ativado com o sinal do clock (qtimer) e captura dados (com um intervalo definido pelo usuário) constantemente, até receber um sinal de parada.
     */
    void enviarDados();
    /**
     * @brief pararEnvio É o slot responsável por parar o envio dos dados.
     *
     * É ativado com o sinal de clique no botão "pararButton" e é responsável por parar o timer responsável pelo envio de sinais para o slot "enviarDados".
     */
    void pararEnvio();
    /**
     * @brief comecarEnvio É o slot responsável por começar o envio dos dados.
     *
     * É ativado com o sinal de clique no botão "comecarButton" e é responsável por iniciar o timer responsável pelo envio de sinais para o slot "enviarDados".
     */
    void comecarEnvio();
    /**
     * @brief conectarHost É o slot responsável por se conectar ao server.
     *
     * É ativado com o sinal de clique no botão "conectarButton" e estabelece conexão com um IP e uma porta informados pelo usuário.
     */
    void conectarHost();
    /**
     * @brief desconectarHost É o slot responsável por se desconectar do server.
     *
     * É ativado com o sinal de clique no botão "desconectarButton".
     */

    void desconectarHost();

private:
    /**
     * @brief ui Cria um objeto que representa a interface gráfica (tela).
     */
    Ui::MainWindow *ui;
    /**
     * @brief socket
     */
    QTcpSocket *socket;
    /**
     * @brief min É uma variável que irá representar o valor mínimo do inteiro a ser produzido
     *
     * Recebe o valor do slider "minSlider" ao começar o envio de dados.
     */
    int min
    /**
     * @brief max É uma variável que irá representar o valor máximo do inteiro a ser produzido
     *
     * Recebe o valor do slider "maxSlider" ao começar o envio de dados.
     */
    int max;
    /**
     * @brief timer
     */
    QTimer *timer;
};

#endif // MAINWINDOW_H
