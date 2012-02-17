#ifndef LOCKCLK_H
#define LOCKCLK_H

#include <QThread>
#include <QTimer>
#include "config.h"

class LockClk : public QThread
{
public:
    LockClk();
    virtual ~LockClk();

    Config *confLock;
    QTimer *lock_timer;

    //线程开始
    void run();

private:
    QThread *lock_thread;
    long lock_delay;


    //锁屏计时嚣控制
    bool lock_timer_init();
    bool lock_timer_start();
    bool lock_timer_clear();

};

#endif // LOCKCLK_H
