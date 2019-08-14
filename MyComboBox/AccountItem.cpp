#include "AccountItem.h"
#include <QHBoxLayout>

AccountItem::AccountItem(QWidget *parent)
    : QWidget(parent)
{
    m_Mouse_press = false;
    m_pAccount_number = new QLabel();
    pic = new QLabel();
//    m_pAccount_number->setMaximumWidth(300);
    m_pDelede_button = new QPushButton();

    pic->setPixmap(QPixmap(":/Close.jpg"));
    m_pDelede_button->setIcon(QIcon(":/cross.png"));
    m_pDelede_button->setFixedSize(20, 20);
    m_pDelede_button->setStyleSheet("background:transparent;");
    connect(m_pDelede_button, SIGNAL(clicked()), this, SLOT(removeAccount()));

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(pic);
    main_layout->addWidget(m_pAccount_number);
    main_layout->addStretch();
    main_layout->addWidget(m_pDelede_button);
//    main_layout->setContentsMargins(5, 5, 5, 5);
//    main_layout->setSpacing(5);
    this->setLayout(main_layout);
}

AccountItem::~AccountItem()
{

}

void AccountItem::setAccountNumber(QString account_text)
{
    m_pAccount_number->setText(account_text);
    //m_pAccount_number->setPixmap(QPixmap(":/cross.png"));
    m_pAccount_number->setAlignment(Qt::AlignCenter);
}

QString AccountItem::getAccountNumber()
{
    QString account_number_text = m_pAccount_number->text();

    return account_number_text;
}

void AccountItem::removeAccount()
{
    QString account_number_text = m_pAccount_number->text();
    emit SignalRemoveAccount(account_number_text);
}

void AccountItem::mousePressEvent(QMouseEvent *event)
{
    emit SignalShowAccount(m_pAccount_number->text());
}
