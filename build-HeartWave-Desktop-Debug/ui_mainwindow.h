/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonCoherenceLow;
    QPushButton *buttonCoherenceMedium;
    QPushButton *buttonCoherenceHigh;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *progressBatteryLevel;
    QLabel *textCoherence;
    QLabel *textLength;
    QLabel *textAchievement;
    QLabel *label_10;
    QWidget *widget;
    QPushButton *buttonMenu;
    QPushButton *buttonDown;
    QPushButton *buttonHeart;
    QPushButton *buttonLeft;
    QPushButton *buttonUp;
    QPushButton *buttonOk;
    QPushButton *buttonPower;
    QPushButton *buttonBack;
    QPushButton *buttonCharge;
    QPushButton *buttonRight;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1578, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(0, 0, 801, 601));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(50, 50, 50, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(208, 208, 208, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        groupBox->setPalette(palette);
        groupBox->setStyleSheet(QString::fromUtf8("background-color:rgb(50,50,50);\n"
"color:rgb(255,255,255);"));
        groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 801, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonCoherenceLow = new QPushButton(horizontalLayoutWidget);
        buttonCoherenceLow->setObjectName(QString::fromUtf8("buttonCoherenceLow"));
        buttonCoherenceLow->setEnabled(true);
        buttonCoherenceLow->setStyleSheet(QString::fromUtf8("background-color:rgb(125,0,0);\n"
"color:rgb(255,255,255);\n"
""));

        horizontalLayout->addWidget(buttonCoherenceLow);

        buttonCoherenceMedium = new QPushButton(horizontalLayoutWidget);
        buttonCoherenceMedium->setObjectName(QString::fromUtf8("buttonCoherenceMedium"));
        buttonCoherenceMedium->setStyleSheet(QString::fromUtf8("background-color:rgb(0,0,125);\n"
"color:rgb(255,255,255);"));

        horizontalLayout->addWidget(buttonCoherenceMedium);

        buttonCoherenceHigh = new QPushButton(horizontalLayoutWidget);
        buttonCoherenceHigh->setObjectName(QString::fromUtf8("buttonCoherenceHigh"));
        buttonCoherenceHigh->setEnabled(false);
        buttonCoherenceHigh->setStyleSheet(QString::fromUtf8("background-color:rgb(0,125,0);\n"
"color:rgb(255,255,255);"));

        horizontalLayout->addWidget(buttonCoherenceHigh);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 60, 801, 291));
        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 20, 801, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        horizontalLayoutWidget_3 = new QWidget(groupBox_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 50, 801, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        progressBatteryLevel = new QProgressBar(horizontalLayoutWidget_3);
        progressBatteryLevel->setObjectName(QString::fromUtf8("progressBatteryLevel"));
        progressBatteryLevel->setMaximumSize(QSize(155, 16777215));
        progressBatteryLevel->setValue(100);

        horizontalLayout_3->addWidget(progressBatteryLevel);

        textCoherence = new QLabel(horizontalLayoutWidget_3);
        textCoherence->setObjectName(QString::fromUtf8("textCoherence"));
        textCoherence->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(textCoherence);

        textLength = new QLabel(horizontalLayoutWidget_3);
        textLength->setObjectName(QString::fromUtf8("textLength"));
        textLength->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(textLength);

        textAchievement = new QLabel(horizontalLayoutWidget_3);
        textAchievement->setObjectName(QString::fromUtf8("textAchievement"));
        textAchievement->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(textAchievement);

        label_10 = new QLabel(horizontalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 350, 801, 251));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(50,50,50)"));
        buttonMenu = new QPushButton(widget);
        buttonMenu->setObjectName(QString::fromUtf8("buttonMenu"));
        buttonMenu->setGeometry(QRect(740, 10, 40, 40));
        buttonMenu->setMinimumSize(QSize(40, 40));
        buttonMenu->setMaximumSize(QSize(40, 40));
        buttonMenu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonMenu.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonDown = new QPushButton(widget);
        buttonDown->setObjectName(QString::fromUtf8("buttonDown"));
        buttonDown->setGeometry(QRect(390, 110, 40, 40));
        buttonDown->setMinimumSize(QSize(40, 40));
        buttonDown->setMaximumSize(QSize(40, 40));
        buttonDown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonDown.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonHeart = new QPushButton(widget);
        buttonHeart->setObjectName(QString::fromUtf8("buttonHeart"));
        buttonHeart->setGeometry(QRect(120, 20, 40, 40));
        buttonHeart->setMinimumSize(QSize(40, 40));
        buttonHeart->setMaximumSize(QSize(40, 40));
        buttonHeart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/iconHeartRate.svg);\n"
"background-color: #565556;\n"
"border-radius: 20px;\n"
"}"));
        buttonLeft = new QPushButton(widget);
        buttonLeft->setObjectName(QString::fromUtf8("buttonLeft"));
        buttonLeft->setGeometry(QRect(330, 60, 40, 40));
        buttonLeft->setMinimumSize(QSize(40, 40));
        buttonLeft->setMaximumSize(QSize(40, 40));
        buttonLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonLeft.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonUp = new QPushButton(widget);
        buttonUp->setObjectName(QString::fromUtf8("buttonUp"));
        buttonUp->setGeometry(QRect(390, 10, 40, 40));
        buttonUp->setMinimumSize(QSize(40, 40));
        buttonUp->setMaximumSize(QSize(40, 40));
        buttonUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonUp.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonOk = new QPushButton(widget);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setGeometry(QRect(390, 60, 40, 40));
        buttonOk->setMinimumSize(QSize(40, 40));
        buttonOk->setMaximumSize(QSize(40, 40));
        buttonOk->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonOk.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonPower = new QPushButton(widget);
        buttonPower->setObjectName(QString::fromUtf8("buttonPower"));
        buttonPower->setGeometry(QRect(390, 190, 40, 40));
        buttonPower->setMinimumSize(QSize(40, 40));
        buttonPower->setMaximumSize(QSize(40, 40));
        buttonPower->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonPower.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonBack = new QPushButton(widget);
        buttonBack->setObjectName(QString::fromUtf8("buttonBack"));
        buttonBack->setGeometry(QRect(20, 10, 40, 40));
        buttonBack->setMinimumSize(QSize(40, 40));
        buttonBack->setMaximumSize(QSize(40, 40));
        buttonBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonBack.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonCharge = new QPushButton(widget);
        buttonCharge->setObjectName(QString::fromUtf8("buttonCharge"));
        buttonCharge->setGeometry(QRect(10, 200, 40, 40));
        buttonCharge->setMinimumSize(QSize(40, 40));
        buttonCharge->setMaximumSize(QSize(40, 40));
        buttonCharge->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonCharge.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        buttonRight = new QPushButton(widget);
        buttonRight->setObjectName(QString::fromUtf8("buttonRight"));
        buttonRight->setGeometry(QRect(450, 60, 40, 40));
        buttonRight->setMinimumSize(QSize(40, 40));
        buttonRight->setMaximumSize(QSize(40, 40));
        buttonRight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/buttonRight.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "HeartWave", nullptr));
        buttonCoherenceLow->setText(QApplication::translate("MainWindow", "Low", nullptr));
        buttonCoherenceMedium->setText(QApplication::translate("MainWindow", "Medium", nullptr));
        buttonCoherenceHigh->setText(QApplication::translate("MainWindow", "High", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Battery:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Coherence", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Length", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Achievement", nullptr));
        label_5->setText(QString());
        textCoherence->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        textLength->setText(QApplication::translate("MainWindow", "00.00", nullptr));
        textAchievement->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        label_10->setText(QString());
        buttonMenu->setText(QString());
        buttonDown->setText(QString());
        buttonHeart->setText(QString());
        buttonLeft->setText(QString());
        buttonUp->setText(QString());
        buttonOk->setText(QString());
        buttonPower->setText(QString());
        buttonBack->setText(QString());
        buttonCharge->setText(QString());
        buttonRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
