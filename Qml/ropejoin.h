#ifndef ROPEJOIN_H
#define ROPEJOIN_H

#include "join.h"
class RopeJoin : public Join
{
    Q_OBJECT
    Q_PROPERTY( qreal length READ lenght WRITE setLength )
public:
    RopeJoin(QQuickItem * parent = 0);
    virtual void initialize(b2World *world);

    qreal lenght(){return m_length;}
    void setLenght(qreal lenght ){
        m_length = lenght;
    }
protected:
    float32 m_length;
    b2Joint *joint;
};

#endif // ROPEJOIN_H
