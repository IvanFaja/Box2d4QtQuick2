#ifndef WORLDITEM_H
#define WORLDITEM_H

#include <QQuickItem>

class WorldItem : public QQuickItem
{
    Q_OBJECT
public:
    explicit WorldItem(QQuickItem *parent = 0);

    virtual void initialize(b2World * wolrd);
    virtual void sinc();
signals:
public slots:

};

#endif // WORLDITEM_H
