#include "simplestaticbody.h"
#include "Box2D/Box2D.h"
#include <QDebug>
SimpleStaticBody::SimpleStaticBody(QQuickItem *parent) :
    Body(parent)
{
}

void SimpleStaticBody::initialize(b2World *wolrd)
{
    m_wolrd = dynamic_cast<World *>( parent() );
    if(m_wolrd){

        b2BodyDef bodyDef;
        b2Vec2 pos = m_wolrd->pointToBox2d(position());
        bodyDef.position.Set(pos.x,pos.y);
        body = wolrd->CreateBody(&bodyDef);
        b2PolygonShape box;
        box.SetAsBox(m_wolrd->sizeToWorld(width()),
                     m_wolrd->sizeToWorld(height()));
        body->CreateFixture(&box,0.0f);

    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }
}
