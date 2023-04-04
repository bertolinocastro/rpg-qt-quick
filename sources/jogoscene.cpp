#include <iostream>
#include <cmath>
#include <QGraphicsItem>
#include "jogoscene.h"
#include "definicoes.h"

JogoScene::JogoScene(std::string file) : QGraphicsScene(0, 0, N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS) {
    std::cout << " rect da cena " << sceneRect().width() << " " << sceneRect().height() << std::endl;
    player_start_position = QPointF(2*LADO_BLOCOS,45*LADO_BLOCOS);

    cenario =  Background(file);
    int n = 48;
    int m = 48;
    for (int i=0;i<n;i++){
		std::cout << std::endl;
		std::cout << "|";
		for (int k=0;k<m;k++){
			if(k>0) std::cout << " ";
			std::cout << cenario.mapa[i][k];
			if(k==m-1) std::cout << "|";
		}
	}

    jogador = new Jogador();
    jogador->setPos(player_start_position);
    addItem(jogador);
}

bool JogoScene::blocked(int x, int y) {
    char token = cenario.mapa[y][x];
    switch(token){
        case ' ':
            return false;
        case 'B':
            return false;
        case 'C':
            return false;
        case 'S':
            return false;
        case 'W':
            return true;
        case 'T':
            return false;
        case 'R':
            return true;
        case 'F':
            return true;
        default:
            return true;
        }
}

void JogoScene::keyPressEvent(QKeyEvent* event) {
    switch(event->key()){
    case Qt::Key_Up:
        if (!JogoScene::blocked(std::floor(jogador->scenePos().x()/LADO_BLOCOS), std::floor((jogador->scenePos().y()-LADO_BLOCOS)/LADO_BLOCOS))) {
            jogador->setPos(jogador->scenePos().x(), jogador->scenePos().y()-LADO_BLOCOS);
        }
        break;
    case Qt::Key_Down:
        if (!JogoScene::blocked(std::floor(jogador->scenePos().x()/LADO_BLOCOS), std::floor((jogador->scenePos().y()+LADO_BLOCOS)/LADO_BLOCOS))) {
            jogador->setPos(jogador->scenePos().x(), jogador->scenePos().y()+LADO_BLOCOS);
        }
        break;
    case Qt::Key_Right:
        if (!JogoScene::blocked(std::floor((jogador->scenePos().x()+LADO_BLOCOS)/LADO_BLOCOS), std::floor(jogador->scenePos().y()/LADO_BLOCOS))) {
            jogador->setPos(jogador->scenePos().x()+LADO_BLOCOS, jogador->scenePos().y());
        }
        break;
    case Qt::Key_Left:
        if (!JogoScene::blocked(std::floor((jogador->scenePos().x()-LADO_BLOCOS)/LADO_BLOCOS), std::floor(jogador->scenePos().y()/LADO_BLOCOS))) {
            jogador->setPos(jogador->scenePos().x()-LADO_BLOCOS, jogador->scenePos().y());
        }
        break;
    }

}