#include "world.h"
#include "Box2D/Box2D.h"
#include "worlditem.h"
#include "body.h"
#include <QDebug>

void World::createRefecence()
{
    b2BodyDef bodyDef;
    m_referenceBody = m_wolrd->CreateBody(&bodyDef);
    itemMoved =0;
}

void World::addWorldItem(WorldItem *item)
{
    m_items.append(item);
}

void World::move(qreal x, qreal y)
{
    if(itemMoved){
        itemMoved->forceMove(x,y);
    }else{
    itemMoved = dynamic_cast<Body*>(childAt(x,y));
    }
}

void World::endMove()
{
    if(itemMoved){
        itemMoved->endMove();
        itemMoved = 0;
    }
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
        WorldItem* item = dynamic_cast<WorldItem*>(children.at(i));
        if(item){
            item->initialize( m_wolrd );
            addWorldItem( item );
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
    for(int i = 0 ;i < m_items.size() ;++i){
        WorldItem* item = m_items.at(i);
        item->sinc();
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
