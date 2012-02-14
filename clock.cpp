#include "clock.h"



Clock::Clock()
{
    lock_thread = new QThread();
    lock_timer = new QTimer(this);
    lock_delay = 50 * 1000;    //ms for 50 minutes.

    rest_thread = new QThread();
    rest_timer = new QTimer(this);
    rest_delay = 10 * 1000;    //ms for 10 minutes.
}

Clock::~Clock()
{
    //线程显示分出？
    delete lock_timer;
    delete rest_timer;

    delete lock_thread;
    delete rest_thread;

}

void Clock::run()
{
    //计算器线程开始
    lock_timer_init();
    lock_timer_start();

}

//锁屏计时嚣控制
bool Clock::lock_timer_init()
{

}

bool Clock::lock_timer_start()
{

}

bool Clock::lock_timer_stop()
{

}

bool Clock::lock_timer_pause()
{

}

bool Clock::lock_timer_clear()
{

}

//休息定时嚣
bool Clock::rest_timer_init()
{

}

bool Clock::rest_timer_start()
{

}

bool Clock::rest_timer_stop()
{

}

bool Clock::rest_timer_pause()
{

}

bool Clock::rest_timer_clear()
{

}
