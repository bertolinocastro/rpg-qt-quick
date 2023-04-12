#include "dialog.h"
#include "definicoes.h"

#include <iostream>
#include <fstream>
#include <QFrame>
#include <QPushButton>

Dialog::Dialog() {
    this->setWindowTitle("Dialog");
    QLabel* name = new QLabel("Personagem Interessante");
    QLabel* text = new QLabel("first line\nsecond line");
    text->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    text->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

    layout = new QGridLayout();
    layout->addWidget(name, 1, 1, 1, 3);
    layout->addWidget(text, 2, 1, 1, 3);


    QPushButton* next = new QPushButton("Continuar");
    QPushButton* skip = new QPushButton("Pular");
    layout->addWidget(next, 3, 2);
    layout->addWidget(skip, 3, 3);
    connect(next, SIGNAL(clicked()), this, SLOT(nextSlot()));
    connect(skip, SIGNAL(clicked()), this, SLOT(close()));
    //layout->setAlignment(dialog, Qt::AlignHCenter | Qt::AlignBottom);
    layout->setContentsMargins(5, 5, 5, 5);
    this->setLayout(layout);
}

Dialog::Dialog(std::string filename) {
    this->setWindowTitle("Dialog");

    std::ifstream file(ROOT_DIR"dialogs/"+filename);
    std::string line;
    if (file.is_open()) {
        while ( std::getline (file,line) )
        {
        std::cout << line << '\n';
        }
        file.close();
    }

    name = new QLabel();
    name->setText("Moeda");
    lines = new QLabel();
    lines->setText("Lorem\nIpsum");
    lines->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lines->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);


     layout = new QGridLayout();
    layout->addWidget(name, 1, 1, 1, 3);
    layout->addWidget(lines, 2, 1, 1, 3);

    QPushButton* next = new QPushButton("Continuar");
    QPushButton* skip = new QPushButton("Pular");
    layout->addWidget(next, 3, 2);
    layout->addWidget(skip, 3, 3);
    connect(next, SIGNAL(clicked()), this, SLOT(nextSlot()));
    connect(skip, SIGNAL(clicked()), this, SLOT(close()));
    //layout->setAlignment(dialog, Qt::AlignHCenter | Qt::AlignBottom);
    layout->setContentsMargins(5, 5, 5, 5);
    this->setLayout(layout);
}

void Dialog::nextSlot()
{
   this->update();
}

void Dialog::skipSlot()
{
   this->close();
}