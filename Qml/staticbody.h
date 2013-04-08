#ifndef STATICBODY_H
#include "body.h"
#include <QVector>

class StaticBody : public Body
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    Q_PROPERTY(QString path READ path WRITE setPath)

public:
    explicit StaticBody(QQuickItem *parent = 0);
    void initialize(b2World *wolrd);
    void sinc();

    const QString& fileName()const {return m_fileName;}
    void setFileName(QString name){m_fileName = name;}

    const QString& path()const{return m_path;}
    void setPath(const QString &path);

signals:
    
public slots:
    void updateShape();
private:
    bool load();
    QVector<b2Vec2> points;
    QString m_fileName;
    QString m_path;
};

#endif // STATICBODY_H
