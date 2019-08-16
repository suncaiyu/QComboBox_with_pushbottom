#pragma once
#include <QListWidget>
#include <QComboBox>

class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    MyComboBox(QWidget *parent = 0);
    ~MyComboBox();

public:
    void hidePopup();
    void showPopup();
    void IncreaseItem(QString text, QVariant userData = QVariant());//添加下拉项
    void IncreaseItem(QIcon icon, QString text, QVariant userData = QVariant());
    int GetListWidgetCount();//获取下拉项的个数
    void RefreshIndex();
    void AdjustItemWidth();


protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

signals:
    void SignalShowAccount(QString account);
    void SignalRemoveItem(int i);
private slots :
    void SlotShowAccount(int index);
    void SlotRemoveAccount(int index);

private:
    QListWidget *listWidget;
};

