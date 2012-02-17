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
    bool default_start_with_system;
    bool default_playSound;
    bool default_rest_with_fullscreen;
    QString default_language;


    int alertTime;
    short restTime;
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
