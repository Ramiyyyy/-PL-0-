#ifndef AUTHOR_H
#define AUTHOR_H

#include <QWidget>

namespace Ui {
class Author;
}

class Author : public QWidget
{
    Q_OBJECT

public:
    explicit Author(QWidget *parent = nullptr);
    ~Author();

private:
    Ui::Author *ui;
};

#endif // AUTHOR_H
