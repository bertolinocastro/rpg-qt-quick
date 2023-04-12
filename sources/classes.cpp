#include<iostream>
#include "classes.h"

using namespace std;
/*
 * Personagens: mago, bruxa, cavaleiro, princesa, aldeao, monstro, dragao.
 */

/*
Mago merlin("Merlin");
Bruxa magaPatalogica("Maga Patalogica");
Cavaleiro arthur("Arthur");
Aldeao tiago("Tiago");
Princesa leia("Leia");
Monstro lucas("Lucas");
Dragao tiamat("Tiamat");
*/

FormaDeVida::FormaDeVida() {
    vida = 100;
    forca = 100;
}

FormaDeVida::FormaDeVida(string n) {
    nome = n;
    vida = 100;
    forca = 100;
}

void FormaDeVida::setNome(string n) {
    nome = n;
}

string FormaDeVida::getNome() {
    return nome;
}

void FormaDeVida::setVida(int v) {
    if (v >= 0 && v <= 100) {
        vida = v;
    }
}

int FormaDeVida::getVida() {
    return vida;
}

void FormaDeVida::setForca(int f) {
    if (f >= 0 && f <= 100) {
        forca = f;
    }
}

int FormaDeVida::getForca() {
    return forca;
}

SerHumano::SerHumano() : FormaDeVida() {
}

SerHumano::SerHumano(string n) : FormaDeVida(n) {
}

void SerHumano::fale(string s) {
    cout << getNome() << " disse: " << s << "\n";
}

string SerHumano::responda(string s) {
    if (s == "Ola!") {
        return "Tudo bem?";
    } else if (s == "Tudo bem?") {
        return "Sim, e voce?";
    } else if (s == "Sim, e voce?") {
        return "Estou otimo!";
    } else if (s == "Ate logo!") {
        return "Ate!";
    } else if (s == "Tchau!") {
        return "Ate!";
    } else {
        return "Nao sei dizer.";
    }
}

Mago::Mago() : SerHumano() {
    magia = 100;
}

Mago::Mago(string n) : SerHumano(n) {
    magia = 100;
}

void Mago::setMagia(int m) {
    if (m >= 0 && m <= 100) {
        magia = m;
    }
}

int Mago::getMagia() {
    return magia;
}

Bruxa::Bruxa() : SerHumano() {
    magia = 100;
}

Bruxa::Bruxa(string n) : SerHumano(n) {
    magia = 100;
}

void Bruxa::setMagia(int m) {
    if (m >= 0 && m <= 100) {
        magia = m;
    }
}

int Bruxa::getMagia() {
    return magia;
}

Cavaleiro::Cavaleiro() : SerHumano() {
    coragem = 100;
    armadura = 100;
}

Cavaleiro::Cavaleiro(string n) : SerHumano(n) {
    coragem = 100;
    armadura = 100;
}

void Cavaleiro::setCoragem(int c) {
    if (c >= 0 && c <= 100) {
        coragem = c;
    }
}

int Cavaleiro::getCoragem() {
    return coragem;
}

void Cavaleiro::setArmadura(int a) {
    if (a >= 0 && a <= 100) {
        armadura = a;
    }
}

int Cavaleiro::getArmadura() {
    return armadura;
}

string Cavaleiro::responda(string s) {
    if (s == "Ola!") {
        return "Como vai nobre pessoa?";
    } else if (s == "Tudo bem?") {
        return "Sim, e como esta Vossa senhoria?";
    } else if (s == "Sim, e voce?") {
        return "Estou passando muitissimo bem!";
    } else if (s == "Ate logo!") {
        return "Ate proxima!";
    } else if (s == "Tchau!") {
        return "Ate logo!";
    } else {
        return "Nao sei dizer.";
    }
}

void Princesa::init() {
    inteligencia = 50;
    beleza = 100;
    dinheiro = 20;
}

Princesa::Princesa() : SerHumano() {
    this->init();
}

Princesa::Princesa(string n) : SerHumano(n) {
    this->init();
}

void Princesa::setInteligencia(int i) {
    if (i >= 0 && i <= 100) {
        inteligencia = i;
    }
}

int Princesa::getInteligencia() {
    return inteligencia;
}

void Princesa::setBeleza(int b) {
    if (b >= 0 && b <= 100) {
        beleza = b;
    }
}

int Princesa::getBeleza() {
    return beleza;
}

void Princesa::setDinheiro(int d) {
    if (d >= 0 && d <= 100) {
        dinheiro = d;
    }
}

int Princesa::getDinheiro() {
    return dinheiro;
}

string Princesa::responda(string s) {
    if (s == "Ola!") {
        return "To de boa, e oce?";
    } else if (s == "To de boa, e oce?") {
        return "Estou ótima!";
    } else if (s == "Nao e de sua conta!") {
        return "Seu mal educado!";
    } else if (s == "Entao sarta fora!") {
        return "Vou chamar meu pai!";
    } else if (s == "Se manda!") {
        return "Você já era!";
    } else if (s == "Você já era!") {
        return "To nem ai!";
    } else {
        return "Nao sei dizer.";
    }
}

void Aldeao::init() {
    lealdade = 0;
    honestidade = 0;
}

Aldeao::Aldeao() : SerHumano() {
    this->init();
}

Aldeao::Aldeao(string n) : SerHumano(n) {
    this->init();
}

void Aldeao::setLealdade(int l) {
    if (l >= 0 && l <= 100) {
        lealdade = l;
    }
}

int Aldeao::getLealdade() {
    return lealdade;
}

void Aldeao::setHonestidade(int h) {
    if (h >= 0 && h <= 100) {
        honestidade = h;
    }
}

int Aldeao::getHonestidade() {
    return honestidade;
}

string Aldeao::responda(string s) {
    if (s == "Ola!") {
        return "To de boa, e oce?";
    } else if (s == "Tudo bem?") {
        return "Nao e de sua conta!";
    } else if (s == "Sim, e voce?") {
        return "Entao sarta fora!";
    } else if (s == "Estou ótima!") {
        return "Entao sarta fora!";
    } else if (s == "Vou chamar meu pai!") {
        return "To nem ai!";
    } else if (s == "Ate logo!") {
        return "Se manda!";
    } else if (s == "Tchau!") {
        return "To nem ai!";
    } else {
        return "Nao sei dizer.";
    }
}

void Monstro::init() {
    simpatia = 0;
}

Monstro::Monstro() : FormaDeVida() {
    this->init();
}

Monstro::Monstro(string n) : FormaDeVida(n) {
    this->init();
}

void Monstro::setSimpatia(int s) {
    if (s >= 0 && s <= 100) {
        simpatia = s;
    }
}

int Monstro::getSimpatia() {
    return simpatia;
}

void Dragao::init() {
    fogo = 0;
}

Dragao::Dragao() : Monstro() {
    this->init();
}

Dragao::Dragao(string n) : Monstro(n) {
    this->init();
}

void Dragao::setFogo(int f) {
    if (f >= 0 && f <= 100) {
        fogo = f;
    }
}

int Dragao::getFogo() {
    return fogo;
}

int Samurai::getFurtividade() const
{
    return furtividade;
}

void Samurai::setFurtividade(int newFurtividade)
{
    furtividade = newFurtividade;
}

Samurai::Samurai() : SerHumano()
{

}

Samurai::Samurai(std::string n) : SerHumano(n)
{
    destreza = 15;
    furtividade = 5;
}

int Samurai::getDestreza() const
{
    return destreza;
}

void Samurai::setDestreza(int newDestreza)
{
    destreza = newDestreza;
}
