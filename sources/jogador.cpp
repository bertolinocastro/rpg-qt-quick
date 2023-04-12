#include "jogador.h"
#include "definicoes.h"
#include <iostream>
#include <QPainter>

Jogador::Jogador(QString nome, QString classe)
{
    /* Personagens: mago, bruxa, cavaleiro, princesa, aldeao, monstro, dragao.*/

    this->nome = nome;
    this->classe = classe;
    if(classe == "Mago"){
        Mago* bnco = new Mago(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
    }else    if(classe == "Bruxa"){
        Bruxa* bnco = new Bruxa(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
    }else    if(classe == "Cavaleiro"){
        Cavaleiro* bnco = new Cavaleiro(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
    }else    if(classe == "Princesa"){
        Princesa* bnco = new Princesa(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
    }else    if(classe == "Aldeao"){
        Aldeao* bnco = new Aldeao(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
    }else    if(classe == "Monstro"){
        Monstro* bnco = new Monstro(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
    }else    if(classe == "Dragao"){
        Dragao* bnco = new Dragao(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
    }else if (classe == "Samurai"){
        Samurai* bnco = new Samurai(nome.toStdString());
        boneco = bnco;
        caminho_sprite = bnco->caminho_sprite;
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
