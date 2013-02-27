#ifndef ROPEJOIN_H
#define ROPEJOIN_H

#include "join.h"
class RopeJoin : public Join
{
    Q_OBJECT
    Q_PROPERTY( qreal lenght READ lenght WRITE setLenght )
public:
    RopeJoin(QQuickItem * parent = 0);
    void initialize(b2World *world);

    qreal lenght(){return m_lenght;}
    void setLenght(qreal lenght ){
        m_lenght = lenght;
    }
protected:
    float32 m_lenght;
    b2RopeJoint *joint;
};

#endif // ROPEJOIN_H
