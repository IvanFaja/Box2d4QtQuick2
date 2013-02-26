#ifndef STATICBODY_H
#include "body.h"
#include <QVector>

class StaticBody : public Body
{
    Q_OBJECT
public:
    explicit StaticBody(QQuickItem *parent = 0);
    void initialize(b2World *wolrd);
    void sinc();
signals:
    
public slots:
private:
    QVector<b2Vec2> points;
};

#endif // STATICBODY_H
