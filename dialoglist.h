#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QWidget>

//QVector<bool>isShow;

namespace Ui {
class DialogList;
}

class DialogList : public QWidget
{
    Q_OBJECT

public:
    explicit DialogList(QWidget *parent = nullptr);
    ~DialogList();

private:
    Ui::DialogList *ui;
};

#endif // DIALOGLIST_H
