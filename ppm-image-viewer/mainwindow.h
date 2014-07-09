#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui 
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onLoad();
    void onReload();
    void onZoomed(double factor);

private:
    Ui::MainWindow *ui;

    QString filename;
    QLabel* statusBarZoomLabel;
};

#endif // MAINWINDOW_H
