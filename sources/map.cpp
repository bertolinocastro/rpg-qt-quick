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

    std::ifstream file("../atormentados/maps/"+arquivo); // caminho gambiarra, porque o deploy do Qt põe em outra pasta...
    std::string linha;
    while(std::getline(file, linha)){
        if (linha.compare("FIM")==0)
            break;
        portais[linha[0]] = linha.substr(2);
    }

//    for (auto& t : portais)
//        std::cout << t.first << " " << t.second << "\n";


    int i=0;
    while(std::getline(file, linha)){
        linha.copy(mapa[i], linha.length());
        i++;
    }


}

std::string Map::parse(char token){
    std::string caminho = "";
    switch(token){
    case 'W':
        caminho += "wall.png";
        break;
    case ' ':

    case 'F':

    case 'T':

    case 'B':

    case 'R':

    case 'C':

    default:
        caminho += "black-square.png";
        break;
    }
    return caminho;
}
