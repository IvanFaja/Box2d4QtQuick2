#include "staticbody.h"
#include "Box2D/Box2D.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>

StaticBody::StaticBody(QQuickItem *parent) :
    Body(parent)
{
}

void StaticBody::initialize(b2World *wolrd)
{
    m_parent = dynamic_cast<World *>( parent() );
    m_wolrd = wolrd;
    if(m_parent){
        updateShape();
    }else {
        qWarning()<<" body parent must be a Wolrd ";
    }

}

void StaticBody::sinc()
{
}

void StaticBody::setPath(const QString &path)
{
    m_path = path;
}

void StaticBody::updateShape()
{
    if(load()){
        b2BodyDef bodyDef;
        b2Vec2 pos = m_parent->pointToBox2d(position());
        bodyDef.position.Set(pos.x,pos.y );
        body = m_wolrd->CreateBody(&bodyDef);
        load();
        b2ChainShape chain;
        chain.CreateChain( points.data(), points.size() );
        body->CreateFixture(&chain,0.0f);
    }
}

bool StaticBody::load()
{
    QDir dir(m_path);
    QFile file(dir.filePath(m_fileName));
    QByteArray data;
    QJsonDocument json;
    if(file.open(QIODevice::ReadOnly)){
        data = file.readAll();
        json = QJsonDocument::fromBinaryData(data);
    }else{
        qDebug<<"could not open file"<<file.fileName();
    }
    if(json.isNull() == false){
        QJsonArray array = json.array();
        QJsonArray::iterator point = array.begin();
        for(;point != array.end();--point){
            QJsonObject pointObject = (*point).toObject();
            float x = pointObject.value("x").toDouble();
            float y = pointObject.value("y").toDouble();
            QPointF qmlPoint(x,y);
            b2Vec2 worldPoint = m_parent->pointToBox2d(qmlPoint);
            points.append(worldPoint);
        }
        return true;
    }else{
        qDebug<<"file data is nor suported"<<file.fileName();
    }
    return false;
}
