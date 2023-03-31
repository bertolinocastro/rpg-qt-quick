#ifndef JOGOVIEW_H
#define JOGOVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <jogoscene.h>

class JogoView : public QGraphicsView
{
    Q_OBJECT
public:
    JogoView(QWidget *parent);
    void setScene(QGraphicsScene *scene);
};

#endif // JOGOVIEW_H
