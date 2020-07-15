#include <QCheckBox>
#include <QVBoxLayout>
#include <QComboBox>

#include <QDebug>

#include "mainwindow.h"
#include "modkey.h"
#include "ui_mainwindow.h"

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

    QCheckBox* editableToggle = findChild<QCheckBox*>("checkBox_enable_config");
    QComboBox* modKey         = findChild<QComboBox*>("modKeyCombo");

    editableToggle->setChecked(settings.value("wm/autoconfig", false).toBool());

    modKey->clear();
    modKey->addItems(ModKey::keys);
    setComboBoxItem(settings.value("wm/modkey", "Mod4").toString(), modKey);

    setItemsEnabled(editableToggle->isChecked());

    connect(editableToggle, &QCheckBox::toggled,
            this, &MainWindow::toggleSettingsEnabled);
}

QSettings MainWindow::settings("TrickyPR", "LGC Settings Manager");

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setItemsEnabled(bool state)
{
    QComboBox* modKey         = findChild<QComboBox*>("modKeyCombo");

    modKey->setEnabled(state);
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
        QComboBox* modKey         = findChild<QComboBox*>("modKeyCombo");

        QString modKeyValue = modKey->currentText();

    }

}
