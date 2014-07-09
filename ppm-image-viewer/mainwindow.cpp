#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpen->setIcon(this->style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionReload->setIcon(this->style()->standardIcon(QStyle::SP_BrowserReload));
    ui->actionExit->setIcon(this->style()->standardIcon(QStyle::SP_DialogCloseButton));
}

MainWindow::~MainWindow()
{
    delete ui;
}
