#include "staticbody.h"

#include <QDebug>
StaticBody::StaticBody(QQuickItem *parent) :
    Body(parent)
{
    points.append(b2Vec2(0,10));
    points.append(b2Vec2(300,50));
}

void StaticBody::initialize(b2World *wolrd)
{
    m_wolrd = dynamic_cast<World *>( parent() );
    if(m_wolrd){

        b2BodyDef bodyDef;
        body = wolrd->CreateBody(&bodyDef);
        b2ChainShape chain;
        chain.CreateChain( points.data(), points.size() );

        body->CreateFixture(&chain,0.0f);

    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }

}

void StaticBody::sinc()
{
    //static body dont move
    qWarning()<<" ******************* ";
    b2Vec2 pos = body->GetPosition();
    qDebug()<<"pos = "<<pos.x<<pos.y;
}
