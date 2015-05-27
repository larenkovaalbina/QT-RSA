#include "mainwindow.h"
#include <QApplication>
#include "RSA.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
/*int main()
{
    cout << "start" << endl;
    RSA tryhard;
    string s="123";


    for (int i = 0; i < s.length(); i++)
    {


        BigInteger message(s[i]);

        cout << "message:   " << message << endl;
        BigInteger crypt, result, e, n;
        tryhard.publish_keys(e, n);
        cout << "exp:  " << e << endl << "key:  " << n << endl;
        tryhard.encryption(message, crypt);
        cout << "crypted message:  " << crypt << endl;
        tryhard.decryption(result, crypt);
        cout << "decrypted message:   " << result << endl;
    }
    system("pause");
    return 0;
}
*/
