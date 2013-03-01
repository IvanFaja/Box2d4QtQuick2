#ifndef BODY_H
#define BODY_H
#include "world.h"
#include "worlditem.h"
#include <QQuickItem>
class b2World;
class b2Body;
class b2MouseJoint;
class Body : public WorldItem
{
    Q_OBJECT
public:
    explicit Body(QQuickItem *parent = 0);
    ~Body();
    virtual void initialize(b2World * wolrd);
    virtual void sinc();
    Q_INVOKABLE void forceMove( qreal x, qreal y);
    Q_INVOKABLE void endMove();
    b2Body * getBody(){return body;}
signals:

public slots:
protected:
    b2Body *body;
    World *m_parent;
    b2World *m_wolrd;
    b2MouseJoint * m_mouse;
};

#endif // BODY_H
