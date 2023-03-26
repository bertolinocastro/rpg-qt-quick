#ifndef MAP_H
#define MAP_H
#include <string>
#include <map>

class Map
{
public:
    Map(std::string);

private:
    std::map<char, std::string> portais;

    char mapa[64][64];


    void leArquivo(std::string);

};

#endif // MAP_H
