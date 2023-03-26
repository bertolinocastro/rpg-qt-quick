#include "map.h"
#include <fstream>
#include <iostream>
//#include <string>


Map::Map(std::string arquivo)
{

    leArquivo(arquivo);

}

void Map::leArquivo(std::string arquivo){

    std::ifstream file("../atormentados/maps/"+arquivo); // caminho gambiarra, porque o deploy do Qt põe em outra pasta...
    std::string linha;
    while(std::getline(file, linha)){
        if (linha.compare("FIM")==0)
            break;
        portais[linha[0]] = linha.substr(2);
    }

    int i=0;
    while(std::getline(file, linha)){
        linha.copy(mapa[i], linha.length());
        std::cout<<mapa[i] << std::endl;
        i++;
    }

}
