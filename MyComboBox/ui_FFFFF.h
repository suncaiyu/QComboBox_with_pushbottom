/********************************************************************************
** Form generated from reading UI file 'FFFFF.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFFFF_H
#define UI_FFFFF_H

#include <MyComboBox.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FFFFF
{
public:
    QGridLayout *gridLayout;
    MyComboBox *comboBox;
    QLineEdit *lineEdit;

    void setupUi(QWidget *FFFFF)
    {
        if (FFFFF->objectName().isEmpty())
            FFFFF->setObjectName(QString::fromUtf8("FFFFF"));
        FFFFF->resize(400, 300);
        gridLayout = new QGridLayout(FFFFF);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new MyComboBox(FFFFF);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        lineEdit = new QLineEdit(FFFFF);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);


        retranslateUi(FFFFF);

        QMetaObject::connectSlotsByName(FFFFF);
    } // setupUi

    void retranslateUi(QWidget *FFFFF)
    {
        FFFFF->setWindowTitle(QApplication::translate("FFFFF", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FFFFF: public Ui_FFFFF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFFFF_H
