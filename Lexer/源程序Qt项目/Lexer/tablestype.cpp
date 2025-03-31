#include "tablestype.h"
#include "ui_tablestype.h"

Tablestype::Tablestype(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tablestype)
{
    ui->setupUi(this);
    this->setFixedSize(679, 490);
}

Tablestype::~Tablestype()
{
    delete ui;
}
