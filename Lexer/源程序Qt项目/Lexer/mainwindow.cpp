#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QTextEdit>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QAction>
#include <QFile>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <QSet>
#include "lexer.h"
#include <QTableWidget>
#include "tablestype.h"
#include "author.h"
#include <QPalette>
#include <QColor>
#include <QHeaderView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//----------------------------------界面----------------------------------------------------------
    this->setFixedSize(1039, 600);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //----------------------美化---------------------------
    // 设置主窗口背景颜色
    QPalette mainPalette;
    mainPalette.setColor(QPalette::Window, QColor(240, 248, 255)); // 浅蓝色背景
    this->setPalette(mainPalette);

    // 设置输入框样式
    ui->textEdit1->setStyleSheet("background-color: #f5f5f5; font-size: 16px; color: #333; border: 1px solid #ccc; border-radius: 5px; padding: 5px;");

    // 设置输出表格样式
    ui->tableWidget->setStyleSheet("background-color: #ffffff; gridline-color: #dcdcdc; font-size: 14px; color: #333;");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color: #add8e6; font-weight: bold; border: 1px solid #ccc;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color: #e6f7ff; font-weight: bold; border: 1px solid #ccc;}");
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setPalette(QPalette(QColor(240, 255, 255)));

    // 设置按钮样式
    ui->pushButtonAnalysis->setStyleSheet("QPushButton {background-color: #4CAF50; color: white; border: none; padding: 10px; border-radius: 5px;} QPushButton:hover {background-color: #45a049;}");
    ui->pushButtonClearInput->setStyleSheet("QPushButton {background-color: #f44336; color: white; border: none; padding: 10px; border-radius: 5px;} QPushButton:hover {background-color: #e53935;}");
    ui->pushButtonClearOutput->setStyleSheet("QPushButton {background-color: #ff9800; color: white; border: none; padding: 10px; border-radius: 5px;} QPushButton:hover {background-color: #fb8c00;}");

    // 设置GroupBox样式
    ui->groupBoxInput->setStyleSheet("QGroupBox {border: 2px solid #009688; border-radius: 5px; margin-top: 10px; font-size: 14px; font-weight: bold;} QGroupBox::title {subcontrol-origin: margin; subcontrol-position: top center; padding: 0 3px;}");
    ui->groupBoxOutput->setStyleSheet("QGroupBox {border: 2px solid #3f51b5; border-radius: 5px; margin-top: 10px; font-size: 14px; font-weight: bold;} QGroupBox::title {subcontrol-origin: margin; subcontrol-position: top center; padding: 0 3px;}");

    // 菜单栏样式
    this->menuBar()->setStyleSheet("QMenuBar {background-color: #f8f8f8; border: 1px solid #e7e7e7; padding: 3px;} QMenuBar::item {background: transparent;} QMenuBar::item:selected {background: #d3d3d3;}");

    // 状态栏样式
    this->statusBar()->setStyleSheet("QStatusBar {background-color: #e0e0e0; font-size: 12px;}");
//----------------------------------界面----------------------------------------------------------




    //-----------------------开始分析按钮----------------------
    connect(ui->pushButtonAnalysis,&QPushButton::clicked,[=](){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        QString text = ui ->textEdit1->toPlainText();

        // 检查输入内容是否为空
        if (text.trimmed().isEmpty()) {
            qDebug() << "输入为空，未进行分析";
            //QMessageBox::information(this, "提示", "输入内容为空，请输入代码后再进行分析！");
            return; // 直接退出，不调用 lexer
        }

        qDebug()<<text;
        lexer(text,ui->tableWidget,this);
    });

    //-----------------------开始分析菜单-----------------------
    connect(ui->actionAnalysis,&QAction::triggered,[=](){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        QString text = ui ->textEdit1->toPlainText();
        // 检查输入内容是否为空
        if (text.trimmed().isEmpty()) {
            qDebug() << "输入为空，未进行分析";
            //QMessageBox::information(this, "提示", "输入内容为空，请输入代码后再进行分析！");
            return; // 直接退出，不调用 lexer
        }
        qDebug()<<text;
        lexer(text,ui->tableWidget,this);
    });

    //------------------------清空输入按钮--------------------------
    connect(ui->pushButtonClearInput,&QPushButton::clicked,[=](){
        ui->textEdit1->clear();
    });

    //-----------------------清空输入菜单-----------------------
    connect(ui->actionClearInput,&QAction::triggered,[=](){
        ui->textEdit1->clear();
    });

    //-----------------------清空输出按钮-------------------------
    connect(ui->pushButtonClearOutput,&QPushButton::clicked,[=](){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    });

    //-----------------------清空输出菜单-----------------------
    connect(ui->actionClearOutput,&QAction::triggered,[=](){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    });

    //-----------------------打开种别码表------------------------
    connect(ui->actionTable, &QAction::triggered, [=]() {
        Tablestype *tableTypeWindow = new Tablestype; // 创建种别码表窗口
        tableTypeWindow->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存
        tableTypeWindow->setWindowModality(Qt::NonModal);    // 非模态窗口
        tableTypeWindow->setWindowTitle("种别码表");         // 设置窗口标题
        tableTypeWindow->show(); // 显示种别码表窗口
    });

    //-----------------------打开作者--------------------------
    connect(ui->actionAuther, &QAction::triggered, [=]() {
        Author *authorWindow = new Author; // 创建窗口
        authorWindow->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存
        authorWindow->setWindowModality(Qt::NonModal);    // 非模态窗口
        authorWindow->setWindowTitle("联系方式");         // 设置窗口标题
        authorWindow->show(); // 显示作者窗口
    });

    //------------------------打开文件------------------------
    connect(ui->actionOpen,&QAction::triggered,[=](){
    QString Path = QFileDialog::getOpenFileName(this,"打开程序文件",QCoreApplication::applicationFilePath(),"*.*");
    QFile file(Path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    QString fileContent = in.readAll();
    ui->textEdit1->setText(fileContent);
    // 读取文件内容
    file.close();  // 关闭文件
    } else {
        //QMessageBox::warning(this, "错误", "无法打开文件");
        // 处理文件打开失败的情况
        qDebug() << "Failed to open file:" << Path;
    }
    });


    //-------------------------保存写入文本--------------------
    connect(ui->actionSave, &QAction::triggered, [=]() {

        QString text = ui ->textEdit1->toPlainText();
        // 检查输入内容是否为空
        if (text.trimmed().isEmpty()) {
            qDebug() << "输入为空，不能进行保存";
            QMessageBox::information(this, "提示", "输入内容为空，请输入代码后再保存！");
            return; // 直接退出
        }
        // 打开文件保存对话框
        QString path = QFileDialog::getSaveFileName(this, "保存写入程序", QCoreApplication::applicationFilePath(), "*.txt");

        // 如果未选择文件路径，直接返回
        if (path.isEmpty()) {
            qDebug() << "No file selected for saving.";
            return;
        }

        QFile file(path);

        // 以写入模式打开文件
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // 从Text Edit组件获取文本并写入文件
            out << ui->textEdit1->toPlainText();

            file.close();
            qDebug() << "File saved successfully at:" << path;
        } else {
            // 处理文件打开失败的情况
            qDebug() << "Failed to open file for writing:" << path;
        }
    });

    //-------------------------保存分析结果--------------------
    connect(ui->actionSaveResult, &QAction::triggered, [=]() {
        // 打开文件保存对话框
        QString path = QFileDialog::getSaveFileName(this, "保存分析结果", QCoreApplication::applicationFilePath(), "*.txt");

        // 如果未选择文件路径，直接返回
        if (path.isEmpty()) {
            qDebug() << "No file selected for saving.";
            return;
        }

        QFile file(path);

        // 以写入模式打开文件
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // 设置每列的固定宽度
            QList<int> columnWidths = {15, 15, 15, 15, 15}; // 每列的宽度，单位为字符
            int columnCount = ui->tableWidget->columnCount();

            // 写入表头
            for (int j = 0; j < columnCount; ++j) {
                QTableWidgetItem* headerItem = ui->tableWidget->horizontalHeaderItem(j);
                QString header = headerItem ? headerItem->text() : "";
                out << header.leftJustified(columnWidths[j], ' ');
            }
            out << "\n";

            // 写入分隔线（可选）
            for (int j = 0; j < columnCount; ++j) {
                out << QString("-").repeated(columnWidths[j]);
            }
            out << "\n";

            // 写入表格内容
            int rowCount = ui->tableWidget->rowCount();
            for (int i = 0; i < rowCount; ++i) {
                for (int j = 0; j < columnCount; ++j) {
                    QTableWidgetItem* item = ui->tableWidget->item(i, j);
                    QString cellText = item ? item->text() : "";
                    out << cellText.leftJustified(columnWidths[j], ' ');
                }
                out << "\n";
            }

            file.close();
            qDebug() << "File saved successfully at:" << path;
        } else {
            // 处理文件打开失败的情况
            qDebug() << "Failed to open file for writing:" << path;
        }
    });





}


MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------键盘事件----------------------
void MainWindow::keyPressEvent(QKeyEvent *k){
    if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_S){
        // Ctrl+S 逻辑：保存文本
        QString text = ui ->textEdit1->toPlainText();
        // 检查输入内容是否为空
        if (text.trimmed().isEmpty()) {
            qDebug() << "输入为空，不能进行保存";
            QMessageBox::information(this, "提示", "输入内容为空，请输入代码后再保存！");
            return; // 直接退出
        }
        // 打开文件保存对话框
        QString path = QFileDialog::getSaveFileName(this, "保存写入程序", QCoreApplication::applicationFilePath(), "*.txt");

        // 如果未选择文件路径，直接返回
        if (path.isEmpty()) {
            qDebug() << "No file selected for saving.";
            return;
        }

        QFile file(path);

        // 以写入模式打开文件
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // 从Text Edit组件获取文本并写入文件
            out << ui->textEdit1->toPlainText();

            file.close();
            qDebug() << "File saved successfully at:" << path;
        } else {
            // 处理文件打开失败的情况
            qDebug() << "Failed to open file for writing:" << path;
        }
    }else if(k->modifiers() == (Qt::ControlModifier | Qt::ShiftModifier) && k->key() == Qt::Key_S){
        // Ctrl+Shift+S 逻辑：保存表格内容
        // 打开文件保存对话框
        QString path = QFileDialog::getSaveFileName(this, "保存分析结果", QCoreApplication::applicationFilePath(), "*.txt");

        // 如果未选择文件路径，直接返回
        if (path.isEmpty()) {
            qDebug() << "No file selected for saving.";
            return;
        }

        QFile file(path);

        // 以写入模式打开文件
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // 设置每列的固定宽度
            QList<int> columnWidths = {15, 15, 15, 15, 15}; // 每列的宽度，单位为字符
            int columnCount = ui->tableWidget->columnCount();

            // 写入表头
            for (int j = 0; j < columnCount; ++j) {
                QTableWidgetItem* headerItem = ui->tableWidget->horizontalHeaderItem(j);
                QString header = headerItem ? headerItem->text() : "";
                out << header.leftJustified(columnWidths[j], ' ');
            }
            out << "\n";

            // 写入分隔线（可选）
            for (int j = 0; j < columnCount; ++j) {
                out << QString("-").repeated(columnWidths[j]);
            }
            out << "\n";

            // 写入表格内容
            int rowCount = ui->tableWidget->rowCount();
            for (int i = 0; i < rowCount; ++i) {
                for (int j = 0; j < columnCount; ++j) {
                    QTableWidgetItem* item = ui->tableWidget->item(i, j);
                    QString cellText = item ? item->text() : "";
                    out << cellText.leftJustified(columnWidths[j], ' ');
                }
                out << "\n";
            }

            file.close();
            qDebug() << "File saved successfully at:" << path;
        } else {
            // 处理文件打开失败的情况
            qDebug() << "Failed to open file for writing:" << path;
        }
    }else if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_O){
        //打开文件行为事件
        QString Path = QFileDialog::getOpenFileName(this,"打开程序文件",QCoreApplication::applicationFilePath(),"*.*");
        QFile file(Path);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            ui->textEdit1->setText(fileContent);

            // 读取文件内容
            file.close();  // 关闭文件
        } else {
            //QMessageBox::warning(this, "错误", "无法打开文件");
            // 处理文件打开失败的情况
            qDebug() << "Failed to open file:" << Path;
        }

    }else if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_1){
        //开始分析
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        QString text = ui ->textEdit1->toPlainText();
        // 检查输入内容是否为空
        if (text.trimmed().isEmpty()) {
            qDebug() << "输入为空，未进行分析";
            //QMessageBox::information(this, "提示", "输入内容为空，请输入代码后再进行分析！");
            return; // 直接退出，不调用 lexer
        }
        qDebug()<<text;
        lexer(text,ui->tableWidget,this);
    }else if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_2){
        //清空输入
        ui->textEdit1->clear();
    }else if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_3){
        //清空输出
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    }

}



