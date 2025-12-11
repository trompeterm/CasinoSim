#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinButton_clicked();
    void on_addChipsBtn_clicked();

    void on_navToSlots_triggered();
    void on_navToMenu_triggered();
    void on_navToBlackjack_triggered();


    void on_dealButton_clicked();

    void on_hitButton_clicked();

    void on_standButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
