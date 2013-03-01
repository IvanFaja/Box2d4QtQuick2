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
    Q_PROPERTY(qreal restitution READ restitution WRITE setRestitution)
    Q_PROPERTY(qreal density READ density WRITE setDensity)
    Q_PROPERTY(qreal friction READ friction WRITE setFriction)
    Q_PROPERTY(qreal moveForce READ moveForce WRITE setMoveForce)
public:
    explicit Body(QQuickItem *parent = 0);
    ~Body();
    virtual void initialize(b2World * wolrd);
    virtual void sinc();
    Q_INVOKABLE void forceMove( qreal x, qreal y);
    Q_INVOKABLE void endMove();
    b2Body * getBody(){return body;}

    qreal restitution(){return m_restitution;}
    void setRestitution(qreal res){m_restitution = res;}

    qreal density(){return m_density;}
    void setDensity(qreal val){m_density = val;}

    qreal friction(){return m_friction;}
    void setFriction(qreal val){m_friction = val;}

    qreal moveForce(){return m_moveForce;}
    void setMoveForce(qreal val){m_moveForce = val;}

signals:

public slots:
protected:
    b2Body *body;
    World *m_parent;
    b2World *m_wolrd;
    b2MouseJoint * m_mouse;
    qreal m_restitution;
    qreal m_density;
    qreal m_friction;
    qreal m_moveForce;
};

#endif // BODY_H
