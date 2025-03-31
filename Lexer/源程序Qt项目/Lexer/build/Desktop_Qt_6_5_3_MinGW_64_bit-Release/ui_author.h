/********************************************************************************
** Form generated from reading UI file 'author.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHOR_H
#define UI_AUTHOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Author
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Author)
    {
        if (Author->objectName().isEmpty())
            Author->setObjectName("Author");
        Author->resize(400, 300);
        layoutWidget = new QWidget(Author);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 40, 354, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);


        retranslateUi(Author);

        QMetaObject::connectSlotsByName(Author);
    } // setupUi

    void retranslateUi(QWidget *Author)
    {
        Author->setWindowTitle(QCoreApplication::translate("Author", "Form", nullptr));
        label->setText(QCoreApplication::translate("Author", "\344\275\234\350\200\205\357\274\232\347\272\270\344\270\212\350\247\202\346\230\237", nullptr));
        label_2->setText(QCoreApplication::translate("Author", "\351\202\256\347\256\261\357\274\232w2645268651@outlook.com", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Author: public Ui_Author {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHOR_H
