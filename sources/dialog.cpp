#include "dialog.h"
#include "definicoes.h"

#include <iostream>
#include <sstream>
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

    std::string file = readFileIntoString(ROOT_DIR"dialogs/"+filename);
    std::string delimiter = "-+";
    text_it = 0;
    full_text = split (file, delimiter);
    std::cout << "Fulltext" << std::endl;
    for (auto i : full_text) std::cout << i << std::endl;

    /*
    std::ifstream file(ROOT_DIR"dialogs/"+filename);
    std::string line;
    if (file.is_open()) {
        while ( std::getline (file,line) )
        {
        linha.copy(mapa[i], N_BLOCOS);
        std::cout << line << '\n';
        }
        file.close();
    }*/

    std::cout << "iterator" << text_it << std::endl;
    name = new QLabel();
    //if (std::getline (file,line)) {
    name->setText(QString(full_text[text_it++].c_str()));
    std::cout << "iterator" << text_it << std::endl;
    //}
    lines = new QLabel();
    //if (std::getline (file,line)) {
    lines->setText(QString(full_text[text_it++].c_str()));
    std::cout << "iterator" << text_it << std::endl;
    //}
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

void Dialog::nextSlot() {
    if (text_it < full_text.size()) name->setText(QString(full_text[text_it++].c_str())); else this->close();
    std::cout << "iterator" << text_it << std::endl;
    if (text_it < full_text.size()) lines->setText(QString(full_text[text_it++].c_str())); else this->close();
    std::cout << "iterator" << text_it << std::endl;

    this->update();
}

// for string delimiter
std::vector<std::string> Dialog::split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

std::string Dialog::readFileIntoString(const std::string& path) {
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}