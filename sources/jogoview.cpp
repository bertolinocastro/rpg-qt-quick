#include "jogoview.h"
#include <QApplication>
#include <QScreen>
#include <iostream>

JogoView::JogoView(QWidget *parent) : QGraphicsView(parent)
{
    setGeometry(100,100, 500,500);
}

void JogoView::setScene(QGraphicsScene* scene){
    QGraphicsView::setScene(scene);

    QRect telaGeometry = QGuiApplication::primaryScreen()->geometry();

    std::cout << "Largura: "<<telaGeometry.width()<< " Altura: " << telaGeometry.height()<<std::endl;

//    scene->setSceneRect(telaGeometry);
    scene->setSceneRect(0, 0, 64*15, 64*15);

//     fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    //fitInView(telaGeometry, Qt::KeepAspectRatio);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QTransform trans = transform();
    std::cout << "M11: " << trans.m11() << std::endl;
    std::cout << "M12: " << trans.m12() << std::endl;
    std::cout << "M13: " << trans.m13() << std::endl;
    std::cout << "M21: " << trans.m21() << std::endl;
    std::cout << "M22: " << trans.m22() << std::endl;
    std::cout << "M23: " << trans.m23() << std::endl;
    std::cout << "M31: " << trans.m31() << std::endl;
    std::cout << "M32: " << trans.m32() << std::endl;
    std::cout << "M33: " << trans.m33() << std::endl;


}
