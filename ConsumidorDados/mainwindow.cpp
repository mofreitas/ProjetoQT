#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetplotter.h"
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QList>
#include <QStringList>
#include <QListWidgetItem>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    timer = new QTimer(this);

    connect(ui->conectarButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(conectarHost()));
    connect(ui->desconectarButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(desconectarHost()));
    connect(ui->atualizarButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(updateLista()));
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(leituraDados()));
    connect(ui->comecarButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(comecarPlotter()));
    connect(ui->pararButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(pararPlotter()));
    connect(ui->listWidget,
            SIGNAL(itemSelectionChanged()),
            this,
            SLOT(ativarBotoes()));

    //TEM QUE DAR "promote to" no botao direito do widget para relaciona-lo a uma classe
}

MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}

void MainWindow::conectarHost()
{
    socket->connectToHost(ui->ipLineEdit->text(), 1234);
    if(socket->waitForConnected(3000))
    {
        qDebug() << "Conectado com sucesso";
        updateLista();
    }
    else
    {
        qDebug() << "Falha na conexão";
    }
}

void MainWindow::desconectarHost()
{
    socket->disconnectFromHost();
    qDebug() << "Desconectando...";
}

void MainWindow::updateLista()
{
    QStringList ip_lista;
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        socket->write("list");
        if(socket->waitForBytesWritten(3000))
        {
            if(socket->waitForReadyRead(3000))
            {
                while(socket->bytesAvailable())
                {
                    ip_lista.append(socket->readLine().replace("\n", "").replace("\r", ""));
                }
            }
            ui->listWidget->clear();
            ui->listWidget->addItems(ip_lista);
            qDebug() << "Lista atualizada";
        }
        else
        {
            qDebug() << "Falha ao listar dipositivos conectados";
            ui->comecarButton->setEnabled(true);
        }
    }
    else
    {
        qDebug() << "Falha na conexão";
    }
}

void MainWindow::comecarPlotter()
{ 
    timer->start(ui->timingSlider->value()*1000);
}

void MainWindow::pararPlotter()
{
    timer->stop();
    socket->readAll();
    qDebug() << "Parando de obter dados do servidor";
}

void MainWindow::leituraDados()
{
    vector<float> eixoX, eixoY;
    QList<QListWidgetItem*> itens_selecionados;
    QString comandoGet, dado;
    QStringList linha;
    QList<QString> dados;
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        if(socket->isOpen())
        {
            //Obtem lista de objetos selecionados
            itens_selecionados=ui->listWidget->selectedItems();
            //Monta o comando "get"
            comandoGet="get " + itens_selecionados.at(0)->text() + " 30";
            //Envia o comando, lembrando que write recebe ponteiro para std::string
            socket->write(comandoGet.toStdString().c_str());
            //Espera 3s para enviar comando
            if(socket->waitForBytesWritten(3000))
            {
                qDebug() << "Dados requeridos com sucesso";
                //Espera 3s para leitura de dados
                if(socket->waitForReadyRead(3000))
                {
                    while(socket->bytesAvailable()) //Repete enquanto houver dados na lista de espera
                    {
                        //qDebug() << "Lendo linha";
                        //ler a linha mandada pelo servidor, retirando os "\n" e "\n" que vem com os dados
                        dado=socket->readLine().replace("\n", "").replace("\r", "");
                        //LEr documentação QString::split -> Separa string em " " e retorna uma QStringList com as substrings;
                        linha=dado.split(" ");
                        //Verifica se tem apenas dois dados (hora e valor)
                        if(linha.size()==2)
                        {
                            dados.append(linha.at(0));
                            //Pega o segundo valor de dados
                            dados.append(linha.at(1));
                        }
                    }
                    bool ok;
                    double hI=dados[0].toDouble(&ok);
                    qDebug() << " hI"  << hI  << "ok" << ok << dados[0];
                    for(int i=0;i<dados.size();i=i+2)
                    {
                        //sem o (float), a operação pode descosiderar os flutuantes
                        eixoX.push_back((float)(dados[i].toDouble()-hI)/1000);
                        eixoY.push_back(dados[i+1].toInt());
                    }

                    for(int i=eixoX.size(); i<30;i++)
                    {
                        qDebug() << "entrou";
                        eixoX.push_back(eixoX.back()+1);
                        eixoY.push_back(0);
                    }
                   ui->plotterWidget->desenharGrafico(eixoX, eixoY);
                }
                else
                {
                    qDebug() << "Falha na leitura de dados";
                    timer->stop();
                }
            }
            else
            {
                qDebug() << "Falha na requisição de dados";
                timer->stop();
            }

        }
    }
    else
    {
        qDebug() << "Servidor desconectado, reconecte-o novamente";
    }
}

void MainWindow::ativarBotoes()
{
        ui->comecarButton->setEnabled(true);
        ui->pararButton->setEnabled(true);
}

