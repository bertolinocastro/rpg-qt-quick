#ifndef JOGADOR_H
#define JOGADOR_H

//#include <QObject>
#include <QGraphicsItem>

class Jogador : public QGraphicsItem//, public QObject
{
//    Q_OBJECT
public:
    Jogador();


    void andaDireita();
    void andaEsquerda();
    void andaCima();
    void andaBaixo();
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
private:
    std::string caminho_sprite = "../resources/jogador.png";
};

#endif // JOGADOR_H
