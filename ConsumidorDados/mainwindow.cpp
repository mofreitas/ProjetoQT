#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

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
            SLOT(updatelista()));
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

            }
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

}

void MainWindow::pararPlotter()
{

}

