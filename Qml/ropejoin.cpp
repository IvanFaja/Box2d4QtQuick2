#include "ropejoin.h"
#include <Box2D/Rope/b2Rope.h>
RopeJoin::RopeJoin(QQuickItem *parent):Join(parent)
{
    m_lenght = 0.0f;
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
    joinDef.maxLength = m_lenght;

    joint = ( b2RopeJoint* )world->CreateJoint(&joinDef);
    }
}
