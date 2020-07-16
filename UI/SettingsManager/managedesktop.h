#ifndef MANAGEDESKTOP_H
#define MANAGEDESKTOP_H

#include <QDialog>

namespace Ui {
class ManageDesktop;
}

class ManageDesktop : public QDialog
{
    Q_OBJECT

public:
    explicit ManageDesktop(QWidget *parent = nullptr);
    ~ManageDesktop();

    void setDesktopIndex(int index);
    void setName(QString name);

    void applyButton();

public slots:
    void accept();

signals:
    void applyDesktop(QString name, int index);

private:
    Ui::ManageDesktop *ui;
    int index;
};

#endif // MANAGEDESKTOP_H
