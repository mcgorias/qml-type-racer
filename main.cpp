#include "typeprogresscontroller.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QStringList texts;
    texts << "S'il est vrai que l'humour est la politesse du désespoir, s'il est vrai que le rire, sacrilège blasphématoire que les bigots de toutes les chapelles taxent de vulgarité et de mauvais goût, s'il est vrai que ce rire-là peut parfois désacraliser la bêtise, exorciser les chagrins véritables et fustiger les angoisses mortelles, alors, oui, on peut rire de tout, on doit rire de tout. De la guerre, de la misère et de la mort.";
    texts << "This is a typing race" ;
    texts << "Ceci est une course de frappe";

    TypeProgressController controller;

    engine.rootContext()->setContextProperty("texts",texts);
    engine.rootContext()->setContextProperty("controller",&controller);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;




    return app.exec();
}
