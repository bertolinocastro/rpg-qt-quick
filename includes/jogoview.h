#ifndef JOGOVIEW_H
#define JOGOVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QKeyEvent>
#include <jogoscene.h>

class JogoView : public QGraphicsView
{
    Q_OBJECT
public:
    JogoView(QWidget *parent);
    void setScene(QGraphicsScene *scene);
    void setBg(Background &mapa);
    JogoScene* cena_atual;
    void death_event();
    void castle_event();
    void setCenaAtual(JogoScene *cena);

protected:
    void keyPressEvent(QKeyEvent *e);

public:

signals:

    void atualizaPlayerStatus();

};

#endif // JOGOVIEW_H
