#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtWidgets/QWidget>
#include <QQmlContext>

#include <QDebug>

#include "tictacengine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setFont(QFont("titilium"));

    TicTacEngine ticTacEngine;
    TicTacBoard *board = ticTacEngine.board();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("TicTacEngine", &ticTacEngine);
    engine.rootContext()->setContextProperty("TicTacBoard", board);

    qDebug() << board->rowCount();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
