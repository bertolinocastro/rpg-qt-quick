#include "windowprincipal.h"
#include "ui_windowprincipal.h"
#include <iostream>

WindowPrincipal::WindowPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowPrincipal)
{
    ui->setupUi(this);
//    QPushButton *btnNovoJogo = ;
    QObject::connect(ui->pushButtonNovoJogo, &QPushButton::clicked, this, &WindowPrincipal::novoJogo);

}

WindowPrincipal::~WindowPrincipal()
{
    delete ui;
}

void WindowPrincipal::novoJogo(){
    std::cout << "Entrou no slot Novo Jogo" <<std::endl;
    ui->stackedWidget->setCurrentIndex(0);
}

