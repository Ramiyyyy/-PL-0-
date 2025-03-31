#ifndef LEXER_H
#define LEXER_H
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <cctype> // 使用标准字符函数，例如 isdigit
#include <QMainWindow>
#include <QtGlobal>
#include <QTableWidget>
#include <QMessageBox>

#define NRW        13     // number of reserved words定义了保留字的数量（11个关键字）
#define MAXNUMLEN  14     // 最大数字长度（14位）
#define NSYM       6     // maximum number of symbols in array ssym and csym符号表的最大长度（8个符号）
#define MAXIDLEN   10     // length of identifiers标识符的最大长度（10个字符）

// 单词符号：关键字，标识符，常数，运算符，界符
QChar ch;         // 用于存储当前读取的字符
int  sym;        // 用于存储当前符号的类别码
int columnum;       //当前单词开头所在列
int linenum;       //当前单词开头所在行



// 对于DFA
enum state {
    START,       // 起始状态，初始状态或空白字符处理后的状态
    INNUM,       // 正在处理数字的状态（如解析整数或浮点数）
    INID,        // 正在处理标识符的状态（以字母开头的字符串）
    INBECOMES,   // 处理可能是赋值运算符 `:=` 的状态，已经读取到冒号 `:`
    BECOMES,     // 确认赋值运算符 `:=` 后的状态
    GTR,         // 处理可能是大于 `>` 或大于等于 `>=` 的状态
    GEQ,         // 确认大于等于 `>=` 后的状态
    NEQ,         // 确认不等于 `<>` 后的状态
    LES,         // 处理可能是小于 `<` 或小于等于 `<=`或不等于`<>` 的状态
    LEQ,         // 确认小于等于 `<=` 后的状态
    END,         // 文件结束或分析完成的状态（未明确使用，保留）
    COMMENT,     // 处理注释的状态（以 `{` 开头的注释，直到 `}` 结束）
    INADD,       // 处理可能是 '+'、'+=' 的状态
    INSUB,       // 处理可能是 '-'、'-=' 的状态
    INC,         // 确定是 '++'
    AAO,         // 确定是 '+='
    DEC,         // 确定是 '--'
    SAO,         // 确定是 '-='
    INMUL,       // 处理可能是 '*'、'*=' 的状态
    INDIV,       // 处理可能是 '/'、'/=' 的状态
    MAO,         // 确定是 '*='
    DAO          // 确定是 '/='
};


int currState = START;



// 类别码
enum symtype {
    SYM_NULL,         // 0: 空类型
    SYM_BEGIN,        // 1: 保留字 'begin'
    SYM_END,          // 2: 保留字 'end'
    SYM_IF,           // 3: 保留字 'if'
    SYM_THEN,         // 4: 保留字 'then'
    SYM_WHILE,        // 5: 保留字 'while'
    SYM_DO,           // 6: 保留字 'do'
    SYM_CALL,         // 7: 保留字 'call'
    SYM_CONST,        // 8: 保留字 'const'
    SYM_VAR,          // 9: 保留字 'var'
    SYM_PROCEDURE,    // 10: 保留字 'procedure'
    SYM_ODD,          // 11: 保留字 'odd'
    SYM_READ,         // 12：保留字 'read'
    SYM_WRITE,        // 13：保留字 'write'

    SYM_IDENTIFIER,   // 14: 标识符
    SYM_NUMBER,       // 15: 数字常量

    SYM_PLUS,         // 16: 加号 '+'
    SYM_MINUS,        // 17: 减号 '-'
    SYM_TIMES,        // 18: 乘号 '*'
    SYM_SLASH,        // 19: 除号 '/'
    SYM_EQU,          // 20: 等号 '='
    SYM_NEQ,          // 21: 不等号 '<>'
    SYM_LES,          // 22: 小于号 '<'
    SYM_LEQ,          // 23: 小于等于号 '<='
    SYM_GTR,          // 24: 大于号 '>'
    SYM_GEQ,          // 25: 大于等于号 '>='
    SYM_BECOMES,      // 26: 赋值符号 ':='
    SYM_INC,          // 27: 自增符号 '++'
    SYM_AAO,          // 28: 加法赋值运算符 '+='
    SYM_DEC,          // 29: 自减符号 '--'
    SYM_SAO,          // 30: 减法赋值运算符 '-='
    SYM_MAO,          // 31: 乘法赋值运算符 '*='
    SYM_DAO,          // 32: 除法赋值运算符 '/='

    SYM_LPAREN,       // 33: 左括号 '('
    SYM_RPAREN,       // 34: 右括号 ')'
    SYM_COMMA,        // 35: 逗号 ','
    SYM_SEMICOLON,    // 36: 分号 ';'
    SYM_PERIOD        // 37: 句号 '.'


};


// 直接符号表
QChar csym[NSYM + 1] = {
    ' ',  '(', ')', '=', ',', '.', ';'
};

// 关键字
const QString word[NRW + 1] = {
    "", /* place holder */
    "begin", "call", "const", "do", "end", "if",
    "odd", "procedure", "then", "var", "while", "read", "write"
};

// 保留字表
int wsym[NRW + 1] = {
    SYM_NULL, SYM_BEGIN, SYM_CALL, SYM_CONST, SYM_DO, SYM_END,
    SYM_IF, SYM_ODD, SYM_PROCEDURE, SYM_THEN, SYM_VAR, SYM_WHILE, SYM_READ, SYM_WRITE
};

// 直接符号种别号表
int ssym[NSYM + 1] = {
    SYM_NULL,
    SYM_LPAREN, SYM_RPAREN, SYM_EQU, SYM_COMMA, SYM_PERIOD, SYM_SEMICOLON
};

// 报错信息
const QString err_msg[] = {
    /*  0 */    "Fatal Error:Unknown character.\n",
    /*  1 */    "Found ':=' when expecting '='.",
    /*  2 */    "There must be a number to follow '='.",
    /*  3 */    "There must be an '=' to follow the identifier.",
    /*  4 */    "There must be an identifier to follow 'const', 'var', or 'procedure'.",
    /*  5 */    "Missing ',' or ';'.",
    /*  6 */    "Incorrect procedure name.",
    /*  7 */    "Statement expected.",
    /*  8 */    "Follow the statement is an incorrect symbol.",
    /*  9 */    "'.' expected.",
    /* 10 */    "';' expected.",
    /* 11 */    "Undeclared identifier.",
    /* 12 */    "Illegal assignment.",
    /* 13 */    "':=' expected.",
    /* 14 */    "There must be an identifier to follow the 'call'.",
    /* 15 */    "A constant or variable can not be called.",
    /* 16 */    "'then' expected.",
    /* 17 */    "';' or 'end' expected.",
    /* 18 */    "'do' expected.",
    /* 19 */    "Incorrect symbol.",
    /* 20 */    "Relative operators expected.",
    /* 21 */    "Procedure identifier can not be in an expression.",
    /* 22 */    "Missing ')'.",
    /* 23 */    "The symbol can not be followed by a factor.",
    /* 24 */    "The symbol can not be as the beginning of an expression.",
    /* 25 */    "The number is too great.",          /* 25 */
    /* 26 */    "The identifier is too long",       /* 26 */
    /* 27 */    "It is forbidden to comment again.",
    /* 28 */    "The identifier cannot start with a number.",
    /* 29 */    "",
    /* 30 */    "",
    /* 31 */    "",
    /* 32 */    "There are too many levels.",
    /* 33 */    "There is no end to the note."      /* 33 */
};

// 获取符号种类的函数
const QString get_token_category(int sym) {
    if (sym >= SYM_BEGIN && sym <= SYM_WRITE) return "关键字";
    if (sym == SYM_IDENTIFIER) return "标识符";
    if (sym == SYM_NUMBER) return "常数";
    if (sym >= SYM_PLUS && sym <= SYM_DAO) return "运算符";
    if (sym >= SYM_LPAREN && sym <= SYM_PERIOD) return "界符";
    return "未知";
}

// 错误处理：带行列号
void error(int n,int line_number,int column_number,QWidget *parent) {
    qDebug() << QString("Error %1 at line %2, column %3: %4")
    .arg(n).arg(line_number).arg(column_number).arg(err_msg[n]);
    QMessageBox::warning(parent, "错误", "错误发生在"+QString::number(line_number)+"行"+QString::number(column_number)+"列，可能是："+err_msg[n]);
}


// 输出符号信息
void print_symbol_info(const QString& value, int sym , QTableWidget *tablewidget ,int line_number,int column_number) {
    QString type = get_token_category(sym);
    /*
     * qDebug() << QString("(原值: %1, 种别码: %2, 种类: %3, 行: %4, 列: %5)")
                    .arg(value).arg(sym).arg(type).arg(line_number).arg(column_number);
    */
    int row1 = tablewidget->rowCount();
    tablewidget->insertRow(row1);

    // 创建每个单元格的项，并设置居中对齐
    QTableWidgetItem* valueItem = new QTableWidgetItem(value);
    valueItem->setTextAlignment(Qt::AlignCenter);
    tablewidget->setItem(row1, 0, valueItem);

    QTableWidgetItem* symItem = new QTableWidgetItem(QString::number(sym));
    symItem->setTextAlignment(Qt::AlignCenter);
    tablewidget->setItem(row1, 1, symItem);

    QTableWidgetItem* typeItem = new QTableWidgetItem(type);
    typeItem->setTextAlignment(Qt::AlignCenter);
    tablewidget->setItem(row1, 2, typeItem);

    QTableWidgetItem* lineItem = new QTableWidgetItem(QString::number(line_number));
    lineItem->setTextAlignment(Qt::AlignCenter);
    tablewidget->setItem(row1, 3, lineItem);

    QTableWidgetItem* columnItem = new QTableWidgetItem(QString::number(column_number));
    columnItem->setTextAlignment(Qt::AlignCenter);
    tablewidget->setItem(row1, 4, columnItem);
}

// Lexer 函数
void lexer(const QString &text , QTableWidget *tablewidget,QWidget *parent) {
    qint64 num = 0;          // 当前识别中的数字
    int k = 0;            // 当前识别中的数字的长度
    QString a;            // 当前识别中的标识符或关键字
    int index = 0;        // 当前字符索引
    int line_number = 1;             // 当前行号
    int column_number = 0;           // 当前列号
    int wnum = 0;           //分析的单词数

    while (index < text.length()) {
        ch = text.at(index); // 获取当前字符
        column_number++;

        switch (currState) {
        case START:{
            if (ch.isSpace()) {
                column_number--;
                if (ch == '\n') {
                    line_number++;
                    column_number = 0;
                }
            }
            else if (ch == '{') {
                columnum = column_number;
                linenum = line_number;
                currState = COMMENT;
            }
            else if (ch.isDigit()) {
                currState = INNUM;
                num = num * 10 + ch.digitValue();
                k++;
            }
            else if (ch.isLetter()||ch == '_') {
                currState = INID;
                a.append(ch);
            }
            else if (ch == ':') {
                currState = INBECOMES;
            }
            else if (ch == '>') {
                currState = GTR;
            }
            else if (ch == '<') {
                currState = LES;
            }else if(ch == '+'){
                currState = INADD;
            }else if(ch == '-'){
                currState = INSUB;
            }else if(ch == '*'){
                currState = INMUL;
            }else if(ch == '/'){
                currState = INDIV;
            }
            else { // 单独字符直接识别
                currState = START;
                int i = 0;
                for (; i <= NSYM; i++) {
                    if (ch == csym[i])
                        break;
                }
                if (i <= NSYM) {
                    sym = ssym[i];
                    wnum++;
                    print_symbol_info(QString(ch), sym, tablewidget , line_number,column_number);
                } else {
                    error(0,line_number,column_number,parent);
                    currState = START;
                    return;
                }
            }
            break;
        }
        case INNUM:{
            if (ch.isDigit()) {
                if (k >= MAXNUMLEN) {
                    error(25,line_number,column_number,parent);
                    currState = START;
                    return;
                }
                num = num * 10 + ch.digitValue();
                k++;
            }else if(ch.isLetter()||ch == '_'){
                error(28,line_number,column_number,parent);
                currState = START;
                return;
            }else {
                currState = START;
                index--; // 回退一个字符
                column_number--;
                sym = SYM_NUMBER;
                wnum++;
                print_symbol_info(QString::number(num), sym ,tablewidget,line_number,column_number);
                k = 0;
                num = 0;
            }
            break;
        }
        case COMMENT:{
            if (ch == '}') {
                currState = START;
                columnum = 0;
                linenum = 0;
            }else if(ch == '{'){
                error(27,line_number,column_number,parent);
                currState = START;
                return;
            }else if (ch.isSpace()) {
                column_number--;
                if (ch == '\n') {
                    line_number++;
                    column_number = 0;
                }
            }
            break;
        }
        case INID:{
            if (ch.isLetterOrNumber()||ch == '_') {
                if (a.length() >= MAXIDLEN) {
                    error(26,line_number,column_number,parent);
                    currState = START;
                    return;
                }
                a.append(ch);
            } else {
                currState = START;
                index--; // 回退一个字符
                column_number--;
                int i = 1;
                for (; i <= NRW; i++) {
                    if (a == word[i])
                        break;
                }
                if (i <= NRW) {
                    sym = wsym[i];
                } else {
                    sym = SYM_IDENTIFIER;
                }
                wnum++;
                print_symbol_info(a, sym,tablewidget, line_number,column_number);
                a.clear();
            }
            break;
        }
        case INBECOMES:{
            if (ch == '=') {
                currState = BECOMES;
            } else {
                index--; // 回退一个字符
                column_number--;
                sym = SYM_NULL;
                error(13,line_number,column_number,parent);
                currState = START;
                return;
            }
            break;
        }
        case BECOMES:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_BECOMES;
            wnum++;
            print_symbol_info(":=", sym,tablewidget, line_number,column_number);
            break;
        }
        case GTR:{
            if (ch == '=') {
                currState = GEQ;
            } else {
                currState = START;
                index--; // 回退一个字符
                column_number--;
                sym = SYM_GTR;
                wnum++;
                print_symbol_info(">", sym,tablewidget, line_number,column_number);
            }
            break;
        }
        case LES:{
            if (ch == '=') {
                currState = LEQ;
            } else if (ch == '>') {
                currState = NEQ;
            } else {
                currState = START;
                index--; // 回退一个字符
                column_number--;
                sym = SYM_LES;
                wnum++;
                print_symbol_info("<", sym,tablewidget, line_number,column_number);
            }
            break;
        }
        case GEQ:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_GEQ;
            wnum++;
            print_symbol_info(">=", sym,tablewidget, line_number,column_number);
            break;
        }
        case LEQ:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_LEQ;
            wnum++;
            print_symbol_info("<=", sym,tablewidget, line_number,column_number);
            break;
        }
        case NEQ:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_NEQ;
            wnum++;
            print_symbol_info("<>", sym,tablewidget,line_number,column_number);
            break;
        }
        case INADD:{
            if(ch == '='){
                currState = AAO;
            }else if(ch == '+'){
                currState = INC;
            }else{
                currState = START;
                index--; // 回退该字符
                column_number--;     // 修正列号
                sym = SYM_PLUS;
                wnum++;
                print_symbol_info("+", sym,tablewidget,line_number,column_number);
            }
            break;
        }
        case INC:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_INC;
            wnum++;
            print_symbol_info("++", sym,tablewidget,line_number,column_number);
            break;
        }
        case AAO:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_AAO;
            wnum++;
            print_symbol_info("+=", sym,tablewidget,line_number,column_number);
            break;
        }
        case INSUB:{
            if(ch == '='){
                currState = SAO;
            }else if(ch == '-'){
                currState = DEC;
            }else{
                currState = START;
                index--; // 回退该字符
                column_number--;     // 修正列号
                sym = SYM_MINUS;
                wnum++;
                print_symbol_info("-", sym,tablewidget,line_number,column_number);
            }
            break;
        }
        case DEC:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_DEC;
            wnum++;
            print_symbol_info("--", sym,tablewidget,line_number,column_number);
            break;
        }
        case SAO:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_SAO;
            wnum++;
            print_symbol_info("-=", sym,tablewidget,line_number,column_number);
            break;
        }
        case INMUL:{
            if(ch == '='){
                currState = MAO;
            }else{
                currState = START;
                index--; // 回退该字符
                column_number--;     // 修正列号
                sym = SYM_TIMES;
                wnum++;
                print_symbol_info("*", sym,tablewidget,line_number,column_number);
            }
            break;
        }
        case MAO:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_MAO;
            wnum++;
            print_symbol_info("*=", sym,tablewidget,line_number,column_number);
            break;
        }
        case INDIV:{
            if(ch == '='){
                currState = DAO;
            }else{
                currState = START;
                index--; // 回退该字符
                column_number--;     // 修正列号
                sym = SYM_SLASH;
                wnum++;
                print_symbol_info("/", sym,tablewidget,line_number,column_number);
            }
            break;
        }
        case DAO:{
            currState = START;
            index--; // 回退该字符
            column_number--;     // 修正列号
            sym = SYM_DAO;
            wnum++;
            print_symbol_info("/=", sym,tablewidget,line_number,column_number);
            break;
        }

            // 添加其他状态...
        }

        index++; // 移向下一个字符
    }

    // 文件结束时检查未处理的符号内容
    if (currState == INNUM) {
        sym = SYM_NUMBER;
        if (k > MAXNUMLEN) {
            error(25,line_number,column_number,parent);
            currState = START;
            return;
        } else {
            wnum++;
            print_symbol_info(QString::number(num), sym,tablewidget, line_number,column_number);
        }
    } else if (currState == INID) {
        int i = 1;
        for (; i <= NRW; i++) {
            if (a == word[i])
                break;
        }
        if (i <= NRW) {
            sym = wsym[i];
        } else {
            sym = SYM_IDENTIFIER;
        }
        wnum++;
        print_symbol_info(a, sym,tablewidget, line_number,column_number);
        a.clear();
    } else if (currState == INBECOMES) {
        sym = SYM_NULL;
        error(1,line_number,column_number,parent);
        currState = START;
        return;
    }else if(currState == BECOMES){
        sym = SYM_BECOMES;
        wnum++;
        print_symbol_info(":=", sym,tablewidget, line_number,column_number);
    }else if (currState == GTR) {
        sym = SYM_GTR;
        wnum++;
        print_symbol_info(">", sym,tablewidget, line_number,column_number);
    } else if (currState == LES) {
        sym = SYM_LES;
        wnum++;
        print_symbol_info("<", sym,tablewidget, line_number,column_number);
    }else if (currState == COMMENT){
        error(33,linenum,columnum,parent);
        currState = START;
        return;
    }else if (currState == GEQ){
        sym = SYM_GEQ;
        wnum++;
        print_symbol_info(">=", sym,tablewidget, line_number,column_number);
    }else if (currState == LEQ){
        sym = SYM_LEQ;
        wnum++;
        print_symbol_info("<=", sym,tablewidget, line_number,column_number);
    }else if (currState == NEQ){
        sym = SYM_NEQ;
        wnum++;
        print_symbol_info("<>", sym,tablewidget, line_number,column_number);
    }else if (currState == INADD){
        sym = SYM_PLUS;
        wnum++;
        print_symbol_info("+", sym,tablewidget, line_number,column_number);
    }else if (currState == INSUB){
        sym = SYM_MINUS;
        wnum++;
        print_symbol_info("-", sym,tablewidget, line_number,column_number);
    }else if (currState == INC){
        sym = SYM_INC;
        wnum++;
        print_symbol_info("++", sym,tablewidget, line_number,column_number);
    }else if (currState == DEC){
        sym = SYM_DEC;
        wnum++;
        print_symbol_info("--", sym,tablewidget, line_number,column_number);
    }else if (currState == AAO){
        sym = SYM_AAO;
        wnum++;
        print_symbol_info("+=", sym,tablewidget, line_number,column_number);
    }else if (currState == SAO){
        sym = SYM_SAO;
        wnum++;
        print_symbol_info("-=", sym,tablewidget, line_number,column_number);
    }else if (currState == INMUL){
        sym = SYM_TIMES;
        wnum++;
        print_symbol_info("*", sym,tablewidget, line_number,column_number);
    }else if (currState == INDIV){
        sym = SYM_SLASH;
        wnum++;
        print_symbol_info("/", sym,tablewidget, line_number,column_number);
    }else if (currState == MAO){
        sym = SYM_MAO;
        wnum++;
        print_symbol_info("*=", sym,tablewidget, line_number,column_number);
    }else if (currState == DAO){
        sym = SYM_DAO;
        wnum++;
        print_symbol_info("/=", sym,tablewidget, line_number,column_number);
    }
    //重置
    currState = START;

    qDebug() << "总单词数" <<wnum;

    // 插入最后一行
    int lastRow = tablewidget->rowCount();
    tablewidget->insertRow(lastRow);
    // 创建单元格项
    QTableWidgetItem* totalItem = new QTableWidgetItem(QString("分析完毕！共计：(%1)个单词").arg(wnum));
    // 设置整行内容居中
    totalItem->setTextAlignment(Qt::AlignCenter);
    // 跨越所有列
    tablewidget->setSpan(lastRow, 0, 1, tablewidget->columnCount());
    // 添加到表格
    tablewidget->setItem(lastRow, 0, totalItem);

    qDebug() << "END";
}

#endif // LEXER_H
