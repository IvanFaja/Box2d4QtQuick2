#include "world.h"
#include "Box2D/Box2D.h"
#include "worlditem.h"

#include <QDebug>

void World::createRefecence()
{
    b2BodyDef bodyDef;
    bodyDef.position.Set(0,0);
    m_referenceBody = m_wolrd->CreateBody(&bodyDef);
    b2PolygonShape box;
    box.SetAsBox(0.1f,
                 0.1f);
    m_referenceBody->CreateFixture(&box,0.0f);
}

World::World(QQuickItem *parent) :
    QQuickItem(parent)
{
    scale = 0.1;

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

b2Vec2 World::pointToBox2d(const QPointF &point)
{
    b2Vec2 worldPoint;
    worldPoint.x = sizeToWorld( point.x());
    worldPoint.y = sizeToWorld( - point.y() );
    return worldPoint;
}

QPointF World::pointFromWorld(const b2Vec2 &point)
{
    QPointF itemPoint;
    itemPoint.setX(sizeFromWorld(point.x));
    itemPoint.setY(-sizeFromWorld( point.y ));
    return itemPoint;
}

void World::componentComplete()
{
    QQuickItem::componentComplete();
    b2Vec2 g(m_gravity.x(),m_gravity.y());
    qDebug()<<"gravity"<<m_gravity.x()<<m_gravity.y();
    m_wolrd = new b2World(g);
    createRefecence();
    QList<QQuickItem*> children = childItems();
    for(int i = 0 ;i < children.size() ;++i){
        WorldItem* tiem = dynamic_cast<WorldItem*>(children.at(i));
        if(tiem){
            tiem->initialize( m_wolrd );
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

    m_wolrd->Step(timeStep,10,5);
    QList<QQuickItem*> children = childItems();
    for(int i = 0 ;i < children.size() ;++i){
        WorldItem* item = dynamic_cast<WorldItem*>(children.at(i));
        if(item){
            item->sinc();
        }else{
            qWarning()<<"World item child must be a Body";
        }
    }
}


qreal World::sizeToWorld(qreal size)
{
    return size*scale;
}

qreal World::sizeFromWorld(qreal size)
{
    return size/scale;
}
