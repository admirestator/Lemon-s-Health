#include "lockclk.h"

LockClk::LockClk()
{
    lock_thread = new QThread();
    lock_timer = new QTimer(this);
    confLock = new Config();
}


LockClk::~LockClk()
{

    //线程显示退出？
    delete confLock;
    delete lock_timer;
    delete confLock;
}

void LockClk::run()
{
    lock_timer_init();
    lock_timer_start();
}


bool LockClk::lock_timer_init()
{
    //读取配置初始化资源等等
    lock_delay = confLock->getAlertTime() * 60 * 1000;    //ms for $confLcok minutes.
    return true;
}

bool LockClk::lock_timer_start()
{
    qDebug() << "start lock timer " << lock_delay;

    lock_timer->start(lock_delay);
    return true;
}



bool LockClk::lock_timer_clear()
{


    return true;
}
