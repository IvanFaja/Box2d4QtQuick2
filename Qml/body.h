#ifndef BODY_H
#define BODY_H
#include "world.h"
#include "worlditem.h"
#include <QQuickItem>
class b2World;
class b2Body;
class Body : public WorldItem
{
    Q_OBJECT
public:
    explicit Body(QQuickItem *parent = 0);
    ~Body();
    virtual void initialize(b2World * wolrd);
    virtual void sinc();
    Q_INVOKABLE void forceMove( qreal x, qreal y);
    b2Body * getBody(){return body;}
signals:

public slots:
protected:
    b2Body *body;
    World *m_wolrd;
};

#endif // BODY_H
