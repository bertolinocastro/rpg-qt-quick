#include <iostream>
#include <QGraphicsItem>
#include "jogoscene.h"
#include "definicoes.h"
//#include "blocodoterreno.h"

JogoScene::JogoScene(Map& mapa) : QGraphicsScene(0, 0, N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS) {

//    setSceneRect(0, 0, 64*15, 64*15);
    std::cout << " rect da cena " << sceneRect().width() << " " << sceneRect().height() << std::endl;
    std::string caminhoBase = "resources/";
/*
    for (int i = 0; i < 32; i++){
        for (int j = 0; j < 32; j++){
            std::string textura = mapa.texturaDaCasa(i, j);
            QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QString::fromStdString(caminhoBase+textura));
            item->setScale(0.06);
            item->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
            item->setPos(1.0/64*i, 1.0/64*j);
            item->setOffset(1.0*i, 1.0*j);
            item->setPos(45*i, 45*j);
            std::cout<<" offsets: "<<1.0*i << " " <<1.0*j<<std::endl;
            std::cout<<" offsets.x.y: "<<item->pos().x()<< " " <<item->pos().y()<<std::endl;
            std::cout<<" boundrect: "<<item->boundingRect().width()<<" "<<item->boundingRect().height()<<std::endl;
            std::cout<<" offsets: "<<item->boundingRect().width()<<" "<<item-><<std::endl;


            addItem(item);
        }
    }
    for (auto& a : items()){
        std::cout << a->boundingRect().x() << ","<<
                     a->boundingRect().y() << "," <<
                     a->boundingRect().width() << ","<<
                     a->boundingRect().height() << ","<<
                     a->scale() << std::endl;

    }
*/
}

void JogoScene::keyPressEvent(QKeyEvent* event) {
    switch(event->key()){
    case Qt::Key_Up:
        std::cout << "Scene Up" << std::endl;
        //emit sobeJogador();
        break;
    case Qt::Key_Down:
        std::cout << "Scene Down" << std::endl;
        //emit desceJogador();
        break;
    case Qt::Key_Right:
        std::cout << "Scene Right" << std::endl;
        //emit orientaJogador();
        break;
    case Qt::Key_Left:
        std::cout << "Scene Left" << std::endl;
        //emit ocidentaJogador();
        break;
    }

}

void JogoScene::setBg(Map& mapa) {

}
