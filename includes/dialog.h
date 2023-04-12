#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class Dialog : public QWidget
{
    Q_OBJECT
public:
    Dialog();
    Dialog(std::string);
    QLabel* name;
    QLabel* lines;
    QGridLayout* layout;

public slots:
   void nextSlot();
};

#endif // DIALOG_H
