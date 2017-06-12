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
     * É conectado ao sinal "timeout()" do timer para o envio de dados para o servidor em intervalos regulares.
     */
    void enviarDados();
    /**
     * @brief pararEnvio É o slot responsável por parar o envio dos dados.
     *
     * É conectado ao sinal de clique do botão "pararButton" e é responsável por parar o timer.
     */
    void pararEnvio();
    /**
     * @brief comecarEnvio É o slot responsável por começar o envio dos dados.
     *
     * É conectado ao sinal de clique do botão "comecarButton" e é responsável por iniciar o timer.
     */
    void comecarEnvio();
    /**
     * @brief conectarHost É o slot responsável por se conectar ao server.
     *
     * É conectado com o sinal de clique no botão "conectarButton" e estabelece conexão com o server por meio do IP e uma porta informados pelo usuário.
     */
    void conectarHost();
    /**
     * @brief desconectarHost É o slot responsável por se desconectar do server.
     *
     * É conectado com o sinal de clique no botão "desconectarButton".
     */
    void desconectarHost();

private:
    /**
     * @brief ui Objeto que representa a interface gráfica (tela).
     */
    Ui::MainWindow *ui;
    /**
     * @brief socket Providencia o estabelecimento de uma conexão TCP para a transferência de dados.
     */
    QTcpSocket *socket;
    /**
     * @brief min Indica o valor mínimo do inteiro a ser enviado para o servidor.
     */
    int min;
    /**
     * @brief max Indica o valor máximo do inteiro a ser enviado para o servidor.
     */
    int max;
    /**
     * @brief timer Providencia a emissão de sinais "timeout()" em intervalos regulares.
     */
    QTimer *timer;
};

#endif // MAINWINDOW_H
