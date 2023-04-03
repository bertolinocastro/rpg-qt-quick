#include "background.h"
#include <fstream>
#include <iostream>
//#include <string>

Background::Background() {
}

Background::Background(std::string arquivo) {
    carregaMapa(arquivo);
}

std::string Background::texturaDaCasa(int i, int j) {
    return parse(mapa[i][j]);
}

void Background::carregaMapa(std::string arquivo) {

    std::ifstream file("maps/"+arquivo); // caminho gambiarra, porque o deploy do Qt põe em outra pasta...
    std::string linha;
    while(std::getline(file, linha)){
        if (linha.compare("FIM")==0)
            break;
        portais[linha[0]] = linha.substr(2);
    }

//    for (auto& t : portais)
//        std::cout << t.first << " " << t.second << "\n";

    // prevenindo do arquivo que tiver mais linhas que o necessário causar stack smashing por acessar memória o mapa[i] além da pré-alocada
    for (int i=0; i<N_BLOCOS; i++) {
        std::getline(file, linha);
        linha.copy(mapa[i], N_BLOCOS); // copiando apenas o que foi alocado na Stack
    }

}

std::string Background::parse(char token) {
    std::string caminho = "";
    switch(token){
    case 'W':
        caminho += "wall.png";
        break;
    case ' ':
    case 'S':
        caminho += "tile.png";
        break;
    case 'F':

    case 'T':
        caminho += "tree.png";
        break;
    case 'B':
        caminho += "bush.png";
        break;
    case 'R':
        caminho += "river.png";
        break;
    case 'C':
        caminho += "coin.png";
        break;
    default:
        caminho += "black-square.png";
        break;
    }
    return caminho;
}

/*
QRectF Background::boundingRect() const {
    return QRectF(-LADO_BLOCOS/2, -LADO_BLOCOS/2, LADO_BLOCOS, LADO_BLOCOS); // supondo o player um quadrado de tamanho 12x12
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    std::string caminhoBase = "resources/";

    QImage bg(N_BLOCOS*LADO_BLOCOS, N_BLOCOS*LADO_BLOCOS, QImage::Format_ARGB32);

    for (int i = 0; i < N_BLOCOS; i++){
        for (int j = 0; j < N_BLOCOS; j++){
            std::string textura = mapa.texturaDaCasa(i, j);
            QImage img(QString::fromStdString(caminhoBase+textura));
            img = img.scaled(LADO_BLOCOS, LADO_BLOCOS); // fazendo a imagem ocupar 12px no x e y
            painter->drawImage(LADO_BLOCOS*j, LADO_BLOCOS*i, img);
        }
    }

}
*/