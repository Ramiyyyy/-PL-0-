/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAnalysis;
    QAction *actionName;
    QAction *actionMail;
    QAction *actionTable;
    QAction *actionClearInput;
    QAction *actionAuther;
    QAction *actionClearOutput;
    QAction *action_R;
    QAction *actionSaveResult;
    QAction *actionCtrl_S;
    QAction *actionCtrl_Shift_S;
    QAction *actionCtrl_O;
    QAction *actionCtrl_1;
    QAction *actionCtrl_2;
    QAction *actionCtrl_3;
    QWidget *centralwidget;
    QGroupBox *groupBoxInput;
    QTextEdit *textEdit1;
    QGroupBox *groupBoxOutput;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAnalysis;
    QPushButton *pushButtonClearInput;
    QPushButton *pushButtonClearOutput;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu;
    QMenu *menu_O;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1039, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionAnalysis = new QAction(MainWindow);
        actionAnalysis->setObjectName("actionAnalysis");
        actionName = new QAction(MainWindow);
        actionName->setObjectName("actionName");
        actionMail = new QAction(MainWindow);
        actionMail->setObjectName("actionMail");
        actionTable = new QAction(MainWindow);
        actionTable->setObjectName("actionTable");
        actionClearInput = new QAction(MainWindow);
        actionClearInput->setObjectName("actionClearInput");
        actionAuther = new QAction(MainWindow);
        actionAuther->setObjectName("actionAuther");
        actionClearOutput = new QAction(MainWindow);
        actionClearOutput->setObjectName("actionClearOutput");
        action_R = new QAction(MainWindow);
        action_R->setObjectName("action_R");
        actionSaveResult = new QAction(MainWindow);
        actionSaveResult->setObjectName("actionSaveResult");
        actionCtrl_S = new QAction(MainWindow);
        actionCtrl_S->setObjectName("actionCtrl_S");
        actionCtrl_Shift_S = new QAction(MainWindow);
        actionCtrl_Shift_S->setObjectName("actionCtrl_Shift_S");
        actionCtrl_O = new QAction(MainWindow);
        actionCtrl_O->setObjectName("actionCtrl_O");
        actionCtrl_1 = new QAction(MainWindow);
        actionCtrl_1->setObjectName("actionCtrl_1");
        actionCtrl_2 = new QAction(MainWindow);
        actionCtrl_2->setObjectName("actionCtrl_2");
        actionCtrl_3 = new QAction(MainWindow);
        actionCtrl_3->setObjectName("actionCtrl_3");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBoxInput = new QGroupBox(centralwidget);
        groupBoxInput->setObjectName("groupBoxInput");
        groupBoxInput->setGeometry(QRect(20, 20, 361, 521));
        QFont font;
        font.setPointSize(12);
        groupBoxInput->setFont(font);
        textEdit1 = new QTextEdit(groupBoxInput);
        textEdit1->setObjectName("textEdit1");
        textEdit1->setGeometry(QRect(10, 30, 341, 471));
        groupBoxOutput = new QGroupBox(centralwidget);
        groupBoxOutput->setObjectName("groupBoxOutput");
        groupBoxOutput->setGeometry(QRect(490, 20, 531, 521));
        groupBoxOutput->setFont(font);
        tableWidget = new QTableWidget(groupBoxOutput);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 30, 511, 471));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(390, 250, 91, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAnalysis = new QPushButton(layoutWidget);
        pushButtonAnalysis->setObjectName("pushButtonAnalysis");
        QFont font1;
        font1.setPointSize(10);
        pushButtonAnalysis->setFont(font1);

        verticalLayout->addWidget(pushButtonAnalysis);

        pushButtonClearInput = new QPushButton(layoutWidget);
        pushButtonClearInput->setObjectName("pushButtonClearInput");
        pushButtonClearInput->setFont(font1);

        verticalLayout->addWidget(pushButtonClearInput);

        pushButtonClearOutput = new QPushButton(layoutWidget);
        pushButtonClearOutput->setObjectName("pushButtonClearOutput");
        pushButtonClearOutput->setFont(font1);

        verticalLayout->addWidget(pushButtonClearOutput);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1039, 22));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName("menu_F");
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_O = new QMenu(menubar);
        menu_O->setObjectName("menu_O");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu->menuAction());
        menu_F->addAction(actionOpen);
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSaveResult);
        menu->addSeparator();
        menu->addAction(actionTable);
        menu->addAction(actionAuther);
        menu->addAction(actionName);
        menu->addAction(actionMail);
        menu->addAction(actionCtrl_S);
        menu->addAction(actionCtrl_Shift_S);
        menu->addAction(actionCtrl_O);
        menu->addAction(actionCtrl_1);
        menu->addAction(actionCtrl_2);
        menu->addAction(actionCtrl_3);
        menu_O->addAction(actionAnalysis);
        menu_O->addAction(actionClearInput);
        menu_O->addAction(actionClearOutput);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\257\215\346\263\225\345\210\206\346\236\220\345\231\250", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
        actionAnalysis->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\236\220(&A)", nullptr));
        actionName->setText(QCoreApplication::translate("MainWindow", "Auther:\347\272\270\344\270\212\350\247\202\346\230\237", nullptr));
        actionMail->setText(QCoreApplication::translate("MainWindow", "E-mail :w2645268651@outlook.com", nullptr));
        actionTable->setText(QCoreApplication::translate("MainWindow", "\347\247\215\345\210\253\347\240\201\350\241\250(&T)", nullptr));
        actionClearInput->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\350\276\223\345\205\245(&C)", nullptr));
        actionAuther->setText(QCoreApplication::translate("MainWindow", "\344\275\234\350\200\205(&E)", nullptr));
        actionClearOutput->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\350\276\223\345\207\272(&V)", nullptr));
        action_R->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        actionSaveResult->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\347\273\223\346\236\234(&R)", nullptr));
        actionCtrl_S->setText(QCoreApplication::translate("MainWindow", "Ctrl+S            \344\277\235\345\255\230\350\276\223\345\205\245\346\226\207\346\234\254", nullptr));
        actionCtrl_Shift_S->setText(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S  \344\277\235\345\255\230\345\210\206\346\236\220\347\273\223\346\236\234", nullptr));
        actionCtrl_O->setText(QCoreApplication::translate("MainWindow", "Ctrl+O           \346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        actionCtrl_1->setText(QCoreApplication::translate("MainWindow", "Ctrl+1            \345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
        actionCtrl_2->setText(QCoreApplication::translate("MainWindow", "Ctrl+2            \346\270\205\347\251\272\350\276\223\345\205\245", nullptr));
        actionCtrl_3->setText(QCoreApplication::translate("MainWindow", "Ctrl+3            \346\270\205\347\251\272\350\276\223\345\207\272", nullptr));
        groupBoxInput->setTitle(QCoreApplication::translate("MainWindow", "PL0\346\272\220\347\250\213\345\272\217\357\274\232", nullptr));
        groupBoxOutput->setTitle(QCoreApplication::translate("MainWindow", "\350\257\215\346\263\225\345\210\206\346\236\220\347\273\223\346\236\234\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\216\237\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\347\247\215\345\210\253\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\347\247\215\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\210\227", nullptr));
        pushButtonAnalysis->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
        pushButtonClearInput->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\350\276\223\345\205\245", nullptr));
        pushButtonClearOutput->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\350\276\223\345\207\272", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257(&I)", nullptr));
        menu_O->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234(&O)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
