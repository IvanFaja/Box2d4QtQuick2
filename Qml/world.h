#ifndef WORD_H
#define WORD_H

#include <QQuickItem>
#include "Box2D/Box2D.h"
#include <QBasicTimer>
class World : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY( float gx READ gx WRITE setGx )
    Q_PROPERTY( float gy READ gy WRITE setGy )
public:
    explicit World(QQuickItem *parent = 0);
    ~World();
    void setGx(float x);
    float gx();
    void setGy(float y);
    float gy();

    b2Vec2 pointToBox2d( const QPointF &point);
    QPointF pointFromWorld(const b2Vec2 &point);

    float32 sizeToWorld( float32 size );
    float32 sizeFromWorld( float32 size );

signals:

protected:
    void componentComplete();
    void timerEvent(QTimerEvent *event);
private:
    void step();
    QBasicTimer timer;
    b2World * m_wolrd;
    QPointF m_gravity;
    float32 scale;
};

#endif // WORD_H
