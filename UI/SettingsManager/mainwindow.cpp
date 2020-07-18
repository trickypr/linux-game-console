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
#include "managedesktop.h"

//
// Utils
//

void setComboBoxItem(QString value, QComboBox* combo) {
    int index = combo->findText(value);
    if (index != -1)
        combo->setCurrentIndex(index);
    else
        qWarning() << "Couldn't find value" << value;
}

//
// Initialisation
//

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Get everything from the ui file
    QCheckBox* editableToggle    = findChild<QCheckBox*>("checkBox_enable_config");
    QComboBox* modKey            = findChild<QComboBox*>("modKeyCombo");
    QListWidget* autoStartApps   = findChild<QListWidget*>("listWidgetAutoStart");
    QPushButton* autoStartAdd    = findChild<QPushButton*>("pushButtonAutoStartNew");
    QPushButton* autoStartRemove = findChild<QPushButton*>("pushButtonAutoStartRemove");
    QListWidget* desktops        = findChild<QListWidget*>("desktops");
    QPushButton* addDesktop      = findChild<QPushButton*>("desktopAdd");
    QPushButton* editDesktop     = findChild<QPushButton*>("desktopEdit");
    QPushButton* removeDesktop   = findChild<QPushButton*>("desktopRemove");
    QPushButton* applySettings   = findChild<QPushButton*>("pushButton_apply");
    QPushButton* okSettings      = findChild<QPushButton*>("pushButton_save");

    // Load data to the checkbox
    editableToggle->setChecked(settings.value("wm/autoconfig", false).toBool());

    // Load all the modkeys and select the value
    modKey->clear();
    modKey->addItems(WMConfig::keys);
    setComboBoxItem(settings.value("wm/modkey", "Mod4").toString(), modKey);

    // Load your settings for the auto start applications
    autoStartApps->clear();
    autoStartApps->addItems(settings.value("wm/autostart", QStringList()).toStringList());

    // Load the desktops
    desktops->clear();
    desktops->addItems(settings.value("wm/desktops", QStringList("Main")).toStringList());

    // Set if you can edit the settings
    setItemsEnabled(editableToggle->isChecked());

    // Toggle being able to edit the files
    connect(editableToggle, &QCheckBox::toggled,
            this, &MainWindow::toggleSettingsEnabled);

    // Auto start configuration
    connect(autoStartAdd, &QPushButton::clicked,
            this, &MainWindow::addAppClick);
    connect(autoStartRemove, &QPushButton::clicked,
            this, &MainWindow::removeAppClick);

    // Desktop configuration
    connect(addDesktop, &QPushButton::clicked,
            this, &MainWindow::desktopAddDialog);
    connect(editDesktop, &QPushButton::clicked,
            this, &MainWindow::desktopEditDialog);
    connect(removeDesktop, &QPushButton::clicked,
            this, &MainWindow::removeDesktop);

    // Apply buttons
    connect(applySettings, &QPushButton::clicked,
            this, &MainWindow::applyButton);
    connect(okSettings, &QPushButton::clicked,
            this, &MainWindow::okButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
// System settings
//

QSettings MainWindow::settings("TrickyPR", "LGC Settings Manager");

//
// General ui code
//

void MainWindow::setItemsEnabled(bool state)
{
    QComboBox*   modKey          = findChild<QComboBox*>("modKeyCombo");
    QPushButton* autoStartAdd    = findChild<QPushButton*>("pushButtonAutoStartNew");
    QPushButton* autoStartRemove = findChild<QPushButton*>("pushButtonAutoStartRemove");
    QListWidget* autoStartApps   = findChild<QListWidget*>("listWidgetAutoStart");
    QListWidget* desktops        = findChild<QListWidget*>("desktops");
    QPushButton* addDesktop      = findChild<QPushButton*>("desktopAdd");
    QPushButton* editDesktop     = findChild<QPushButton*>("desktopEdit");
    QPushButton* removeDesktop   = findChild<QPushButton*>("desktopRemove");

    modKey->setEnabled(state);
    autoStartAdd->setEnabled(state);
    autoStartRemove->setEnabled(state);
    autoStartApps->setEnabled(state);
    desktops->setEnabled(state);
    addDesktop->setEnabled(state);
    editDesktop->setEnabled(state);
    removeDesktop->setEnabled(state);
}

void MainWindow::toggleSettingsEnabled(bool state)
{
    setItemsEnabled(state);
}

//
// Screen settings interface
//

void MainWindow::desktopAddDialog()
{
    ManageDesktop* add = new ManageDesktop() ;

    connect(add, &ManageDesktop::applyDesktop,
            this, &MainWindow::applyDesktop);

    add->exec();
}

void MainWindow::desktopEditDialog()
{
    // Helpful UI bits
    QListWidget* desktops = findChild<QListWidget*>("desktops");
    ManageDesktop* edit = new ManageDesktop();

    connect(edit, &ManageDesktop::applyDesktop,
            this, &MainWindow::applyDesktop);

    edit->setName(desktops->currentItem()->text());
    edit->setDesktopIndex(desktops->currentRow());
    edit->exec();
}

void MainWindow::removeDesktop()
{
    // Helpful UI bits
    QListWidget* desktops = findChild<QListWidget*>("desktops");
    desktops->takeItem(desktops->currentRow());
}

void MainWindow::applyDesktop(QString name, int index)
{
    // Helpful ui varaibles
    QListWidget* desktops = findChild<QListWidget*>("desktops");

    // If the index == -1 then the desktop does not exist
    if (index == -1)
    {
        desktops->addItem(name);
    } else
    {
        // Extract the item
        QListWidgetItem* item = desktops->takeItem(index);
        // Change it's text
        item->setText(name);
        // Drop the item back into the list at the same spot
        desktops->insertItem(index, item);
    }
}

//
// Auto start app interface
//

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
}

//
// Configuration buttons
//

void MainWindow::okButton()
{
    applySettings();
    close();
}

void MainWindow::applyButton()
{
    applySettings();
}

//
// Apply settings and store them
//

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
