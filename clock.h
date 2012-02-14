#ifndef CLOCK_H
#define CLOCK_H


//#include <QWidget>
#include <QTimer>
#include <QThread>

class Clock : public QThread
{
    //对于具有signal，slot机制的类需要声明
    Q_OBJECT

private:
    QThread *lock_thread;
    QTimer *lock_timer;
    long lock_delay;

    QThread *rest_thread;
    QTimer *rest_timer;
    long rest_delay;


public:
    Clock();
    virtual ~Clock();

    //线程控制
    void lock_run(); //在QThread类中已有的虚函数
    void lock_run(); //在QThread类中已有的虚函数
   // void foo();

    //锁屏计时嚣控制
    bool lock_timer_init();
    bool lock_timer_start();
    bool lock_timer_stop();
    bool lock_timer_pause();
    bool lock_timer_clear();

   //休息定时嚣
    bool rest_timer_init();
    bool rest_timer_start();
    bool rest_timer_stop();
    bool rest_timer_pause();
    bool rest_timer_clear();

};

#endif // CLOCK_H
