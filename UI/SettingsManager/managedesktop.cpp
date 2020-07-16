#include "managedesktop.h"
#include "ui_managedesktop.h"

ManageDesktop::ManageDesktop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDesktop)
{
    ui->setupUi(this);
    index = -1;
}

ManageDesktop::~ManageDesktop()
{
    delete ui;
}

//
// Config functions
//

void ManageDesktop::setDesktopIndex(int index)
{
    this->index = index;
}

void ManageDesktop::setName(QString name)
{
    QLineEdit* desktopName = findChild<QLineEdit*>("desktopName");
    desktopName->setText(name);
}

//
// Close events
//

void ManageDesktop::accept()
{
    QLineEdit* desktopName = findChild<QLineEdit*>("desktopName");
    emit applyDesktop(desktopName->text(), index);
    close();
}
