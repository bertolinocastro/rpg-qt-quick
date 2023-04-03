#ifndef JOGOSCENE_H
#define JOGOSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>
#include <background.h>
#include <jogador.h>

class JogoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    JogoScene(std::string);
    void setBg(Background &mapa);
    void keyPressEvent(QKeyEvent* event);
    QPointF player_start_position;
    Jogador* jogador;
    Background mapa;
};

#endif // JOGOSCENE_H
