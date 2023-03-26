#include "windowprincipal.h"
#include "ui_windowprincipal.h"

WindowPrincipal::WindowPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowPrincipal)
{
    ui->setupUi(this);
}

WindowPrincipal::~WindowPrincipal()
{
    delete ui;
}

void WindowPrincipal::novoJogo(){

}

