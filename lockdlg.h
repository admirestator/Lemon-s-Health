#ifndef LOCKDLG_H
#define LOCKDLG_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QUrl>
#include <QPalette>
#include <QColor>
#include <QDesktopWidget>
#include <QTextBrowser>
#include <QKeyEvent>

#include "restclk.h"

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

private:
   QString format_rest_time;
   QTimer *refresh_timer;    //1s刷新器

private slots:
    void display_rest_time();
    void display_date();
    void on_restbtn_exit_clicked();
    void keyPressEvent (QKeyEvent * event);

private:
    Ui::LockDlg *ui;
};

#endif // LOCKDLG_H
