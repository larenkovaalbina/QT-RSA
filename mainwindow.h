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
    //��������� ��������� ���������
    void on_actionRead_triggered();
    //������������� ���������
    void on_actionEncode_triggered();
    //�������������� ���������
    void on_actionDecode_triggered();
    //������ ������
    void on_actionQuit_triggered();
    //������ "�����������", ������������ ��� �������� ��������� ����� ����� ������������,
    //��������� ������� e � n �������
    void on_radioButton_toggled(bool checked);
    //������ "������������", ������������ ��� �������� ��������� ����� ����� ������������,
    //���������� e � n
    void on_radioButton_2_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    RSA tryhard;
    BigInteger crypt, e, n;
    bool flag;
};

#endif // MAINWINDOW_H
