#ifndef BODY_H
#define BODY_H


#include "world.h"
#include "Box2D/Box2D.h"
#include "worlditem.h"

#include <QQuickItem>

class Body : public WorldItem
{
    Q_OBJECT
public:
    explicit Body(QQuickItem *parent = 0);
    virtual void initialize(b2World * wolrd);
    virtual void sinc();
    b2Body * getBody(){return body;}
signals:

public slots:
protected:
    b2Body *body;
    World *m_wolrd;
};

#endif // BODY_H
