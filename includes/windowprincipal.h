#ifndef WINDOWPRINCIPAL_H
#define WINDOWPRINCIPAL_H

#include <QMainWindow>
#include <QKeyEvent>
#include <string>
#include "jogador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WindowPrincipal; }
QT_END_NAMESPACE

class WindowPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    WindowPrincipal(QWidget *parent = nullptr);
    ~WindowPrincipal();

    void iniciaJogoNaTela(std::string);
    void keyPressEvent(QKeyEvent *event) override;

    void conectaJogador(Jogador* jogador);
signals:
    void sobeJogador();
    void desceJogador();
    void orientaJogador();
    void ocidentaJogador();

private:
    Ui::WindowPrincipal *ui;

public slots:
    void novoJogo();
};
#endif // WINDOWPRINCIPAL_H
