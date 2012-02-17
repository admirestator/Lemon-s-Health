#include "config.h"


//#define DEBUG

Config::Config()
{
    const QString FileName = "Config";
    confFile = new QFile(FileName);

    //default settings
    default_alertTime = 50;
    default_restTime = 10;
    default_start_with_system = false;
    default_playSound = false;
    default_rest_with_fullscreen = false;
    default_language = "zh_CN";

    alertTime = default_alertTime;
    restTime = default_restTime;
    start_with_system = default_start_with_system;
    playSound = default_playSound;
    rest_with_fullscreen = default_rest_with_fullscreen;
    language = default_language;

    version = QString("214");

    if (QFileInfo(FileName).exists() == false) { //first create
        language = QLocale::system().name();
        writeConfig();
    }
    else { //read exist config
        readConfig();
    }
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

    inconf >> default_language >> default_alertTime
           >> default_restTime >> default_playSound;
    inconf >> language >> alertTime >> restTime >> playSound;

#ifdef DEBUG

    qDebug() << alertTime << restTime  << playSound;
#endif

    confFile->close();

}


void Config::writeConfig()
{
//#ifdef DEBUG
    qDebug() << "write config" << alertTime << " " << restTime;
//#endif
    confFile->open(QIODevice::WriteOnly | QIODevice::Text);
    QDataStream outconf(confFile);

    outconf << default_language << default_alertTime
            << default_restTime << default_playSound;
    outconf << language << alertTime << restTime << playSound;

    confFile->close();
}



void Config::restoreConfig()
{
#ifdef DEBUG
    qDebug() << "restore config";
#endif

    alertTime = default_alertTime; //minute
    restTime = default_restTime;   //
    playSound = default_restTime;
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
