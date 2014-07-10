//! \file mainwindow.h

#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui
{
class MainWindow;
}

/*!
 * Class for MainWindow
 * \author Pavel Lokvenc
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*!
     * Slot for loading image action. Load image file and store its #filename for reloading.
     */
    void onLoad();

    /*!
     * Slot for reload action. Check the filename and reload it.
     */
    void onReload();

    /*!
     * Slot for signal zoomed from ImageView. It can use information about zoom factor.
     * \param[in] factor Factor of zooming current loaded image.
     */
    void onZoomed(double factor);

private:
    Ui::MainWindow *ui; //!< Genereated UI.

    QString filename; //!< Store filename for realoading.
    QLabel* statusBarZoomLabel; //!< Label for display zoom percent in status bar.
};

#endif // MAINWINDOW_H
