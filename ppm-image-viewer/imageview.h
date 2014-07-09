#pragma once

#include <QtWidgets/QGraphicsView>
#include <QGraphicsItem>

class ImageView : public QGraphicsView
{
    Q_OBJECT;


public:
    explicit ImageView(QWidget *parent = 0);
    ~ImageView(void);

    void setPixmap(const QPixmap& pixmap);

private:
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
};

