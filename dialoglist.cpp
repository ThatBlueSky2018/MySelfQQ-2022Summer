#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <QToolButton>
#include "widget.h"
#include <QMessageBox>
#include <QApplication>
#include<QString>

//QVector<bool>isShow;
DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    setWindowTitle("MyQQ 2022 Summer");
    setWindowIcon(QPixmap(":/image/qq.png"));

    QVector<QToolButton *>vToolBtn; //声明存放QtoolButton的容器 vToolBtn
    QList<QString> nameList;
    nameList << "Bill Gates" << "Bezos" << "Zuckerberg" << "Andrew Wiggins" << "Elon Musk" << "Bjarne Stroustrup" << "James Gosling" << "Bill Russell" << "Kobe" ;
    QStringList iconNameList;
    iconNameList << "ftbz" << "ymrl" << "qq" << "Cherry" << "dr" <<"jj"<< "lswh" << "qmnn" << "wy";
       for(int i = 0 ; i < 9 ; i++)
       {
           //设置头像
           QToolButton * btn = new QToolButton;
           //设置文字
           btn->setText(nameList[i]);
           //设置头像
           QString iconName = QString(":/image/%1.png").arg(iconNameList.at(i));
           btn->setIcon(QPixmap(iconName));
           //设置头像大小
           btn->setIconSize( QPixmap(iconName).size() );
           //设置按钮风格 透明
           btn->setAutoRaise(true);
           //设置文字和图片一起显示
           btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
           //加到 垂直布局中
           ui->vLayout->addWidget(btn);
           //容器保存住9个按钮，方便以后再次操作
           vToolBtn.push_back(btn);
       }
       for(int i = 0;i < 9 ; i++) {
           QToolButton * btn = new QToolButton;//创建新按钮
           btn->setText(nameList[i]);//设置按钮名称
           QString iconName = QString(":/image/%1.png").arg(iconNameList.at(i));
           btn->setIcon(QPixmap(iconName));//设置图片
           btn->setIconSize(QPixmap(iconName).size());//设置图片大小
           btn->setAutoRaise(true);
       }
       //添加点击事件
       for(int i=0;i<vToolBtn.size();i++) {
           connect(vToolBtn[i],&QToolButton::clicked,this,[=]()
           {
               //qDebug() <<i;
               Widget *chatWidget = new Widget(0,vToolBtn[i]->text());
               chatWidget->setWindowTitle(vToolBtn[i]->text());
               chatWidget->setWindowIcon(vToolBtn[i]->icon());
               chatWidget->show();
           });
       }
       //九个标识位置
       /*for(int i=0;i<9;i++) {
           isShow.push_back(false);
       }
       //添加点击事件
       for(int i=0;i<vToolBtn.size();i++) {
            connect(vToolBtn[i],&QToolButton::clicked,this,[=]()
            {
                if(isShow[i])//如果打开的标志为true，不要重复打开
                {
                    QMessageBox::warning(this,"警告",QString("%1窗口已经被打开了").arg(vToolBtn[i]->text()));
                    return;
                }
                isShow[i]=true;//如果打开不表示为true，可以打开，并且修改打开标志位为true
                Widget *chatWidget = new Widget(0,vToolBtn[i]->text());
                chatWidget->setWindowTitle(vToolBtn[i]->text());
                chatWidget->setWindowIcon(vToolBtn[i]->icon());
                chatWidget->show();
                //如果窗口关闭，将标志位设置回来
                connect(chatWidget,&Widget::closeWidget,this,[=](){
                    isShow[i]=false;
                });
            });
        }*/
        //一个窗口不能多次弹出
}

DialogList::~DialogList()
{
    delete ui;
}
