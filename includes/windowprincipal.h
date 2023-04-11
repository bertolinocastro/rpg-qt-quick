#ifndef WINDOWPRINCIPAL_H
#define WINDOWPRINCIPAL_H

#include <QMainWindow>
#include <QKeyEvent>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowPrincipal; }
QT_END_NAMESPACE

class WindowPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    WindowPrincipal(QWidget *parent = nullptr);
    ~WindowPrincipal();

    void iniciaFase(std::string);
    void start(std::string, QString personagem, QString classe);

private:
    Ui::WindowPrincipal *ui;

public slots:
    void novoJogo();
};
#endif // WINDOWPRINCIPAL_H
