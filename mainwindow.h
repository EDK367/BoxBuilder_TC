#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "rules/GameRules.h"
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
    void on_playersB_clicked();
    void updateBoardRequirements();
    bool isDuplicate(const QString& letterNew, const QString& colorNew);

    void on_play_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QDialog *popup;
    int minRow;
    int minColumn;
    int numberPlayers;
    bool rowAcept;
    bool columnAcept;

};

#endif // MAINWINDOW_H
