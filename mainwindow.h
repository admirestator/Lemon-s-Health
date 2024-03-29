#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Qt>
#include <QMainWindow>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QDesktopWidget>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QDate>
#include <QSound>
#include <QDebug>
#include <QColor>
#include <QColorDialog>

#include "lockclk.h"
#include "lockdlg.h"
#include "config.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QColor color4all;

    //system tray
    QAction *runRest;
    QAction *minimizeAction;

    //QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    QMenu *trayIconMenu;
    QSystemTrayIcon *trayIcon;
    void createActions();
    void createTrayIcon();


    //configuration
    Config *confAll;
    QString old_lan;
    int old_alertTime;  //backup while changed
    short old_restTime;
    bool old_playSound;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//private:
    LockClk *lock_clk;
    LockDlg *lock_dlg;
    QTimer *refresh_timer;

signals:
    void app_quit();

public slots:
    void run_lock_dlg();
    void stop_lock_dlg();
    void update_curtime();
    void on_pushbtn_exit_clicked();
    void on_pushbtn_run_clicked();
    void pushbtn_update();
    void updateConfValue();

private slots:
    void pushbutton_defaults();
    void pushbutton_apply();
    void pushbutton_rejected();
    void checkBoxPlaySound_clicked();
    void checkBoxShowStartup_clicked();

    void radioButton_zhCN_checked();
    void radioButton_enUS_checked();
    void systrayClicked();

    void on_pushbtn_update_clicked();
    void change_bg_color();
    void change_fg_color();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
