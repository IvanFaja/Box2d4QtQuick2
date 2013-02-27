#ifndef SIMPLESTATICBODY_H
#define SIMPLESTATICBODY_H
#include "body.h"
class SimpleStaticBody : public Body
{
    Q_OBJECT
public:
    explicit SimpleStaticBody(QQuickItem *parent = 0);
    void initialize(b2World *wolrd);
signals:
    
public slots:
};

#endif // SIMPLESTATICBODY_H
