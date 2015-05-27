#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRead_triggered()
{
    s=ui->textBrowser_4->toPlainText();
}

void MainWindow::on_actionEncode_triggered()
{
        QString l;

        std::string k,usl;
        k=s.toLocal8Bit().constData();

        if (flag == false)
        {
            tryhard.publish_keys(e, n);



            l = BigIntegerToStr(e);
            ui->textBrowser_2->setPlainText(l);

            l = BigIntegerToStr(n);
            ui->textBrowser_3->setPlainText(l);
            l.clear();

            for(int i=0; i<s.length();i++)
            {
            BigInteger message(k[i]);

            tryhard.encryption(message, crypt);
            l += BigIntegerToStr(crypt);
            l += ";";
            }

       }

        else{

            QString eee= ui->textBrowser_2->toPlainText();
        QString nnn=ui->textBrowser_3->toPlainText();

       std::string ee=eee.toStdString(),nn=nnn.toStdString();
        BigInteger e(ee);
        BigInteger n(nn);
        for(int i=0; i<s.length();i++)
        {
        BigInteger message(k[i]);

        tryhard.encryption(message, crypt,e,n);
        l += BigIntegerToStr(crypt);
        l += ";";
        }
        }


        ui->textBrowser->setPlainText(l);


}

void MainWindow::on_actionDecode_triggered()
{
    QString l;
    std::string k,temp_saver,total;

    k=s.toLocal8Bit().constData();
    vector<string> saver;
    temp_saver.clear();
    for(int i=0; i<k.size();i++)
    {
    if (k[i]!=';')
        temp_saver +=k[i];
    else
    {
        saver.push_back(temp_saver);
        temp_saver.clear();
    }
    }
    BigInteger result;
    l.clear();
    total.clear();
    for(int i=0; i<saver.size();i++)
    {
        BigInteger message(saver[i]);
        tryhard.decryption(result, message);
        total += result.toInt();

    }
    l=QString::fromStdString(total);
    ui->textBrowser->setText(l);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_radioButton_toggled(bool checked)
{

        flag = true;

        QString li;
        std::string usls;

        ui->textBrowser_2->setReadOnly(false);
        li = ui->textBrowser_2->toPlainText();
        usls = li.toStdString();
        e = BigInteger::BigInteger(usls);

        ui->textBrowser_3->setReadOnly(false);
        li = ui->textBrowser_3->toPlainText();
        usls = li.toStdString();
        n = BigInteger::BigInteger(usls);

}
void MainWindow::on_radioButton_2_toggled(bool checked)
{
    flag = false;
    ui->textBrowser_2->setReadOnly(true);
    ui->textBrowser_3->setReadOnly(true);
}
