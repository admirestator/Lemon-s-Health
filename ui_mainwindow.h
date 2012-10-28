/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabConfig;
    QWidget *main_tab;
    QLabel *label_8;
    QLabel *label_logo;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushbtn_update;
    QPushButton *pushbtn_exit;
    QPushButton *pushbtn_run;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *labelVersionNum;
    QLabel *label_curtime;
    QLabel *label_curtime_value;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelAlertTime;
    QLabel *labelRestTime;
    QVBoxLayout *verticalLayout;
    QLabel *label_16;
    QLabel *label_10;
    QWidget *tab;
    QLabel *label_15;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLabel *label_13;
    QSpinBox *spinBoxRestTime;
    QSpinBox *spinBoxAlertTime;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonDefaults;
    QPushButton *pushButtonApply;
    QPushButton *pushButtonCancel;
    QLabel *label_lan_tip;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBoxPlaySound;
    QCheckBox *checkBoxShowStartup;
    QRadioButton *radioButton_zhCN;
    QRadioButton *radioButton_enUS;
    QCheckBox *checkBox_startup;
    QLabel *label_12;
    QLabel *label_22;
    QWidget *layoutWidget9;
    QGridLayout *gridLayout_6;
    QLabel *label_bg_color;
    QPushButton *pushButtonChangeBGColor;
    QLabel *label_fg_color;
    QPushButton *pushButtonChangeFGColor;
    QWidget *tab_help;
    QLabel *label_23;
    QWidget *tab_license;
    QLabel *label_5;
    QLabel *label_18;
    QWidget *tab_about;
    QLabel *label_4;
    QLabel *label_9;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout_4;
    QLabel *label_14;
    QLabel *label_19;
    QLabel *label_author;
    QLabel *label_3;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_2;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(524, 348);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo/baby_tux_cow.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabConfig = new QTabWidget(centralwidget);
        tabConfig->setObjectName(QString::fromUtf8("tabConfig"));
        tabConfig->setGeometry(QRect(10, 0, 501, 311));
        tabConfig->setTabPosition(QTabWidget::West);
        tabConfig->setIconSize(QSize(25, 25));
        tabConfig->setDocumentMode(true);
        tabConfig->setTabsClosable(false);
        main_tab = new QWidget();
        main_tab->setObjectName(QString::fromUtf8("main_tab"));
        label_8 = new QLabel(main_tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(170, 10, 101, 21));
        label_logo = new QLabel(main_tab);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(280, 50, 161, 131));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/logo/baby_tux_cow555px.png")));
        label_logo->setScaledContents(true);
        layoutWidget2 = new QWidget(main_tab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(100, 220, 247, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushbtn_update = new QPushButton(layoutWidget2);
        pushbtn_update->setObjectName(QString::fromUtf8("pushbtn_update"));
        pushbtn_update->setAutoDefault(false);

        horizontalLayout->addWidget(pushbtn_update);

        pushbtn_exit = new QPushButton(layoutWidget2);
        pushbtn_exit->setObjectName(QString::fromUtf8("pushbtn_exit"));
        pushbtn_exit->setAutoDefault(false);

        horizontalLayout->addWidget(pushbtn_exit);

        pushbtn_run = new QPushButton(layoutWidget2);
        pushbtn_run->setObjectName(QString::fromUtf8("pushbtn_run"));
        pushbtn_run->setAutoDefault(false);

        horizontalLayout->addWidget(pushbtn_run);

        layoutWidget3 = new QWidget(main_tab);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(320, 190, 96, 16));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        labelVersionNum = new QLabel(layoutWidget3);
        labelVersionNum->setObjectName(QString::fromUtf8("labelVersionNum"));

        horizontalLayout_3->addWidget(labelVersionNum);

        label_curtime = new QLabel(main_tab);
        label_curtime->setObjectName(QString::fromUtf8("label_curtime"));
        label_curtime->setGeometry(QRect(30, 70, 72, 16));
        label_curtime_value = new QLabel(main_tab);
        label_curtime_value->setObjectName(QString::fromUtf8("label_curtime_value"));
        label_curtime_value->setGeometry(QRect(120, 70, 111, 16));
        layoutWidget = new QWidget(main_tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 101, 229, 58));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelAlertTime = new QLabel(layoutWidget);
        labelAlertTime->setObjectName(QString::fromUtf8("labelAlertTime"));
        sizePolicy.setHeightForWidth(labelAlertTime->sizePolicy().hasHeightForWidth());
        labelAlertTime->setSizePolicy(sizePolicy);
        labelAlertTime->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_2->addWidget(labelAlertTime);

        labelRestTime = new QLabel(layoutWidget);
        labelRestTime->setObjectName(QString::fromUtf8("labelRestTime"));
        sizePolicy.setHeightForWidth(labelRestTime->sizePolicy().hasHeightForWidth());
        labelRestTime->setSizePolicy(sizePolicy);
        labelRestTime->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_2->addWidget(labelRestTime);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout->addWidget(label_16);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);


        horizontalLayout_4->addLayout(verticalLayout);

        tabConfig->addTab(main_tab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 20, 81, 16));
        layoutWidget4 = new QWidget(tab);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 70, 140, 71));
        gridLayout_3 = new QGridLayout(layoutWidget4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        spinBoxRestTime = new QSpinBox(layoutWidget4);
        spinBoxRestTime->setObjectName(QString::fromUtf8("spinBoxRestTime"));
        spinBoxRestTime->setMaximum(60);

        gridLayout_3->addWidget(spinBoxRestTime, 1, 1, 1, 1);

        spinBoxAlertTime = new QSpinBox(layoutWidget4);
        spinBoxAlertTime->setObjectName(QString::fromUtf8("spinBoxAlertTime"));
        spinBoxAlertTime->setMaximum(120);

        gridLayout_3->addWidget(spinBoxAlertTime, 0, 1, 1, 1);

        layoutWidget5 = new QWidget(tab);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(80, 270, 297, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonDefaults = new QPushButton(layoutWidget5);
        pushButtonDefaults->setObjectName(QString::fromUtf8("pushButtonDefaults"));

        horizontalLayout_2->addWidget(pushButtonDefaults);

        pushButtonApply = new QPushButton(layoutWidget5);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));

        horizontalLayout_2->addWidget(pushButtonApply);

        pushButtonCancel = new QPushButton(layoutWidget5);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);

        label_lan_tip = new QLabel(tab);
        label_lan_tip->setObjectName(QString::fromUtf8("label_lan_tip"));
        label_lan_tip->setGeometry(QRect(260, 40, 201, 21));
        layoutWidget6 = new QWidget(tab);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(260, 70, 201, 111));
        gridLayout_5 = new QGridLayout(layoutWidget6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBoxPlaySound = new QCheckBox(layoutWidget6);
        checkBoxPlaySound->setObjectName(QString::fromUtf8("checkBoxPlaySound"));

        gridLayout_5->addWidget(checkBoxPlaySound, 1, 0, 1, 2);

        checkBoxShowStartup = new QCheckBox(layoutWidget6);
        checkBoxShowStartup->setObjectName(QString::fromUtf8("checkBoxShowStartup"));

        gridLayout_5->addWidget(checkBoxShowStartup, 2, 0, 1, 2);

        radioButton_zhCN = new QRadioButton(layoutWidget6);
        radioButton_zhCN->setObjectName(QString::fromUtf8("radioButton_zhCN"));

        gridLayout_5->addWidget(radioButton_zhCN, 3, 0, 1, 1);

        radioButton_enUS = new QRadioButton(layoutWidget6);
        radioButton_enUS->setObjectName(QString::fromUtf8("radioButton_enUS"));

        gridLayout_5->addWidget(radioButton_enUS, 3, 1, 1, 1);

        checkBox_startup = new QCheckBox(layoutWidget6);
        checkBox_startup->setObjectName(QString::fromUtf8("checkBox_startup"));
        checkBox_startup->setChecked(false);
        checkBox_startup->setTristate(false);

        gridLayout_5->addWidget(checkBox_startup, 0, 0, 1, 2);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(60, 40, 71, 16));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(80, 170, 71, 16));
        layoutWidget9 = new QWidget(tab);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(31, 190, 184, 59));
        gridLayout_6 = new QGridLayout(layoutWidget9);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_bg_color = new QLabel(layoutWidget9);
        label_bg_color->setObjectName(QString::fromUtf8("label_bg_color"));

        gridLayout_6->addWidget(label_bg_color, 0, 0, 1, 1);

        pushButtonChangeBGColor = new QPushButton(layoutWidget9);
        pushButtonChangeBGColor->setObjectName(QString::fromUtf8("pushButtonChangeBGColor"));
        pushButtonChangeBGColor->setAutoFillBackground(false);

        gridLayout_6->addWidget(pushButtonChangeBGColor, 0, 1, 1, 1);

        label_fg_color = new QLabel(layoutWidget9);
        label_fg_color->setObjectName(QString::fromUtf8("label_fg_color"));

        gridLayout_6->addWidget(label_fg_color, 1, 0, 1, 1);

        pushButtonChangeFGColor = new QPushButton(layoutWidget9);
        pushButtonChangeFGColor->setObjectName(QString::fromUtf8("pushButtonChangeFGColor"));
        pushButtonChangeFGColor->setAutoFillBackground(false);

        gridLayout_6->addWidget(pushButtonChangeFGColor, 1, 1, 1, 1);

        tabConfig->addTab(tab, QString());
        tab_help = new QWidget();
        tab_help->setObjectName(QString::fromUtf8("tab_help"));
        label_23 = new QLabel(tab_help);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(20, 0, 441, 271));
        tabConfig->addTab(tab_help, QString());
        tab_license = new QWidget();
        tab_license->setObjectName(QString::fromUtf8("tab_license"));
        label_5 = new QLabel(tab_license);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 10, 391, 231));
        label_18 = new QLabel(tab_license);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(50, 230, 381, 61));
        QFont font;
        font.setPointSize(11);
        label_18->setFont(font);
        tabConfig->addTab(tab_license, QString());
        tab_about = new QWidget();
        tab_about->setObjectName(QString::fromUtf8("tab_about"));
        label_4 = new QLabel(tab_about);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 30, 131, 31));
        label_9 = new QLabel(tab_about);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 60, 401, 81));
        layoutWidget7 = new QWidget(tab_about);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(20, 150, 449, 83));
        gridLayout_4 = new QGridLayout(layoutWidget7);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget7);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 0, 0, 1, 1);

        label_19 = new QLabel(layoutWidget7);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 0, 1, 1, 1);

        label_author = new QLabel(layoutWidget7);
        label_author->setObjectName(QString::fromUtf8("label_author"));

        gridLayout_4->addWidget(label_author, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget7);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        label_17 = new QLabel(layoutWidget7);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_4->addWidget(label_17, 2, 1, 1, 1);

        label_20 = new QLabel(layoutWidget7);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_4->addWidget(label_20, 3, 0, 1, 1);

        label_21 = new QLabel(layoutWidget7);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_4->addWidget(label_21, 3, 1, 1, 1);

        label_2 = new QLabel(layoutWidget7);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 1, 1, 1);

        tabConfig->addTab(tab_about, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        tabConfig->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lemon's Health", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Set Basic Setting", 0, QApplication::UnicodeUTF8));
        label_logo->setText(QString());
        pushbtn_update->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        pushbtn_exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        pushbtn_run->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Version:", 0, QApplication::UnicodeUTF8));
        labelVersionNum->setText(QApplication::translate("MainWindow", "version", 0, QApplication::UnicodeUTF8));
        label_curtime->setText(QApplication::translate("MainWindow", "Current Time", 0, QApplication::UnicodeUTF8));
        label_curtime_value->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Time for Alert(m)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Time for Rest(m)", 0, QApplication::UnicodeUTF8));
        labelAlertTime->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelRestTime->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "minute(s)", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "minute(s)", 0, QApplication::UnicodeUTF8));
        tabConfig->setTabText(tabConfig->indexOf(main_tab), QApplication::translate("MainWindow", "Main", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Config Menu", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Alert Time(m)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Rest Time(m)", 0, QApplication::UnicodeUTF8));
        pushButtonDefaults->setText(QApplication::translate("MainWindow", "Defaults", 0, QApplication::UnicodeUTF8));
        pushButtonApply->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        label_lan_tip->setText(QApplication::translate("MainWindow", "System Setting (effects after relunch)", 0, QApplication::UnicodeUTF8));
        checkBoxPlaySound->setText(QApplication::translate("MainWindow", "Play a sound after rest", 0, QApplication::UnicodeUTF8));
        checkBoxShowStartup->setText(QApplication::translate("MainWindow", "Show on startup", 0, QApplication::UnicodeUTF8));
        radioButton_zhCN->setText(QApplication::translate("MainWindow", "\347\256\200\344\275\223\344\270\255\346\226\207", 0, QApplication::UnicodeUTF8));
        radioButton_enUS->setText(QApplication::translate("MainWindow", "English", 0, QApplication::UnicodeUTF8));
        checkBox_startup->setText(QApplication::translate("MainWindow", "Startup with system", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Time Setting", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Color Setting", 0, QApplication::UnicodeUTF8));
        label_bg_color->setText(QApplication::translate("MainWindow", "BackgroundColor", 0, QApplication::UnicodeUTF8));
        pushButtonChangeBGColor->setText(QApplication::translate("MainWindow", "Change", 0, QApplication::UnicodeUTF8));
        label_fg_color->setText(QApplication::translate("MainWindow", "ForegroundColor", 0, QApplication::UnicodeUTF8));
        pushButtonChangeFGColor->setText(QApplication::translate("MainWindow", "Change", 0, QApplication::UnicodeUTF8));
        tabConfig->setTabText(tabConfig->indexOf(tab), QApplication::translate("MainWindow", "Config", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "1. Why Lemon?\n"
"Lemon is not the fruit lemon.It was the name a female.So you had got that\n"
"this program was named after from her. \n"
"\n"
"2. Who is Lemon?\n"
"Lemon is a woman in myth, she had played an important role in my life. \n"
"\n"
"3. How to use this program?\n"
"Just start it and leave it alone. \n"
"\n"
"4. What is alert time?\n"
"it means how long you will have a rest. \n"
"\n"
"5. What is rest time?\n"
"It means how much time you will take for a rest. \n"
"\n"
"6. How can I change the color?\n"
"You can change the color in \"Config\" menu, then you can see two buttons\n"
"with color, one for background color, and another for foreground.\n"
"", 0, QApplication::UnicodeUTF8));
        tabConfig->setTabText(tabConfig->indexOf(tab_help), QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "    Copyright (C) <2012>  <admirestator>\n"
"\n"
"    This program is free software: you can redistribute it and/or modify\n"
"    it under the terms of the GNU General Public License as published by\n"
"    the Free Software Foundation, either version 3 of the License, or\n"
"    (at your option) any later version.\n"
"\n"
"    This program is distributed in the hope that it will be useful,\n"
"    but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"    GNU General Public License for more details.\n"
"\n"
"    You should have received a copy of the GNU General Public License\n"
"    along with this program.  If not, see <http://www.gnu.org/licenses/\">.\n"
"", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "The images of this program came from the Internet, if\n"
"it harms your rights, please contact me, I will change it.", 0, QApplication::UnicodeUTF8));
        tabConfig->setTabText(tabConfig->indexOf(tab_license), QApplication::translate("MainWindow", "license", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "About Lemon's Health", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Lemon's Health is a program written with Qt that can alert you to have a\n"
"rest while you had been sat from the computer.It was inspired by the\n"
"\"workrave\".Which is also a famouse software written in GTK.\n"
"I release it as a speciall present for Lemon today!", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Project Page:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "https://github.com/admirestator/Lemon-s-health", 0, QApplication::UnicodeUTF8));
        label_author->setText(QApplication::translate("MainWindow", "Author:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Blog:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "http://admirestator.diandian.com", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "GooglePlus:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "https://plus.google.com/u/0/107811042264601559587/posts", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "admirestator <admirestator@gmail.com>", 0, QApplication::UnicodeUTF8));
        tabConfig->setTabText(tabConfig->indexOf(tab_about), QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
