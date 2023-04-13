#include "jogador.h"
#include "definicoes.h"
#include <iostream>
#include <QPainter>

Jogador::Jogador(QString nome, QString classe)
{
    /* Personagens: mago, bruxa, cavaleiro, princesa, aldeao, monstro, dragao.*/

    this->name = nome;
    this->classe = classe;
    if (classe == "Samurai") {
        Samurai* bnco = new Samurai();
        caminho_sprite = bnco->caminho_sprite;
        hp = bnco->getMaxHP();
        mp = bnco->getMaxMP();
    }
    else if(classe ==  "Ninja") {
        Ninja* bnco = new Ninja();
        caminho_sprite = bnco->caminho_sprite;
        hp = bnco->getMaxHP();
        mp = bnco->getMaxMP();
    }
    else if(classe == "Místico") {
        Mystic* bnco = new Mystic();
        caminho_sprite = bnco->caminho_sprite;
        hp = bnco->getMaxHP();
        mp = bnco->getMaxMP();
    }

}


QRectF Jogador::boundingRect() const {
    return QRectF(0, 0, LADO_BLOCOS, LADO_BLOCOS); // supondo o player um quadrado de tamanho 12x12
}

void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QImage img(QString::fromStdString(caminho_sprite));
    img = img.scaled(LADO_BLOCOS, LADO_BLOCOS); // fazendo a imagem ocupar 12px no x e y
    painter->drawImage(0, 0, img);

}


QString Jogador::getName() {
    return name;
}

void Jogador::setHP(int new_v) {
    hp = new_v;
}

void Jogador::setMP(int new_v) {
    mp = new_v;
}

int Jogador::getHP() {
    return hp;
}


int Jogador::getMP() {
    return mp;
}
