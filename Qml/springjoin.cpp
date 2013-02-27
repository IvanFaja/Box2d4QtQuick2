#include "springjoin.h"

SpringJoin::SpringJoin(QQuickItem *parent) :
    RopeJoin(parent)
{
}

void SpringJoin::initialize(b2World *wolrd)
{
    m_world = world;
    if(world){
    b2DistanceJointDef joinDef;
    joinDef.Initialize(bodyA()->getBody(),bodyB()->getBody(),
                        bodyA()->getBody()->GetPosition(),
                        bodyB()->getBody()->GetPosition());
    joinDef.collideConnected = true;
    joinDef.frequencyHz = m_hz;
    joinDef.dampingRatio = m_dampingRatio;
    joinDef.length = m_length;
    joint = world->CreateJoint(&joinDef);
    }
}
