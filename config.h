#ifndef CONFIG_H
#define CONFIG_H

#include <QFile>
#include <QDataStream>
#include <QFileInfo>
#include <QDebug>

class Config : QObject
{
    Q_OBJECT

    QFile *confFile;

public:
    Config();
    virtual ~Config();

    //default settings
    int default_alertTime;
    short default_restTime;
    unsigned short default_bg_colorR;
    unsigned short default_bg_colorG;
    unsigned short default_bg_colorB;
    unsigned short default_fg_colorR;
    unsigned short default_fg_colorG;
    unsigned short default_fg_colorB;
    bool default_start_with_system;
    bool default_playSound;
    bool default_rest_with_fullscreen;
    QString default_language;


    int alertTime;
    short restTime;
    unsigned short bg_colorR;
    unsigned short bg_colorG;
    unsigned short bg_colorB;
    unsigned short fg_colorR;
    unsigned short fg_colorG;
    unsigned short fg_colorB;
    bool start_with_system;
    bool playSound;
    bool rest_with_fullscreen;
    QString language;

    QString version;

public slots:

    void readConfig();
    void writeConfig();
    void restoreConfig();

    int getAlertTime();
    short getRestTime();
    bool getPlaySound();
};

#endif // CONFIG_H
