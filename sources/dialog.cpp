#include "dialog.h"
#include "definicoes.h"


#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>

Dialog::Dialog() {
    this->setWindowTitle("Dialog");

    QLabel* name = new QLabel("Personagem Interessante");
    QLabel* text = new QLabel("first line\nsecond line");
    text->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    text->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(name, 1, 1, 1, 3);
    layout->addWidget(text, 2, 1, 1, 3);
    layout->addWidget(new QPushButton("Continuar"), 3, 2);
    layout->addWidget(new QPushButton("Pular"), 3, 3);
    //layout->setAlignment(dialog, Qt::AlignHCenter | Qt::AlignBottom);
    layout->setContentsMargins(5, 5, 5, 5);
    this->setLayout(layout);
}