#include "windowprincipal.h"
#include "qgraphicsitem.h"
#include "ui_windowprincipal.h"
#include <iostream>
#include <map.h>

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

    iniciaJogoNaTela("inicial.txt");
}

void WindowPrincipal::iniciaJogoNaTela(std::string fase){

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

void WindowPrincipal::keyPressEvent(QKeyEvent* event){

    switch(event->key()){
    case Qt::Key_Up:
        emit sobeJogador();
        break;
    case Qt::Key_Down:
        emit desceJogador();
        break;
    case Qt::Key_Right:
        emit orientaJogador();
        break;
    case Qt::Key_Left:
        emit ocidentaJogador();
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }

}

void WindowPrincipal::conectaJogador(Jogador *jogador){
//    QObject::connect(this, &WindowPrincipal::sobeJogador, jogador, &Jogador::andaCima);
//    QObject::connect(ui->pushButtonNovoJogo, &QPushButton::clicked, this, &WindowPrincipal::novoJogo);
//    QObject::connect(ui->pushButtonNovoJogo, &QPushButton::clicked, this, &WindowPrincipal::novoJogo);
//    QObject::connect(ui->pushButtonNovoJogo, &QPushButton::clicked, this, &WindowPrincipal::novoJogo);

}
