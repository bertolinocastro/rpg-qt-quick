#include <iostream>
#include <QGraphicsItem>
#include "jogoscene.h"
#include "definicoes.h"

JogoScene::JogoScene(std::string file) : QGraphicsScene(0, 0, N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS) {
    std::cout << " rect da cena " << sceneRect().width() << " " << sceneRect().height() << std::endl;
    player_start_position = QPointF(25,25);

    Map mapa = Map(file);

    jogador = new Jogador();
    jogador->setPos(player_start_position);
    addItem(jogador); // TODO: Continuar dessa desgraça aqui. Não tô conseguindo compilar o código pra adicionar o player como uma subclasse do QGraphicsItem
}

void JogoScene::keyPressEvent(QKeyEvent* event) {
    switch(event->key()){
    case Qt::Key_Up:
        std::cout << "Scene Up" << std::endl;
        jogador->setPos(jogador->scenePos().x(), jogador->scenePos().y()-LADO_BLOCOS);
        break;
    case Qt::Key_Down:
        std::cout << "Scene Down" << std::endl;
        jogador->setPos(jogador->scenePos().x(), jogador->scenePos().y()+LADO_BLOCOS);
        break;
    case Qt::Key_Right:
        std::cout << "Scene Right" << std::endl;
        jogador->setPos(jogador->scenePos().x()+LADO_BLOCOS, jogador->scenePos().y());
        break;
    case Qt::Key_Left:
        std::cout << "Scene Left" << std::endl;
        jogador->setPos(jogador->scenePos().x()-LADO_BLOCOS, jogador->scenePos().y());
        break;
    }

}