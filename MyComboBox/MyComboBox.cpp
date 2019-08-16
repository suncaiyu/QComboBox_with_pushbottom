#include "MyComboBox.h"
#include "AccountItem.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QCompleter>
#include <QDebug>

MyComboBox::MyComboBox(QWidget *parent)
    : QComboBox(parent)
{
    listWidget = new QListWidget(this);
    this->setModel(listWidget->model());
    this->setView(listWidget);
}

MyComboBox::~MyComboBox()
{

}

// 解决垂直滚动条出现，多次popup时item错乱的问题  （重要）
void MyComboBox::hidePopup()
{
    listWidget->scrollToTop();
    QComboBox::hidePopup();
}

void MyComboBox::showPopup()
{
    QComboBox::showPopup();
    listWidget->scrollToTop();
}

void MyComboBox::IncreaseItem(QIcon icon, QString text, QVariant userData)
{
    AccountItem *accountItem = new AccountItem(this);
    connect(accountItem, SIGNAL(ItemClicked(int)), this, SLOT(SlotShowAccount(int)));
    connect(accountItem, SIGNAL(SignalRemoveAccount(int)), this, SLOT(SlotRemoveAccount(int)));
    QListWidgetItem *listItem = new QListWidgetItem(listWidget);
    listWidget->setItemWidget(listItem, accountItem);
    int count = GetListWidgetCount() - 1;
    setItemData(count, userData);
    setItemIcon(count, icon);
    setItemText(count, text);
    RefreshIndex();
    AdjustItemWidth();
}

void MyComboBox::IncreaseItem(QString text, QVariant userData)
{

}

int MyComboBox::GetListWidgetCount()
{
    return listWidget->count();
}

void MyComboBox::SlotShowAccount(int index)
{
    hidePopup();
    setCurrentIndex(index);
}

void MyComboBox::SlotRemoveAccount(int index)
{
    hidePopup();
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, QStringLiteral("删除"), QStringLiteral("确定要删除该地区吗?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (rb == QMessageBox::Yes)
    {
        int listCount = GetListWidgetCount();
        for (int i = 0; i < listCount; i++)
        {
            QListWidgetItem *item = listWidget->item(i);
            AccountItem *accountItem = (AccountItem *)(listWidget->itemWidget(item));
            if (accountItem->GetIndex() == index) {
                listWidget->takeItem(i);
                break;
            }
        }
    }
    RefreshIndex();
}


void MyComboBox::paintEvent(QPaintEvent *e)
{
    QComboBox::paintEvent(e);
}

void MyComboBox::RefreshIndex()
{
    for (int i = 0; i < GetListWidgetCount(); i++) {
        QListWidgetItem *item = listWidget->item(i);
        AccountItem *accountItem = (AccountItem *)(listWidget->itemWidget(item));
        accountItem->SetIndex(i);
    }
}

void MyComboBox::AdjustItemWidth()
{
    int max_len = 0;
    for (int idx = 0; idx < this->count(); idx++) {
        if (max_len < this->itemText(idx).length()) {
            max_len = this->itemText(idx).length();
        }
    }
    int pt_val = this->font().pointSize();//获取字体的磅值
    int value = max_len * pt_val*0.75 +55;
    if (this->view()->width() < value) {
        this->view()->setMinimumWidth(value);
    }
}

void MyComboBox::resizeEvent(QResizeEvent *e)
{
    AdjustItemWidth();
}