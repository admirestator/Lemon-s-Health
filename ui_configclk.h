/********************************************************************************
** Form generated from reading UI file 'configclk.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGCLK_H
#define UI_CONFIGCLK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigCLK
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QDialog *ConfigCLK)
    {
        if (ConfigCLK->objectName().isEmpty())
            ConfigCLK->setObjectName(QString::fromUtf8("ConfigCLK"));
        ConfigCLK->resize(400, 300);
        buttonBox = new QDialogButtonBox(ConfigCLK);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 180, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_3 = new QLabel(ConfigCLK);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 40, 51, 13));
        formLayoutWidget = new QWidget(ConfigCLK);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(110, 80, 181, 81));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        spinBox_2 = new QSpinBox(formLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 0, 1, 1, 1);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);


        retranslateUi(ConfigCLK);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigCLK, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigCLK, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigCLK);
    } // setupUi

    void retranslateUi(QDialog *ConfigCLK)
    {
        ConfigCLK->setWindowTitle(QApplication::translate("ConfigCLK", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConfigCLK", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConfigCLK", "\344\274\221\346\201\257\351\227\264\351\232\224", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigCLK", "\344\274\221\346\201\257\346\227\266\351\225\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigCLK: public Ui_ConfigCLK {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGCLK_H
