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
    void setBg(Map &mapa);
    void keyPressEvent(QKeyEvent* event);

};

#endif // JOGOSCENE_H
