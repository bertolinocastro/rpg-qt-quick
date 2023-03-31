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



}
