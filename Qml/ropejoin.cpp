#include "ropejoin.h"
#include "Box2D/Box2D.h"
RopeJoin::RopeJoin(QQuickItem *parent):Join(parent)
{
    m_length = 0.0f;
}

void RopeJoin::initialize(b2World *world)
{
    m_world = world;
    if(world){
    b2RopeJointDef joinDef;

    joinDef.bodyA = m_bodyA->getBody();
    joinDef.bodyB = m_bodyB->getBody();
    joinDef.localAnchorA =m_bodyA->getBody()->GetLocalCenter();
    joinDef.localAnchorA =m_bodyB->getBody()->GetLocalCenter();
    joinDef.maxLength = m_length;

    joint = world->CreateJoint(&joinDef);
    }
}
