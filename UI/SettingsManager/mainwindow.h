#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static QSettings settings;

public slots:
    void toggleSettingsEnabled(bool state);

    void addAppClick();
    void addAutoApp(QString app);
    void removeAppClick();

    void desktopAddDialog();
    void desktopEditDialog();
    void removeDesktop();
    void applyDesktop(QString name, int index);

    void applyButton();
    void okButton();

private:
    Ui::MainWindow *ui;

    void setItemsEnabled(bool state);

    void applySettings();
};
#endif // MAINWINDOW_H
