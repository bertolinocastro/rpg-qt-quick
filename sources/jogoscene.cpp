#include "jogoscene.h"
#include "playerstatus.h"
#include "definicoes.h"
#include "classes.h"

#include <iostream>
#include <algorithm>
#include <cmath>

#include <QApplication>
#include <QScreen>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QInputDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QGuiApplication>
#include <QPushButton>


JogoScene::JogoScene(std::string file, QString nome, QString classe) : QGraphicsScene(0, 0, N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS) {
    std::cout << " rect da cena " << sceneRect().width() << " " << sceneRect().height() << std::endl;
//    player_start_position = QPointF(2*LADO_BLOCOS,45*LADO_BLOCOS);

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

    jogador = new Jogador(nome, classe);
//    jogador->setPos(player_start_position);
    jogador->setPos(cenario.player_start_position);
    addItem(jogador);
}

bool JogoScene::blocked(int x, int y) {
    char token = cenario.mapa[y][x];
    switch(token){
        case ' ':
        case 'B':
        case 'C':
        case 'S':
            return false;
        case 'W':
        case 'R':
        case 'F':
        default:
            return true;
        }
}

void JogoScene::start_dialog(std::string filename) {
    Dialog* cena;
    if (filename != "") {
        cena = new Dialog(filename);
    } else {
        cena = new Dialog();
    }
    cena->move((N_BLOCOS/2)*LADO_BLOCOS - cena->frameSize().width()/2, (N_BLOCOS/2)*LADO_BLOCOS - cena->frameSize().height()/2);
    this->addWidget(cena);
}

void JogoScene::keyPressEvent(QKeyEvent* event) {
    int x = jogador->scenePos().x();
    int y = jogador->scenePos().y();
    switch(event->key()){
    case Qt::Key_Up:
    case Qt::Key_W:
        if (!JogoScene::blocked(std::floor(x/LADO_BLOCOS), std::floor((y-LADO_BLOCOS)/LADO_BLOCOS))) {
            jogador->setPos(x, y-LADO_BLOCOS);
        }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if (!JogoScene::blocked(std::floor(x/LADO_BLOCOS), std::floor((y+LADO_BLOCOS)/LADO_BLOCOS))) {
            jogador->setPos(x, y+LADO_BLOCOS);
        }
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if (!JogoScene::blocked(std::floor((x-LADO_BLOCOS)/LADO_BLOCOS), std::floor(y/LADO_BLOCOS))) {
            jogador->setPos(x-LADO_BLOCOS, y);
        }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if (!JogoScene::blocked(std::floor((x+LADO_BLOCOS)/LADO_BLOCOS), std::floor(y/LADO_BLOCOS))) {
            jogador->setPos(x+LADO_BLOCOS, y);
        }
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
    case Qt::Key_E:
        char token_u = cenario.mapa[(y-LADO_BLOCOS)/LADO_BLOCOS][x/LADO_BLOCOS];
        char token_d = cenario.mapa[(y+LADO_BLOCOS)/LADO_BLOCOS][x/LADO_BLOCOS];
        char token_l = cenario.mapa[y/LADO_BLOCOS][(x-LADO_BLOCOS)/LADO_BLOCOS];
        char token_r = cenario.mapa[y/LADO_BLOCOS][(x+LADO_BLOCOS)/LADO_BLOCOS];
        switch(token_u){
            case 'N':
                JogoScene::start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                JogoScene::start_dialog("fight.txt");
                jogador->setHP(std::max(0, jogador->getHP()-30));
                break;
            default:
                break;
        }
        switch(token_d){
            case 'N':
                JogoScene::start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                JogoScene::start_dialog("fight.txt");
                jogador->setHP(std::max(0, jogador->getHP()-30));
                break;
            default:
                break;
        }
        switch(token_l){
            case 'N':
                JogoScene::start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                JogoScene::start_dialog("fight.txt");
                jogador->setHP(std::max(0, jogador->getHP()-30));
                break;
            default:
                break;
        }
        switch(token_r){
            case 'N':
                JogoScene::start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                JogoScene::start_dialog("fight.txt");
                jogador->setHP(std::max(0, jogador->getHP()-30));
                break;
            default:
                break;
        }
        break;
    }

}
