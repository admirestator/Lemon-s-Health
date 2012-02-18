#include <QApplication>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

#include "lockclk.h"
#include "lockdlg.h"
#include "restclk.h"
#include "mainwindow.h"
#include "config.h"


int main(int argc, char *argv[])
{

    //read config
    Config conf_main;
    conf_main.readConfig();

    QApplication *app = new QApplication(argc, argv);
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        app->quit();
    }
    QApplication::setQuitOnLastWindowClosed(false);

    //language
    QTranslator translator;
    translator.load(conf_main.language);
            qDebug() << conf_main.language;
    app->installTranslator(&translator);

    //create main window
    MainWindow *main_window = new MainWindow();


    //连接程序退出信号和槽
    QObject::connect(main_window, SIGNAL(app_quit()), app, SLOT(quit()));

    //锁屏时间间隔到开始锁屏
    main_window->show();

    return app->exec();
}
