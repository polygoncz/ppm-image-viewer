#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    statusBarZoomLabel(new QLabel("Pumba je prase")),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpen->setIcon(this->style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionReload->setIcon(this->style()->standardIcon(QStyle::SP_BrowserReload));
    ui->actionExit->setIcon(this->style()->standardIcon(QStyle::SP_DialogCloseButton));

    ui->actionZoomIn->setDisabled(true);
    ui->actionZoomOut->setDisabled(true);
    ui->actionFit->setDisabled(true);
    ui->actionResetView->setDisabled(true);

    //add label to status bar
    ui->statusBar->addPermanentWidget(statusBarZoomLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoad()
{
    QString file = QFileDialog::getOpenFileName(this, "Open image file", "", "PPM (*.ppm)");

    if (file.isEmpty()) return;

    if (!QFile::exists(file))
    {
        QMessageBox::critical(this, "Error on loading", "File not found!");
        return;
    }

    filename = file;
    
    QPixmap pixmap(filename);
    ui->imageView->setPixmap(pixmap);

    ui->actionZoomIn->setEnabled(true);
    ui->actionZoomOut->setEnabled(true);
    ui->actionFit->setEnabled(true);
    ui->actionResetView->setEnabled(true);
}

void MainWindow::onReload()
{
    if (filename.isEmpty()) return;

    if (!QFile::exists(filename))
    {
        QMessageBox::critical(this, "Error on loading", "File not found!");
        return;
    }
    
    QPixmap pixmap(filename);
    ui->imageView->setPixmap(pixmap);
}

void MainWindow::onZoomed(double factor)
{
    statusBarZoomLabel->setText("Zoom: " + QString::number(factor * 100.0, 'f', 0) + "%");
}