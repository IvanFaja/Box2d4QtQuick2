#ifndef SPRINGJOIN_H
#define SPRINGJOIN_H
#include "ropejoin.h"
class SpringJoin : public RopeJoin
{
    Q_OBJECT
    Q_PROPERTY( qreal frecuency READ frecuency WRITE setFrecuency)
    Q_PROPERTY( qreal damping READ damping WRITE setDamping)

public:
    explicit SpringJoin(QQuickItem *parent = 0);
    void initialize(b2World *world);

    qreal frecuency(){return m_hz;}
    void setFrecuency(qreal hz){m_hz = hz;}

    qreal damping(){return m_dampingRatio;}
    void setDamping(qreal damping){m_dampingRatio = damping;}
signals:

public slots:
private:
    qreal m_hz;
    qreal m_dampingRatio;
};

#endif // SPRINGJOIN_H
