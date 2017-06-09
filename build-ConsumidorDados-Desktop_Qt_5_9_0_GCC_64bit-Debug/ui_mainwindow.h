/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgetplotter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *ipLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *conectarButton;
    QPushButton *desconectarButton;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *atualizarButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *timingSlider;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *comecarButton;
    QPushButton *pararButton;
    widgetPlotter *plotterWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(684, 447);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        ipLineEdit = new QLineEdit(centralWidget);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));

        verticalLayout_3->addWidget(ipLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        conectarButton = new QPushButton(centralWidget);
        conectarButton->setObjectName(QStringLiteral("conectarButton"));

        horizontalLayout->addWidget(conectarButton);

        desconectarButton = new QPushButton(centralWidget);
        desconectarButton->setObjectName(QStringLiteral("desconectarButton"));

        horizontalLayout->addWidget(desconectarButton);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        atualizarButton = new QPushButton(centralWidget);
        atualizarButton->setObjectName(QStringLiteral("atualizarButton"));

        horizontalLayout_2->addWidget(atualizarButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        timingSlider = new QSlider(centralWidget);
        timingSlider->setObjectName(QStringLiteral("timingSlider"));
        timingSlider->setMinimum(1);
        timingSlider->setMaximum(10);
        timingSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(timingSlider);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        comecarButton = new QPushButton(centralWidget);
        comecarButton->setObjectName(QStringLiteral("comecarButton"));
        comecarButton->setEnabled(true);

        horizontalLayout_3->addWidget(comecarButton);

        pararButton = new QPushButton(centralWidget);
        pararButton->setObjectName(QStringLiteral("pararButton"));
        pararButton->setEnabled(true);

        horizontalLayout_3->addWidget(pararButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        plotterWidget = new widgetPlotter(centralWidget);
        plotterWidget->setObjectName(QStringLiteral("plotterWidget"));
        listWidget->raise();

        horizontalLayout_4->addWidget(plotterWidget);

        horizontalLayout_4->setStretch(0, 30);
        horizontalLayout_4->setStretch(1, 70);

        horizontalLayout_5->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "IP do servidor:", Q_NULLPTR));
        conectarButton->setText(QApplication::translate("MainWindow", "Conectar", Q_NULLPTR));
        desconectarButton->setText(QApplication::translate("MainWindow", "Desconectar", Q_NULLPTR));
        atualizarButton->setText(QApplication::translate("MainWindow", "Atualizar", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Timing", Q_NULLPTR));
        comecarButton->setText(QApplication::translate("MainWindow", "Come\303\247ar", Q_NULLPTR));
        pararButton->setText(QApplication::translate("MainWindow", "Parar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
