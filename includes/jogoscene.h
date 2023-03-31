#ifndef JOGOSCENE_H
#define JOGOSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <map.h>

class JogoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    JogoScene(Map& mapa);
};

#endif // JOGOSCENE_H
