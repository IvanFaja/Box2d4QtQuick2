#ifndef BODY_H
#define BODY_H

#include <QQuickItem>
#include "Box2D/Box2D.h"
class Body : public QQuickItem
{
    Q_OBJECT
public:
    explicit Body(QQuickItem *parent = 0);
    void initialize(b2World * wolrd);
    void sinc();
signals:
    
public slots:
private:
    b2Body *body;
};

#endif // BODY_H
