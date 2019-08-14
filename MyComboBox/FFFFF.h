#ifndef FFFFF_H
#define FFFFF_H

#include <QWidget>
#include "MyComboBox.h"

namespace Ui {
class FFFFF;
}

class FFFFF : public QWidget
{
    Q_OBJECT

public:
    explicit FFFFF(QWidget *parent = nullptr);
    ~FFFFF();

public slots:
    void addii();

private:
    Ui::FFFFF *ui;
    MyComboBox *m_pAddressBox;
};

#endif // FFFFF_H
