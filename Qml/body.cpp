#include "body.h"
#include <QDebug>
Body::Body(QQuickItem *parent) :
    WorldItem(parent)
{
}

void Body::initialize(b2World *wolrd)
{
    m_wolrd = dynamic_cast<World *>( parent() );
    if(m_wolrd){
        b2BodyDef m_def;
        m_def.type = b2_dynamicBody;

        b2Vec2 pos = m_wolrd->pointToBox2d(position());
        m_def.position.Set(pos.x,pos.y);

        body = wolrd->CreateBody(&m_def);
        b2PolygonShape box;
        box.SetAsBox(1.0f, 1.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.restitution =0.1;

        body->CreateFixture(&fixtureDef);
    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }
}

void Body::sinc()
{
    b2Vec2 pos = body->GetPosition();
    float32 angle = body->GetAngle();
    setRotation( angle*180.0f/3.1416f );
    setPosition(m_wolrd->pointFromWorld(pos));
    qDebug()<<"pos = "<<x()<<y();
    update();
}


