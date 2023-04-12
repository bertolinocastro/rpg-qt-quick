#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <vector>
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
    int text_it;
    std::vector<std::string> full_text;
    std::vector<std::string> split(std::string, std::string);
    std::string readFileIntoString(const std::string&);

public slots:
   void nextSlot();
};

#endif // DIALOG_H
