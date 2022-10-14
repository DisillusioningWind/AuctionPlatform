#include <QApplication>
#include "GlobalVariable.h"
#include "View/LoginWidget.h"
#include "View/UsrWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LoginWidget* login = new LoginWidget;
    //if (login->exec() == QDialog::Accepted)
    //{
    //    if (pCon.GetConState() == ConState::stUserLogin)
    //    {
    //        UsrWidget usr;
    //        usr.show();
    //        return a.exec();
    //    }
    //}
    //else
    //    return 0;

    pCon.UserLogin("usr", "pwd");

    UsrWidget u;
    u.show();
    return a.exec();
}
