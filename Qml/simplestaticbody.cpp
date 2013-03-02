#include "simplestaticbody.h"
#include "Box2D/Box2D.h"
#include <QDebug>
SimpleStaticBody::SimpleStaticBody(QQuickItem *parent) :
    Body(parent)
{
}

void SimpleStaticBody::initialize(b2World *wolrd)
{
    type = b2_staticBody;
    m_density =0.0f;
    Body::initialize( wolrd );

}


