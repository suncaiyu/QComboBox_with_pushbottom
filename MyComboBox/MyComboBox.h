#pragma once
#include <QListWidget>
#include <QComboBox>

class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    MyComboBox(QWidget *parent = 0);
    ~MyComboBox();
        QListWidget *m_pListWidget;

public:
    void hidePopup();
    void showPopup();
    void increaseItem(QString text);//添加下拉项
    void removeItem(QString account);//删除下拉项,返回该项的位置
    int getListWidgetCount();//获取下拉项的个数
    bool findItem(QString account);
protected:
    void paintEvent(QPaintEvent *e);

signals:
    void SignalShowAccount(QString account);
    void SignalRemoveItem(int i);
private slots :
    void SlotShowAccount(QString);
    void SlotRemoveAccount(QString);

private:

};

