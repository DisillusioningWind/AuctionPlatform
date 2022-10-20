#include <QApplication>
#include "View/LoginWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget login;
    login.show();
    return a.exec();
}
