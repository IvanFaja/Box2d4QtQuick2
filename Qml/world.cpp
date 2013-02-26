#include "world.h"
#include "Box2D/Box2D.h"
#include "worlditem.h"

#include <QDebug>

World::World(QQuickItem *parent) :
    QQuickItem(parent)
{

}

World::~World()
{
    delete m_wolrd;
}

void World::setGx(float x)
{
    m_gravity.setX(x);
}

float World::gx()
{
    return m_gravity.x();
}
void World::setGy(float y)
{
    m_gravity.setY(y);
}

float World::gy()
{
    return m_gravity.y();
}
void World::componentComplete()
{
    QQuickItem::componentComplete();
    b2Vec2 g(m_gravity.x(),m_gravity.y());
    qDebug()<<"gravity"<<m_gravity.x()<<m_gravity.y();
    m_wolrd = new b2World(g);
    QList<QQuickItem*> children = childItems();
    for(int i = 0 ;i < children.size() ;++i){
        Body* body = dynamic_cast<WorldItem*>(children.at(i));
        if(body){
            body->initialize( m_wolrd );
        }else{
            qWarning()<<"World item child must be a Body";
        }
    }
    int timeStep = 1000/24;
    timer.start(timeStep,this);
}

void World::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId()) {
        step();
    } else {
        QQuickItem::timerEvent(event);
    }
}


void World::step()
{
    float32 timeStep = 1.0f/24.0f;
    qDebug()<<"sinc"<<timeStep;
    m_wolrd->Step(timeStep,10,5);
    QList<QQuickItem*> children = childItems();
    for(int i = 0 ;i < children.size() ;++i){
        Body* body = dynamic_cast<Body*>(children.at(i));
        if(body){
            body->sinc();
        }else{
            qWarning()<<"World item child must be a Body";
        }
    }
}
