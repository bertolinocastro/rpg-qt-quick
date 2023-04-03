#ifndef JOGOSCENE_H
#define JOGOSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>
#include <map.h>

class JogoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    JogoScene(Map& mapa);
    void keyPressEvent(QKeyEvent* event);

/*
    void conectaJogador(Jogador* jogador);
signals:
    void sobeJogador();
    void desceJogador();
    void orientaJogador();
    void ocidentaJogador();
*/
};

#endif // JOGOSCENE_H
