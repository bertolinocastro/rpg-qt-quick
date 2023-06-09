#ifndef JOGOSCENE_H
#define JOGOSCENE_H

//#include "playerstatus.h"
#include <background.h>
#include <jogador.h>
#include <dialog.h>

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>

class JogoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    JogoScene();
    JogoScene(std::string, Jogador* jogador);
    void setBg(Background &mapa);
    void keyPressEvent(QKeyEvent* event);
    QPointF player_start_position;
    Jogador* jogador;
    Background cenario;
    void start_dialog(std::string);

private:
    bool blocked(int x, int y);
    bool special(int x, int y);
};

#endif // JOGOSCENE_H
