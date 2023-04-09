#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QCoreApplication>
#include <QDebug>
#include <qstring.h>
#include <QMainWindow>
#include <Menu.h>
#include <vector>
#include <tuple>
#include <unistd.h>
#include <QTimer>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void consoleMenu();
    void handleButtons();
    ~MainWindow();


    //getters

    void setBattery_UI(int newVal); //done
    void setLength_UI(int newVal); //done
    void setHC_UI(int newVal); //done

    void handleCS();
    void setLow_UI(bool newVal);
    void setMed_UI(bool newVal);
    void setHigh_UI(bool newVal);

    int getHCVal();
    void setHCVal(int newVal);


signals:
    void updateUI(int csIndex);

public slots:
    void onUpdateUI(int csIndex);
    void performIteration();
    void updateBreathPacer();


private:
    Ui::MainWindow *ui;
    enum stringValue {
        up,
        down,
        left,
        right,
        ok,
        charge,
        heart,
        menu,
        power,
        back
    };
    std::map<std::string, stringValue> mapStringValues;
    void initialize();
    int csIndex = 0;
    int hcVal = 0;
    Menu test;

    //Breath pacer stuff
    QProgressBar *progressBar;
    QTimer *breathTimer;
    QTimer *uiTimer;
    int progressValue;
    bool breathVal;
    int lcount; //low count
    int mcount; //medium count
    int hcount; //high count


};
#endif // MAINWINDOW_H
