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


    QApplication *app = new QApplication(argc, argv);
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        app->quit();
    }

    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString(locale));
            qDebug() << locale;
    app->installTranslator(&translator);

    QApplication::setQuitOnLastWindowClosed(false);
    MainWindow *main_window = new MainWindow();


    //连接程序退出信号和槽
    QObject::connect(main_window, SIGNAL(app_quit()), app, SLOT(quit()));

    //锁屏时间间隔到开始锁屏
    main_window->show();

    return app->exec();
}
