#include "body.h"
#include <QDebug>
#include "Box2D/Box2D.h"
Body::Body(QQuickItem *parent) :
    WorldItem(parent)
{
}

Body::~Body()
{
}

void Body::initialize(b2World *wolrd)
{
    m_wolrd = dynamic_cast<World *>( parent() );
    if(m_wolrd){
        b2BodyDef m_def;
        m_def.type = b2_dynamicBody;

        const b2Vec2 pos = m_wolrd->pointToBox2d(position());
        m_def.position.Set(pos.x,
                           pos.y );
        m_def.linearDamping = 0.2f;
        m_def.angularDamping = 0.2f;
        body = wolrd->CreateBody(&m_def);
        b2PolygonShape box;
        box.SetAsBox(m_wolrd->sizeToWorld(width()), m_wolrd->sizeToWorld(height()));

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.restitution =0.1f;
        body->CreateFixture(&fixtureDef);
    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }
}

void Body::sinc()
{
    const b2Vec2 pos = body->GetPosition();
    float32 angle = body->GetAngle();
    setRotation( angle*180.0f/3.1416f );
    QPointF qPoint = m_wolrd->pointFromWorld(pos);
    setPosition( qPoint );

}

void Body::forceMove(qreal x, qreal y)
{
//    QQuickItem *p = static_cast<QQuickItem *>(parent());
//    QPointF pPos = QQuickItem::mapToItem(p,QPointF(x,y));
////    float32 angle = body->GetTransform().q.GetAngle();
//    b2Vec2 pos = m_wolrd->pointToBox2d(pPos);
//    body->ApplyForce(pos,
//                     body->GetWorldCenter());
////    body->SetTransform(pos,angle);

}


