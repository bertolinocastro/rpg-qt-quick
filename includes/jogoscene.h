#ifndef JOGOSCENE_H
#define JOGOSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>
#include <background.h>
#include <jogador.h>
#include <dialog.h>

class JogoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    JogoScene(std::string, QString nome, QString classe);
    void setBg(Background &mapa);
    void keyPressEvent(QKeyEvent* event);
    QPointF player_start_position;
    Jogador* jogador;
    Background cenario;

private:
    bool blocked(int x, int y);
    bool special(int x, int y);
    void start_dialog(std::string);
};

#endif // JOGOSCENE_H
