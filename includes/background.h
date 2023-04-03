#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <string>
#include <QPointF>
#include <QGraphicsItem>
#include <map>
#include "definicoes.h"

/*
 * Definindo caracteres reservados do arquivo de mapa:
 *
 * 'S' = Start, posição inicial do player no mapa2
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



class Background
{
public:
    Background();
    Background(std::string);
    std::string texturaDaCasa(int i, int j);
    void carregaMapa(std::string);
    QPointF player_start_position;

protected:
    std::string parse(char token);

private:
    std::map<char, std::string> portais;
    char mapa[N_BLOCOS][N_BLOCOS];

};

#endif // BACKGROUND_H
