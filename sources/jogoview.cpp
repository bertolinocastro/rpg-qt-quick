#include "jogoview.h"
#include "definicoes.h"

#include <iostream>

#include <QApplication>
#include <QScreen>
#include <QImage>
#include <QPainter>
#include <QBrush>
#include <QLineEdit>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QMap>
#include <QDir>


JogoView::JogoView(QWidget *parent) : QGraphicsView(parent) {
}

void JogoView::setCenaAtual(JogoScene *cena) {
    cena_atual = cena;
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

void JogoView::setBg(Background& mapa) {

    std::string caminhoBase = ROOT_DIR"resources/";
    QMap<QString, QImage> cache;
    QImage img;


    QImage bg(N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS, QImage::Format_ARGB32);
    QPainter painter(&bg);
    for (int i = 0; i < N_BLOCOS; i++){
        for (int j = 0; j < N_BLOCOS; j++){
            std::string textura = mapa.texturaDaCasa(i, j);
            QString path = QString::fromStdString(caminhoBase+textura);
            if (!cache.contains(path)){
                cache[path] = QImage(path);
            }
            img = cache[path];
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

void JogoView::castle_event() {
    JogoScene* jogoScene = new JogoScene("castle_in.txt", cena_atual->jogador->name, cena_atual->jogador->classe);
    this->setCenaAtual(jogoScene);
    this->setScene(jogoScene);
    this->setBg(jogoScene->cenario);
    std::cout << "Inside Castle" << std::endl;

}
void JogoView::death_event() {
    JogoScene* jogoScene = new JogoScene("goddess_map.txt", cena_atual->jogador->name, cena_atual->jogador->classe);
    this->setCenaAtual(jogoScene);
    this->setScene(jogoScene);
    this->setBg(jogoScene->cenario);
    std::cout << "Found Death" << std::endl;
    jogoScene->start_dialog("death.txt");
}

void JogoView::keyPressEvent(QKeyEvent *event) {
    // Do something
    int x = cena_atual->jogador->scenePos().x();
    int y = cena_atual->jogador->scenePos().y();
    switch(event->key()){
    case(Qt::Key_T):
        castle_event();
        break;
    case(Qt::Key_R):
        death_event();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
    case Qt::Key_E:
        char token_u = cena_atual->cenario.mapa[(y-LADO_BLOCOS)/LADO_BLOCOS][x/LADO_BLOCOS];
        char token_d = cena_atual->cenario.mapa[(y+LADO_BLOCOS)/LADO_BLOCOS][x/LADO_BLOCOS];
        char token_l = cena_atual->cenario.mapa[y/LADO_BLOCOS][(x-LADO_BLOCOS)/LADO_BLOCOS];
        char token_r = cena_atual->cenario.mapa[y/LADO_BLOCOS][(x+LADO_BLOCOS)/LADO_BLOCOS];
        switch(token_u){
            case 'N':
                cena_atual->start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                cena_atual->jogador->setHP(std::max(0, cena_atual->jogador->getHP()-30));
                // ATUALIZAR PLAYER STATUS
                if (cena_atual->jogador->getHP() == 0) {
                    death_event();
                    return;
                }
                cena_atual->start_dialog("fight.txt");
                break;
            case '1':
            case '2':
            case '3':
            case '4':
                castle_event();
            break;
            default:
                break;
        }
        switch(token_d){
            case 'N':
                cena_atual->start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                cena_atual->jogador->setHP(std::max(0, cena_atual->jogador->getHP()-30));
                // ATUALIZAR PLAYER STATUS
                if (cena_atual->jogador->getHP() == 0) {
                    death_event();
                    return;
                }
                cena_atual->start_dialog("fight.txt");
                break;
            case '1':
            case '2':
            case '3':
            case '4':
                castle_event();
            break;
            default:
                break;
        }
        switch(token_l){
            case 'N':
                cena_atual->start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                cena_atual->jogador->setHP(std::max(0, cena_atual->jogador->getHP()-30));
                // ATUALIZAR PLAYER STATUS
                if (cena_atual->jogador->getHP() == 0) {
                    death_event();
                    return;
                }
                cena_atual->start_dialog("fight.txt");
                break;
            case '1':
            case '2':
            case '3':
            case '4':
                castle_event();
            break;
            default:
                break;
        }
        switch(token_r){
            case 'N':
                cena_atual->start_dialog("other_soldier.txt");
                break;
            case 'D':
            case 'F':
                cena_atual->jogador->setHP(std::max(0, cena_atual->jogador->getHP()-30));
                // ATUALIZAR PLAYER STATUS
                if (cena_atual->jogador->getHP() == 0) {
                    death_event();
                    return;
                }
                cena_atual->start_dialog("fight.txt");
                break;
            case '1':
            case '2':
            case '3':
            case '4':
                castle_event();
            break;
            default:
                break;
        }
        break;
    }


    // Otherwise pass to the graphics view
    QGraphicsView::keyPressEvent(event);
}
