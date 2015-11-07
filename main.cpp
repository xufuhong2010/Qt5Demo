#include "dialog.h"
//#include "msgboxdlg.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog *w = new Dialog;
    w->show();

 //   MsgBoxDlg *m = new MsgBoxDlg(0);
 //   m->show();


    return a.exec();
}
