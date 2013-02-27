#include "staticbody.h"
#include "Box2D/Box2D.h"
#include <QDebug>
StaticBody::StaticBody(QQuickItem *parent) :
    Body(parent)
{
    points.append(b2Vec2(0,5));
    points.append(b2Vec2(10.0f,6.0f));
    points.append(b2Vec2(20.0f,10.0f));
}

void StaticBody::initialize(b2World *wolrd)
{
    m_wolrd = dynamic_cast<World *>( parent() );
    if(m_wolrd){

        b2BodyDef bodyDef;
        b2Vec2 pos = m_wolrd->pointToBox2d(position());
        bodyDef.position.Set(pos.x,pos.y);
        body = wolrd->CreateBody(&bodyDef);
        b2ChainShape chain;
        chain.CreateLoop( points.data(), points.size() );

        body->CreateFixture(&chain,0.0f);

    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }

}

void StaticBody::sinc()
{
}
