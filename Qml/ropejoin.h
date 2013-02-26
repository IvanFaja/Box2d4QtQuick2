#ifndef ROPEJOIN_H
#define ROPEJOIN_H

#include "join.h"
class RopeJoin : public Join
{
    Q_OBJECT
    Q_PROPERTY( float32 lenght READ lenght WRITE setLenght )
public:
    RopeJoin(QQuickItem * parent);
    void initialize(b2World *world);

    float32 lenght(){return m_lenght;}
    void setLenght(float32 lenght ){
        m_lenght = lenght;
    }
protected:
    float32 m_lenght;
    b2RopeJoint *joint;
};

#endif // ROPEJOIN_H
