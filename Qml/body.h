#ifndef BODY_H
#define BODY_H

#include <QQuickItem>

#include "Box2D/Box2D.h"
#include "world.h"
class Body : public QQuickItem
{
    Q_OBJECT
public:
    explicit Body(QQuickItem *parent = 0);
    virtual void initialize(b2World * wolrd);
    virtual void sinc();

signals:
    
public slots:
protected:
    b2Body *body;
    World *m_wolrd;
};

#endif // BODY_H
