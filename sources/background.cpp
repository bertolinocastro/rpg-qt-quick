#include "background.h"
#include <QPainter>
#include <fstream>
#include <iostream>
//#include <string>
#include <algorithm>

Background::Background() {
}

Background::Background(std::string arquivo) {
    carregaMapa(arquivo);
    posInicialJogador();
}

std::string Background::texturaDaCasa(int i, int j) {
    return parse(mapa[i][j]);
}

void Background::carregaMapa(std::string arquivo) {

    std::ifstream file(ROOT_DIR"maps/"+arquivo); // caminho gambiarra, porque o deploy do Qt põe em outra pasta...
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

void Background::posInicialJogador(){
    char* p = std::find(&mapa[0][0], &mapa[0][0]+N_BLOCOS*N_BLOCOS, 'S');

    int l = std::distance(&mapa[0][0], p);
    int i = l/N_BLOCOS;
    int j = l%N_BLOCOS;
    std::cout << "l "<<l<<" i "<<i<<" j "<<j<<std::endl;

    player_start_position = QPointF(j*LADO_BLOCOS, i*LADO_BLOCOS);

}
