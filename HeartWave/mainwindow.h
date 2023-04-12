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
/*
Class: Main Window
Purpose: Mainwindow for UI and handle all data collection to display

Variables:
    Ui::MainWindow *ui                                                                      -> UI Object for controlling window
    enum stringValue                                                                        -> Button String Values
    std::map<std::string, stringValue> mapStringValues;                                     -> Map for Buttons and Values
    int index = 0;                                                                          -> Iteration Index for Mock Data
    int hcVal = 0;                                                                          -> Currrent HC Val
    Menu test;                                                                              -> Menu Object
    QProgressBar *progressBar;                                                              -> Breathpacer progress bar
    QTimer *breathTimer;                                                                    -> QTimer for Breaths
    QTimer *uiTimer;                                                                        -> UI Update Timer
    QListWidget *menuUI;                                                                    -> Menu UI List
    int progressValue;                                                                      -> Prgress Bar Value
    bool breathVal;                                                                         -> Breath Value to indicate inhale/exhale
    int lcount;                                                                             -> Percent in Low Coherence
    int mcount;                                                                             -> Percent in Med Coherence
    int hcount;                                                                             -> Percent in High Coherence
    double yMax;                                                                            -> Graph Y Max
    double xMax;                                                                            -> Graph X Max

Functions:
    MainWindow(QWidget *parent = nullptr);                                                  -> MainWindow constructor
    void consoleMenu();                                                                     -> Console Output for relevant data
    void handleButtons();                                                                   -> Handle button selections
    ~MainWindow();                                                                          -> Deconstructor
    void setBattery_UI(int newVal);                                                         -> UI Element: Set Battery
    void setLength_UI(int newVal);                                                          -> UI Element: Set Length (s)
    void setHC_UI(int newVal);                                                              -> UI Element: Set HeartCo Score
    void handleCS();                                                                        -> Unused Function
    void setLow_UI(bool newVal);                                                            -> UI Element: Set Low %
    void setMed_UI(bool newVal);                                                            -> UI Element: Set Med %
    void setHigh_UI(bool newVal);                                                           -> UI Element: Set High %
    int getHCVal();                                                                         -> HCVal getter
    void setHCVal(int newVal);                                                              -> HCVal Setter
    void handleDirection(QString dir);                                                      -> Menu Direction
    void handleOk();                                                                        -> OK Press Handle
    void handleMenu();                                                                      -> Menu Press Handle
    void updateMenu(QStringList list, std::string);                                         -> Dynamic Menu Update
    void handleBack();                                                                      -> Back Press Handle
    void handleSummary(std::tuple<double,double,double,double,int,int,double> dataTuple);   -> Data Tuple for Summary
    void addCoordinates(double, double, int);                                               -> Plot Coordinates to Graph
    void displaySessionGraph(std::vector<std::pair<double, double>>);                       -> Session Graph with full coordinates
    void graphColor(int);                                                                   -> Change color of graph
    void initializeGraphs();                                                                -> Init Graph
    void performIteration();                                                                -> Perform iteration every 5 seconds for HEART Variables
    void updateBreathPacer();                                                               -> Update Breath pacer object
    void initialize();                                                                      -> Initialize Device
    void deinitialize();                                                                    -> Deinitilize Device
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void consoleMenu();
    void handleButtons();
    ~MainWindow();
    void setBattery_UI(int newVal);
    void setLength_UI(int newVal);
    void setHC_UI(int newVal);
    void handleCS();
    void setLow_UI(bool newVal);
    void setMed_UI(bool newVal);
    void setHigh_UI(bool newVal);
    int getHCVal();
    void setHCVal(int newVal);
    void handleDirection(QString dir);
    void handleOk();
    void handleMenu();
    void updateMenu(QStringList list, std::string);
    void handleBack();
    void handleSummary(std::tuple<double,double,double,double,int,int,double> dataTuple);
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
    QProgressBar *progressBar;
    QTimer *breathTimer;
    QTimer *uiTimer;
    QListWidget *menuUI;
    int progressValue;
    bool breathVal;
    int lcount;
    int mcount;
    int hcount;
    double yMax;
    double xMax;


};
#endif // MAINWINDOW_H
