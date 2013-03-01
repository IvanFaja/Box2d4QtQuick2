#include "simplestaticbody.h"
#include "Box2D/Box2D.h"
#include <QDebug>
SimpleStaticBody::SimpleStaticBody(QQuickItem *parent) :
    Body(parent)
{
}

void SimpleStaticBody::initialize(b2World *wolrd)
{
    m_parent = dynamic_cast<World *>( parent() );
    if(m_parent){

        b2BodyDef bodyDef;
        b2Vec2 pos = m_parent->pointToBox2d(position());
        bodyDef.position.Set(pos.x ,
                             pos.y - m_parent->sizeToWorld(height()));
        body = wolrd->CreateBody(&bodyDef);
        b2PolygonShape box;
        box.SetAsBox(m_parent->sizeToWorld(width()/2),
                     m_parent->sizeToWorld(height())/2);
        body->CreateFixture(&box,0.0f);

    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }
}

void SimpleStaticBody::sinc()
{
    const b2Vec2 pos = body->GetPosition();
    float32 angle = body->GetAngle();
    setRotation( angle*180.0f/3.1416f );
    QPointF qPoint = m_parent->pointFromWorld(pos);
    qPoint.setY(qPoint.y() - height());
    setPosition( qPoint );

}

