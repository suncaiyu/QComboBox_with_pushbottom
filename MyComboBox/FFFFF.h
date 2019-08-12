#ifndef FFFFF_H
#define FFFFF_H

#include <QWidget>

namespace Ui {
class FFFFF;
}

class FFFFF : public QWidget
{
    Q_OBJECT

public:
    explicit FFFFF(QWidget *parent = nullptr);
    ~FFFFF();

private:
    Ui::FFFFF *ui;
};

#endif // FFFFF_H
