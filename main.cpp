#include <QApplication>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

#include <iostream>

#include "lockclk.h"
#include "lockdlg.h"
#include "restclk.h"
#include "mainwindow.h"
#include "config.h"

using namespace std;

int main(int argc, char *argv[])
{
#ifdef Q_WS_WIN
   cout << "Win32" << endl;
#endif
#ifdef Q_WS_X11
   cout << "Linux/Unix" << endl;
#endif
#ifdef  Q_WS_MAC
   cout << "Mac OS" << endl;
#endif
    //read config
    Config confMain;
    confMain.readConfig();

    QApplication *app = new QApplication(argc, argv);
    qDebug() << "new";
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        qDebug() << "icon mgs";
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        app->quit();
    }
    QApplication::setQuitOnLastWindowClosed(false);

    //language
    QTranslator translator;
    translator.load(confMain.language);
    //translator.load("zh_CN");
        qDebug() << confMain.language;
    app->installTranslator(&translator);

    //create main window
    MainWindow *main_window = new MainWindow();

    //连接程序退出信号和槽
    QObject::connect(main_window, SIGNAL(app_quit()), app, SLOT(quit()));

    //锁屏时间间隔到开始锁屏
    if (confMain.show_startup)
        main_window->show();

    return app->exec();
}
