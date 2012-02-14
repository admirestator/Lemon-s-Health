#ifndef RUNCLOCK_H
#define RUNCLOCK_H

#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include "mainwindow.h"
#include "lockdlg.h"
#include "lockclk.h"
#include "restclk.h"

class RunClock : public QWidget
{
//    Q_OBJECT

public:
    RunClock(int arguc, char **arguv);
    virtual ~RunClock();

private:
//    QApplication *app;
    MainWindow *main_window;
    LockDlg *lock_dlg;
    LockClk *lock_clk;
    RestClk *rest_clk;

public:
    bool runclock();

};

#endif // RUNCLOCK_H
