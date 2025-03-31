#ifndef TABLESTYPE_H
#define TABLESTYPE_H

#include <QWidget>

namespace Ui {
class Tablestype;
}

class Tablestype : public QWidget
{
    Q_OBJECT

public:
    explicit Tablestype(QWidget *parent = nullptr);
    ~Tablestype();

private:
    Ui::Tablestype *ui;
};

#endif // TABLESTYPE_H
