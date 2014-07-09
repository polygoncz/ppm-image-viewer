#pragma once

#include <QGraphicsView>
#include <QGraphicsItem>

class ImageView : public QGraphicsView
{
    Q_OBJECT;


public:
    explicit ImageView(QWidget *parent = 0);
    ~ImageView(void);

    void setPixmap(const QPixmap& pixmap);
    virtual void wheelEvent(QWheelEvent* ev);

public slots:
    void zoomIn();
    void zoomOut();
    void fitView();
    void resetView();

signals:
    void zoomed(double factor);

private:
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    double currentScaleFactor;

    static const double stepScaleFactor;
};