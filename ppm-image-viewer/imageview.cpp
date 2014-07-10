#include "ImageView.h"

#include <QGraphicsItem>
#include <QWheelEvent>

const double ImageView::stepScaleFactor = 1.15;

ImageView::ImageView(QWidget *parent)
    : QGraphicsView(parent)
{
    //Scene setup
    scene.addItem(&item);
    scene.setBackgroundBrush(QBrush(Qt::gray));
    setScene(&scene);

    currentScaleFactor = 1.0;

    //panning
    setDragMode(ScrollHandDrag);
}

ImageView::~ImageView(void)
{}

void ImageView::setPixmap(const QPixmap& pixmap)
{
    item.setPixmap(pixmap);
    resetView();
    update();
}

void ImageView::wheelEvent(QWheelEvent* ev)
{
    if (ev->delta() > 0)
        zoomIn();
    else
        zoomOut();

    ev->accept();
}

void ImageView::zoomIn()
{
    scale(stepScaleFactor, stepScaleFactor);
    currentScaleFactor *= stepScaleFactor;
    emit zoomed(currentScaleFactor);
}

void ImageView::zoomOut()
{
    scale(1.0 / stepScaleFactor, 1.0 / stepScaleFactor);
    currentScaleFactor /= stepScaleFactor;
    emit zoomed(currentScaleFactor);
}

void ImageView::fitView()
{
    fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    currentScaleFactor = transform().m11();
    emit zoomed(currentScaleFactor);
}

void ImageView::resetView()
{
    resetTransform();
    currentScaleFactor = 1.0;
    emit zoomed(currentScaleFactor);
}