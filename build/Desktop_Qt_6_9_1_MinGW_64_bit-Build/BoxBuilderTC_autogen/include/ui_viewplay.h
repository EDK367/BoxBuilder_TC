/********************************************************************************
** Form generated from reading UI file 'viewplay.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPLAY_H
#define UI_VIEWPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewPlay
{
public:
    QGridLayout *gridLayout;
    QWidget *nav;
    QVBoxLayout *verticalLayout;
    QLabel *winLabel;
    QWidget *container;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollBoard;
    QWidget *boardW;
    QWidget *optionsGame;
    QGridLayout *gridLayout_2;
    QTableWidget *tablePlayers;
    QWidget *moreOption;
    QGridLayout *gridLayout_5;
    QPushButton *desactiveteButton;
    QPushButton *activiteButton;
    QWidget *powersW;
    QGridLayout *gridLayout_4;
    QGridLayout *containerPowerW;
    QLineEdit *yEdit;
    QLineEdit *xEdit;
    QWidget *powersW_2;
    QPushButton *usePowerB;
    QPushButton *pasePowerB;
    QPushButton *specialButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QFrame *viewPlay)
    {
        if (viewPlay->objectName().isEmpty())
            viewPlay->setObjectName("viewPlay");
        viewPlay->resize(1162, 800);
        viewPlay->setStyleSheet(QString::fromUtf8("QWidget#nav {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                     stop:0 #2a2a40, stop:1 #1a1a2a);\n"
"    border-top: 2px solid #00ff00;\n"
"    border-radius: 0;\n"
"    padding: 8px;\n"
"    margin: 0px;\n"
"}"));
        gridLayout = new QGridLayout(viewPlay);
        gridLayout->setObjectName("gridLayout");
        nav = new QWidget(viewPlay);
        nav->setObjectName("nav");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nav->sizePolicy().hasHeightForWidth());
        nav->setSizePolicy(sizePolicy);
        nav->setMinimumSize(QSize(0, 0));
        nav->setMaximumSize(QSize(16777215, 60));
        nav->setStyleSheet(QString::fromUtf8("QWidget#nav {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                     stop:0 #2a2a40, stop:1 #1a1a2a);\n"
"    border-top: 2px solid #00ff00;\n"
"    border-radius: 0;\n"
"    padding: 8px;\n"
"    margin: 0px;\n"
"}"));
        verticalLayout = new QVBoxLayout(nav);
        verticalLayout->setObjectName("verticalLayout");
        winLabel = new QLabel(nav);
        winLabel->setObjectName("winLabel");
        winLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 18px 'Segoe UI';  \n"
"    color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                           stop:0 #FFD700, stop:1 #FFA500);\n"
"    background-color: transparent;\n"
"    border-radius: 10px;\n"
"    padding: 5px; \n"
"    border: 2px solid #00ff00;;\n"
"}\n"
""));

        verticalLayout->addWidget(winLabel);


        gridLayout->addWidget(nav, 0, 0, 1, 1);

        container = new QWidget(viewPlay);
        container->setObjectName("container");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(container->sizePolicy().hasHeightForWidth());
        container->setSizePolicy(sizePolicy1);
        container->setStyleSheet(QString::fromUtf8("QWidget#container {\n"
"    background-color: #1e1e2f;\n"
"    border: 3px solid #00ff00;\n"
"    border-radius: 8px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(container);
        horizontalLayout->setObjectName("horizontalLayout");
        scrollBoard = new QScrollArea(container);
        scrollBoard->setObjectName("scrollBoard");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollBoard->sizePolicy().hasHeightForWidth());
        scrollBoard->setSizePolicy(sizePolicy2);
        scrollBoard->setMinimumSize(QSize(775, 0));
        scrollBoard->setSizeIncrement(QSize(800, 0));
        scrollBoard->setStyleSheet(QString::fromUtf8("QScrollArea#scrollBoard {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QScrollArea#scrollBoard QScrollBar:vertical {\n"
"    width: 15px;\n"
"    background: transparent;\n"
"    border-left: 1px solid #FFD700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollArea#scrollBoard QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #FFD700, stop:1 #f1c40f);\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollArea#scrollBoard QScrollBar::handle:vertical:hover {\n"
"    background: #ffea00;\n"
"}\n"
"\n"
"QScrollArea#scrollBoard QScrollBar:horizontal {\n"
"    height: 12px;\n"
"    background: transparent;\n"
"    border-top: 1px solid #FFD700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollArea#scrollBoard QScrollBar::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FFD700, stop:1 #f1c40f);\n"
"    min-width: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollArea#scroll"
                        "Board QScrollBar::handle:horizontal:hover {\n"
"    background: #ffea00;\n"
"}\n"
""));
        scrollBoard->setWidgetResizable(true);
        boardW = new QWidget();
        boardW->setObjectName("boardW");
        boardW->setGeometry(QRect(0, 0, 775, 698));
        boardW->setStyleSheet(QString::fromUtf8("QWidget#boardW {\n"
"    background-color: #0d0d18;\n"
"    border: 2px solid #ffaa00;\n"
"    border-radius: 8px;\n"
"}"));
        scrollBoard->setWidget(boardW);

        horizontalLayout->addWidget(scrollBoard);

        optionsGame = new QWidget(container);
        optionsGame->setObjectName("optionsGame");
        sizePolicy1.setHeightForWidth(optionsGame->sizePolicy().hasHeightForWidth());
        optionsGame->setSizePolicy(sizePolicy1);
        optionsGame->setMinimumSize(QSize(345, 0));
        optionsGame->setMaximumSize(QSize(16777215, 16777215));
        optionsGame->setSizeIncrement(QSize(800, 0));
        optionsGame->setBaseSize(QSize(0, 0));
        optionsGame->setStyleSheet(QString::fromUtf8("QWidget#optionsGame {\n"
"    background-color: #2a2a40;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}"));
        gridLayout_2 = new QGridLayout(optionsGame);
        gridLayout_2->setObjectName("gridLayout_2");
        tablePlayers = new QTableWidget(optionsGame);
        tablePlayers->setObjectName("tablePlayers");
        tablePlayers->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #1a1a2e, stop:1 #2c2c44);\n"
"    color: #FFD700;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #FFD700;\n"
"    font-size: 13px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #1a1a2e;\n"
"    border: 1px solid #FFD700;\n"
"}\n"
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
"    padding: 6px;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #333355;\n"
"    color: #FFD700;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 12px;\n"
"    background: #0f0f1a;\n"
""
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
"    border-top: 1px solid #FFD700;\n"
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

        gridLayout_2->addWidget(tablePlayers, 1, 0, 1, 1);

        moreOption = new QWidget(optionsGame);
        moreOption->setObjectName("moreOption");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(moreOption->sizePolicy().hasHeightForWidth());
        moreOption->setSizePolicy(sizePolicy3);
        moreOption->setStyleSheet(QString::fromUtf8("QWidget#moreOption {\n"
"    background-color: #12121f;\n"
"    border: 2px solid #ffaa00;\n"
"    border-radius: 6px;\n"
"}"));
        gridLayout_5 = new QGridLayout(moreOption);
        gridLayout_5->setObjectName("gridLayout_5");
        desactiveteButton = new QPushButton(moreOption);
        desactiveteButton->setObjectName("desactiveteButton");
        desactiveteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_5->addWidget(desactiveteButton, 1, 1, 1, 1);

        activiteButton = new QPushButton(moreOption);
        activiteButton->setObjectName("activiteButton");
        activiteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_5->addWidget(activiteButton, 0, 1, 1, 1);


        gridLayout_2->addWidget(moreOption, 3, 0, 1, 1);

        powersW = new QWidget(optionsGame);
        powersW->setObjectName("powersW");
        sizePolicy3.setHeightForWidth(powersW->sizePolicy().hasHeightForWidth());
        powersW->setSizePolicy(sizePolicy3);
        powersW->setStyleSheet(QString::fromUtf8("QWidget#powersW {\n"
"    background-color: #12121f;\n"
"    border: 2px solid #ffaa00;\n"
"    border-radius: 6px;\n"
"}"));
        gridLayout_4 = new QGridLayout(powersW);
        gridLayout_4->setObjectName("gridLayout_4");
        containerPowerW = new QGridLayout();
        containerPowerW->setObjectName("containerPowerW");
        yEdit = new QLineEdit(powersW);
        yEdit->setObjectName("yEdit");
        yEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #1E1E1E;\n"
"    color: #00FFAA;\n"
"    border: 2px solid #00FFAA;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font-size: 16px;\n"
"}\n"
""));

        containerPowerW->addWidget(yEdit, 1, 2, 1, 1);

        xEdit = new QLineEdit(powersW);
        xEdit->setObjectName("xEdit");
        xEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #1E1E1E;\n"
"    color: #00FFAA;\n"
"    border: 2px solid #00FFAA;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font-size: 16px;\n"
"}\n"
""));

        containerPowerW->addWidget(xEdit, 1, 1, 1, 1);

        powersW_2 = new QWidget(powersW);
        powersW_2->setObjectName("powersW_2");
        powersW_2->setStyleSheet(QString::fromUtf8("QWidget#moreOption {\n"
"    background-color: #12121f;\n"
"    border: 2px solid #ffaa00;\n"
"    border-radius: 6px;\n"
"}"));

        containerPowerW->addWidget(powersW_2, 3, 1, 1, 1);

        usePowerB = new QPushButton(powersW);
        usePowerB->setObjectName("usePowerB");
        usePowerB->setMinimumSize(QSize(156, 68));
        usePowerB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 12px; \n"
"    padding: 12px 16px;  \n"
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
"    padding: 11px 15px 9px 17px; \n"
"}\n"
"\n"
"Q"
                        "PushButton:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}"));

        containerPowerW->addWidget(usePowerB, 4, 1, 1, 1);

        pasePowerB = new QPushButton(powersW);
        pasePowerB->setObjectName("pasePowerB");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pasePowerB->sizePolicy().hasHeightForWidth());
        pasePowerB->setSizePolicy(sizePolicy4);
        pasePowerB->setMinimumSize(QSize(112, 59));
        pasePowerB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                      stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"    color: #FFD700;\n"
"    font-size: 14px; \n"
"    font-weight: bold;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    border-radius: 10px; \n"
"    padding: 10px 14px;  \n"
"    border: 2px solid #FFD700;\n"
"    min-width: 80px;  \n"
"    min-height: 35px;  \n"
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
"    padding: 11px 15px 9px 17px; \n"
"}\n"
"\n"
""
                        "QPushButton:disabled {\n"
"    background-color: #2c3e50;\n"
"    color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}"));

        containerPowerW->addWidget(pasePowerB, 4, 2, 1, 1);

        specialButton = new QPushButton(powersW);
        specialButton->setObjectName("specialButton");
        specialButton->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"                background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                                  stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);\n"
"                color: #FFD700;\n"
"                font-size: 12px; \n"
"                font-weight: bold;\n"
"                font-family: 'Segoe UI', sans-serif;\n"
"                border-radius:8px;\n"
"                padding: 4px 8px; \n"
"                border: 1px solid #FFD700; \n"
"                min-width: 70px;  \n"
"                min-height: 30px;  \n"
"            }\n"
"\n"
"            QPushButton:hover {\n"
"                background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                                  stop:0 #2a2a4e, stop:0.5 #1e3a5f, stop:1 #134074);\n"
"                color: #fffacd;\n"
"                border: 1px solid #fffacd;  \n"
"            }\n"
"\n"
"            QPushButton:pressed {\n"
"                background-color: "
                        "qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                                  stop:0 #FFD700, stop:1 #ffcc00);\n"
"                color: #0f3460;\n"
"                border: 1px solid #0f3460;  \n"
"                padding: 5px 7px 3px 9px; \n"
"            }\n"
"\n"
"            QPushButton:disabled {\n"
"                background-color: #2c3e50;\n"
"                color: #7f8c8d;\n"
"                border: 1px solid #7f8c8d;  \n"
"            }"));

        containerPowerW->addWidget(specialButton, 3, 2, 1, 1);

        label = new QLabel(powersW);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        containerPowerW->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(powersW);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    color: #FFFFFF;\n"
"}\n"
""));

        containerPowerW->addWidget(label_2, 0, 2, 1, 1);


        gridLayout_4->addLayout(containerPowerW, 0, 0, 1, 1);


        gridLayout_2->addWidget(powersW, 2, 0, 1, 1);


        horizontalLayout->addWidget(optionsGame);

        horizontalLayout->setStretch(0, 70);

        gridLayout->addWidget(container, 1, 0, 1, 1);


        retranslateUi(viewPlay);

        QMetaObject::connectSlotsByName(viewPlay);
    } // setupUi

    void retranslateUi(QFrame *viewPlay)
    {
        viewPlay->setWindowTitle(QCoreApplication::translate("viewPlay", "Frame", nullptr));
        winLabel->setText(QString());
        desactiveteButton->setText(QCoreApplication::translate("viewPlay", "Desactivar Clarividencia", nullptr));
        activiteButton->setText(QCoreApplication::translate("viewPlay", "Clarividencia", nullptr));
        usePowerB->setText(QCoreApplication::translate("viewPlay", "Usar Poder", nullptr));
        pasePowerB->setText(QCoreApplication::translate("viewPlay", "Pase (-1)", nullptr));
        specialButton->setText(QCoreApplication::translate("viewPlay", "Poder Especial", nullptr));
        label->setText(QCoreApplication::translate("viewPlay", "X", nullptr));
        label_2->setText(QCoreApplication::translate("viewPlay", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewPlay: public Ui_viewPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPLAY_H
