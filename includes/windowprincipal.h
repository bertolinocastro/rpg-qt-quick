#ifndef WINDOWPRINCIPAL_H
#define WINDOWPRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowPrincipal; }
QT_END_NAMESPACE

class WindowPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    WindowPrincipal(QWidget *parent = nullptr);
    ~WindowPrincipal();

private:
    Ui::WindowPrincipal *ui;

public slots:
    void novoJogo();
};
#endif // WINDOWPRINCIPAL_H
