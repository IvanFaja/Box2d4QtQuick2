#include "circlebody.h"
#include "Box2D/Box2D.h"
#include <QDebug>
CircleBody::CircleBody(QQuickItem *parent) :
    Body(parent)
{
}

void CircleBody::createShape()
{
    b2CircleShape shape;
    shape.m_radius = m_parent->sizeToWorld(width()/2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = m_density;
    fixtureDef.friction = m_friction;
    fixtureDef.restitution = m_restitution;
    body->CreateFixture(&fixtureDef);
}


