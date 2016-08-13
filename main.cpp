#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtWidgets/QWidget>
#include <QQmlContext>

#include <QDebug>

#include "tictacengine.h"

int main(int argc, char *argv[])
{
    // Init QApplication & set base font
    QGuiApplication app(argc, argv);
    app.setFont(QFont("titilium"));

    // Init back-end engine
    TicTacEngine ticTacEngine;
    // Obtain data model
    TicTacBoard *board = ticTacEngine.board();

    // Register types to QML-side
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("TicTacEngine", &ticTacEngine);
    engine.rootContext()->setContextProperty("TicTacBoard", board);
    engine.rootContext()->setContextProperty("FirstPlayer", ticTacEngine.firstPlayer());
    engine.rootContext()->setContextProperty("SecondPlayer", ticTacEngine.secondPlayer());

    // Load main QML
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
