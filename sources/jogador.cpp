#include "jogador.h"
#include "definicoes.h"
#include <QPainter>

Jogador::Jogador()
{

}

QRectF Jogador::boundingRect() const {
    //return QRectF(-LADO_BLOCOS/2, -LADO_BLOCOS/2, LADO_BLOCOS, LADO_BLOCOS); // supondo o player um quadrado de tamanho 12x12
    return QRectF(128, 128, 128, 128); // supondo o player um quadrado de tamanho 12x12
}

void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage img(QString::fromStdString(caminho_sprite));
    img = img.scaled(LADO_BLOCOS, LADO_BLOCOS); // fazendo a imagem ocupar 12px no x e y
    painter->drawImage(-LADO_BLOCOS/2, -LADO_BLOCOS/2, img);

}

void Jogador::andaDireita()
{

}

void Jogador::andaEsquerda()
{

}

void Jogador::andaCima()
{

}

void Jogador::andaBaixo()
{

}
