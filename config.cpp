#include "config.h"


//#define DEBUG

Config::Config()
{
    const QString FileName = "Config";
    confFile = new QFile(FileName);

    //default settings
    default_alertTime = 50;
    default_restTime = 3;
    default_start_with_system = false;
    default_playSound = true;
    default_show_startup = false;
    //default_show_systray = true;
    default_language = QString("zh_CN");

    alertTime = default_alertTime;
    restTime = default_restTime;


    //default background color RGB(72, 118, 255));
    //Mac蓝色 RGB(61, 108, 239)
    //Facebook蓝色 RGB(59, 89, 153)
    //YAHOO!紫色 RGB(63, OA, 6E)
    default_bg_colorR = 61;
    default_bg_colorG = 108;
    default_bg_colorB = 239;

    //default foreground color RGB(173, 255, 47)
    default_fg_colorR = 173;
    default_fg_colorG = 255;
    default_fg_colorB = 47;

    bg_colorR = default_bg_colorR;
    bg_colorG = default_bg_colorG;
    bg_colorB = default_bg_colorB;
    fg_colorR = default_fg_colorR;
    fg_colorG = default_fg_colorG;
    fg_colorB = default_fg_colorB;

    start_with_system = default_start_with_system;
    //show_systray = default_show_systray;
    playSound = default_playSound;
    show_startup = default_show_startup;
    language = default_language;

    version = QString("510");

    if (QFileInfo(FileName).exists() == false) { //first create
#ifdef DEBUG
        qDebug() << "not exists";
#endif
        language = QLocale::system().name();
        writeConfig();
    }
    else { //read exist config
#ifdef DEBUG
        qDebug() << "exists";
#endif
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
    confFile->open(QIODevice::ReadOnly |  QIODevice::Text);
    //QTextStream inconf(confFile);
    QDataStream inconf(confFile);

    inconf >> default_language >> default_alertTime
           >> default_restTime >> default_playSound >> default_show_startup
           >> language >> alertTime >> restTime >> playSound >> show_startup
           >> default_bg_colorR >> default_bg_colorG >> default_bg_colorB
           >> default_fg_colorR >> default_fg_colorG >> default_fg_colorB
           >> bg_colorR >> bg_colorG >> bg_colorB
           >> fg_colorR >> fg_colorG >> fg_colorB;

    confFile->close();

#ifdef DEBUG
    qDebug() << "read debug: "
             << default_language << default_alertTime
             << default_restTime << default_playSound << default_show_startup
             << language<< alertTime << restTime  << playSound << show_startup
             << default_bg_colorR << default_bg_colorG << default_bg_colorB
             << default_fg_colorR << default_fg_colorG << default_fg_colorB;
#endif
}


void Config::writeConfig()
{
#ifdef DEBUG
    qDebug() << "write cnf";
  //  qDebug() << "write cng"<< default_language << default_alertTime << default_restTime << default_playSound
   //          << language<< alertTime << restTime  << playSound;
#endif

    confFile->open(QIODevice::WriteOnly | QIODevice::Text);
    QDataStream outconf(confFile);

    outconf << default_language << default_alertTime
            << default_restTime << default_playSound << default_show_startup
            << language << alertTime << restTime << playSound << show_startup
            << default_bg_colorR << default_bg_colorG << default_bg_colorB
            << default_fg_colorR << default_fg_colorG << default_fg_colorB
            << bg_colorR << bg_colorG << bg_colorB
            << fg_colorR << fg_colorG << fg_colorB;
    confFile->close();

#ifdef DEBUG
        qDebug() << "write debug: "
                 << default_language << default_alertTime
                 << default_restTime << default_playSound << default_show_startup
                 << language << alertTime << restTime << playSound << show_startup
                 << default_bg_colorR << default_bg_colorG << default_bg_colorB
                 << default_fg_colorR << default_fg_colorG << default_fg_colorB
                 << bg_colorR << bg_colorG << bg_colorB
                 << fg_colorR << fg_colorG << fg_colorB;
#endif
}



void Config::restoreConfig()
{
#ifdef DEBUG
    qDebug() << "restore config";
#endif
    bg_colorR = default_bg_colorR;
    bg_colorG = default_bg_colorG;
    bg_colorB = default_bg_colorB;
    fg_colorR = default_fg_colorR;
    fg_colorG = default_fg_colorG;
    fg_colorB = default_fg_colorB;

    alertTime = default_alertTime; //minute
    restTime = default_restTime;
    playSound = default_restTime;

    writeConfig();
}


int Config::getAlertTime()
{
    readConfig();
    return alertTime;
}



short Config::getRestTime()
{
    readConfig();
    return restTime;
}

bool Config::getPlaySound()
{
    readConfig();
    return playSound;
}
