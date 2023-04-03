#include "jogoview.h"
#include "definicoes.h"
#include <QApplication>
#include <QScreen>
#include <iostream>
#include <QImage>
#include <QPainter>
#include <QBrush>

JogoView::JogoView(QWidget *parent) : QGraphicsView(parent) {

}

void JogoView::setScene(QGraphicsScene* scene) {
    QGraphicsView::setScene(scene);

    QRect telaGeometry = QGuiApplication::primaryScreen()->geometry();

    std::cout << "Largura: "<<telaGeometry.width()<< " Altura: " << telaGeometry.height()<<std::endl;

//    scene->setSceneRect(telaGeometry);
//    scene->setSceneRect(0, 0, 64*15, 64*15);

//     fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    //fitInView(telaGeometry, Qt::KeepAspectRatio);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

//    setGeometry(0, 0, 64*12, 64*12);
}

void JogoView::setBg(Map& mapa) {

    std::string caminhoBase = "resources/";

    QImage bg(N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS, QImage::Format_ARGB32);
    QPainter painter(&bg);

    for (int i = 0; i < N_BLOCOS; i++){
        for (int j = 0; j < N_BLOCOS; j++){
            std::string textura = mapa.texturaDaCasa(i, j);
            QImage img(QString::fromStdString(caminhoBase+textura));
            img = img.scaled(LADO_BLOCOS, LADO_BLOCOS); // fazendo a imagem ocupar 12px no x e y
            painter.drawImage(LADO_BLOCOS*j, LADO_BLOCOS*i, img);
        }
    }

    QBrush bgBrush(bg);
    setBackgroundBrush(bgBrush);

    QRect geo = QApplication::primaryScreen()->availableGeometry();
    setGeometry(0, 0, N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS);


    float x = (geo.width() - width()) / 2;
    float y = 0; // (geo.height() - height()) / 2;
    move(x, y);

    x = geo.width()/(N_BLOCOS*LADO_BLOCOS);

    std::cout << " scale em x: "<<x<<std::endl;
//    scale(x, 1);
//    setTransform(QTransform::fromScale(2.0, 1.0));
//    setSceneRect(0, 0, 2*width(), height());

}

void JogoView::keyPressEvent(QKeyEvent *e) {
    // Do something

    // Otherwise pass to the graphics view
    QGraphicsView::keyPressEvent(e);
}
