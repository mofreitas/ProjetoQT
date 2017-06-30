#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
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
    /**
     * @brief updateLista É o slot responsável por atualizar a lista de IPs dos produtores de dados.
     *
     * É conectado com o sinal de clique no botão "atualizarButton".
     */
    void updateLista();
    /**
     * @brief comecarPlotter É o slot responsável por começar a plotar o gráfico dos dados fornecidos pelo cliente produtor.
     *
     * É conectado com o sinal de clique no botão "comecarButton".
     */
    void comecarPlotter();
    /**
     * @brief pararPlotter É o slot responsável por parar a plotagem de novos pontos no gráfico dos dados fornecidos pelo cliente produtor.
     *
     * É conectado com o sinal de clique no botão "pararButton".
     */
    void pararPlotter();
    /**
     * @brief leituraDados É o slot responsável pela leitura dos dados.
     *
     * É conectado ao sinal "timeout()" do timer para receber os dados fornecidos do consumidor para o servidor em intervalos regulares.
     */
    void leituraDados();

private:
    /**
     * @brief ui Objeto que representa a interface gráfica (tela).
     */
    Ui::MainWindow *ui;
    /**
     * @brief socket Providencia o estabelecimento de uma conexão TCP para o recebimento de dados.
     */
    QTcpSocket *socket;
    /**
     * @brief timer Providencia a emissão de sinais "timeout()" em intervalos regulares.
     */
    QTimer *timer;
};

#endif // MAINWINDOW_H
