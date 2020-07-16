#include "autostartadd.h"
#include "ui_autostartadd.h"

#include "desktopapps.h"

AutoStartAdd::AutoStartAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutoStartAdd)
{
    ui->setupUi(this);

    QComboBox* appBox           = findChild<QComboBox*>("comboBoxApp");

    appBox->clear();
    appBox->addItems(DesktopApps());
}

void AutoStartAdd::accept()
{
    QComboBox* appBox           = findChild<QComboBox*>("comboBoxApp");

    emit addApp(appBox->currentText());

    close();
}

AutoStartAdd::~AutoStartAdd()
{
    delete ui;
}
