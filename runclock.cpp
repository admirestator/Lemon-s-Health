#include "runclock.h"
#include <cstdlib>

RunClock::RunClock(int arguc, char **arguv)
{
    app = new QApplication(arguc, arguv);
    main_window = new MainWindow();
    lock_dlg = new LockDlg();
    lock_clk = new LockClk();
    rest_clk = new RestClk();

}

RunClock::~RunClock()
{
    delete app;
    delete main_window;
    delete lock_dlg;
    delete lock_clk;
    delete rest_clk;

}

bool RunClock::runclock()
{
    //run register server and open timer

    //waiter for timeout then lock the screen

//    clk->lock_timer_start();

    //connect signals and slots here.
    QObject::connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_dlg, SLOT(close()));
    QObject::connect(main_window, SIGNAL(app_quit()), lock_dlg, SLOT(close()));
    QObject::connect(main_window, SIGNAL(app_quit()), app, SLOT(quit()));

    //锁屏时间间隔到开始锁屏
//    QObject::connect();
    main_window->show();
    lock_dlg->show();


    //QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();也可以
    //lock_dlg->move((desktop->width() - lock_dlg->width())/2, (desktop->height() - lock_dlg->height())/2);
//    lock_dlg->move((QApplication::desktop().width() - lock_dlg.width())/2,
 //                     (QApplication::desktop().height() - lock_dlg.height())/2);

    return app->exec();

}
