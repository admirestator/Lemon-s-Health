#include "restclk.h"

//#define DEBUG


RestClk::RestClk()
{
    confRest = new Config();
    rest_timer = new QTimer(this);
    rest_timer_init();
}


RestClk::~RestClk()
{
    //线程显示退出？
    delete confRest;
    delete rest_timer;

}

void RestClk::run()
{
    rest_timer_start();

#ifdef DEBUG
    qDebug() << "rest thread run!";
    qDebug() << rest_delay;
#endif

}



void RestClk::rest_timer_init()
{
    //读取配置初始化资源等等
 //   rest_delay = 1 * 60;   //seconds
    rest_delay = confRest->getRestTime() * 60;
}


bool RestClk::rest_timer_start()
{
    rest_timer->start(rest_delay * 1000);
    return true;
}