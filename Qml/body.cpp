#include "body.h"
#include <QDebug>
Body::Body(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void Body::initialize(b2World *wolrd)
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = wolrd->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);


    b2BodyDef m_def;
    m_def.type = b2_dynamicBody;
    m_def.position.Set(0 , 10);
    body = wolrd->CreateBody(&m_def);
    b2PolygonShape box;
    box.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution =0.99999;

    body->CreateFixture(&fixtureDef);
}

void Body::sinc()
{
    b2Vec2 pos = body->GetPosition();
    qreal x = pos.x*10.0f;
    qreal y = (-pos.y +10.0f)*50.0f;
    setPosition(QPointF(x,y));
    qDebug()<<"pos = "<<x<<y;
    update();
}
