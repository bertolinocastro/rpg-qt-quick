#ifndef JOGADOR_H
#define JOGADOR_H
//#include "definicoes.h"
#include "classes.h"

//#include <QObject>
#include <QGraphicsItem>

class Jogador : public QGraphicsItem
{
//    Q_OBJECT
public:
    Jogador(QString nome, QString classe);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    Template* boneco;
    QString name;
    QString classe;
    int hp;
    int mp;

    QString getName();
    int getHP();
    void setHP(int v);
    int getMP();
    void setMP(int v);

private:
    std::string caminho_sprite;

//public:
//signals:/*
//    void atualizaPlayerStatus();*/
};

#endif // JOGADOR_H

