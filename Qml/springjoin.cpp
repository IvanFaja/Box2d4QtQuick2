#include "springjoin.h"
#include "Box2D/Box2D.h"
SpringJoin::SpringJoin(QQuickItem *parent) :
    RopeJoin(parent)
{
}

void SpringJoin::initialize(b2World *world)
{
    m_world = world;
    if(world){
        b2DistanceJointDef joinDef;
        joinDef.Initialize(m_bodyA->getBody(),m_bodyB->getBody(),
                           m_bodyA->getBody()->GetPosition(),
                           m_bodyB->getBody()->GetPosition());
        joinDef.collideConnected = true;
        joinDef.frequencyHz = m_hz;
        joinDef.dampingRatio = m_dampingRatio;
        joinDef.length = m_length;
        joint = world->CreateJoint(&joinDef);
    }
}
