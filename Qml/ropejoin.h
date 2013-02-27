#ifndef ROPEJOIN_H
#define ROPEJOIN_H
#include "join.h"
struct b2Joint;
class RopeJoin : public Join
{
    Q_OBJECT
    Q_PROPERTY( qreal length READ length WRITE setLength )
public:
    RopeJoin(QQuickItem * parent = 0);
    virtual void initialize(b2World *world);

    qreal length(){return m_length;}
    void setLength(qreal lenght ){
        m_length = lenght;
    }
protected:
    qreal m_length;
    b2Joint *joint;
};

#endif // ROPEJOIN_H
