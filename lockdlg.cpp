#include "lockdlg.h"
#include "ui_lockdlg.h"

//#define DEBUG

LockDlg::LockDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LockDlg)
{
#ifdef DEBUG
    qDebug() << "lock dlg constructor";
#endif

    confLockDlg = new Config();
    confLockDlg->readConfig();

    //透明测试
    QPalette pal = palette();
    //修改锁屏窗口的颜色
    pal.setColor(QPalette::Background, QColor(confLockDlg->bg_colorR, confLockDlg->bg_colorG, confLockDlg->bg_colorB));
    pal.setColor(QPalette::Foreground, QColor(confLockDlg->fg_colorR, confLockDlg->fg_colorG, confLockDlg->fg_colorB));
    setPalette(pal);

#ifdef DEBUG
    qDebug() << "dlg debug: "
             << confLockDlg->bg_colorR << confLockDlg->bg_colorG << confLockDlg->bg_colorB
             << confLockDlg->fg_colorR << confLockDlg->fg_colorG << confLockDlg->fg_colorB;
#endif

    rest_clk = new RestClk();
    refresh_timer = new QTimer();

    //连接锁屏间隔计时器和休息计时界面
    //当前休息时间刷新
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(display_rest_time()));

    //当前日期时钟刷新
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(display_date()));

    //休息时间结束，退出锁屏幕
    refresh_timer->start(1000);

    //创建界面
    ui->setupUi(this);

    //隐藏标题
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置全屏显示(封锁屏幕)
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::CustomizeWindowHint | (Qt::Window) | Qt::WindowStaysOnTopHint);
    this->showFullScreen();

    //部件居中显示
    ui->label_title->move((QApplication::desktop()->width() - ui->label_title->width())/2,
                            QApplication::desktop()->height()*2/7);

    ui->lcd_resttime->move((QApplication::desktop()->width() - ui->lcd_resttime->width())/2,
                            QApplication::desktop()->height()*2/5);

    ui->label_currenttime->move((QApplication::desktop()->width() - ui->label_currenttime->width())/2,
                                QApplication::desktop()->height()/2);

    ui->restbtn_exit->move((QApplication::desktop()->width() - (ui->restbtn_exit->width()+ui->label_tips->width())) / 2,
                           QApplication::desktop()->height()*2/3);

    ui->label_tips->move((QApplication::desktop()->width() - (ui->restbtn_exit->width()+ui->label_tips->width())) / 2 + ui->label_tips->width()*2/3,
                         QApplication::desktop()->height()*2/3);

    //LCD默认时间显示
    ui->lcd_resttime->display(format_rest_time.sprintf("%02d:%02d",
                                                       rest_clk->rest_delay/60,
                                                       rest_clk->rest_delay%60));

    //锁屏时间到，退出屏幕，计时器清
    connect(rest_clk->rest_timer, SIGNAL(timeout()), this, SLOT(on_restbtn_exit_clicked()));
    connect(ui->restbtn_exit, SIGNAL(clicked()), this, SLOT(on_restbtn_exit_clicked()));

    //播放音乐
    sound_name = "canonind.wav";
    sound = new QSound(sound_name);
    execPlaySound(QString(sound_name));

    rest_clk->run();

#ifdef DEBUG
    qDebug() << "lock dlg constructor";
#endif
}

LockDlg::~LockDlg()
{
#ifdef DEBUG
    qDebug() << "destery lockdlg";
#endif

    on_restbtn_exit_clicked();
    delete refresh_timer;
    delete rest_clk;
    delete ui;
    delete confLockDlg;
}


void LockDlg::display_date()
{
    ui->label_currenttime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void LockDlg::display_rest_time()
{
#ifdef DEBUG
    qDebug() << "display_rest_time"
             << rest_clk->rest_delay/60
             << rest_clk->rest_delay%60;
#endif

    rest_clk->update_resttime();
    ui->lcd_resttime->display(format_rest_time.sprintf("%02d:%02d", rest_clk->rest_delay/60, rest_clk->rest_delay%60));
}

void LockDlg::on_restbtn_exit_clicked()
{
#ifdef Q_OS_MAC //Mac OS X platfrom
    sound->stop();
#else
    #ifdef WIN32 //windows platfrom
        sound->stop();
    #else //linux platfrom
        system("pkill -9 aplay");
    #endif
#endif
    execPlaySound(QString("complete.wav"));
    this->hide();
}

void LockDlg::keyPressEvent (QKeyEvent * event)
{
    if (event->key() == 27) {   //ASCII for ESC
        qDebug() << "Got ESC!";
    }
    this->close();
}

//got it from the libfetion source code
void LockDlg::execPlaySound(QString music)
{
#ifdef Q_OS_MAC //Mac OS X platfrom
    //QSound::play(music);
    //sound->play(music);
    sound->play();
#else
    #ifdef WIN32 //windows platfrom
        //QSound::play(music);
    //sound->play(music);
    sound->play();
    #else //linux platfrom
        QString cmd;
        cmd = "aplay " + music + "&";
        system(cmd.toStdString().c_str());
     #endif
#endif
}
