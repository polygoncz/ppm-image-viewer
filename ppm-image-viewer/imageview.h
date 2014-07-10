//! \file imageview.h

#pragma once

#ifndef _IMAGEVIEW_H
#define _IMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsItem>

/*!
 * Class for displaying single image using QGraphicsView. It can zooming and panning.
 * \author Pavel Lokvenc
 */
class ImageView : public QGraphicsView
{
    Q_OBJECT

public:
    /*!
     * Basic settings of widget.
     */
    explicit ImageView(QWidget *parent = 0);
    ~ImageView(void);

    /*!
     * Provide set image for viewing. It is reset all scaling or panning.
     * \param[in] pixmap displayed image as pixmap.
     */
    void setPixmap(const QPixmap& pixmap);

    /*!
     * Override default wheelEvent for enable zooming.
     * \param[in] ev event object
     */
    virtual void wheelEvent(QWheelEvent* ev);

public slots:
    //! Zoom in action
    void zoomIn();

    //! Zoom out action
    void zoomOut();

    //! Fit in whole window
    void fitView();

    //! Reset all transformation
    void resetView();

signals:
    /*!
     * Emited when after zooming.
     * \param[in] factor current zoom factor
     */
    void zoomed(double factor);

private:
    QGraphicsScene scene; //!< Displayed scene.
    QGraphicsPixmapItem item; //!< Displayed image as pixmap.
    double currentScaleFactor; //!< Current zooming factor.

    static const double stepScaleFactor; //!< Constant zooming step.
};

#endif //_IMAGEVIEW_H