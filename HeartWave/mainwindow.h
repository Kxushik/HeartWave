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
#include <QElapsedTimer>

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
    void updateCS(int csIndex);

public slots:
    void onUpdateCS(int csIndex);
    void performIteration();


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

};
#endif // MAINWINDOW_H
