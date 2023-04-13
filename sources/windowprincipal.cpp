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

    start("initial-new.txt", ui->lineEditNomePersonagem->text(), ui->comboBoxClasses->currentText());
}

void WindowPrincipal::start(std::string fase, QString personagem, QString classe){

    JogoView* jogoView = ui->jogoView;
    jogoView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    //Background mapa = Background(fase);
    JogoScene* jogoScene = new JogoScene(fase, personagem, classe);

    jogoView->setCenaAtual(jogoScene);
    jogoView->setScene(jogoScene);
    jogoView->setBg(jogoScene->cenario);

    ui->playerStatus->setBoneco(jogoScene->jogador);
    ui->playerStatus->init();

}
