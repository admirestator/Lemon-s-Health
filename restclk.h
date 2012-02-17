#ifndef RESTCLK_H
#define RESTCLK_H

#include <QThread>
#include <QTimer>
#include <QDebug>

#include "config.h"

class RestClk : public QThread
{
public:
    RestClk();
    virtual ~RestClk();

    int rest_delay;//换算秒做计时

public:
    Config *confRest;
    QTimer *rest_timer;
    void rest_timer_init();

    long update_resttime() {
        return rest_delay--;
    }// minute

    //线程开始
    void run();

private:
    //休息定时嚣
    bool rest_timer_start();
};

#endif // REST_CLK_H
