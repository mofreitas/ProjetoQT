#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTcpSocket>
#include <QDateTime>
#include <QTimer>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    timer = new QTimer(this);

    connect(ui->comecarButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(comecarEnvio()));
   connect(ui->pararButton,
           SIGNAL(clicked(bool)),
           this,
           SLOT(pararEnvio()));
   connect(ui->conectarButton,
           SIGNAL(clicked(bool)),
           this,
           SLOT(conectarHost()));
   connect(ui->desconectarButton,
           SIGNAL(clicked(bool)),
           this,
           SLOT(desconectarHost()));
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(enviarDados()));
}

void MainWindow::conectarHost()
{
    socket->connectToHost(ui->ipEdit->text(), 1234);
    if(socket->waitForConnected(3000))
    {
        qDebug() << "Conectado com sucesso";
        ui->logBrowser->append("Conectado com sucesso");
    }
    else
    {
        qDebug() << "Falha na conexão";
        ui->logBrowser->append("Falha na conexão");
    }
}

void MainWindow::desconectarHost()
{
    socket->disconnectFromHost();
    qDebug() << "Desconectando...";
    ui->logBrowser->append("Desconectando...");
}

MainWindow::~MainWindow()
{
    delete timer;
    delete socket;
    delete ui;
}

void MainWindow::pararEnvio()
{
    timer->stop();
    qDebug() << "Envio terminado com sucesso";
    ui->logBrowser->append("Envio terminado com sucesso");
}

void MainWindow::enviarDados()
{
    QDateTime datahora;
    QString string_envio;

    if(socket->state()==QTcpSocket::ConnectedState&&max>0)
    {
        datahora=QDateTime::currentDateTime();
        string_envio="set " + QString::number(datahora.currentMSecsSinceEpoch()) + " " + QString::number(qrand()%max+min) + "\n\r";

        qDebug() << string_envio;
        socket->write(string_envio.toStdString().c_str());
        if(socket->waitForBytesWritten(3000))
        {
            ui->logBrowser->append(string_envio.replace("\n", "").replace("\r", ""));
            qDebug() << "Dados enviados com sucesso";
            ui->logBrowser->append("Dados enviados com sucesso");
        }
    }
    else
    {
        qDebug() << "Falha no envio de dados";
        ui->logBrowser->append("Falha no envio de dados");
    }
}


void MainWindow::comecarEnvio()
{
    min = ui->minSlider->value();
    max = ui->maxSlider->value()-min;
    if(max>0)
    {
        timer->start(ui->timingSlider->value()*1000);
        qDebug() << "Iniciando envio";
        ui->logBrowser->append("Iniciando envio");
    }
    else
    {
        qDebug() << "Erro na definição de Min e Max";
        ui->logBrowser->append("Erro na definição de Min e Max");
    }
}
