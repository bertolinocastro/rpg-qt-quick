#ifndef JOGADOR_H
#define JOGADOR_H
#include "definicoes.h"
#include "classes.h"

//#include <QObject>
#include <QGraphicsItem>

class Jogador : public QGraphicsItem//, public QObject
{
//    Q_OBJECT
public:
    Jogador(QString nome, QString classe);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    FormaDeVida* boneco;
    QString nome;
    QString classe;
};

#endif // JOGADOR_H
