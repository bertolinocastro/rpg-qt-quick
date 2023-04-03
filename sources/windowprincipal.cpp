#include "windowprincipal.h"
#include "qgraphicsitem.h"
#include "ui_windowprincipal.h"
#include <iostream>
#include <background.h>

WindowPrincipal::WindowPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowPrincipal)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
//    QPushButton *btnNovoJogo = ;
    QObject::connect(ui->pushButtonNovoJogo, &QPushButton::clicked, this, &WindowPrincipal::novoJogo);

    showFullScreen();
}

WindowPrincipal::~WindowPrincipal()
{
    delete ui;
}

void WindowPrincipal::novoJogo(){
    std::cout << "Entrou no slot Novo Jogo" <<std::endl;
    ui->stackedWidget->setCurrentIndex(0);

    start("inicial.txt");
    //iniciaFase("inicial.txt");
}

/*
void WindowPrincipal::iniciaFase(std::string fase){

    Map mapa = Map(fase);

    JogoView* jogoView = ui->jogoView;
    jogoView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    JogoScene* jogoScene = new JogoScene(mapa);

    jogoView->setScene(jogoScene);
    jogoView->setBg(mapa);


    Jogador* jogador = new Jogador();
    jogoScene->addItem(jogador); // TODO: Continuar dessa desgraça aqui. Não tô conseguindo compilar o código pra adicionar o player como uma subclasse do QGraphicsItem

//    conectaJogador(jogador);
}
*/

void WindowPrincipal::start(std::string fase){

    JogoView* jogoView = ui->jogoView;
    jogoView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    Background mapa = Background(fase);
    JogoScene* jogoScene = new JogoScene(fase);

    jogoView->setScene(jogoScene);
    jogoView->setBg(mapa);
}
