#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QGridLayout>

#include "inputdlg.h"
#include "msgboxdlg.h"
#include "customdlg.h"


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();

private:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;
    QPushButton *colorBtn;
    QFrame *colorFrame;
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;
    QPushButton *inputBtn;
    InputDlg *inputDlg;
    QPushButton *msgBtn;
    MsgBoxDlg *msgDlg;
    QPushButton *CustomBtn;
    QLabel *label;
};

#endif // DIALOG_H
