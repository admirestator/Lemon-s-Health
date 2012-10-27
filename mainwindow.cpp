#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"


//#define DEBUG

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //system tray and menu
    createActions();
    createTrayIcon();

    //timer for lock screen
    lock_clk = new LockClk();
    lock_clk->run();

    //refresh timer
    refresh_timer = new QTimer();
    refresh_timer->start(1000);

    //config operations
    confAll = new Config();
    confAll->readConfig();
    old_alertTime = confAll->alertTime;  //backup while changed
    old_restTime = confAll->restTime;
    old_playSound = confAll->playSound;

    lock_clk->time2Rest = confAll->alertTime * 60; //convert seconds

    //create ui
    ui->setupUi(this);

    //main menu
    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));
    //ui->labelTime2Rest->setText(QString::number(confAll->alertTime, 10));

    //config menu
    ui->spinBoxAlertTime->setValue(confAll->alertTime);
    ui->spinBoxRestTime->setValue(confAll->restTime);
    if (!confAll->start_with_system) {
        ui->checkBox_startup->setCheckState(Qt::Checked);
    }
    else {
        ui->checkBox_startup->setCheckState(Qt::Unchecked);
    }

    if (confAll->playSound) {
        ui->checkBoxPlaySound->setCheckState(Qt::Checked);
    }
    else {
        ui->checkBoxPlaySound->setCheckState(Qt::Unchecked);
    }

    if (confAll->show_startup) {
        ui->checkBoxShowStartup->setCheckState(Qt::Checked);
    }
    else {
        ui->checkBoxShowStartup->setCheckState(Qt::Unchecked);
    }

    if (confAll->language == QString("zh_CN")) {
        ui->radioButton_zhCN->setChecked(true);
        ui->radioButton_enUS->setChecked(false);
    }
    else {
        ui->radioButton_zhCN->setChecked(false);
        ui->radioButton_enUS->setChecked(true);
    }


    //background color control
    ui->pushButtonChangeBGColor->setPalette(
                QPalette(QColor(confAll->bg_colorR,
                                confAll->bg_colorG, confAll->bg_colorB)));
    //foreground color control
    ui->pushButtonChangeFGColor->setPalette(
                QPalette(QColor(confAll->fg_colorR,
                                confAll->fg_colorG, confAll->fg_colorB)));

    //Version
    ui->labelVersionNum->setText(confAll->version);

    //居中显示
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);


//-----------------------------slot-----------------------------------------
    //update refresh time
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(update_curtime()));

    //add lock_clk timer
    connect(lock_clk->lock_timer, SIGNAL(timeout()), this, SLOT(run_lock_dlg()));
    //connect(lock_clk->lock_timer, SIGNAL(timeout()), lock_clk->lock_timer, SLOT(stop()));
    connect(lock_clk->lock_timer, SIGNAL(timeout()), this, SLOT(stop_lock_dlg()));

    //time setting
    connect(ui->spinBoxAlertTime, SIGNAL(valueChanged(int)), this, SLOT(updateConfValue()));
    connect(ui->spinBoxRestTime, SIGNAL(valueChanged(int)), this, SLOT(updateConfValue()));
    connect(ui->checkBoxPlaySound, SIGNAL(stateChanged(int)),
            this, SLOT(checkBoxPlaySound_clicked()));

    //show on startup
    connect(ui->checkBoxShowStartup, SIGNAL(stateChanged(int)),
            this, SLOT(checkBoxShowStartup_clicked()));

    //language
    connect(ui->radioButton_zhCN, SIGNAL(clicked()), this, SLOT(radioButton_zhCN_checked()));
    connect(ui->radioButton_enUS, SIGNAL(clicked()), this, SLOT(radioButton_enUS_checked()));

    //color contral
    connect(ui->pushButtonChangeBGColor, SIGNAL(clicked()), this, SLOT(change_bg_color()));
    connect(ui->pushButtonChangeFGColor, SIGNAL(clicked()), this, SLOT(change_fg_color()));

    //config menu buttons
    connect(ui->pushButtonDefaults, SIGNAL(clicked()), this, SLOT(pushbutton_defaults()));
    connect(ui->pushButtonApply, SIGNAL(clicked()), this, SLOT(pushbutton_apply()));
    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(pushbutton_rejected()));
//-----------------------------slot-----------------------------------------
}

MainWindow::~MainWindow()
{
    delete refresh_timer;
    delete lock_clk;
    delete lock_dlg;
    delete ui;
}

void MainWindow::update_curtime()
{
    QString tmp_time;
    ui->label_curtime_value->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    tmp_time = --lock_clk->time2Rest;
    //ui->labelTime2Rest->setText(tmp_time.sprintf("%02d:%02d", lock_clk->time2Rest/60, lock_clk->time2Rest%60));
}

void MainWindow::createActions()
{
    runRest = new QAction(tr("&Run"), this);
    connect(runRest, SIGNAL(triggered()), this, SLOT(run_lock_dlg()));

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(runRest);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon("zafx.svg"));

    trayIcon->show();
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(systrayClicked()));
}

void MainWindow::run_lock_dlg()
{
    lock_dlg = new LockDlg();

    //how much time left to rest
    //lock_clk->time2Rest = (confAll->alertTime + confAll->restTime) * 60;
    lock_clk->time2Rest = confAll->alertTime * 60;

    connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_dlg->rest_clk->rest_timer, SLOT(stop()));
    connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_clk->lock_timer, SLOT(start()));
    connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_dlg, SLOT(close()));

    lock_dlg->show();
}

void MainWindow::stop_lock_dlg()
{
    lock_clk->lock_timer->stop();
}


void MainWindow::on_pushbtn_update_clicked()
{
    qDebug() << "fetch update info...";
}

void MainWindow::on_pushbtn_exit_clicked()
{
    emit app_quit();
}

void MainWindow::on_pushbtn_run_clicked()
{
    this->hide();
    run_lock_dlg();
}

void MainWindow::pushbtn_update()
{
    qDebug() << "check update...";
}

void MainWindow::updateConfValue()
{
    confAll->alertTime = ui->spinBoxAlertTime->value();
    confAll->restTime = ui->spinBoxRestTime->value();
    confAll->writeConfig();
    confAll->readConfig();
}

void MainWindow::pushbutton_defaults()
{
    confAll->restoreConfig();

    //main-windowsome
    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));

    ui->spinBoxAlertTime->setValue(confAll->default_alertTime);
    ui->spinBoxRestTime->setValue(confAll->default_restTime);

    //default color
    ui->pushButtonChangeBGColor->setPalette(QPalette(QColor(confAll->bg_colorR,
                                                            confAll->bg_colorG,
                                                            confAll->bg_colorB)));
    ui->pushButtonChangeFGColor->setPalette(QPalette(QColor(confAll->fg_colorR,
                                                            confAll->fg_colorG,
                                                            confAll->fg_colorB)));
}

void MainWindow::pushbutton_apply()
{
    //backup while changed
    old_alertTime = confAll->alertTime;
    old_restTime = confAll->restTime;
    old_playSound = confAll->playSound;

    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));
    confAll->writeConfig();

    //update current time
    confAll->readConfig();
}

void MainWindow::pushbutton_rejected()
{
    //update backup value
    confAll->alertTime = old_alertTime;
    confAll->restTime = old_restTime;
    confAll->playSound = old_playSound;

    //update mainmenu value
    ui->spinBoxAlertTime->setValue(confAll->alertTime);
    ui->spinBoxRestTime->setValue(confAll->restTime);
}

void MainWindow::checkBoxPlaySound_clicked()
{
    confAll->playSound = ui->checkBoxPlaySound->isChecked();
}

void MainWindow::checkBoxShowStartup_clicked()
{
    confAll->show_startup = ui->checkBoxShowStartup->isChecked();
}

void MainWindow::systrayClicked()
{
    QMessageBox::information(0, tr("Systray"),
                             tr("Sorry, I already gave what help I could.\n"
                                "Maybe you should try asking a human?"));
}

void MainWindow::radioButton_zhCN_checked()
{
    ui->radioButton_zhCN->setChecked(true);
    ui->radioButton_enUS->setChecked(false);
    confAll->language="zh_CN";

}

void MainWindow::radioButton_enUS_checked()
{
    ui->radioButton_zhCN->setChecked(false);
    ui->radioButton_enUS->setChecked(true);
    confAll->language="en_US";

}

void MainWindow::change_bg_color()
{
    color4all = QColorDialog::getColor(Qt::white, this);
    confAll->bg_colorR = color4all.red();
    confAll->bg_colorG = color4all.green();
    confAll->bg_colorB = color4all.blue();

    ui->pushButtonChangeBGColor->setPalette(QPalette(QColor(confAll->bg_colorR,
                                                            confAll->bg_colorG,
                                                            confAll->bg_colorB)));

}

void MainWindow::change_fg_color()
{
    color4all = QColorDialog::getColor(Qt::white, this);
    confAll->fg_colorR = color4all.red();
    confAll->fg_colorG = color4all.green();
    confAll->fg_colorB = color4all.blue();

    ui->pushButtonChangeFGColor->setPalette(QPalette(QColor(confAll->fg_colorR,
                                                            confAll->fg_colorG,
                                                            confAll->fg_colorB)));
}
