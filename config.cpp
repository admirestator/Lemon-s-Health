#include "config.h"


//#define DEBUG

Config::Config()
{
    confFile = new QFile("ConfFile");
    alertTime = 50;
    restTime = 10;
    playSound = false;
    version = QString("214");

    //write config
    writeConfig();
    readConfig();
}


Config::~Config()
{
    confFile->close();
    delete confFile;
}

void Config::readConfig()
{
#ifdef DEBUG
    qDebug() << "read config";
#endif
    confFile->open(QIODevice::ReadOnly);
    //QTextStream inconf(confFile);
    QDataStream inconf(confFile);
    inconf >> alertTime >> restTime >> playSound;

#ifdef DEBUG

    qDebug() << alertTime << restTime  << playSound;
#endif

    confFile->close();

}


void Config::writeConfig()
{
#ifdef DEBUG
    qDebug() << "write config";
#endif
    confFile->open(QIODevice::WriteOnly | QIODevice::Text);
    //QTextStream outconf(confFile);
    QDataStream outconf(confFile);
    outconf << alertTime << restTime << playSound;

    confFile->close();
}



void Config::restoreConfig()
{
#ifdef DEBUG
    qDebug() << "restore config";
#endif

    alertTime = 50; //minute
    restTime = 1;   //
    playSound = Qt::Unchecked;
    writeConfig();
}


int Config::getAlertTime()
{
    readConfig();
    return alertTime;
    return 50 * 1000;
}



short Config::getRestTime()
{
    readConfig();
    return restTime;
    return 1 * 60;
}

bool Config::getPlaySound()
{
    readConfig();
    return playSound;
    return true;
}
