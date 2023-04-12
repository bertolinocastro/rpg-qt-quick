#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class Dialog : public QWidget
{
public:
    Dialog();
    Dialog(std::string);
    QLabel* name;
    QLabel* lines;
    QGridLayout* layout;

public slots:
   void nextSlot();
   void skipSlot();
};

#endif // DIALOG_H
