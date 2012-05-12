#ifndef LOCKDLG_H
#define LOCKDLG_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QUrl>
#include <QPalette>
#include <QColor>
#include <QSound>
#include <QDesktopWidget>
#include <QTextBrowser>
#include <QKeyEvent>
#include "restclk.h"
#include "config.h"

namespace Ui {
    class LockDlg;
}

class LockDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit LockDlg(QWidget *parent = 0);
    ~LockDlg();

    RestClk *rest_clk;
    int time2Rest;

private:
    Config *confLockDlg;
    QString format_rest_time;
    QTimer *refresh_timer;    //1s刷新器
    QString sound_name;
    QSound *sound;

private slots:
    void display_rest_time();
    void display_date();
    void on_restbtn_exit_clicked();
    void keyPressEvent (QKeyEvent * event);
    void execPlaySound(QString music);

private:
    Ui::LockDlg *ui;
};

#endif // LOCKDLG_H
