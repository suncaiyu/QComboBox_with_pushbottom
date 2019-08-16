#include "AccountItem.h"

AccountItem::AccountItem(QWidget *parent)
    : QWidget(parent)
{
    deleteButton = new QPushButton();

    deleteButton->setIcon(QIcon(":/cross.png"));
    deleteButton->setFixedSize(20, 20);
    deleteButton->setStyleSheet("background:transparent;");
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(RemoveAccount()));

    mainLayout = new QHBoxLayout();
    mainLayout->addStretch();
    mainLayout->addWidget(deleteButton);
    mainLayout->setContentsMargins(5, 5, 5, 5);
    mainLayout->setSpacing(5);
    this->setLayout(mainLayout);
}

AccountItem::~AccountItem()
{
    delete deleteButton;
    deleteButton = nullptr;
    delete mainLayout;
    mainLayout = nullptr;
}

void AccountItem::RemoveAccount()
{
    emit SignalRemoveAccount(index);
}

void AccountItem::mousePressEvent(QMouseEvent *event)
{
    emit ItemClicked(index);
}

int AccountItem::GetIndex()
{
    return index;
}

void AccountItem::SetIndex(int index)
{
    this->index = index;
}
