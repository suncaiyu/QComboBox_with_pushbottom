#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MyComboBox.h"
#include <QDebug>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pAddressBox = new MyComboBox(this);

    m_pAddressBox->setEditable(true);
    m_pAddressBox->setMaxVisibleItems(6);
    m_pAddressBox->setStyleSheet("QComboBox QAbstractItemView::item{height:30px;}");
    for (int i = 0; i<5; i++){
    m_pAddressBox->IncreaseItem(QString("Account")+QString::number(i,10));  //加入下拉项（str：文本）
    m_pAddressBox->setItemIcon(i,QIcon(":/Close.jpg"));
    }
//    m_pAddressBox->setCurrentIndex(0);
    setCentralWidget(m_pAddressBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
//    m_pAddressBox->move(10,30);
//    m_pAddressBox->resize(rect().width() - 20,30);
}

void MainWindow::lineClicked()
{
    qDebug()<<"22";
}
