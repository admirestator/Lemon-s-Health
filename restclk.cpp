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
}


void RestClk::rest_timer_init()
{
    //读取配置初始化资源等 //
    rest_delay = 1 * 60;   //seconds
    confRest->readConfig();
    rest_delay = confRest->getRestTime() * 60;
}


bool RestClk::rest_timer_start()
{
    qDebug() << rest_delay << " rest_dealy *1000";
    rest_timer->start(rest_delay * 1000);

    return true;
}
