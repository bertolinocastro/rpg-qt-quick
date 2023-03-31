#ifndef MAP_H
#define MAP_H
#include <string>
#include <map>
#include "definicoes.h"

/*
 * Definindo caracteres reservados do arquivo de mapa:
 *
 * 'W' = Wall, parede intransponível
 * ' ' = Espaço vazio onde o player pode caminhar
 * 'F' = Fight, local onde tem um NPC para batalhar
 * 'T' = Tree, árvore (intransponível?)
 * 'B' = Bush, mato (transponível)
 * 'R' = River, rio ou água (intransponível)
 * 'C' = Coin, moeda no chão
 * Quais outras?
 *
 */



class Map
{
public:
    Map(std::string);

    std::string texturaDaCasa(int i, int j);

protected:
    std::string parse(char token);
private:
    std::map<char, std::string> portais;

    char mapa[N_BLOCOS][N_BLOCOS];

    void carregaMapa(std::string);

};

#endif // MAP_H
