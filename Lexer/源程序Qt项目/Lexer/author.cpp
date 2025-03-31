#include "author.h"
#include "ui_author.h"

Author::Author(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Author)
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
}

Author::~Author()
{
    delete ui;
}
