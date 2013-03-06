#include "body.h"
#include <QDebug>
#include "Box2D/Box2D.h"
Body::Body(QQuickItem *parent) :
    WorldItem(parent)
{
    m_mouse = 0;
    m_restitution = 0;
    m_density = 1.0f;
    m_friction = 0.1f;
    m_moveForce = 11.0f;
    type = b2_dynamicBody;
    isForcingMove = false;
    m_allowUserMove = true;
}

Body::~Body()
{
}

void Body::creteBody(b2World *wolrd)
{
    b2BodyDef m_def;
    m_def.type = static_cast<b2BodyType>(type);
    QPointF qPoint = position();
    qPoint.setX(qPoint.x()+width()/2);
    qPoint.setY(qPoint.y()-height()/2);
    const b2Vec2 pos = m_parent->pointToBox2d(qPoint);
    setTransformOrigin(Center);
    m_def.position.Set(pos.x, pos.y );
    m_def.angle = -rotation()*b2_pi/180.0f;
    m_def.linearDamping = 0.2f;
    m_def.angularDamping = 0.2f;
    body = wolrd->CreateBody(&m_def);
}

void Body::createShape()
{
    const qreal hx = m_parent->sizeToWorld(width());
    const qreal hy = m_parent->sizeToWorld(height());
    b2Vec2 ver[4];

//    ver[0].Set(0, 0);
//    ver[1].Set(0, -hy);
//    ver[2].Set(hx, -hy);
//    ver[3].Set(hx, 0);
//    ver[3].Set(0, 0);
//    ver[2].Set(hx, 0);
//    ver[1].Set(hx, -hy);
//    ver[0].Set(0, -hy);

    ver[0].Set(-hx/2, hy/2);
    ver[1].Set(-hx/2, -hy/2);
    ver[2].Set(hx/2, -hy/2);
    ver[3].Set(hx/2, hy/2);
    b2PolygonShape box;
//        box.SetAsBox(hx,hy);
    box.Set( ver, 4);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = m_density;
    fixtureDef.friction = m_friction;
    fixtureDef.restitution = m_restitution;
    body->CreateFixture(&fixtureDef);
}

void Body::initialize(b2World *wolrd)
{
    m_parent = dynamic_cast<World *>( parent() );
    m_wolrd = wolrd;
    if(m_parent){
        creteBody(wolrd);
        createShape();
    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }
}

void Body::sinc()
{
    const b2Vec2 pos = body->GetPosition();
    float32 angle = body->GetAngle();
    setRotation( -angle*180.0f/b2_pi );
    QPointF qPoint = m_parent->pointFromWorld(pos);
    qPoint.setX(qPoint.x()-width()/2);
    qPoint.setY(qPoint.y()-height()/2);
    setPosition( qPoint );
    if(isForcingMove){
        stepMove();
    }else{
        stepEndMove();
    }
}

void Body::stepMove()
{
//    QQuickItem *p = static_cast<QQuickItem *>(parent());
//    QPointF pPos = QQuickItem::mapToItem(p,QPointF(mx,my));
    b2Vec2 pos = m_parent->pointToBox2d(QPointF(mx,my));
    if(m_mouse == 0){
        b2MouseJointDef def;
        def.bodyA = m_parent->referenceBody();
        def.bodyB = body;
        def.collideConnected = true;
        def.maxForce = m_moveForce *body->GetMass();
        def.target = pos;
        m_mouse = (b2MouseJoint *) m_wolrd->CreateJoint(&def);
    }
    else{
        m_mouse->SetTarget(pos);
        qDebug()<<"################"<<pos.x<<pos.y;
    }
}

void Body::forceMove(qreal x, qreal y)
{
    if(m_allowUserMove == false)
        return;
    mx = x;
    my = y;
    isForcingMove = true;
//    body->SetTransform(pos,body->GetAngle());
}


void Body::endMove()
{
    isForcingMove = false;
}

void Body::stepEndMove()
{
    if(m_mouse){
        m_wolrd->DestroyJoint(m_mouse);
        m_mouse = 0;
        qDebug()<<"body free ";
    }
}

