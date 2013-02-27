#ifndef BOX2D4QML_H
#define BOX2D4QML_H

#include <Qml/world.h>
#include <Qml/body.h>
#include <Qml/simplestaticbody.h>
#include <Qml/springjoin.h>
#include <Qml/staticbody.h>
#include <Qml/ropejoin.h>

#define BOX2DQML qmlRegisterType<World>("box2d4qml",1,0,"World");\
qmlRegisterType<Body>("box2d4qml",1,0,"Body");\
qmlRegisterType<SimpleStaticBody>("box2d4qml",1,0,"StaticBox");\
qmlRegisterType<SpringJoin>("box2d4qml",1,0,"Spring");\
qmlRegisterType<StaticBody>("box2d4qml",1,0,"StaticChain");\
qmlRegisterType<RopeJoin>("box2d4qml",1,0,"Rope");
#endif // BOX2D4QML_H
