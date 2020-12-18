#include "gui.h"
#include "send.h"
#include "receive.h"
#include "ui_gui.h"
#include <QDebug>
#include <string>

GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
}

GUI::~GUI()
{
    delete ui;
}

void GUI::on_pushButton_clicked()
{
    startEncode();
}


void GUI::on_lineEdit_returnPressed()
{
    startEncode();
}

void GUI::startEncode(){
    bool copy = true;

    QString mode = ui->comboBox->currentText();
    qDebug() << "Mode: " << mode;

    QString input = ui->lineEdit->text();
    qDebug() << "Input: " << input;

    std::string stdOutput = "error";

    std::string stdInput = input.toUtf8().constData();

    if(mode == "Send"){
        stdOutput = getSendOutput(stdInput);
    }
    if(mode == "Receive"){
        stdOutput = getReceiveOutput(stdInput);
        copy = false;
    }

    QString output = QString::fromStdString(stdOutput);

    ui->plainTextEdit->setPlainText(output);

    if(copy){
        ui->plainTextEdit->selectAll();
        ui->plainTextEdit->copy();
    }

    qDebug() << "Output: " << output;
}
