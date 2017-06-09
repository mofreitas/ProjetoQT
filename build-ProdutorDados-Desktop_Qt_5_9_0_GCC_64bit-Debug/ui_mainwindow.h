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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *ipEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *conectarButton;
    QPushButton *desconectarButton;
    QGridLayout *gridLayout_2;
    QSlider *minSlider;
    QLabel *minlabel;
    QLCDNumber *minLcdNumber;
    QSlider *maxSlider;
    QLabel *maxLabel;
    QLCDNumber *maxLcdNumber;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *timingSlider;
    QLabel *timingLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *comecarButton;
    QPushButton *pararButton;
    QTextBrowser *logBrowser;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(520, 388);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ipEdit = new QLineEdit(centralWidget);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        QFont font;
        font.setPointSize(9);
        ipEdit->setFont(font);

        verticalLayout->addWidget(ipEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        conectarButton = new QPushButton(centralWidget);
        conectarButton->setObjectName(QStringLiteral("conectarButton"));
        conectarButton->setFont(font);

        horizontalLayout_2->addWidget(conectarButton);

        desconectarButton = new QPushButton(centralWidget);
        desconectarButton->setObjectName(QStringLiteral("desconectarButton"));
        desconectarButton->setFont(font);

        horizontalLayout_2->addWidget(desconectarButton);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        minSlider = new QSlider(centralWidget);
        minSlider->setObjectName(QStringLiteral("minSlider"));
        minSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(minSlider, 0, 0, 2, 1);

        minlabel = new QLabel(centralWidget);
        minlabel->setObjectName(QStringLiteral("minlabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minlabel->sizePolicy().hasHeightForWidth());
        minlabel->setSizePolicy(sizePolicy);
        minlabel->setFont(font);

        gridLayout_2->addWidget(minlabel, 0, 1, 1, 1);

        minLcdNumber = new QLCDNumber(centralWidget);
        minLcdNumber->setObjectName(QStringLiteral("minLcdNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(minLcdNumber->sizePolicy().hasHeightForWidth());
        minLcdNumber->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(minLcdNumber, 1, 1, 1, 1);

        maxSlider = new QSlider(centralWidget);
        maxSlider->setObjectName(QStringLiteral("maxSlider"));
        maxSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(maxSlider, 2, 0, 2, 1);

        maxLabel = new QLabel(centralWidget);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));
        sizePolicy.setHeightForWidth(maxLabel->sizePolicy().hasHeightForWidth());
        maxLabel->setSizePolicy(sizePolicy);
        maxLabel->setFont(font);

        gridLayout_2->addWidget(maxLabel, 2, 1, 1, 1);

        maxLcdNumber = new QLCDNumber(centralWidget);
        maxLcdNumber->setObjectName(QStringLiteral("maxLcdNumber"));
        sizePolicy1.setHeightForWidth(maxLcdNumber->sizePolicy().hasHeightForWidth());
        maxLcdNumber->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(maxLcdNumber, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        timingSlider = new QSlider(centralWidget);
        timingSlider->setObjectName(QStringLiteral("timingSlider"));
        timingSlider->setMinimum(1);
        timingSlider->setMaximum(10);
        timingSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(timingSlider);

        timingLabel = new QLabel(centralWidget);
        timingLabel->setObjectName(QStringLiteral("timingLabel"));
        timingLabel->setFont(font);

        horizontalLayout_3->addWidget(timingLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comecarButton = new QPushButton(centralWidget);
        comecarButton->setObjectName(QStringLiteral("comecarButton"));
        comecarButton->setFont(font);

        horizontalLayout->addWidget(comecarButton);

        pararButton = new QPushButton(centralWidget);
        pararButton->setObjectName(QStringLiteral("pararButton"));
        pararButton->setFont(font);

        horizontalLayout->addWidget(pararButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(2, 10);
        verticalLayout->setStretch(3, 6);
        verticalLayout->setStretch(4, 4);

        horizontalLayout_4->addLayout(verticalLayout);

        logBrowser = new QTextBrowser(centralWidget);
        logBrowser->setObjectName(QStringLiteral("logBrowser"));

        horizontalLayout_4->addWidget(logBrowser);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(minSlider, SIGNAL(sliderMoved(int)), minLcdNumber, SLOT(display(int)));
        QObject::connect(maxSlider, SIGNAL(sliderMoved(int)), maxLcdNumber, SLOT(display(int)));
        QObject::connect(timingSlider, SIGNAL(sliderMoved(int)), timingLabel, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        conectarButton->setText(QApplication::translate("MainWindow", "Conectar", Q_NULLPTR));
        desconectarButton->setText(QApplication::translate("MainWindow", "Desconectar", Q_NULLPTR));
        minlabel->setText(QApplication::translate("MainWindow", "Min", Q_NULLPTR));
        maxLabel->setText(QApplication::translate("MainWindow", "Max", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Timing(s)", Q_NULLPTR));
        timingLabel->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        comecarButton->setText(QApplication::translate("MainWindow", "Come\303\247ar", Q_NULLPTR));
        pararButton->setText(QApplication::translate("MainWindow", "Parar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
