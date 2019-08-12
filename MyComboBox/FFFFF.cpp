#include "FFFFF.h"
#include "ui_FFFFF.h"

FFFFF::FFFFF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FFFFF)
{
    ui->setupUi(this);
    for (int i = 0; i<15; i++){
    ui->comboBox->increaseItem(QString("Account")+QString::number(i,10));  //加入下拉项（str：文本）
    ui->comboBox->setItemIcon(i,QIcon(":/Close.jpg"));
    }
}

FFFFF::~FFFFF()
{
    delete ui;
}
