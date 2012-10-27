/********************************************************************************
** Form generated from reading UI file 'lockdlg.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCKDLG_H
#define UI_LOCKDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LockDlg
{
public:
    QWidget *centralWidget;
    QLabel *label_title;
    QLCDNumber *lcd_resttime;
    QPushButton *restbtn_exit;
    QLabel *label_tips;
    QLabel *label_currenttime;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LockDlg)
    {
        if (LockDlg->objectName().isEmpty())
            LockDlg->setObjectName(QString::fromUtf8("LockDlg"));
        LockDlg->resize(495, 383);
        LockDlg->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo/baby_tux_cow.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LockDlg->setWindowIcon(icon);
        LockDlg->setWindowOpacity(0.618);
        LockDlg->setAutoFillBackground(true);
        centralWidget = new QWidget(LockDlg);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_title = new QLabel(centralWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(50, 30, 391, 51));
        QFont font;
        font.setPointSize(20);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lcd_resttime = new QLCDNumber(centralWidget);
        lcd_resttime->setObjectName(QString::fromUtf8("lcd_resttime"));
        lcd_resttime->setGeometry(QRect(100, 90, 291, 81));
        QFont font1;
        font1.setPointSize(14);
        lcd_resttime->setFont(font1);
        restbtn_exit = new QPushButton(centralWidget);
        restbtn_exit->setObjectName(QString::fromUtf8("restbtn_exit"));
        restbtn_exit->setGeometry(QRect(90, 240, 91, 41));
        QFont font2;
        font2.setPointSize(18);
        restbtn_exit->setFont(font2);
        label_tips = new QLabel(centralWidget);
        label_tips->setObjectName(QString::fromUtf8("label_tips"));
        label_tips->setGeometry(QRect(190, 240, 211, 41));
        label_tips->setFont(font2);
        label_currenttime = new QLabel(centralWidget);
        label_currenttime->setObjectName(QString::fromUtf8("label_currenttime"));
        label_currenttime->setGeometry(QRect(70, 180, 341, 51));
        label_currenttime->setFont(font);
        label_currenttime->setAlignment(Qt::AlignCenter);
        LockDlg->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(LockDlg);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LockDlg->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LockDlg);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LockDlg->setStatusBar(statusBar);

        retranslateUi(LockDlg);

        QMetaObject::connectSlotsByName(LockDlg);
    } // setupUi

    void retranslateUi(QMainWindow *LockDlg)
    {
        LockDlg->setWindowTitle(QApplication::translate("LockDlg", "Lemon's Health", 0, QApplication::UnicodeUTF8));
        label_title->setText(QApplication::translate("LockDlg", "Go and Have a Cup of Tea :-)", 0, QApplication::UnicodeUTF8));
        restbtn_exit->setText(QApplication::translate("LockDlg", "Leave", 0, QApplication::UnicodeUTF8));
        label_tips->setText(QApplication::translate("LockDlg", "Click to LEAVE", 0, QApplication::UnicodeUTF8));
        label_currenttime->setText(QApplication::translate("LockDlg", "current time", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LockDlg: public Ui_LockDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCKDLG_H
