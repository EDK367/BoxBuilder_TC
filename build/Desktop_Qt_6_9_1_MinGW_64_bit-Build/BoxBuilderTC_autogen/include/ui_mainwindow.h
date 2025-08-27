/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QWidget *container;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *panelW;
    QWidget *playW;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *forL;
    QLineEdit *rowSize;
    QLabel *columsL;
    QLabel *sizeL;
    QLineEdit *columnSize;
    QLabel *boardSize;
    QLabel *rowsL;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QLabel *numberPlayersL;
    QPushButton *playersB;
    QPushButton *play;
    QWidget *powersW;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *powerTable;
    QWidget *infoW;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QWidget *mainW;
    QVBoxLayout *verticalLayout_2;
    QLabel *box;
    QLabel *frase;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *optionsW;
    QVBoxLayout *verticalLayout;
    QPushButton *mainB;
    QPushButton *playB;
    QPushButton *powerB;
    QPushButton *infoB;
    QWidget *nav;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1160, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        container = new QWidget(centralwidget);
        container->setObjectName("container");
        container->setStyleSheet(QString::fromUtf8("QWidget#container {\n"
"    background-color: #1e1e2f;\n"
"    border: 3px solid #00ff00;\n"
"    border-radius: 8px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(container);
        horizontalLayout->setObjectName("horizontalLayout");
        panelW = new QStackedWidget(container);
        panelW->setObjectName("panelW");
        panelW->setStyleSheet(QString::fromUtf8("QWidget#panelW {\n"
"    background-color: #2a2a40;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}"));
        playW = new QWidget();
        playW->setObjectName("playW");
        playW->setStyleSheet(QString::fromUtf8("QWidget#playW {\n"
"    background-color: #0d0d18;\n"
"    border: 2px solid #ffaa00;\n"
"    border-radius: 8px;\n"
"}"));
        gridLayout = new QGridLayout(playW);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMinAndMaxSize);
        forL = new QLabel(playW);
        forL->setObjectName("forL");
        forL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        gridLayout_2->addWidget(forL, 6, 1, 1, 1);

        rowSize = new QLineEdit(playW);
        rowSize->setObjectName("rowSize");
        rowSize->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #1E1E1E;\n"
"    color: #00FFAA;\n"
"    border: 2px solid #00FFAA;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font-size: 16px;\n"
"}\n"
""));

        gridLayout_2->addWidget(rowSize, 6, 0, 1, 1);

        columsL = new QLabel(playW);
        columsL->setObjectName("columsL");
        columsL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        gridLayout_2->addWidget(columsL, 5, 2, 1, 1);

        sizeL = new QLabel(playW);
        sizeL->setObjectName("sizeL");
        sizeL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        gridLayout_2->addWidget(sizeL, 3, 0, 1, 2);

        columnSize = new QLineEdit(playW);
        columnSize->setObjectName("columnSize");
        columnSize->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #1E1E1E;\n"
"    color: #00FFAA;\n"
"    border: 2px solid #00FFAA;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font-size: 16px;\n"
"}\n"
""));

        gridLayout_2->addWidget(columnSize, 6, 2, 1, 1);

        boardSize = new QLabel(playW);
        boardSize->setObjectName("boardSize");
        boardSize->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: rgb(255, 0, 0);\n"
"}\n"
""));

        gridLayout_2->addWidget(boardSize, 3, 2, 1, 1);

        rowsL = new QLabel(playW);
        rowsL->setObjectName("rowsL");
        rowsL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        gridLayout_2->addWidget(rowsL, 5, 0, 1, 1);

        tableWidget = new QTableWidget(playW);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #1a1a2e, stop:1 #2c2c44);\n"
"    color: #FFD700;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #FFD700;\n"
"    font-size: 13px;\n"
"    text-align: center;\n"
"    min-height: 35px; \n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #1a1a2e, stop:1 #2c2c44);\n"
"    color: #FFD700;\n"
"    border: 2px solid #FFD700;\n"
"    border-radius: 6px;\n"
"    padding: 4px 12px;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2c2c44, stop:1 #3a3a5a);\n"
"    color: #fff700;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FFD700;\n"
"    color: #1a1a2e;\n"
"}\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #1a1a2e;\n"
"    border: 1px solid #FFD700;\n"
"}\n"
""
                        "\n"
"QTableWidget {\n"
"    border: 2px solid #FFD700;\n"
"    border-radius: 8px;\n"
"    gridline-color: #FFD700;\n"
"    background-color: #0f0f1a;\n"
"    alternate-background-color: #1a1a2e;\n"
"    selection-background-color: #FFD700;\n"
"    selection-color: black;\n"
"    color: #ecf0f1;\n"
"    font-size: 12px;\n"
"    outline: 0;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 1px;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #333355;\n"
"    color: #FFD700;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 15px;\n"
"    background: #0f0f1a;\n"
"    border-left: 1px solid #FFD700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #FFD700, stop:1 #f1c40f);\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #ffea00;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    height: 12px;\n"
"    background: #0f0f1a;\n"
"   "
                        " border-top: 1px solid #FFD700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FFD700, stop:1 #f1c40f);\n"
"    min-width: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #ffea00;\n"
"}\n"
""));

        gridLayout_2->addWidget(tableWidget, 2, 0, 1, 3);

        pushButton = new QPushButton(playW);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px;\n"
"    padding: 14px 28px;\n"
"    border: 2px solid #FFD700;\n"
"    min-width: 120px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"    color: #fffacd;\n"
"    border: 2px solid #fffacd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #FFD700, stop:1 #ffcc00);\n"
"    color: #0f3460;\n"
"    border: 2px solid #0f3460;\n"
"    padding: 15px 27px 13px 29px;\n"
"}\n"
"\n"
"QPush"
                        "Button:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
""));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        numberPlayersL = new QLabel(playW);
        numberPlayersL->setObjectName("numberPlayersL");
        numberPlayersL->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        gridLayout_2->addWidget(numberPlayersL, 0, 0, 1, 3);

        playersB = new QPushButton(playW);
        playersB->setObjectName("playersB");
        playersB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px;\n"
"    padding: 14px 28px;\n"
"    border: 2px solid #FFD700;\n"
"    min-width: 120px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"    color: #fffacd;\n"
"    border: 2px solid #fffacd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #FFD700, stop:1 #ffcc00);\n"
"    color: #0f3460;\n"
"    border: 2px solid #0f3460;\n"
"    padding: 15px 27px 13px 29px;\n"
"}\n"
"\n"
"QPush"
                        "Button:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
""));

        gridLayout_2->addWidget(playersB, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        play = new QPushButton(playW);
        play->setObjectName("play");
        play->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px;\n"
"    padding: 14px 28px;\n"
"    border: 2px solid #FFD700;\n"
"    min-width: 120px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"    color: #fffacd;\n"
"    border: 2px solid #fffacd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #FFD700, stop:1 #ffcc00);\n"
"    color: #0f3460;\n"
"    border: 2px solid #0f3460;\n"
"    padding: 15px 27px 13px 29px;\n"
"}\n"
"\n"
"QPush"
                        "Button:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
""));

        gridLayout->addWidget(play, 1, 0, 1, 1);

        panelW->addWidget(playW);
        powersW = new QWidget();
        powersW->setObjectName("powersW");
        powersW->setStyleSheet(QString::fromUtf8("QWidget#optionsGame {\n"
"    background-color: #2a2a40;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(powersW);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        powerTable = new QTableWidget(powersW);
        powerTable->setObjectName("powerTable");
        powerTable->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #1a1a2e, stop:1 #2c2c44);\n"
"    color: #FFD700;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #FFD700;\n"
"    font-size: 13px;\n"
"    text-align: center;\n"
"    min-height: 35px; \n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #1a1a2e, stop:1 #2c2c44);\n"
"    color: #FFD700;\n"
"    border: 2px solid #FFD700;\n"
"    border-radius: 6px;\n"
"    padding: 4px 12px;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2c2c44, stop:1 #3a3a5a);\n"
"    color: #fff700;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FFD700;\n"
"    color: #1a1a2e;\n"
"}\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #1a1a2e;\n"
"    border: 1px solid #FFD700;\n"
"}\n"
""
                        "\n"
"QTableWidget {\n"
"    border: 2px solid #FFD700;\n"
"    border-radius: 8px;\n"
"    gridline-color: #FFD700;\n"
"    background-color: #0f0f1a;\n"
"    alternate-background-color: #1a1a2e;\n"
"    selection-background-color: #FFD700;\n"
"    selection-color: black;\n"
"    color: #ecf0f1;\n"
"    font-size: 12px;\n"
"    outline: 0;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 1px;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #333355;\n"
"    color: #FFD700;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 15px;\n"
"    background: #0f0f1a;\n"
"    border-left: 1px solid #FFD700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #FFD700, stop:1 #f1c40f);\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #ffea00;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    height: 12px;\n"
"    background: #0f0f1a;\n"
"   "
                        " border-top: 1px solid #FFD700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FFD700, stop:1 #f1c40f);\n"
"    min-width: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #ffea00;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(powerTable);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        panelW->addWidget(powersW);
        infoW = new QWidget();
        infoW->setObjectName("infoW");
        infoW->setStyleSheet(QString::fromUtf8("QWidget#optionsGame {\n"
"    background-color: #2a2a40;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(infoW);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(infoW);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFD700;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 2px;\n"
"}"));

        verticalLayout_3->addWidget(label);

        panelW->addWidget(infoW);
        mainW = new QWidget();
        mainW->setObjectName("mainW");
        mainW->setStyleSheet(QString::fromUtf8("QWidget#optionsGame {\n"
"    background-color: #2a2a40;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(mainW);
        verticalLayout_2->setObjectName("verticalLayout_2");
        box = new QLabel(mainW);
        box->setObjectName("box");
        box->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00ff00;\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 2px;\n"
"}"));

        verticalLayout_2->addWidget(box);

        frase = new QLabel(mainW);
        frase->setObjectName("frase");
        frase->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        verticalLayout_2->addWidget(frase);

        label_3 = new QLabel(mainW);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(mainW);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(mainW);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        panelW->addWidget(mainW);

        horizontalLayout->addWidget(panelW);

        optionsW = new QWidget(container);
        optionsW->setObjectName("optionsW");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(optionsW->sizePolicy().hasHeightForWidth());
        optionsW->setSizePolicy(sizePolicy);
        optionsW->setMinimumSize(QSize(0, 0));
        optionsW->setStyleSheet(QString::fromUtf8("QWidget#optionsGame {\n"
"    background-color: #2a2a40;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}"));
        verticalLayout = new QVBoxLayout(optionsW);
        verticalLayout->setObjectName("verticalLayout");
        mainB = new QPushButton(optionsW);
        mainB->setObjectName("mainB");
        mainB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px;\n"
"    padding: 14px 28px;\n"
"    border: 2px solid #FFD700;\n"
"    min-width: 120px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"    color: #fffacd;\n"
"    border: 2px solid #fffacd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #FFD700, stop:1 #ffcc00);\n"
"    color: #0f3460;\n"
"    border: 2px solid #0f3460;\n"
"    padding: 15px 27px 13px 29px;\n"
"}\n"
"\n"
"QPush"
                        "Button:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
""));

        verticalLayout->addWidget(mainB);

        playB = new QPushButton(optionsW);
        playB->setObjectName("playB");
        playB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px;\n"
"    padding: 14px 28px;\n"
"    border: 2px solid #FFD700;\n"
"    min-width: 120px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"    color: #fffacd;\n"
"    border: 2px solid #fffacd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #FFD700, stop:1 #ffcc00);\n"
"    color: #0f3460;\n"
"    border: 2px solid #0f3460;\n"
"    padding: 15px 27px 13px 29px;\n"
"}\n"
"\n"
"QPush"
                        "Button:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
""));

        verticalLayout->addWidget(playB);

        powerB = new QPushButton(optionsW);
        powerB->setObjectName("powerB");
        powerB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px;\n"
"    padding: 14px 28px;\n"
"    border: 2px solid #FFD700;\n"
"    min-width: 120px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"    color: #fffacd;\n"
"    border: 2px solid #fffacd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #FFD700, stop:1 #ffcc00);\n"
"    color: #0f3460;\n"
"    border: 2px solid #0f3460;\n"
"    padding: 15px 27px 13px 29px;\n"
"}\n"
"\n"
"QPush"
                        "Button:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
""));

        verticalLayout->addWidget(powerB);

        infoB = new QPushButton(optionsW);
        infoB->setObjectName("infoB");
        infoB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px;\n"
"    padding: 14px 28px;\n"
"    border: 2px solid #FFD700;\n"
"    min-width: 120px;\n"
"    min-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"    color: #fffacd;\n"
"    border: 2px solid #fffacd;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #FFD700, stop:1 #ffcc00);\n"
"    color: #0f3460;\n"
"    border: 2px solid #0f3460;\n"
"    padding: 15px 27px 13px 29px;\n"
"}\n"
"\n"
"QPush"
                        "Button:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
""));

        verticalLayout->addWidget(infoB);


        horizontalLayout->addWidget(optionsW);


        gridLayout_3->addWidget(container, 1, 0, 1, 1);

        nav = new QWidget(centralwidget);
        nav->setObjectName("nav");
        nav->setMinimumSize(QSize(0, 60));
        nav->setMaximumSize(QSize(16777215, 60));
        nav->setStyleSheet(QString::fromUtf8("QWidget#nav {\n"
"    background-color: #2a2a40;\n"
"    border-top: 2px solid #00ff00;\n"
"    border-radius: 0;\n"
"}"));

        gridLayout_3->addWidget(nav, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1160, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        panelW->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        forL->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        columsL->setText(QCoreApplication::translate("MainWindow", "Columnas", nullptr));
        sizeL->setText(QCoreApplication::translate("MainWindow", "Tama\303\261o de Tablero:", nullptr));
        boardSize->setText(QString());
        rowsL->setText(QCoreApplication::translate("MainWindow", "Filas", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Partida Rapida", nullptr));
        numberPlayersL->setText(QCoreApplication::translate("MainWindow", "Cantidad De Jugadores:", nullptr));
        playersB->setText(QCoreApplication::translate("MainWindow", "Ingresar Jugadores", nullptr));
        play->setText(QCoreApplication::translate("MainWindow", "Jugar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\n"
"\360\237\223\226 Descripci\303\263n\n"
"BoxBuilderTC es una versi\303\263n avanzada \n"
"de Dots and Boxes, \n"
"donde la estrategia y los poderes\n"
" especiales hacen\n"
" cada partida \303\272nica.\n"
"\360\237\216\257 Objetivo\n"
"Cerrar m\303\241s cuadrados que tus rivales y usar\n"
" los poderes sabiamente para ganar.\n"
"\360\237\233\240\357\270\217 Estructuras de Datos Utilizadas\n"
"Listas enlazadas \342\206\222 representaci\303\263n\n"
" del tablero\n"
"Pilas \342\206\222 administraci\303\263n de poderes especiales \n"
"Colas \342\206\222 gesti\303\263n de turnos de jugadores\n"
"\360\237\216\250 Personalizaci\303\263n del Juego\n"
"Selecci\303\263n del tama\303\261o del tablero\n"
"Nombres personalizados para los jugadores\n"
"Colores \303\272nicos para cada jugador\n"
"\360\237\217\206 Condiciones de Victoria\n"
"El ganador se determina evaluando:\n"
"M\303\241s puntos acumulados\n"
"Mayor cantidad de cuadrados cerrados\n"
"M\303\241s filas y columnas completas\n"
"Uso estrat\303\251gico y efe"
                        "ctivo de los poderes\n"
"\360\237\221\250\342\200\215\360\237\222\273 Desarrollado por: Erikson Orozco (EDK367)\n"
"", nullptr));
        box->setText(QCoreApplication::translate("MainWindow", "BoxBuilderTC", nullptr));
        frase->setText(QCoreApplication::translate("MainWindow", "\302\277Qui\303\251n ser\303\241 el rey del tablero hoy?", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        mainB->setText(QCoreApplication::translate("MainWindow", "Pantalla Principal", nullptr));
        playB->setText(QCoreApplication::translate("MainWindow", "Jugar Nueva Partida", nullptr));
        powerB->setText(QCoreApplication::translate("MainWindow", "Poderes", nullptr));
        infoB->setText(QCoreApplication::translate("MainWindow", "Informaci\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
