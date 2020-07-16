#include <QCheckBox>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>

#include <QDebug>

#include "mainwindow.h"
#include "wmconfig.h"
#include "ui_mainwindow.h"
#include "desktopapps.h"
#include "autostartadd.h"

void setComboBoxItem(QString value, QComboBox* combo) {
    int index = combo->findText(value);
    if (index != -1)
        combo->setCurrentIndex(index);
    else
        qWarning() << "Couldn't find value" << value;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCheckBox* editableToggle   = findChild<QCheckBox*>("checkBox_enable_config");
    QComboBox* modKey           = findChild<QComboBox*>("modKeyCombo");
    QListWidget* autoStartApps  = findChild<QListWidget*>("listWidgetAutoStart");
    QPushButton* autoStartAdd   = findChild<QPushButton*>("pushButtonAutoStartNew");
    QPushButton* autoStartRemove = findChild<QPushButton*>("pushButtonAutoStartRemove");

    editableToggle->setChecked(settings.value("wm/autoconfig", false).toBool());

    modKey->clear();
    modKey->addItems(WMConfig::keys);
    setComboBoxItem(settings.value("wm/modkey", "Mod4").toString(), modKey);

    autoStartApps->clear();
    autoStartApps->addItems(settings.value("wm/autostart", QStringList()).toStringList());

    setItemsEnabled(editableToggle->isChecked());

    connect(editableToggle, &QCheckBox::toggled,
            this, &MainWindow::toggleSettingsEnabled);
    connect(autoStartAdd, &QPushButton::clicked,
            this, &MainWindow::addAppClick);
    connect(autoStartRemove, &QPushButton::clicked,
            this, &MainWindow::removeAppClick);
}

QSettings MainWindow::settings("TrickyPR", "LGC Settings Manager");

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addAppClick()
{
    AutoStartAdd* add = new AutoStartAdd();

    connect(add, &AutoStartAdd::addApp,
            this, &MainWindow::addAutoApp);

    add->exec();
}

void MainWindow::addAutoApp(QString app)
{
    QListWidget* autoStartApps   = findChild<QListWidget*>("listWidgetAutoStart");
    autoStartApps->addItem(app);
}

void MainWindow::removeAppClick()
{
    QListWidget* autoStartApps   = findChild<QListWidget*>("listWidgetAutoStart");
    autoStartApps->takeItem(autoStartApps->currentRow());

    QStringList startApps = {};

    for (QListWidgetItem* app : autoStartApps->findItems("*", Qt::MatchWildcard)) {
        startApps << app->text();
    }

    qInfo() << startApps;

}

void MainWindow::setItemsEnabled(bool state)
{
    QComboBox*   modKey          = findChild<QComboBox*>("modKeyCombo");
    QPushButton* autoStartAdd    = findChild<QPushButton*>("pushButtonAutoStartNew");
    QPushButton* autoStartRemove = findChild<QPushButton*>("pushButtonAutoStartRemove");
    QListWidget* autoStartApps   = findChild<QListWidget*>("listWidgetAutoStart");

    modKey->setEnabled(state);
    autoStartAdd->setEnabled(state);
    autoStartRemove->setEnabled(state);
    autoStartApps->setEnabled(state);
}

void MainWindow::toggleSettingsEnabled(bool state)
{
    setItemsEnabled(state);
}

void MainWindow::applySettings()
{
    QCheckBox* editableToggle = findChild<QCheckBox*>("checkBox_enable_config");

    bool autoConfig = editableToggle->isChecked();

    settings.setValue("wm/autoconfig", autoConfig);

    if (autoConfig)
    {
        QComboBox* modKey            = findChild<QComboBox*>("modKeyCombo");
        QListWidget* autoStartApps   = findChild<QListWidget*>("listWidgetAutoStart");

        QString modKeyValue = modKey->currentText();
        settings.setValue("wm/modkey", modKeyValue);

        QStringList apps = {};
        for (QListWidgetItem* app : autoStartApps->findItems("*", Qt::MatchWildcard))
            apps << app->text();
        settings.setValue("wm/autostart", apps);

        WMConfig::applySettings(modKeyValue, apps);
    }

}
