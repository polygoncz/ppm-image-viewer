#pragma once

#include <QtWidgets/QGraphicsView>

class ImageView : public QGraphicsView
{
    Q_OBJECT;


public:
    explicit ImageView(QWidget *parent = 0);
    ~ImageView(void);
};

