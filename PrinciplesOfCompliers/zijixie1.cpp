//
// Created by Anthony Wong on 2023/3/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;

int wrongt=0;
int Beginsign=0;
int Whilesign=0;
int havevarjudge=0;
int sign=0;
int wrongi=0;
int start=0;
int truewrongi=0;
int truewrongt=0;
vector<string> global_vars;

bool findSubstring(const std::vector<std::string>& vec, const std::string& substr) {
    return std::find(vec.begin(), vec.end(), substr) != vec.end();
}

std::string trim(const std::string& str) {
    if (str.empty()) {
        return str;
    }

    std::size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) {
        return "";
    }

    std::size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

bool is_valid_variable(string variable) {
    int colon_pos = variable.find(":");
    if (colon_pos == string::npos) {
        return false;
    }
    string var_type = variable.substr(colon_pos+1);
    string var_name = variable.substr(0, colon_pos);
    var_name.erase(remove_if(var_name.begin(), var_name.end(), ::isspace), var_name.end());
    if (var_name.empty() || (!isalpha(var_name[0])&& !isnumber(var_name[0]))) {
        return false;
    }
    /*
    for (char c : var_name) {
        if (!isalnum(c) && c != ',') {
            return false;
        }
    }*/
    return true;
}

void A(string str) {
    if (str.empty())
        return;
    string temp=str;
    if (str.back() != ';') {
        cout << "定义语句格式错误: ";
        wrongi++;
        str=temp;
        cout << str << endl;
        return;
    }
    str = str.substr(0, str.size()-1); // remove the trailing semicolon
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    size_t start_pos = 0;
    while (start_pos < str.size()) {
        size_t end_pos = str.find(";", start_pos);
        if (end_pos == string::npos)
            end_pos = str.size();
        string variable = str.substr(start_pos, end_pos - start_pos);
        sign=1;
        if (sign == 0 && !variable.empty() && variable.substr(0, 3) != "var") {
            cout << "定义语句格式错误: " ;
            wrongi++;
            str=temp;
            cout << str << endl;
            return;
        }
        if (sign == 0)
            variable = variable.substr(3); // remove the leading "var"
        if (!is_valid_variable(variable)) {
            cout << "定义语句格式错误: ";
            wrongi++;
            str=temp;
            cout << str << endl;
            return;
        }
        start_pos = end_pos + 1;
    }
    sign = 1;
    str=temp;
}

void B(string s) {
    if (s.find("var") == 0) { // 判断字符串是否以"var"开头
        if (s.find("var ") != 0) { // 判断"var"后是否有空格
            cout << "定义格式错误，var后无空格：" << s << endl;
            wrongi++; // 发现错误，将全局变量wrongi置为1
        }
    }
}

void C(string str) {
    int pos = str.find("var ");
    if (pos == 0)
        pos+=4;
    else
        pos+=1;
    int endPos = str.find(";", pos); // 找到分号的位置
    if (endPos == -1) {
        return; // 没有分号，直接返回
    }
    // 从 "var " 后面的第一个空格开始，检测是否有非法空格
    for (int i = pos + 1; i < endPos; i++) {
        if (str[i] == ' ') {
            cout << "定义格式错误，出现非法空格：" << str << endl;
            wrongi++;
            return;
        }
    }
}

void D(string s) {
    int len = s.length();
    bool isVar = false;  // 是否以var开头
    bool hasType = false;  // 是否已经找到类型
    string type;  // 变量类型
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            if (!hasType) {
                // 变量名称格式错误，首字符不应是数字
                if (i + 1 < len && isdigit(s[i + 1])) {
                    cout << "变量名称格式错误，首字符不应是数字：" << s << endl;
                    wrongi++;
                    return;
                }
            }
        }  if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != ',' && s[i] != ';' && s[i] != ':' && s[i] != ' ') {
            // 含有非法字符
            cout << "含有非法字符：" << s << endl;
            wrongi++;
            return;
        } }
            if (!hasType) {
                // 搜索类型
                int j =0;
                while (j < len && s[j] != ':') {
                    j++;
                }
                int k = j + 1;
                while (k < len && s[k] != ';') {
                    k++;
                }
                type = s.substr(j + 1, k - j - 1);
                if (type != "integer" && type != "bool" && type != "longint") {
                    // 非法数据类型
                    cout << "非法数据类型：" << type << endl;
                    wrongi++;
                    return;
                }
        }
}





void E(string str) {
    //global_vars.clear();

    // Find "var" at the beginning of the string
    size_t start_pos = str.find("var");
    if (start_pos == string::npos) {
        // "var" not found
        return;
    }
    start_pos += 4;

    // Find the position of the first colon
    size_t colon_pos = str.find(":");
    if (colon_pos == string::npos) {
        // No colon found
        return;
    }

    // Find the position of the first comma
    size_t comma_pos = str.find(",", start_pos);
    if (comma_pos == string::npos || comma_pos > colon_pos) {
        // No comma found, or comma is after colon
        // Get the string before the colon
        size_t var_name_pos = str.find_first_not_of(" ", start_pos);
        string var_name = str.substr(var_name_pos, colon_pos - var_name_pos);
        if (!findSubstring(global_vars, var_name))
            global_vars.push_back(var_name);
        else {
            cout << "不支持变量重定义！重定义的变量初始化失败: " << var_name << endl;
            wrongi++;
        }
    } else {
        // Comma found before colon
        // Get the string before the first comma
        size_t var_name_pos = str.find_first_not_of(" ", start_pos);
        string var_name1 = str.substr(var_name_pos, comma_pos - var_name_pos);
        if (!findSubstring(global_vars, var_name1))
            global_vars.push_back(var_name1);
        else {
            cout << "不支持变量重定义！重定义的变量初始化失败: " << var_name1 << endl;
            wrongi++;
        }
        // Get the string after the first comma and before the colon
        var_name_pos = str.find_first_not_of(" ", comma_pos + 1);
        string var_name2 = str.substr(var_name_pos, colon_pos - var_name_pos);
        if (!findSubstring(global_vars, var_name2))
            global_vars.push_back(var_name2);
        else {
            cout << "不支持变量重定义！重定义的变量初始化失败: " << var_name2 << endl;
            wrongi++;
        }
    }

    // Check if there is a second colon
    size_t second_colon_pos = str.find(":", colon_pos + 1);
    if (second_colon_pos != string::npos) {
        // Get the string after the first semicolon and before the second colon
        size_t  fenhao_pos =str.find(";",colon_pos);
        size_t var_name_pos = str.find_first_not_of(" ", fenhao_pos + 1);
        string var_name3 = str.substr(var_name_pos, second_colon_pos - fenhao_pos-1);
        if (!findSubstring(global_vars, var_name3))
            global_vars.push_back(var_name3);
        else {
            cout << "不支持变量重定义！重定义的变量初始化失败: " << var_name3 << endl;
            wrongi++;
        }
    }
}

int H(string line) {
    string firstTwoChars = "";
    string firstFiveChars = "";
    string firstFourChars = "";
    // 找到第一个非空格非制表符的字符
    int i = 0;
    while (i < line.length() && (line[i] == ' ' || line[i] == '\t')) {
        i++;
    }
    // 获取第一个非空格非制表符的两个字符或五个字符
    if (i + 1 < line.length()) {
        firstTwoChars = line.substr(i, 2);
    }
    if (i + 4 < line.length()) {
        firstFiveChars = line.substr(i, 5);
    }
    if (i + 3 < line.length()) {
        firstFourChars = line.substr(i, 4);
    }
    // 检查是否为if或while
    if (firstTwoChars == "if") {
        return 1;
    }
    else if (firstFiveChars == "while") {
        return 2;
    }
    else if(firstFiveChars == "begin")
        return 3;
    else if(firstFourChars == "end;")
        return 3;
    else {
        return 0;
    }
}

void I(string str) {
    int index = str.find(":=");
    if (index == string::npos || index == 0 || index == str.length() - 2 || str[index + 2] == ';') {
        cout << "赋值语句格式错误，无效赋值：" << str << endl;
        wrongt++;
    }
    int len = str.length();
    if (str[len - 1] != ';') {
        cout << "赋值语句格式错误，无分号，无效赋值：" << str << endl;
        wrongt++;
        return;
    }
}

void J(string s) {
    // 去掉空格
    int start = s.find_first_not_of(" \t");
    int end = s.find_last_not_of(" \t");
    s = s.substr(start, end - start + 1);

    // 判断if语句格式是否正确
    if (s.find("if") != 0) {
        cout << "if语句格式错误: " << s << endl;
        wrongt++;
        return;
    }
    int len = s.length();
    if (s[len - 4] != 't' || s[len - 1] != 'n' || s[len - 2] != 'e' || s[len - 3] != 'h') {
        cout << "if语句格式错误: " << s << endl;
        wrongt++;
        return;
    }
    stack<char> st;
    for (int i = 2; i < len - 4; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << "括号格式错误: " << s << endl;
                wrongt++;
                return;
            }
            st.pop();
        }
    }
    if (!st.empty()) {
        cout << "if语句格式错误: " << s << endl;
        wrongt++;
        return;
    }
}

void K(std::string str) {
    string temp=str;
    // 移除字符串前后的空格
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);

    // 检查while语句格式是否正确
    if (str.find("while(") == std::string::npos || str.find(")do") == std::string::npos) {
        std::cout << "while语句格式错误: " << str << std::endl;
        wrongt++;
        str=temp;
        return;
    }

    // 获取条件表达式
    std::string condition_str = str.substr(str.find("(") + 1, str.find(")") - str.find("(") - 1);
    // 如果存在and或or，则检查第二个条件表达式的格式是否正确
    if (condition_str.find("and") != std::string::npos || condition_str.find("or") != std::string::npos) {
        // 获取第二个条件表达式
        std::string second_condition_str = condition_str.substr(condition_str.find("and") + 4);
        if (second_condition_str.empty()) {
            second_condition_str = condition_str.substr(condition_str.find("or") + 3);
        }
        second_condition_str.erase(0, second_condition_str.find_first_not_of(" "));
        second_condition_str.erase(second_condition_str.find_last_not_of(" ") + 1);

        // 检查第二个条件表达式的格式是否正确
        if (second_condition_str.empty()) {
            std::cout << "条件表达式语句为空: " << str << std::endl;
            wrongt++;
            str=temp;
            return;
        }
    }

    // 检查条件表达式的格式是否正确
    condition_str.erase(0, condition_str.find_first_not_of(" "));
    condition_str.erase(condition_str.find_last_not_of(" ") + 1);
    if (condition_str.empty()) {
        std::cout << "条件表达式语句为空: " << str << std::endl;
        wrongt++;
        str=temp;
        return;
    }
    str=temp;
    Whilesign = 1;
}

void M(string str) {
    size_t pos1 = str.find(":=");
    size_t pos2 = str.find(";");
    string var1 = str.substr(0, pos1);
    string var2 = str.substr(pos1 + 2, pos2 - pos1 - 2);
    string var3 = str.substr(pos2 + 1);
    var1.erase(0, var1.find_first_not_of(" "));
    var1.erase(var1.find_last_not_of(" ") + 1);
    var2.erase(0, var2.find_first_not_of(" "));
    var2.erase(var2.find_last_not_of(" ") + 1);
    var3.erase(0, var3.find_first_not_of(" "));
    var3.erase(var3.find_last_not_of(" ") + 1);
    if (find(global_vars.begin(), global_vars.end(), var1) == global_vars.end()) {
        cout << "赋值失败，存在未定义变量：" << var1 << endl;
        wrongt++;
        return;
    }
    for (int i = 0; i < var2.size(); i++) {
        if (!isalnum(var2[i])) {
            var2 = var2.substr(0, i);
            break;
        }
    }
    if(!isnumber(var2[0])){
    if (find(global_vars.begin(), global_vars.end(), var2) == global_vars.end()) {
        cout << "赋值失败，存在未定义变量：" << var2 << endl;
        wrongt++;
        return;
    }}
    for (int i = 0; i < var3.size(); i++) {
        if (!isalnum(var3[i])) {
            var3 = var3.substr(0, i);
            break;
        }
    }
    if(var3!=""){
    if (find(global_vars.begin(), global_vars.end(), var3) == global_vars.end()) {
        cout << "赋值失败，存在未定义变量：" << var3 << endl;
        wrongt++;
        return;
    }}
}

void Z(string line) {
    // 在这里实现C函数的代码
    cout << "All lines have been processed." << endl;
}

int main() {
    cout<<"如果无实现体，请在结尾加DNE"<<endl;
    cout<<"粘贴代码段："<<endl;
    string line;
    vector<string> lines;

    while (getline(cin, line)) {
        // 将输入转换为小写字母，以便进行大小写不敏感的比较
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line=="dne"){
            if(start==0)
                cout<<"未检测到实现体代码"<<endl;
            return 0;
        }
        // 如果用户输入 "begin"，则跳出当前循环，进入下一个循环
        if (line == "begin") {
            if(havevarjudge==0)
                cout<<"错误！无定义体！"<<endl;
            break;
        }

        // 如果当前行不是 "begin"，则执行 A 和 B 函数
        A(line);
        havevarjudge=1;
        if(wrongi==0)
            B(line);
        if(wrongi==0)
            C(line);
        if(wrongi==0)
            D(line);
        if(wrongi==0)
            E(line);
/*
        for (auto var : global_vars) {
            cout << var << " ";
        }
        cout<<endl;*/
        truewrongi+=wrongi;
        wrongi=0;
    }

    // 如果用户输入了 "begin"，则执行 C 和 D 函数
    if (line == "begin") {
        start=1;
        while (getline(cin, line)) {
            // 将输入转换为小写字母，以便进行大小写不敏感的比较
            transform(line.begin(), line.end(), line.begin(), ::tolower);

            // 如果用户输入了 "end"，则退出循环
            if (line == "dne"||line=="end") {
                break;
            }
            if(Whilesign==1) {
                if (line != "begin") {
                    cout << "while语句范围错误: " << line << endl;
                    truewrongt++;
                } else if (line == "begin") {
                    Whilesign = 0;
                    Beginsign++;
                }
            }
            else if(Whilesign==0&&line=="begin") {
                cout << "未知的begin: begin" << endl;
                truewrongt++;
            }
            else if(line=="end;") {
                if (Beginsign > 0)
                    Beginsign--;
                else if (Beginsign == 0){
                    cout << "未知的end：end;" << endl;
                    truewrongt++;
                }
            }
            else {
                // 否则执行 C 和 D 函数
                if (H(line) == 0){
                    I(line);
                    M(line);}
                else if (H(line) == 1)
                    J(line);
                else
                    K(line);
            }
            truewrongt+=wrongt;
            wrongt=0;
        }
    }
    if(start==0)
        cout<<"未检测到实现体代码"<<endl;
    if(truewrongi+truewrongt==0)
        cout<<"未发现错误！"<<endl;
    else
        cout<<"共"<<truewrongi+truewrongt<<"处错误，其中定义体："<<truewrongi<<"处, 实现体："<<truewrongt<<"处。"<<endl;
    Z(line);
    return 0;
}