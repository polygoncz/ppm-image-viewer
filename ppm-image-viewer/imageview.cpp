#include "ImageView.h"

#include <QGraphicsItem>

ImageView::ImageView(QWidget *parent)
    : QGraphicsView(parent)
{
    scene.addItem(&item);
    scene.setBackgroundBrush(QBrush(Qt::gray));
    setScene(&scene);
}


ImageView::~ImageView(void)
{}

void ImageView::setPixmap(const QPixmap& pixmap)
{
    item.setPixmap(pixmap);
    update();
}