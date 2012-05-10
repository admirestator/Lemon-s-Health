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

    lock_clk = new LockClk();
    lock_clk->run();

    refresh_timer = new QTimer();
    refresh_timer->start(1000);

    //config operations
    confAll = new Config();
    confAll->readConfig();
    old_alertTime = confAll->alertTime;  //backup while changed
    old_restTime = confAll->restTime;
    old_playSound = confAll->playSound;



    //update refresh time
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(update_curtime()));

    //add lock_clk timer
    connect(lock_clk->lock_timer, SIGNAL(timeout()), this, SLOT(run_lock_dlg()));
    connect(lock_clk->lock_timer, SIGNAL(timeout()), lock_clk->lock_timer, SLOT(stop()));

    //create ui
    ui->setupUi(this);

    //main menu
    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));

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
    connect(ui->pushButtonChangeBGColor, SIGNAL(clicked()), this, SLOT(change_bg_color()));
    ui->pushButtonChangeBGColor->setPalette(QPalette(QColor(confAll->bg_colorR, confAll->bg_colorG, confAll->bg_colorB)));

    //foreground color control
    connect(ui->pushButtonChangeFGColor, SIGNAL(clicked()), this, SLOT(change_fg_color()));
    ui->pushButtonChangeFGColor->setPalette(QPalette(QColor(confAll->fg_colorR, confAll->fg_colorG, confAll->fg_colorB)));

#ifdef DEBUG
    qDebug() << confAll->version;
#endif

    //Version
    ui->labelVersionNum->setText(confAll->version);

    //居中显示
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);

    connect(ui->spinBoxAlertTime, SIGNAL(valueChanged(int)), this, SLOT(updateConfValue()));
    connect(ui->spinBoxRestTime, SIGNAL(valueChanged(int)), this, SLOT(updateConfValue()));
    connect(ui->checkBoxPlaySound, SIGNAL(stateChanged(int)),
            this, SLOT(checkBoxPlaySound_clicked()));

    connect(ui->checkBoxShowStartup, SIGNAL(stateChanged(int)),
            this, SLOT(checkBoxShowStartup_clicked()));

    //config menu buttons
    connect(ui->pushButtonDefaults, SIGNAL(clicked()), this, SLOT(pushbutton_defaults()));
    connect(ui->pushButtonApply, SIGNAL(clicked()), this, SLOT(pushbutton_apply()));
    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(pushbutton_rejected()));

    trayIcon->show();
    qDebug() << "sound" << " " << QSound::isAvailable();
    if(QSound::isAvailable()== true) {
       QSound::play(QString("canonind.wav"));
    }
}

MainWindow::~MainWindow()
{
    delete refresh_timer;
    delete lock_clk;
    delete ui;
}

void MainWindow::update_curtime()
{
    ui->label_curtime_value->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

#ifdef DEBUG
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
#endif
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
    connect(trayIcon,SIGNAL(messageClicked()),this,SLOT(show()));
}

void MainWindow::run_lock_dlg()
{
    lock_dlg = new LockDlg();
    connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_dlg->rest_clk->rest_timer, SLOT(stop()));
    connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_clk->lock_timer, SLOT(start()));
    connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_dlg, SLOT(close()));

   // delete lock_dlg_tmp;
    lock_dlg->show();


#ifdef DEBUG
    qDebug() << "run lock dlg";
#endif
}

void MainWindow::on_pushbtn_update_clicked()
{
    qDebug() << "fetch update info...";
}

void MainWindow::on_pushbtn_exit_clicked()
{
#ifdef DEBUG
    qDebug() << "user exit";
#endif
    emit app_quit();
    //lock_dlg->close();
}

void MainWindow::on_pushbtn_run_clicked()
{
#ifdef DEBUG
    qDebug() << "show lock dialg";
#endif
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

    //playsound was set in on_checkboxplaysound_clicked()
    confAll->writeConfig();

#ifdef DEBUG
    qDebug() << confAll->alertTime;
    qDebug() << confAll->restTime;
#endif
}


void MainWindow::pushbutton_defaults()
{
    confAll->restoreConfig();

    //main-windowsome
    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));
    //ui->playSound =  confAll->playSound;

    ui->spinBoxAlertTime->setValue(confAll->default_alertTime);
    ui->spinBoxRestTime->setValue(confAll->default_restTime);

    //default color
    ui->pushButtonChangeBGColor->setPalette(QPalette(QColor(confAll->bg_colorR,
                                                            confAll->bg_colorG,
                                                            confAll->bg_colorB)));
    ui->pushButtonChangeFGColor->setPalette(QPalette(QColor(confAll->fg_colorR,
                                                            confAll->fg_colorG,
                                                            confAll->fg_colorB)));

#ifdef DEBUG
    qDebug() << "resetore to default";
#endif

}


void MainWindow::pushbutton_apply()
{
#ifdef DEBUG
    qDebug() << "apply";
#endif

    old_alertTime = confAll->alertTime;  //backup while changed
    old_restTime = confAll->restTime;
    old_playSound = confAll->playSound;

    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));
    confAll->writeConfig();
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

#ifdef DEBUG
    qDebug() << "rejected";
#endif
}

void MainWindow::checkBoxPlaySound_clicked()
{
    confAll->playSound = ui->checkBoxPlaySound->isChecked();
    //confAll->write();

#ifdef DEBUG
    qDebug() << confAll->playSound << ui->checkBoxPlaySound->checkState();
#endif
}


void MainWindow::checkBoxShowStartup_clicked()
{
    confAll->show_startup = ui->checkBoxShowStartup->isChecked();
    //confAll->write();

#ifdef DEBUG
    qDebug() << confAll->playSound << ui->checkBoxPlaySound->checkState();
#endif
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
