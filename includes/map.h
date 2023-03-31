#ifndef MAP_H
#define MAP_H
#include <string>
#include <map>

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

    char mapa[64][64];

    void carregaMapa(std::string);

};

#endif // MAP_H
