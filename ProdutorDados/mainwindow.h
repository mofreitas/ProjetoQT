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
    void enviarDados();
    void pararEnvio();
    void comecarEnvio();
    void conectarHost();
    void desconectarHost();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    int min, max;
    QTimer *timer;
};

#endif // MAINWINDOW_H
