#include "msgboxdlg.h"
#include "QMessageBox"


MsgBoxDlg::MsgBoxDlg(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(QStringLiteral("标准消息对话框的实例"));
    label = new QLabel;
    label->setText(QStringLiteral("请选择一种消息"));

    questionBtn = new QPushButton;
    questionBtn->setText(tr("questionMsg"));

    informationBtn = new QPushButton;
    informationBtn->setText(tr("informatinMsg"));

    warningBtn = new QPushButton;
    warningBtn->setText(tr("warningMsg"));

    criticalBtn = new QPushButton;
    criticalBtn->setText(tr("criticalMsg"));

    aboutBtn = new QPushButton;
    aboutBtn->setText(tr("aboutMsg"));

    aboutQtBtn = new QPushButton;
    aboutQtBtn->setText(tr("aboutQtMsg"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label, 0, 0, 1, 2);
    mainLayout->addWidget(questionBtn, 1, 0);
    mainLayout->addWidget(informationBtn, 1, 1);
    mainLayout->addWidget(warningBtn, 2, 0);
    mainLayout->addWidget(criticalBtn, 2, 1);
    mainLayout->addWidget(aboutBtn, 3, 0);
    mainLayout->addWidget(aboutQtBtn, 3, 1);

    connect(questionBtn, SIGNAL(clicked()), this, SLOT(showQuestionMsg()));
    connect(informationBtn, SIGNAL(clicked()), this, SLOT(showInformationMsg()));
    connect(warningBtn, SIGNAL(clicked()), this, SLOT(showWarningMsg()));
    connect(criticalBtn, SIGNAL(clicked()), this, SLOT(showCriticalMsg()));
    connect(aboutBtn, SIGNAL(clicked()), this, SLOT(showAboutMsg()));
    connect(aboutQtBtn, SIGNAL(clicked()), this, SLOT(showAboutQtMsg()));
}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    switch (QMessageBox::question(this, QStringLiteral("Question 消息框"),
                                  QStringLiteral("您现在已经修改完成，是否要结束程序？"),
                                  QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        label->setText("Qusetion button/Ok");
        break;

    case QMessageBox::Cancel:
        label->setText("Question button/Cancel");
        break;

    default:
        break;
    }
    return;
}

void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this, QStringLiteral("Information 消息框"),
                             QStringLiteral("这是Information消息框测试，欢迎您！"));
    return;

}

void MsgBoxDlg::showWarningMsg()
{
    label->setText(tr("Warning Message Box"));
    switch(QMessageBox::warning(this, QStringLiteral("Warning 消息框"),
                   QStringLiteral("您修改的内容还未保存，是否要保存对文档的修改？"),
                    QMessageBox::Discard | QMessageBox::Save | QMessageBox::Cancel,  QMessageBox::Save))
    {
    case QMessageBox::Save:
        label->setText(tr("Warning button/Save"));
        break;
    case QMessageBox::Discard:
        label->setText(tr("Warning button/Discard"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("Warning button/Cancel"));
        break;

    default:
        break;
    }
    return;

}

void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this, QStringLiteral("Critiacal 消息框"), QStringLiteral("这是一个Critical消息框测试！"));
    return;

}

void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this, QStringLiteral("About 消息框"), QStringLiteral("这是一个About消息框测试！"));
    return;
}

void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("About Qt Message Box"));
    QMessageBox::aboutQt(this, QStringLiteral("About Qt 消息框"));
    return;
}



