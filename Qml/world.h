#ifndef WORD_H
#define WORD_H

#include <QQuickItem>
#include <QBasicTimer>
#include <Box2D/Common/b2Math.h>
class b2World;
class b2Body;
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

    inline b2Body* referenceBody(){return m_referenceBody;}
    b2Vec2 pointToBox2d( const QPointF &point);
    QPointF pointFromWorld(const b2Vec2 &point);

    Q_INVOKABLE qreal sizeToWorld( qreal size );
    Q_INVOKABLE qreal sizeFromWorld( qreal size );

    void createRefecence();
signals:

protected:
    void componentComplete();
    void timerEvent(QTimerEvent *event);
private:
    void step();
    QBasicTimer timer;
    b2World * m_wolrd;
    QPointF m_gravity;
    qreal scale;
    b2Body* m_referenceBody;
};

#endif // WORD_H
