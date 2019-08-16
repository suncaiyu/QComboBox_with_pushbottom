#include "FFFFF.h"
#include "ui_FFFFF.h"
#include "AccountItem.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

FFFFF::FFFFF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FFFFF)
{
    m_pAddressBox = new MyComboBox(this);

    m_pAddressBox->setMaxVisibleItems(6);
    m_pAddressBox->setStyleSheet("QComboBox QAbstractItemView::item{height:30px;}");


    QPushButton *b = new QPushButton;
    connect(b,SIGNAL(clicked()),this,SLOT(addii()));
    QVBoxLayout *l=new QVBoxLayout();
    l->addWidget(m_pAddressBox);
    l->addWidget(b);
    setLayout(l);
}

FFFFF::~FFFFF()
{
    delete ui;
}

void FFFFF::addii()
{
    m_pAddressBox->IncreaseItem(QIcon(":/Close.jpg"), QString("Account")+QString::number(qrand(),10));  //加入下拉项（str：文本）
    m_pAddressBox->setCurrentIndex(m_pAddressBox->GetListWidgetCount() - 1);
}