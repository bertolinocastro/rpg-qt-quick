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
        boneco = new Mago(nome.toStdString());
    }else    if(classe == "Bruxa"){
        boneco = new Bruxa(nome.toStdString());
    }else    if(classe == "Cavaleiro"){
        boneco = new Cavaleiro(nome.toStdString());
    }else    if(classe == "Princesa"){
        boneco = new Princesa(nome.toStdString());
    }else    if(classe == "Aldeao"){
        boneco = new Aldeao(nome.toStdString());
    }else    if(classe == "Monstro"){
        boneco = new Monstro(nome.toStdString());
    }else    if(classe == "Dragao"){
        boneco = new Dragao(nome.toStdString());
    }else if (classe == "Samurai"){
        // TODO: criar classe Samurai e fazer as paradinhas aqui
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
