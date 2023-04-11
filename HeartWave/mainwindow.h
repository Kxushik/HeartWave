#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QProgressBar>
#include <QVector>


#include <Menu.h>
#include <unistd.h>

#include <vector>
#include <tuple>

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

    void handleDirection(QString dir); //good
    void handleOk();
    void handleMenu();
    void updateMenu(QStringList list, std::string);
    void handleBack();
    void handleSummary(std::tuple<double,double,double,double,int,int,double> dataTuple);

    //graph display
    void addCoordinates(double, double, int);
    void displaySessionGraph(std::vector<std::pair<double, double>>);
    void graphColor(int);
    void initializeGraphs();

signals:
    void updateUI(std::tuple<int, int, int, double, int, int, double, int, int, int, int, int> dataTuple);

public slots:
    void onUpdateUI(std::tuple<int, int, int, double, int, int, double, int, int, int, int, int> dataTuple);
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
    void deinitialize();
    int index = 0;
    int hcVal = 0;
    Menu test;

    //Breath pacer stuff
    QProgressBar *progressBar;
    QTimer *breathTimer;
    QTimer *uiTimer;
    QListWidget *menuUI;
    int progressValue;
    bool breathVal;
    int lcount; //low count
    int mcount; //medium count
    int hcount; //high count
    double yMax; //graph range
    double xMax; //graph range


};
#endif // MAINWINDOW_H
