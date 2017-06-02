#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <vector>

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
    void conectarHost();
    void desconectarHost();
    void updateLista();
    void comecarPlotter();
    void pararPlotter();

private slots:
    void on_atualizarButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
