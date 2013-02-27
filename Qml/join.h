#ifndef JOIN_H
#define JOIN_H
#include "worlditem.h"
#include "body.h"

class Join : public WorldItem
{
    Q_OBJECT
    Q_PROPERTY( Body* bodyA READ bodyA  WRITE setBodyA )
    Q_PROPERTY( Body* bodyB READ bodyB  WRITE setBodyB )
public:
    explicit Join(QQuickItem *parent = 0);

    Body* bodyA(){return m_bodyA;}
    Body* bodyB(){return m_bodyB;}

    void setBodyA(Body* body){
        m_bodyA = body;
    }

    void setBodyB(Body* body){
        m_bodyB = body;
    }
signals:

public slots:
protected:
    Body *m_bodyA;
    Body *m_bodyB;
    b2World * m_world;
};

#endif // JOIN_H
