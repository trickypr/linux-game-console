#ifndef AUTOSTARTADD_H
#define AUTOSTARTADD_H

#include <QDialog>

namespace Ui {
class AutoStartAdd;
}

class AutoStartAdd : public QDialog
{
    Q_OBJECT

public:
    explicit AutoStartAdd(QWidget *parent = nullptr);
    ~AutoStartAdd();

public slots:
    void accept();

signals:
    void addApp(QString app);

private:
    Ui::AutoStartAdd *ui;
};

#endif // AUTOSTARTADD_H
