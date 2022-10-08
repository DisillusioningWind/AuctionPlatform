#include "LoginWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget* login = new LoginWidget;
    if (login->exec() == QDialog::Accepted)
    {
        return a.exec();
    }
    else
        return 0;
}
