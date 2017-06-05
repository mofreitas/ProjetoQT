#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetplotter.h"
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>

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
                    ip_lista.append(socket->readLine());
                }
            }
            ui->listWidget->clear();
            ui->listWidget->addItems(ip_lista);
            qDebug() << "Lista atualizada";
        }
        else
        {
            qDebug() << "Falha ao listar dipositivos conectados";
        }
    }
    else
    {
        qDebug() << "Falha na conexão";
    }
}

void MainWindow::comecarPlotter()
{
    ui->plotterWidget->limparVetor();
    QList<QListWidgetItem*> itens_selecionados;
    QString comandoGet;
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        //Perguntar ao professor (sempre necessário?)
        if(socket->isOpen())
        {
            //Obtem lista de objetos selecionados
            itens_selecionados=ui->listWidget->selectedItems();
            //Monta o comando "get"
            comandoGet="get " + itens_selecionados.at(0)->text();
            //Envia o comando, lembrando que write recebe ponteiro para std::string
            socket->write(comandoGet.toStdString().c_str());
            //Espera 3s para enviar comando
            if(socket->waitForBytesWritten(3000))
            {
                qDebug() << "Dados requeridos com sucesso";
                //https://stackoverflow.com/questions/16023533/how-to-make-sure-that-readyread-signals-from-qtcpsocket-cant-be-missed
                //waitForReadyRead() só pode ser chamado no mesmo slot do write
                if(socket->waitForReadyRead(3000))
                {
                    timer->start(ui->timingSlider->value()*250);
                }
                else
                {
                    qDebug() << "Falha na leitura de dados";
                }
            }
            else
            {
                qDebug() << "Falha na requisição de dados";
            }
        }
    }
    else
    {
        qDebug() << "Servidor desconectado, reconecte-o novamente";
    }


    /*QList<QListWidgetItem*> itens_selecionados;
    QString comandoGet, dado;
    QStringList linha, dados;
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        //Perguntar ao professor (sempre necessário?)
        if(socket->isOpen())
        {
            //Obtem lista de objetos selecionados
            itens_selecionados=ui->listWidget->selectedItems();
            //Monta o comando "get"
            comandoGet="get " + itens_selecionados.at(0)->text();
            //Envia o comando, lembrando que write recebe ponteiro para std::string
            socket->write(comandoGet.toStdString().c_str());
            //Espera 3s para enviar comando
            if(socket->waitForBytesWritten(3000))
            {
                qDebug() << "Dados requeridos com sucesso";
            }
            else
            {
                qDebug() << "Falha na requisição de dados";
            }
            //Espera 3s para leitura de dados
            if(socket->waitForReadyRead(3000))
            {
                qDebug() << "Lendo Dados";
                while(socket->bytesAvailable()) //Repete enquanto houver dados na lista de espera
                {
                    //ler a linha mandada pelo servidor, retirando os "\n" e "\n" que vem com os dados
                    dado=socket->readLine().replace("\n", "").replace("\r", "");
                    //LEr documentação QString::split -> Separa string em " " e retorna uma QStringList com as substrings;
                    linha=dado.split(" ");
                    //Verifica se tem apenas dois dados (hora e valor)
                    if(linha.size()==2)
                    {
                        //Pega o segundo valor de dados
                        dados.append(linha.at(1));
                    }
                }
            }
            else
            {
                qDebug() << "Falha na leitura de dados";
            }
            ui->plotterWidget->converterDados(dados);
            timer->start(ui->timingSlider->value());
        }
    }
    else
    {
        qDebug() << "Servidor desconectado, reconecte-o novamente";
    }*/
}

void MainWindow::pararPlotter()
{
    timer->stop();
    socket->readAll();
    qDebug() << "Parando de obter dados do servidor";
}

void MainWindow::leituraDados()
{
    QString dado;
    QStringList linha;
    QDateTime dT;
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        //Perguntar ao professor (sempre necessário?)
        if(socket->isOpen())
        {
            qDebug() << "Lendo Dados";
            if(socket->bytesAvailable()) //Repete enquanto houver dados na lista de espera
            {
                //ler a linha mandada pelo servidor, retirando os "\n" e "\n" que vem com os dados
                dado=socket->readLine().replace("\n", "").replace("\r", "");
                //LEr documentação QString::split -> Separa string em " " e retorna uma QStringList com as substrings;
                linha=dado.split(" ");
                //Verifica se tem apenas dois dados (hora e valor)
                if(linha.size()==2)
                {

                    dT = QDateTime::fromString(linha.at(0), Qt::ISODate);
                    dado=linha.at(1);
                    qDebug() << dT.toString(Qt::ISODate) << " " << QString::number(dado.toInt());

                    ui->plotterWidget->setReta(dT, dado.toInt());
                }
            }
            else
            {
                timer->stop();
                qDebug() << "Leitura finalizada";
            }
        }
    }
    else
    {
        qDebug() << "Servidor desconectado, reconecte-o novamente";
    }
}

