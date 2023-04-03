#ifndef JOGOSCENE_H
#define JOGOSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>
#include <map.h>
#include <jogador.h>

class JogoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    JogoScene(std::string);
    void setBg(Map &mapa);
    void keyPressEvent(QKeyEvent* event);
    QPointF player_start_position;
    Jogador* jogador;
};

#endif // JOGOSCENE_H
