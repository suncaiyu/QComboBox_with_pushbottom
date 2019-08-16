#pragma once
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>

class AccountItem : public QWidget
{
    Q_OBJECT
public:
    AccountItem(QWidget *parent);
    ~AccountItem();
    int GetIndex();
    void SetIndex(int index);

private:
    void mousePressEvent(QMouseEvent *event);
signals:
    void SignalRemoveAccount(int);
    void ItemClicked(int index);

private slots:
    void RemoveAccount();

private:
    QPushButton * deleteButton;
    QHBoxLayout *mainLayout;
    int index;
};
