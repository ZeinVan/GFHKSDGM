//
// Created by Anthony Wong on 2023/5/5.
//
#include "LA.h"
using namespace std;

fstream laSource;
fstream laOutput;

const string key[21] = {"program", "const", "var", "procedure", "begin", "if", "end", "while", "call", "read", "write", "then", "odd", "do","integer","longint","bool","short","and","or","int"};

int linenum;
int column;

/**
 * Verify whether is blank char, 1 is BC, 0 is not.
 * @param ch char
 * @author TripleZ
 */
int isBC(char ch){
    if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'){
        switch (ch) {
            case ' ':
                column++;
                break;
            case '\t':
                column+=4; // A tab = 4 spaces
                break;
            case '\r':
            case '\n':
                linenum++;
                column = 1;
                break;
        }
        return 1;
    } else {
        return 0;
    }
}

/**
 * Add a character to strToken.
 * @param a strToken
 * @param ch add charater
 * @return new strToken string
 */
string Concat(string a, char ch) {
    a.push_back(ch);
    return a;
}

/**
 * Check a character whether is a digit.
 * @param ch A character
 * @return 1 is true, 0 is false.
 */
int isDigit(char ch) {
    if (ch >= '0' && ch <= '9'){
        return 1;
    } else {
        return 0;
    }
}

/**
 * Check a character whether is a letter.
 * @param ch A character
 * @return 1 is true, 0 is false.
 */
int isLetter(char ch){
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return 1;
    } else {
        return 0;
    }
}
int varsign=0;
/**
 * Check strToken whether is a reserved word.
 * @param strToken search-forward string.
 * @return 1 is reserved, 0 is not.
 */
int Reserve(string strToken) {
    int i;
    for(i = 0; i< 21; i++) {
        if(strToken.compare(key[i]) == 0&&key[i]=="var"){
            varsign=1;
            return 1;
        }
        if(strToken.compare(key[i]) == 0&&(key[i]=="program"||key[i]=="procedure"||key[i]=="begin")){
            varsign=0;
            return 1;
        }
        else if (strToken.compare(key[i]) == 0) {
            return 1;// is reserved;
        }
    }
    return 0;
}


/**
 * Move the cursor back a character.
 */
void Retract(){
    if (!laSource.eof()){
        laSource.seekg(-1, ios::cur);
    }
}

/**
 * Main function.
 * @return 0
 */
int LA() {

    string inputFileName;

    cout << "Enter the program file name: ";
    cin >> inputFileName;
    cout << endl;
    cout << "Write Something about LA?" << endl;
int thinking=1;
int powersign=0;
    int plussign=0;
    int downsign=0;
    int dividesign=0;
int multisign=0;
while(thinking) {
    string writing;
    cin>>writing;
    if(writing=="No"||writing=="no"){
        thinking=0;
        cout<<"Okay"<<endl;
    }else if(writing=="OOP"){
        cin>>writing;
        if(writing=="**"){
            powersign=1;
            cout<<"Received,and anything else?"<<endl;
        }
    }else if(writing=="AOP"){
        cin>>writing;
        if(writing=="*="){
            multisign=1;
            cout<<"Received,and anything else?"<<endl;
        }else if(writing=="+="){
            plussign=1;
            cout<<"Received,and anything else?"<<endl;
        }else if(writing=="-="){
            downsign=1;
            cout<<"Received,and anything else?"<<endl;
        }else if(writing=="/="){
            dividesign=1;
            cout<<"Received,and anything else?"<<endl;
        }
    }else{
        cout<<"Invalid Request, Enter No to skip."<<endl;
    }

}

    laSource.open(inputFileName, ios::in); // Read file
    laOutput.open("la_output", ios::out | ios::trunc); // Write file
    linenum = 1;
    column = 1;

    if (!laSource.is_open()) {
        cout << "Cannot open the laSource file!\a" << endl;
        exit(1);
    }
    if (!laOutput.is_open()) {
        cout << "Cannot open the laOutput file!\a" << endl;
    } else {
        // Header of the file (DateTime & File name & Lang set)

        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);

        laOutput << "# Lexical Analysis Result" << endl;
        laOutput << "# Generate Time: " << asctime(timeinfo);
        laOutput << "# Program File Name: " << inputFileName << endl;
        laOutput << "# Language Set: PL/0" << endl;
        laOutput << endl;
    }

    string strToken;
    char ch;
    while (!laSource.eof())
    {
        ch = laSource.get();

        if (isBC(ch)){ // Blank character check
            strToken = "";
        } else if (isLetter(ch)){ // Letter check

            while (isLetter(ch) || isDigit(ch)){ // ID check loop
                strToken = Concat(strToken, ch);
                column++;
                ch = laSource.get();
            }


            if (Reserve(strToken)){ // Reserved word check
//                cout << strToken << ", RESERVED" << endl;
                laOutput << strToken << " RESERVED" << " " << linenum << " " << column << endl;
            }
            else{
//                cout << strToken << ", ID" << endl;
                laOutput << strToken << " ID" << " " << linenum << " " << column << endl;
            }
            strToken = "";

            Retract();

        } else if (isDigit(ch)){ // Digit check
            while (isDigit(ch)) {
                strToken = Concat(strToken, ch);
                column++;
                ch = laSource.get();
            }

            if (isLetter(ch)) {
                cout << "[Lexical ERROR] " << " [" << linenum << "," << column <<"] " << "Invalid ID: " ;

                while (isLetter(ch) || isDigit(ch)){
                    strToken = Concat(strToken, ch);
                    column++;
                    ch = laSource.get();
                }

                cout << "\"" << strToken << "\"" << endl;
                laOutput << "^ " << strToken << " ID " << linenum << " " << column << endl;
                laOutput << "[Lexical ERROR] " << " [" << linenum << "," << column <<"] " << "Invalid ID: " ;
                laOutput << "\"" << strToken << "\"" << endl;

            } else {
//                cout << strToken << ", INT" << endl;
                laOutput << strToken << " INT" << " " << linenum << " " << column << endl;
            }

            Retract();
            strToken = "";

        } else {
            switch(ch) { // Other characters check
                case '=':
                    column++;
//					cout << ch << ", COP" << endl;
                    laOutput << ch << " COP" << " " << linenum << " " << column << endl;
                    break;
                case '<':
                    column++;
                    ch = laSource.get();
                    if (ch == '>') {
                        column++;
//						cout << "<>, COP" << endl;
                        laOutput << "<> COP" << " " << linenum << " " << column << endl;
                    } else if (ch == '='){
                        column++;
//						cout << "<=, COP" << endl;
                        laOutput << "<= COP" << " " << linenum << " " << column << endl;
                    } else {
//						cout << "<, COP" << endl;
                        laOutput << "< COP" << " " << linenum << " " << column << endl;
                        Retract();
                    }
                    break;
                case '>':
                    column++;
                    ch = laSource.get();
                    if (ch == '=') {
                        column++;
//						cout << ">=, COP" << endl;
                        laOutput << ">= COP" << " " << linenum << " " << column << endl;
                    } else {
//						cout << ">, COP" << endl;
                        laOutput << "> COP" << " " << linenum << " " << column << endl;
                        Retract();
                    }
                    break;
                case ':':
                    column++;
                    if(varsign==0)
                        ch = laSource.get();
                    if(varsign==1){
                        //column++;
//						cout << ":, AOP" << endl;
                        laOutput << ": AOP" << " " << linenum << " " << column << endl;
                        break;
                    }
                    else{
                    if (ch == '=') {
                        column++;
//						cout << ":=, AOP" << endl;
                        laOutput << ":= AOP" << " " << linenum << " " << column << endl;
                    } else {
                        cout << "[Lexical ERROR] " << " [" << linenum << "," << column <<"] " << "Missing \"=\" near the \":\"" << endl;
                        laOutput << "^ := AOP " << linenum << " " << column << endl;
                        laOutput << "[Lexical ERROR] " << " [" << linenum << "," << column <<"] " << "Missing \"=\" near the \":\"" << endl;
                        Retract();
                    }
                    break;}
                case '+':
                    column++;
                    //if(plussign==1)
                    ch = laSource.get();
                    if (ch == '='&&plussign==1) {
                        column++;
                        laOutput << "+= AOP" << " " << linenum << " " << column << endl;
                    } else {
                        laOutput << "+ COP" << " " << linenum << " " << column << endl;
                        Retract();
                    }
                    //laOutput << ch << " OOP" << " " << linenum << " " << column << endl;
                    break;
                case '-':
                    column++;
                    //if(minussign==1)
                    ch = laSource.get();
                    if (ch == '='&&downsign==1) {
                        column++;
                        laOutput << "-= AOP" << " " << linenum << " " << column << endl;
                    } else {
                        laOutput << "- COP" << " " << linenum << " " << column << endl;
                        Retract();
                    }
                    //laOutput << ch << " OOP" << " " << linenum << " " << column << endl;
                    break;
                case '/':
                    column++;
                    ch = laSource.get();
                    if (ch == '='&&dividesign==1) {
                        column++;
                        laOutput << "/= AOP" << " " << linenum << " " << column << endl;
                    } else {
                        laOutput << "/ COP" << " " << linenum << " " << column << endl;
                        Retract();
                    }
//					cout << ch << ", OOP" << endl;
                    //laOutput << ch << " OOP" << " " << linenum << " " << column << endl;
                    break;
                case'*':
                    column++;
                    if (powersign==1||multisign==1)
                    ch = laSource.get();
                    if (powersign==1&&ch == '*') {
                        column++;
                        laOutput << "** OOP" << " " << linenum << " " << column << endl;
                    } else if(multisign==1&&ch=='='){
                        column++;
                        laOutput << "*= AOP" << " " << linenum << " " << column << endl;
                    }else {
//						cout << ">, COP" << endl;
                        laOutput << "* OOP" << " " << linenum << " " << column << endl;
                        if(powersign==1)
                        Retract();
                    }
                    break;
                case ';':
                    column++;
//					cout << ch << ", EOP" << endl;
                    laOutput << ch << " EOP" << " " << linenum << " " << column << endl;
                    break;
                case '(':
                case ')':
                case ',':
                    column++;
//                    cout << ch << ", SOP" << endl;
                    laOutput << ch << " SOP" << " " << linenum << " " << column << endl;
                    break;
                default:
                    column++;
//					cout << ch << ", UNKNOWN" << endl;
                    laOutput << ch << " UNKNOWN" << " " << linenum << " " << column << endl;
            }
        }
    }

    laSource.close();
    laOutput.close();
//    cout << endl;
//    cout << "Finish lexical analysis" << endl;
//    cout << "Save lexical analysis results successfully" << endl;
//    cout << endl;
    return 0;
}