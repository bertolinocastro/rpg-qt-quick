#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <QWidget>

class Dialog : public QWidget
{
public:
    Dialog();
    Dialog(std::string);


public slots:
   void nextSlot();
   void skipSlot();
};

#endif // DIALOG_H
