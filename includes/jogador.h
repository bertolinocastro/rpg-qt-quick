#ifndef JOGADOR_H
#define JOGADOR_H
#include "definicoes.h"

//#include <QObject>
#include <QGraphicsItem>

class Jogador : public QGraphicsItem//, public QObject
{
//    Q_OBJECT
public:
    Jogador();

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    std::string caminho_sprite = ROOT_DIR"resources/samurai.png";
};

#endif // JOGADOR_H
