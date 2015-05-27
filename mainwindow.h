#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RSA.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString s;
    ~MainWindow();

private slots:
    //считывает введенное сообщение
    void on_actionRead_triggered();
    //зашифровывает сообщение
    void on_actionEncode_triggered();
    //расшифровывает сообщение
    void on_actionDecode_triggered();
    //кнопка выхода
    void on_actionQuit_triggered();
    //кнопка "зашифровать", используется при передаче сообщений между двумя компьютерами,
    //позволяет вводить e и n вручную
    void on_radioButton_toggled(bool checked);
    //кнопка "расшифровать", используется при передаче сообщений между двумя компьютерами,
    //генерирует e и n
    void on_radioButton_2_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    RSA tryhard;
    BigInteger crypt, e, n;
    bool flag;
};

#endif // MAINWINDOW_H
