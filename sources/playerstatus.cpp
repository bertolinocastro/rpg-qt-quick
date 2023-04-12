#include "playerstatus.h"
#include "definicoes.h"
#include <QString>
#include <QApplication>
#include <QScreen>

PlayerStatus::PlayerStatus(QWidget *parent) : QLabel(parent)
{

}

void PlayerStatus::init(){
    QRect geo = QApplication::primaryScreen()->availableGeometry();

    int h = QFontMetrics(this->font()).lineSpacing();
    setGeometry(0, 0, 10*LADO_BLOCOS, 5*h);


    float x = (geo.width() - N_BLOCOS*LADO_BLOCOS) / 2;
    float y = geo.height() - height();
    move(x+N_BLOCOS*LADO_BLOCOS, y);

    atualizaConteudo();
}

void PlayerStatus::setBoneco(Jogador* boneco){
    this->boneco = boneco;
    nome = QString::fromStdString(boneco->boneco->getNome());
}

void PlayerStatus::atualizaConteudo()
{

    this->setText(QString(
            " %1 %2\n"\
            " Vida: %3\n"\
            " Força: %4\n"
    )
    .arg(boneco->classe)
    .arg(nome)
    .arg(boneco->boneco->getVida())
    .arg(boneco->boneco->getForca()));

}