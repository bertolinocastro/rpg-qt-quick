#include "jogador.h"
#include "definicoes.h"
#include <iostream>
#include <QPainter>

Jogador::Jogador()
{

}

QRectF Jogador::boundingRect() const {
    return QRectF(0, 0, LADO_BLOCOS, LADO_BLOCOS); // supondo o player um quadrado de tamanho 12x12
}

void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QImage img(QString::fromStdString(caminho_sprite));
    img = img.scaled(LADO_BLOCOS, LADO_BLOCOS); // fazendo a imagem ocupar 12px no x e y
    painter->drawImage(0, 0, img);

}