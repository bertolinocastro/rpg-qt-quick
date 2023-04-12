#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include "definicoes.h"

/*
 * Personagens: mago, bruxa, cavaleiro, princesa, aldeao, monstro, dragao.
 */

class FormaDeVida {
protected:
    std::string nome;
    int vida;  // Faixa de valores: 0 a 100.
    int forca; // Faixa de valores: 0 a 100.

public:
    FormaDeVida();
    FormaDeVida(std::string n);
    void setNome(std::string n);
    std::string getNome();
    void setVida(int v);
    int getVida();
    void setForca(int f);
    int getForca();

    std::string caminho_sprite = ROOT_DIR"resources/samurai.png";
};


class SerHumano : public FormaDeVida {
public:
    SerHumano();
    SerHumano(std::string n);

    void fale(std::string s);

    virtual std::string responda(std::string s);

    template <class ClasseTemplate>
    void converse(ClasseTemplate pessoa, std::string s) {
        std::string respostaPessoa;
        std::string minhaResposta;
        minhaResposta = s;
        while (true) {
            this->fale(minhaResposta);
            respostaPessoa = pessoa.responda(minhaResposta);
            pessoa.fale(respostaPessoa);
            minhaResposta = this->responda(respostaPessoa);
            if (respostaPessoa == "Nao sei dizer." || minhaResposta == "Nao sei dizer.") {
                break;
            }
        }
    }
};

class Mago : public SerHumano {
protected:
    int magia;

public:
    Mago();
    Mago(std::string n);

    void setMagia(int m);
    int getMagia();

    std::string caminho_sprite = ROOT_DIR"resources/mago.png";
};

class Bruxa : public SerHumano {
protected:
    int magia;

public:
    Bruxa();
    Bruxa(std::string n);

    void setMagia(int m);
    int getMagia();
    std::string caminho_sprite = ROOT_DIR"resources/bruxa.png";
};


class Cavaleiro : public SerHumano {
protected:
    int coragem;
    int armadura;

public:
    Cavaleiro();
    Cavaleiro(std::string n);

    void setCoragem(int c);
    int getCoragem();
    void setArmadura(int a);
    int getArmadura();

    virtual std::string responda(std::string s);

    std::string caminho_sprite = ROOT_DIR"resources/cavaleiro.png";
};

class Princesa : public SerHumano {
protected:
    int inteligencia;
    int beleza;
    int dinheiro;

public:
    void init();
    Princesa();
    Princesa(std::string n);

    void setInteligencia(int i);
    int getInteligencia();
    void setBeleza(int b);
    int getBeleza();
    void setDinheiro(int d);
    int getDinheiro();

    std::string responda(std::string s);

    std::string caminho_sprite = ROOT_DIR"resources/princesa.png";
};

class Aldeao : public SerHumano {
protected:
    int lealdade;
    int honestidade;

public:
    void init();
    Aldeao();
    Aldeao(std::string n);

    void setLealdade(int l);
    int getLealdade();
    void setHonestidade(int h);
    int getHonestidade();

    std::string responda(std::string s);

    std::string caminho_sprite = ROOT_DIR"resources/aldeao.png";
};

class Samurai : public SerHumano {
protected:
    int destreza;
    int furtividade;

public:
    Samurai();
    Samurai(std::string n);

    int getDestreza() const;
    void setDestreza(int newDestreza);
    int getFurtividade() const;
    void setFurtividade(int newFurtividade);

    std::string caminho_sprite = ROOT_DIR"resources/cavaleiro.png";

};


class Monstro : public FormaDeVida {
protected:
    int simpatia;

public:
    void init();
    Monstro();
    Monstro(std::string n);

    void setSimpatia(int s);
    int getSimpatia();
    std::string caminho_sprite = ROOT_DIR"resources/monstro.png";
};

class Dragao : public Monstro {
protected:
    int fogo;

public:
    void init();
    Dragao();
    Dragao(std::string n);

    void setFogo(int f);
    int getFogo();

    std::string caminho_sprite = ROOT_DIR"resources/dragao.png";
};


#endif // CLASSES_H
