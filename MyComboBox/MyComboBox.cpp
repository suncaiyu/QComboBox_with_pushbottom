#include "MyComboBox.h"
#include "AccountItem.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QCompleter>
#include <QDebug>

MyComboBox::MyComboBox(QWidget *parent)
    : QComboBox(parent)
{
    m_pListWidget = new QListWidget(this);
    this->setModel(m_pListWidget->model());
    this->setView(m_pListWidget);
}

MyComboBox::~MyComboBox()
{

}

// 解决垂直滚动条出现，多次popup时item错乱的问题  （重要）
void MyComboBox::hidePopup()
{
    m_pListWidget->scrollToTop();
    QComboBox::hidePopup();
}

void MyComboBox::showPopup()
{
    QComboBox::showPopup();
    m_pListWidget->scrollToTop();
}

void MyComboBox::increaseItem(QString text)
{
    AccountItem *account_item = new AccountItem(this);
    account_item->setAccountNumber(text);
    connect(account_item, SIGNAL(SignalShowAccount(QString)), this, SLOT(SlotShowAccount(QString)));
    connect(account_item, SIGNAL(SignalRemoveAccount(QString)), this, SLOT(SlotRemoveAccount(QString)));
    QListWidgetItem *list_item = new QListWidgetItem(m_pListWidget);
    m_pListWidget->setItemWidget(list_item, account_item);
}

void MyComboBox::removeItem(QString account)
{
    int list_count = getListWidgetCount();
    for (int i = 0; i < list_count; i++)
    {
        QListWidgetItem *item = m_pListWidget->item(i);
        AccountItem *account_item = (AccountItem *)(m_pListWidget->itemWidget(item));
        QString account_number = account_item->getAccountNumber();
        if (account == account_number)
        {
            m_pListWidget->takeItem(i);
            delete item;
            emit SignalRemoveItem(i);
        }
    }
}

int MyComboBox::getListWidgetCount()
{
    return m_pListWidget->count();
}

void MyComboBox::SlotShowAccount(QString account)
{
    qDebug()<<account;
    setEditText(account);
    lineEdit()->setReadOnly(1);
    hidePopup();
    emit SignalShowAccount(account.trimmed());
}

void MyComboBox::SlotRemoveAccount(QString account)
{
    hidePopup();
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, QStringLiteral("删除"), QStringLiteral("确定要删除该地区吗?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (rb == QMessageBox::Yes)
    {
        int list_count = getListWidgetCount();
        for (int i = 0; i < list_count; i++)
        {
            QListWidgetItem *item = m_pListWidget->item(i);
            AccountItem *account_item = (AccountItem *)(m_pListWidget->itemWidget(item));
            QString account_number = account_item->getAccountNumber();
            if (account == account_number)
            {
                m_pListWidget->takeItem(i);
                delete item;
                emit SignalRemoveItem(i);
                break;
            }
        }
    }
}

bool  MyComboBox::findItem(QString account)
{
    int list_count = getListWidgetCount();
    for (int i = 0; i < list_count; i++)
    {
        QListWidgetItem *item = m_pListWidget->item(i);
        AccountItem *account_item = (AccountItem *)(m_pListWidget->itemWidget(item));
        QString account_number = account_item->getAccountNumber();
        if (account == account_number)
        {
            return true;
        }
    }
    return false;
}

void MyComboBox::paintEvent(QPaintEvent *e)
{
    QComboBox::paintEvent(e);
}
