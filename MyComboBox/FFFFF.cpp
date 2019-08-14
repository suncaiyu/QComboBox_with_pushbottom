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

    m_pAddressBox->setEditable(true);
    m_pAddressBox->setMaxVisibleItems(6);
    m_pAddressBox->setStyleSheet("QComboBox QAbstractItemView::item{height:30px;}");
//    for (int i = 0; i<5; i++){
//    m_pAddressBox->increaseItem(QString("Account")+QString::number(i,10));  //加入下拉项（str：文本）
//    m_pAddressBox->setItemIcon(i,QIcon(":/Close.jpg"));
//    }


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
    m_pAddressBox->increaseItem(QString("Account")+QString::number(qrand(),10));  //加入下拉项（str：文本）
//    qDebug()<<m_pAddressBox->m_pListWidget->count();
//    m_pAddressBox->setItemIcon(i,QIcon(":/Close.jpg"));
    int i = m_pAddressBox->m_pListWidget->count()-1;
    QListWidgetItem *item = m_pAddressBox->m_pListWidget->item(i);
    AccountItem *account_item = (AccountItem *)(m_pAddressBox->m_pListWidget->itemWidget(item));
    qDebug()<<account_item->getAccountNumber();
    m_pAddressBox->setCurrentText(account_item->getAccountNumber());
//    qDebug()<<m_pAddressBox->currentText();
}
