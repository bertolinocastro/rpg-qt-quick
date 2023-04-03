#include "map.h"
#include <fstream>
#include <iostream>
//#include <string>


Map::Map(std::string arquivo)
{

    carregaMapa(arquivo);

}

std::string Map::texturaDaCasa(int i, int j)
{

    return parse(mapa[i][j]);
}

void Map::carregaMapa(std::string arquivo){

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

std::string Map::parse(char token){
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
