#include "dialog.h"
#include "inputdlg.h"
#include <QString>
#include <QColorDialog>
#include <QFontDialog>
#include <QPixmap>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    fileBtn = new QPushButton;
    fileBtn->setText(QStringLiteral("文件标准对话框实例"));
    fileLineEdit = new QLineEdit;

    colorBtn = new QPushButton;
    colorBtn->setText(QStringLiteral("颜色标准对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    fontBtn = new QPushButton;
    fontBtn->setText(QStringLiteral("字体标准对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome!"));

    inputBtn = new QPushButton;
    inputBtn->setText(QStringLiteral("标准输入对话框实例"));

    msgBtn = new QPushButton;
    msgBtn->setText(QStringLiteral("标准消息对话框实例"));

    CustomBtn = new QPushButton;
    CustomBtn->setText(QStringLiteral("用户自定义消息对话框"));
    label = new QLabel;
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn, 0, 0);
    mainLayout->addWidget(fileLineEdit, 0, 1);
    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame, 1, 1);
    mainLayout->addWidget(fontBtn, 2, 0);
    mainLayout->addWidget(fontLineEdit, 2, 1);
    mainLayout->addWidget(inputBtn, 3, 0);
    mainLayout->addWidget(msgBtn, 3, 1);
    mainLayout->addWidget(CustomBtn, 4, 0);
    mainLayout->addWidget(label, 4, 1);

    QObject::connect(fileBtn, SIGNAL(clicked()), this, SLOT(showFile()));
     QObject::connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));
     QObject::connect(fontBtn, SIGNAL(clicked()), this, SLOT(showFont()));
     QObject::connect(inputBtn, SIGNAL(clicked()), this, SLOT(showInputDlg()));
     QObject::connect(msgBtn, SIGNAL(clicked()), this, SLOT(showMsgDlg()));
     QObject::connect(CustomBtn, SIGNAL(clicked()), this, SLOT(showCustomDlg()));
}

void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/", tr("files (*.cpp *.c *.h)"));
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if(c.isValid())
    {
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if(ok)
    {
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg;
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg();
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    label->setText(tr("Custom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(QStringLiteral("用户自定义消息框"));
    QPushButton *yesBtn = customMsgBox.addButton(tr("yes"), QMessageBox::ActionRole);
    QPushButton *noBtn = customMsgBox.addButton(tr("No"), QMessageBox::ActionRole);
    QPushButton *cancelBtn = customMsgBox.addButton(QMessageBox::Cancel);

    customMsgBox.setText(QStringLiteral("这是一个用户自定义消息框"));
    customMsgBox.setIconPixmap(QPixmap("Qt.png"));
    customMsgBox.exec();

    if(customMsgBox.clickedButton() == yesBtn)
        label->setText("Custom Message Box/Yes");
    if(customMsgBox.clickedButton() == noBtn)
        label->setText("Custom Message Box/No");
    if(customMsgBox.clickedButton() == cancelBtn)
        label->setText("Custom Message Box/Cancel");

}

Dialog::~Dialog()
{

}
