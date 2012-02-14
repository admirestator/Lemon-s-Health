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
    //lock_dlg = new LockDlg();
    run_lock_dlg();
    refresh_timer = new QTimer();

    refresh_timer->start(1000);
    //system tray
    //connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
     //          this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    //config operations
    confAll = new Config();
    confAll->readConfig();
    old_alertTime = confAll->alertTime;  //backup while changed
    old_restTime = confAll->restTime;
    old_playSound = confAll->playSound;



    //update refresh time
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(update_curtime()));
    //connect(lock_clk->lock_timer, SIGNAL(timeout()), this, SLOT());
    connect(lock_dlg->rest_clk->rest_timer, SIGNAL(timeout()), lock_dlg, SLOT(close()));

    ui->setupUi(this);
    //main menu
    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));
    //config menu
    ui->spinBoxAlertTime->setValue(confAll->alertTime);
    ui->spinBoxRestTime->setValue(confAll->restTime);

   // qDebug() << confAll->version;
    //Version
    ui->labelVersionNum->setText(confAll->version);

    //居中显示
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);

    connect(ui->spinBoxAlertTime, SIGNAL(valueChanged(int)), this, SLOT(updateConfValue()));
    connect(ui->spinBoxRestTime, SIGNAL(valueChanged(int)), this, SLOT(updateConfValue()));
    connect(ui->checkBoxPlaySound, SIGNAL(stateChanged(int)),
            this, SLOT(checkBoxPlaySound_clicked()));

    //config menu buttons
    connect(ui->pushButtonDefaults, SIGNAL(clicked()), this, SLOT(pushbutton_defaults()));
    connect(ui->pushButtonApply, SIGNAL(clicked()), this, SLOT(pushbutton_apply()));
    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(pushbutton_rejected()));

    trayIcon->show();
    qDebug() << "sound";
    QSound::play("/home/admire/workshop/qt/clock/Clock/ss.wav");
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
}


void MainWindow::createActions()
{
    runRest = new QAction(tr("&Run"), this);
    connect(runRest, SIGNAL(triggered()), this, SLOT(run_lock_dlg()));

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

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
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon("tux_cow_baby.svg"));
    trayIcon->showMessage("Name","Lemon's Health?");
    connect(trayIcon,SIGNAL(messageClicked()),this,SLOT(show()));
}


void MainWindow::run_lock_dlg()
{
    lock_dlg = new LockDlg();
    //lock_dlg->show();
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
    lock_dlg->close();
}

void MainWindow::on_pushbtn_run_clicked()
{
#ifdef DEBUG
    qDebug() << "show lock dialg";
#endif
    this->hide();
    lock_dlg->show();
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

    qDebug() << confAll->alertTime;
    qDebug() << confAll->restTime;
}


void MainWindow::pushbutton_defaults()
{
    confAll->alertTime = 50;
    confAll->restTime = 10;
    confAll->playSound = false;
    confAll->version = "214";

    //main-windowsome
    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));
    //ui->playSound =  confAll->playSound;

#ifdef DEBUG
    qDebug() << "resetore to default";
#endif

}


void MainWindow::pushbutton_apply()
{
    ui->labelAlertTime->setText(QString::number(confAll->alertTime, 10));
    ui->labelRestTime->setText(QString::number(confAll->restTime, 10));
    confAll->writeConfig();

    old_alertTime = confAll->alertTime;  //backup while changed
    old_restTime = confAll->restTime;
    old_playSound = confAll->playSound;

#ifdef DEBUG
    qDebug() << "apply";
#endif
}

void MainWindow::pushbutton_rejected()
{
    confAll->alertTime = old_alertTime; //update backup value
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
    qDebug() << confAll->playSound << ui->checkBoxPlaySound->checkState();
}

