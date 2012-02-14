#ifndef CONFIG_H
#define CONFIG_H

#include <QFile>
#include <QDataStream>
#include <QDebug>

class Config : QObject
{
    Q_OBJECT

    QFile *confFile;

public:
    Config();
    virtual ~Config();

    int alertTime;
    short restTime;
    bool playSound;
    QString version;

    //enum CheckState { Unchecked, PartiallyChecked, Checked }
    //Qt::CheckState playSound;


public slots:

    void readConfig();
    void writeConfig();
    void restoreConfig();

    int getAlertTime();
    short getRestTime();
    bool getPlaySound();
};

#endif // CONFIG_H
