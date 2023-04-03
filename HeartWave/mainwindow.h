#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QCoreApplication>
#include <QDebug>
#include <qstring.h>
#include <QMainWindow>
#include <Menu.h>

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

    //setters for UI values, not all of them will be useful (sessionID)
    void setBattery_UI(int newVal); //done
    //whats the difference between battery and charge
    void setCharge_UI(bool newVal);
    void setContact_UI(bool newVal);
    void setLength_UI(int newVal); //done
    void setID_UI(int newVal);
    void setHC_UI(int newVal); //done
    void setCS_UI(int newVal);
    void setCL_UI(int newVal);
    void setHRV_UI(int newVal);

    void setLow_UI(bool newVal);
    void setMed_UI(bool newVal);
    void setHigh_UI(bool newVal);

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

};
#endif // MAINWINDOW_H
