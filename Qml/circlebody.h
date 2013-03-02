#ifndef CRICLEBODY_H
#define CRICLEBODY_H
#include "body.h"
class CircleBody : public Body
{
    Q_OBJECT
public:
    explicit CircleBody(QQuickItem *parent = 0);

signals:
    
public slots:
protected:
    void createShape();
    
};

#endif // CRICLEBODY_H
