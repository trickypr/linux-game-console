/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *wm;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_enable_config;
    QVBoxLayout *verticalLayout_wm_settings;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *modKeyCombo;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidgetAutoStart;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButtonAutoStartNew;
    QPushButton *pushButtonAutoStartRemove;
    QSpacerItem *verticalSpacer_3;
    QWidget *about;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_save;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        wm = new QWidget();
        wm->setObjectName(QString::fromUtf8("wm"));
        verticalLayout_5 = new QVBoxLayout(wm);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMinAndMaxSize);
        checkBox_enable_config = new QCheckBox(wm);
        checkBox_enable_config->setObjectName(QString::fromUtf8("checkBox_enable_config"));

        verticalLayout_5->addWidget(checkBox_enable_config);

        verticalLayout_wm_settings = new QVBoxLayout();
        verticalLayout_wm_settings->setObjectName(QString::fromUtf8("verticalLayout_wm_settings"));
        verticalLayout_wm_settings->setContentsMargins(10, -1, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(wm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        modKeyCombo = new QComboBox(wm);
        modKeyCombo->setObjectName(QString::fromUtf8("modKeyCombo"));
        modKeyCombo->setEditable(false);

        horizontalLayout_2->addWidget(modKeyCombo);


        verticalLayout_wm_settings->addLayout(horizontalLayout_2);

        label_3 = new QLabel(wm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_wm_settings->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listWidgetAutoStart = new QListWidget(wm);
        listWidgetAutoStart->setObjectName(QString::fromUtf8("listWidgetAutoStart"));

        horizontalLayout_3->addWidget(listWidgetAutoStart);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButtonAutoStartNew = new QPushButton(wm);
        pushButtonAutoStartNew->setObjectName(QString::fromUtf8("pushButtonAutoStartNew"));

        verticalLayout_4->addWidget(pushButtonAutoStartNew);

        pushButtonAutoStartRemove = new QPushButton(wm);
        pushButtonAutoStartRemove->setObjectName(QString::fromUtf8("pushButtonAutoStartRemove"));

        verticalLayout_4->addWidget(pushButtonAutoStartRemove);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_wm_settings->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_wm_settings);

        tabWidget->addTab(wm, QString());
        about = new QWidget();
        about->setObjectName(QString::fromUtf8("about"));
        about->setEnabled(false);
        verticalLayout = new QVBoxLayout(about);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(about);
        label->setObjectName(QString::fromUtf8("label"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget->addTab(about, QString());

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_apply = new QPushButton(centralwidget);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));

        horizontalLayout->addWidget(pushButton_apply);

        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox_enable_config->setText(QCoreApplication::translate("MainWindow", "Automatic configuration", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mod Key", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Autostart apps", nullptr));
        pushButtonAutoStartNew->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButtonAutoStartRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(wm), QCoreApplication::translate("MainWindow", "Window manager", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Settings manager for linux game console</span></p><p align=\"center\"><span style=\" font-size:7pt;\">v1.0</span></p><p align=\"center\">The settings manager for a basic game console setup.</p><p align=\"center\"><span style=\" font-size:8pt;\"><br/>\302\251 2020 TrickyPR under the MIT License. Source available on </span><a href=\"https://github.com/trickypr/linux-game-console\"><span style=\" text-decoration: underline;font-size:8pt; color:#009dff;\">github</span></a><span style=\" font-size:8pt;\">.</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(about), QCoreApplication::translate("MainWindow", "About", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton_save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
