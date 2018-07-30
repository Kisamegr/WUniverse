#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "wuniverse.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");
//    QQuickStyle::setStyle("Fusion");
//    QQuickStyle::setStyle("Imagine");

    WUniverse::registerData();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
