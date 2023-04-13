#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include "definicoes.h"

class Template {
protected:
    int max_hp;  // Faixa de valores: 0 a 100.
    int max_mp; // Faixa de valores: 0 a 100.

public:
    Template();
    Template(std::string n);

    int getMaxHP();
    int getMaxMP();

    std::string caminho_sprite;
};

class Samurai : public Template {

public:
    Samurai();
    std::string caminho_sprite = ROOT_DIR"resources/samurai.png";
};

class Ninja : public Template {

public:
    Ninja();
    std::string caminho_sprite = ROOT_DIR"resources/ninja.png";
};

class Mystic : public Template {

public:
    Mystic();
    std::string caminho_sprite = ROOT_DIR"resources/mystic.png";
};

#endif // CLASSES_H

