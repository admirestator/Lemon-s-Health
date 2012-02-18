#include "lockdlg.h"
#include "ui_lockdlg.h"

//#define DEBUG

LockDlg::LockDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LockDlg)
{
//#ifdef DEBUG
    qDebug() << "lock dlg constructor";
//#endif

    //透明测试
    QPalette pal = palette();
    //修改锁屏窗口的颜�    //pal.setColor(QPalette::Background, QColor(61, 108, 239));
    pal.setColor(QPalette::Background, QColor(72, 118, 255));
    pal.setColor(QPalette::Foreground, QColor(173, 255, 47));
    setPalette(pal);

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

    //隐藏标题�    this->setWindowFlags(Qt::FramelessWindowHint);

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

    //锁屏时间到，退出屏幕，计时器清�    connect(rest_clk->rest_timer, SIGNAL(timeout()), this, SLOT(on_restbtn_exit_clicked()));
    connect(ui->restbtn_exit, SIGNAL(clicked()), this, SLOT(on_restbtn_exit_clicked()));
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

    delete refresh_timer;
    delete rest_clk;
    delete ui;
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
    this->hide();
}

void LockDlg::keyPressEvent (QKeyEvent * event)
{
    if (event->key() == 27) {   //ASCII for ESC
        qDebug() << "Got ESC!";
    }
    this->close();
}
