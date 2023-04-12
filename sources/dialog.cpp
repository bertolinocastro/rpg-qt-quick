#include "dialog.h"
#include "definicoes.h"

#include <iostream>
#include <fstream>
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

Dialog::Dialog(std::string filename) {
    this->setWindowTitle("Dialog");

    std::ifstream text(ROOT_DIR"dialogs/"+filename);
    std::string line;
    if (text.is_open()) {
        while ( std::getline (text,line) )
        {
        std::cout << line << '\n';
        }
        text.close();
    }

    QLabel* name = new QLabel("Personagem Interessante");
    QLabel* lines = new QLabel("first line\nsecond line");
    lines->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lines->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);


    QGridLayout* layout = new QGridLayout();
    layout->addWidget(name, 1, 1, 1, 3);
    layout->addWidget(lines, 2, 1, 1, 3);
    QPushButton* next = new QPushButton("Continuar");
    QPushButton* skip = new QPushButton("Pular");
    layout->addWidget(next, 3, 2);
    layout->addWidget(skip, 3, 3);

    connect(next, SIGNAL(clicked()), this, SLOT(nextSlot()));
    connect(skip, SIGNAL(clicked()), this, SLOT(skipSlot()));
    //layout->setAlignment(dialog, Qt::AlignHCenter | Qt::AlignBottom);
    layout->setContentsMargins(5, 5, 5, 5);
    this->setLayout(layout);
}

void Dialog::nextSlot()
{
   this->show();
}

void Dialog::skipSlot()
{
   this->show();
}