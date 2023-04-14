#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include "jogador.h"

class PlayerStatus : public QLabel
{
    Q_OBJECT
public:
    PlayerStatus(QWidget *parent);
    void setBoneco(Jogador *boneco);
    void atualizaConteudo();
    void init();

private:
    Jogador* boneco;
    QString nome;
public slots:
    void atualiza();

};

#endif // PLAYERSTATUS_H
