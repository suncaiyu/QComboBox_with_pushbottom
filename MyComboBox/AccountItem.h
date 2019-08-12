#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QIcon>

class AccountItem : public QWidget
{
    Q_OBJECT
public:
    AccountItem(QWidget *parent);
    ~AccountItem();

public:
    void setAccountNumber(QString account_text);
    QString getAccountNumber();
private:
    void mousePressEvent(QMouseEvent *event);
signals:
    void SignalRemoveAccount(QString);
    void SignalShowAccount(QString);

    private slots:
    void removeAccount();

private:
    bool m_Mouse_press;
    QIcon *m_icon;
    QLabel * m_pAccount_number;
    QPushButton * m_pDelede_button;

};
