//
// Created by Anthony Wong on 2023/5/5.
//

#include "GA.h"
using namespace std;

Unit unit, former_unit;
int errorStack[100] = {-1};
int *errorType = errorStack;
bool error = false;
fstream gaSource;
fstream gaOutput;
int errorc=0;
int Blocksign=0;

string line;
string::iterator itLine;

string nameArray[10];

string nameArray2[10];
string nameArray3[10];
void ReadLine() {
// Remember ERROR procedure.
    if (getline(gaSource, line)){
//    cout << line << endl;

        itLine = line.begin();
        while (*itLine == '#' || line.empty()) {// Jump annotations & empty lines
            getline(gaSource, line);
//        cout << line << endl;
            itLine = line.begin();
        }

        former_unit = unit;

        istringstream iss(line);

        if (*itLine == '^'){ // Lexical error
            char ch;
            iss >> ch; // '^'
            iss >> unit.value;
            iss >> unit.key;
            iss >> unit.line;
            iss >> unit.column;
//        unit.print();
            getline(gaSource, line);
        } else { // No lexical error
            iss >> unit.value;
            iss >> unit.key;
            iss >> unit.line;
            iss >> unit.column;
//        unit.print();
        }
    } else {
//        cout << "[DEBUG] End of file" << endl;
    }
}

/**
 * Throw an error.
 * @param type Error type.
 */

void ThrowError(int type){
    //error = true;
    errorc=1;
    *errorType = type;
    errorType++;
    switch(type){
        case 0:
            cout << "[Grammar ERROR] " << " [" << unit.line << "," << unit.column << "] " << "Spell error \"program\"" << endl;
            break;
        case 1:
            cout << "[Grammar ERROR] " << " [" << unit.line << "," << unit.column << "] " << "Missing identifier after \"program\"" << endl;
            break;
        case 2:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " <<"Missing end character \";\"" << endl;
            break;
        case 3:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing identifier after \"const\"" << endl;
            break;
        case 4:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing assignment operation" << endl;
            break;
        case 5:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing assignment integer" << endl;
            break;
        case 6:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing identifier after \"var\"" << endl;
            break;
        case 7:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing identifier after \",\"" << endl;
            break;
        case 8:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Cannot resolve type \"" << unit.value << "\"" << endl;
            break;
        case 9:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing identifier after \"procedure\"" << endl;
            break;
        case 10:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing parentheses in \"procedure\"" << endl;
            break;
        case 11:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing identifier in \"procedure\"" << endl;
            break;
        case 12:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing word \"begin\"" << endl;
            break;
        case 13:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing word \"end\"" << endl;
            break;
        case 14:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing statement identifier" << endl;
            break;
        case 15:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing word \"then\"" << endl;
            break;
        case 16:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing word \"do\"" << endl;
            break;
        case 17:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing identifier in \"call\"" << endl;
            break;
        case 18:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing parentheses in \"call\"" << endl;
            break;
        case 19:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing identifier in \"read\"" << endl;
            break;
        case 20:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing parentheses in \"read\"" << endl;
            break;
        case 21:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing parentheses in \"write\"" << endl;
            break;
        case 22:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing the compare operator" << endl;
            break;
        case 23:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Missing parentheses" << endl;
            break;
        case 24:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Wrong factor" << endl;
            break;
        case 25:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " << "Extra semicolon \";\" before \"end\"" << endl;
            break;
        case 26:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " << "Missing comma \",\" in \"var\"" << endl;
            break;
        case 27:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " << "Missing comma \",\" in \"const\"" << endl;
            break;
        case 28:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " << "Fail to Detect DataType." << endl;
            break;
        case 29:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " << "Error in your Personal Rules 1." << endl;
            break;
        case 30:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " << "Error in your Personal Rules 2." << endl;
            break;
        case 31:
            cout << "[Grammar ERROR] "<< " [" << former_unit.line << "," << former_unit.column << "] " << "Error in your Personal Rules 3." << endl;
            break;
        default:
            cout << "[Grammar ERROR] "<< " [" << unit.line << "," << unit.column << "] " <<"Unknown error" << endl;
            break;
    }
}

void Exp();
/**
 * <factor>→<id>|<integer>|(<exp>)
 */
void Factor() {
    if (unit.key == "ID" || *errorType == 24) {
        if (unit.key != "ID" && unit.key != "INT" && unit.value == "(" && *errorType == 24) errorType++;
        ReadLine();
        // End factor
    } else if (unit.key == "INT") {
        ReadLine();
        // End factor
    } else if (unit.key == "SOP" && unit.value == "(") {
        ReadLine();
        Exp();
        if (unit.key == "SOP" && unit.value == ")" || *errorType == 23) {
            if (unit.value != ")" && *errorType == 23) errorType++;
            ReadLine();
            // End factor
        } else {
            ThrowError(23);
        }
    } else {
        ThrowError(24);
    }
}

/**
 * <term> → <factor>{<mop><factor>}
 */
void Term() {
    Factor();
    if (unit.value == "*" || unit.value == "/") {
        ReadLine();
        Factor();
    }if(unit.value=="**"||unit.key=="OOP"){
        ReadLine();
        Factor();
    }
}

/**
 * <exp> → [+|-]<term>{<aop><term>}
 */
void Exp() {
    if (unit.value == "+" || unit.value == "-") {
        ReadLine();
    }
    Term();
    if (unit.value == "+" || unit.value == "-") {
        ReadLine();
        Term();
    }
}

/**
 * <lexp> → <exp> <lop> <exp>|odd <exp>
 */
void Lexp() {
    if (unit.key == "SOP" && unit.value == "(") {
        ReadLine();
    if (unit.value == "odd") {
        ReadLine();
        Exp();
    } else {
        Exp();
//        ReadLine();
        if (unit.key == "COP" || *errorType == 22) {
            if (unit.key != "COP" && *errorType == 22) errorType++;
            ReadLine();
            Exp();
        } else {
            //ThrowError(22);
        }
    }if (unit.key == "SOP" && unit.value == ")" || *errorType == 23) {
        if (unit.value != ")" && *errorType == 23) errorType++;
        ReadLine();
    }else {
        ThrowError(23);
    }}else {
        if (unit.value == "odd") {
            ReadLine();
            Exp();
        } else {
            Exp();
//        ReadLine();
            if (unit.key == "COP" || *errorType == 22) {
                if (unit.key != "COP" && *errorType == 22) errorType++;
                ReadLine();
                Exp();
            } else {
                ThrowError(22);
            }
        }
    }

}


void Body();
/**
 * <statement> → <id> := <exp>
               |if <lexp> then <statement>[else <statement>]
               |while <lexp> do <statement>
               |call <id>[（<exp>{,<exp>}）]
               |<body>
               |read (<id>{，<id>})
               |write (<exp>{,<exp>})
 */
void Statement() {
    if (unit.key == "RESERVED" && unit.value == "if") {
        ReadLine();
        Lexp();
        if (unit.key == "RESERVED" && unit.value == "then" || *errorType == 15) {
            if (*errorType == 15 && unit.value != "then") errorType++; else ReadLine();
            Statement();
//            ReadLine();
            if (unit.key == "RESERVED" && unit.value == "else") {
                ReadLine();
                Statement();
//                ReadLine();
            }
        } else {
            ThrowError(15);
        }

    } else if (unit.key == "RESERVED" && unit.value == "while") {
        ReadLine();
        Lexp();
        //ReadLine();
        while(unit.key == "RESERVED" && (unit.value == "and"||unit.value=="or")){
            ReadLine();
            Lexp();
        }
        if (unit.key == "RESERVED" && unit.value == "do" || *errorType == 16) {
            if (*errorType == 16 && unit.value != "do") errorType++; else ReadLine();
//            ReadLine();
            Statement();
//            ReadLine();
        } else {
            ThrowError(16);
        }

    } else if (unit.key == "RESERVED" && unit.value == "call") {
        ReadLine();
        if (unit.key == "ID" || *errorType == 17) {
            if (*errorType == 17 && unit.key != "ID") errorType++;
            ReadLine();// Read more one line...
            if (unit.key == "SOP" && unit.value == "(") {
                ReadLine();
                Exp();
//                ReadLine();
                while (unit.key == "SOP" && unit.value == ",") {
                    ReadLine();
                    Exp();
//                    ReadLine();
                }
                if (unit.value == ",") ReadLine();
                if (unit.key == "SOP" && unit.value == ")" || *errorType == 18) {
                    if (*errorType == 18 && unit.value != ")") errorType++; else ReadLine();
//                    ReadLine();
                } else {
                    ThrowError(18);
                }
            }
        } else {
            ThrowError(17);
        }

    } else if (unit.key == "RESERVED" && unit.value == "read") {
        // read (<id>{，<id>})
        ReadLine();
        if (unit.key == "SOP" && unit.value == "(" || *errorType == 20) {
            if (*errorType == 20 && unit.value != "(") errorType++; else ReadLine();
//            ReadLine();
            if (unit.key == "ID" || *errorType == 19) {
                if (*errorType == 19 && unit.key != "ID") errorType++; else ReadLine();
//                ReadLine();
                while (unit.key == "SOP" && unit.value == ",") {
                    ReadLine();
                    if (unit.key == "ID" || *errorType == 19) {
                        if (*errorType == 19 && unit.key != "ID") errorType++; else ReadLine();
//                        ReadLine();
                    } else {
                        ThrowError(19);
                    }
                }
                if (unit.value == ",") ReadLine();
                if (unit.key == "SOP" && unit.value == ")" || *errorType == 20) {
                    if (*errorType == 20 && unit.value != ")") errorType++; else ReadLine();
                    // Over read...
                } else {
                    ThrowError(20);
                }
            } else {
                ThrowError(19);
            }

        } else {
            ThrowError(20);
        }

    } else if (unit.key == "RESERVED" && unit.value == "write") {
        // write (<exp>{,<exp>})

        ReadLine();
        if (unit.key == "SOP" && unit.value == "(" || *errorType == 21) {
            if (*errorType == 21 && unit.value != "(") errorType++; else ReadLine();
//            ReadLine();
            Exp();
            while (unit.key == "SOP" && unit.value == ",") {
                ReadLine();
                Exp();
            }
//            if (unit.value == ",") ReadLine();
            if (unit.key == "SOP" && unit.value == ")" || *errorType == 21) {
                if (*errorType == 21 && unit.value != ")") errorType++; else ReadLine();
//                ReadLine();
                // Over write...
            } else {
                ThrowError(21);
            }
        } else {
            ThrowError(21);
        }

    } else if (unit.key == "ID") {
        // <id> := <exp>
        ReadLine();
        if (unit.key == "AOP" || *errorType == 4) {
            if (*errorType == 4 ) errorType++;
            ReadLine();
            Exp();
        } else {
            ThrowError(4);
        }
    }else if(unit.key == "RESERVED" && unit.value == "var"){

    }else{
        Body();
    }
}

/**
 * <body> → begin <statement>{;<statement>}end
 */
void Body() {
    if (unit.key == "RESERVED" && unit.value == "begin" || *errorType == 12) {
        if (*errorType == 12 && unit.value != "begin") errorType++;
        ReadLine();
        Statement();
        while (unit.key == "EOP" && unit.value == ";" && !error) {
            ReadLine();
            if (unit.value == "end") {
                if (*errorType == 25) ThrowError(25);
                break;
            }
            Statement();
        }
//        if (unit.value == ";") ReadLine();
        if(*errorType == 25) {
            errorType++;
            ReadLine();
        }
        if (unit.key == "RESERVED" && unit.value == "end" || *errorType == 13 || error) {
            if (*errorType == 13 && unit.value != "end") errorType++;
            if (!error) ReadLine();
            // Over
        } else {
            ThrowError(13);
        }
    } else {
        ThrowError(12);
    }

}

void Block();
/**
 * <proc> → procedure <id>（<id>{,<id>}）;<block>{;<proc>}
 */
void Proc() {
    if(unit.key == "ID" || *errorType == 9) {
        if(*errorType == 9 && unit.key != "ID") errorType++; else ReadLine();
//        ReadLine();
        if (unit.key == "SOP" && unit.value == "(" || *errorType == 10){
            if (*errorType == 10 && unit.value != "(") errorType++;
            ReadLine();
            if (unit.key == "ID" || *errorType == 11) {
                if (*errorType == 11 && unit.key != "ID") errorType++;
                ReadLine();

                while (unit.value == "," && unit.key == "SOP"){

                    ReadLine();
                    if (unit.key == "ID"|| *errorType == 11){
                        if(unit.key != "ID") errorType++;
                        ReadLine();

                    } else{
                        ThrowError(11); // Missing id
                    }
                    if(error) break;
                }
                if (unit.value == ",") ReadLine();
                if (unit.key == "SOP" && unit.value == ")" || *errorType == 10){
                    if (*errorType == 10 && unit.value != ")") errorType++;
                    ReadLine();

                    if (unit.key == "EOP" && unit.value == ";" || *errorType == 2) {
                        if (*errorType == 2 && unit.value != ";") errorType++; else ReadLine();
//                        ReadLine();
                        Block();

                        while (unit.key == "EOP" && unit.value == ";") {
                            ReadLine();
                            Proc();
                        }

//                        ReadLine();
                        // End Proc
                    } else {
                        ThrowError(2);
                    }
                } else {
                    ThrowError(10);
                }

            } else {
                ThrowError(11);
            }
        } else {
            ThrowError(10);
        }
    } else {
        ThrowError(9);
    }
}

/**
 * <vardecl> → var <id>{,<id>};
 * <id> → l{l|d}
 */
void Vardecl() {
    int expsign=0;
    while (unit.key == "ID") {
        expsign=1;
        ReadLine();
        while (unit.value == "," && unit.key == "SOP" || *errorType == 26) {
            if (*errorType == 26 && unit.value != ",") errorType++; else ReadLine();
//            ReadLine();
            if (unit.key == "ID") {
                ReadLine();
            } else {
                ThrowError(7);// Missing ID
            }
        }
        if(unit.key == "ID") {
            ThrowError(26);
        }

        if(unit.key=="AOP"&&unit.value==":"||*errorType==28){
            if(*errorType==28&&unit.value!=":") *errorType++; else ReadLine();

            if(unit.key=="RESERVED"&&(unit.value=="integer"||unit.value=="long"||unit.value=="bool"||unit.value=="short")){
                ReadLine();
            }else{
                ThrowError(28);
                ReadLine();
            }
        }
        if (unit.value == ";" && unit.key == "EOP" || *errorType == 2) {
            if (*errorType == 2 && unit.value != ";") errorType++; else {
                ReadLine();
            }
//            ReadLine();
            // Finish var declaration.
        } else {
            ThrowError(2); // Missing EOP
        }
    } if(expsign==0){
        ThrowError(6); // Missing ID
    }
}

/**
 * <condecl> → const <const>{,<const>};
 * <const> → <id>:=<integer>
 * <id> → l{l|d}
 */
void Condecl() {
    if (unit.key == "ID" || *errorType == 3){
        if(unit.key != "ID") errorType++;
        ReadLine();
        if (unit.value == ":=" && unit.key == "AOP" || *errorType == 4) {
            if(!(unit.value == ":=" && unit.key == "AOP")) errorType++; else ReadLine();
//            ReadLine();
            if (unit.key == "INT" || *errorType == 5) {
                if(unit.key != "INT" && *errorType == 5) {
                    errorType++;
                    while (unit.value != "," && unit.value != ";") {
                        ReadLine();
                        if (unit.key == "ID") break;// For missing comma
                    }
                } else {
                    ReadLine();
                }
//                ReadLine();

                while (unit.value == "," && unit.key == "SOP" || *errorType == 27){
                    if (*errorType == 27 && unit.value != ",") errorType++; else ReadLine();
//                    ReadLine();
                    if (unit.key == "ID"|| *errorType == 3){
                        if(unit.key != "ID") errorType++; else ReadLine();
//                        ReadLine();
                        if (unit.value == ":=" && unit.key == "AOP"|| *errorType == 4){
                            if(!(unit.value == ":=" && unit.key == "AOP")) errorType++; else ReadLine();
//                            ReadLine();
                            if (unit.key == "INT"|| *errorType == 5) {
                                if(unit.key != "INT") {
                                    errorType++;
                                    while (unit.value != "," && unit.key != ";") {
                                        ReadLine();
                                    }
                                } else {
                                    ReadLine();
                                }
//                                ReadLine();
                            } else {
                                ThrowError(5); // Missing INT
                            }
                        } else {
                            ThrowError(4); // Missing AOP
                        }
                    } else{
                        ThrowError(3); // Missing id
                    }
                    if(error) break;
                }

                if(unit.key == "ID" && !error) {
                    ThrowError(27);// Missing comma
                }
                while (unit.value == ",") ReadLine();
                if (unit.value == ";" && unit.key == "EOP"|| *errorType == 2 || error) {
                    if(!(unit.value == ";" && unit.key == "EOP") && !error) errorType++; else ReadLine();
//                    ReadLine();
                    // Finish const declaration.
                } else {
                    ThrowError(2); // Missing EOP
                }
            } else {
                ThrowError(5); // Missing INT
            }
        } else {
            ThrowError(4); // Missing AOP
        }
    } else{
        ThrowError(3); // Missing id
    }
}

void BlockPreJudge(){



}
int rightsign=1;
int rightsign2=1;
int rightsign3=1;
void BlockAddFunc(){
    int ibiu=0;
    int ibiu2=0;
    int ibiu3=0;
    while (!nameArray[ibiu].empty()||!nameArray2[ibiu].empty()||!nameArray3[ibiu].empty()){
        if(rightsign==1) {
            if (nameArray[ibiu] == "<DataType>") {
                if (unit.key == "RESERVED" &&
                    (unit.value == "integer" || unit.value == "int" || unit.value == "bool" || unit.value == "short" ||
                     unit.value == "longint")) {
                    ibiu++;
                } else{
                    rightsign = 0;
                }
            } else if (nameArray[ibiu] == "<INT>") {
                if(unit.key == "INT") {
                    ibiu++;
                }else{
                    rightsign = 0;
                }
            }else if (nameArray[ibiu] == "<EOP>") {
                if(unit.key == "EOP" && unit.value == ";") {
                    ReadLine();
                    break;
                }
            }else if(nameArray[ibiu]=="<ID>"){
                if(unit.key=="ID"){
                    ibiu++;
                }else{
                    rightsign = 0;
                }
            }else if(nameArray[ibiu]==unit.value){
                ibiu++;
            }else{
                rightsign=0;
            }
        }
        if(rightsign2==1) {
            if (nameArray2[ibiu2] == "<DataType>") {
                if (unit.key == "RESERVED" &&
                    (unit.value == "integer" || unit.value == "int" || unit.value == "bool" || unit.value == "short" ||
                     unit.value == "longint")) {
                    ibiu2++;
                } else{
                    rightsign2 = 0;
                }
            } else if (nameArray2[ibiu2] == "<INT>") {
                if(unit.key == "INT") {
                    ibiu2++;
                }else{
                    rightsign2 = 0;
                }
            }else if (nameArray2[ibiu2] == "<EOP>") {
                if(unit.key == "EOP" && unit.value == ";") {
                    ReadLine();
                    break;
                }
            }else if(nameArray2[ibiu2]=="<ID>"){
                if(unit.key=="ID"){
                    ibiu2++;
                }else{
                    rightsign2 = 0;
                }
            }else if(nameArray2[ibiu2]==unit.value){
                ibiu2++;
            }else{
                rightsign2=0;
            }
        }
        if(rightsign3==1) {
            if (nameArray3[ibiu3] == "<DataType>") {
                if (unit.key == "RESERVED" &&
                    (unit.value == "integer" || unit.value == "int" || unit.value == "bool" || unit.value == "short" ||
                     unit.value == "longint")) {
                    ibiu3++;
                } else{
                    rightsign3 = 0;
                }
            } else if (nameArray3[ibiu3] == "<INT>") {
                if(unit.key == "INT") {
                    ibiu3++;
                }else{
                    rightsign3 = 0;
                }
            }else if (nameArray3[ibiu3] == "<EOP>") {
                if(unit.key == "EOP" && unit.value == ";") {
                    ReadLine();
                    break;
                }
            }else if(nameArray3[ibiu3]=="<ID>"){
                if(unit.key=="ID"){
                    ibiu3++;
                }else{
                    rightsign3 = 0;
                }
            }else if(nameArray3[ibiu3]==unit.value){
                ibiu3++;
            }else{
                rightsign3=0;
            }
        }
ReadLine();


    }
    if(!(rightsign||rightsign2||rightsign3))
        ThrowError(29);
}

/**
 * <block> → [<condecl>][<vardecl>][<proc>]<body>
 */
 int varsigng=0;
void Block() {

    //BlockPreJudge();
    if (unit.value == "const" && unit.key == "RESERVED" && !error) {
        ReadLine();
        Condecl();
    } else if (unit.key == "ID" && *errorType != 8 && !error&&!Blocksign) {
        ThrowError(8); // Cannot resolve type
        while (unit.key != "EOP" && unit.key != "RESERVED") {
            ReadLine();
        }
        ReadLine();
    } else if (*errorType == 8 && !error) {
        errorType++;
        while (unit.key != "EOP" && unit.key != "RESERVED") {
            ReadLine();
        }
        ReadLine();
    }
    while (unit.value == "var" || unit.key == "ID") {
    if (unit.value == "var" && unit.key == "RESERVED" && !error) {
        varsigng = 1;
        ReadLine();
        Vardecl();
        continue;
    } else if (unit.key == "ID" && varsigng == 1 && !error) {
        //ReadLine();
        Vardecl();
        continue;
    } else if (unit.key == "ID" && *errorType != 8 && !error&&!Blocksign) {
        ThrowError(8); // Cannot resolve type
        while (unit.key != "EOP" && unit.key != "RESERVED") {
            ReadLine();
        }
        ReadLine();
    } else if (*errorType == 8 && !error) {
        errorType++;
        while (unit.key != "EOP" && unit.key != "RESERVED") {
            ReadLine();
        }
        ReadLine();
    }else if(Blocksign)
        break;

}
    if (unit.value == "procedure" && unit.key == "RESERVED" && !error) {
        ReadLine();
        Proc();
    } else if (*errorType != 8 && !error&&!Blocksign&&unit.value!="begin"){
        ThrowError(8); // Cannot resolve type
        while(unit.key != "EOP"){
            ReadLine();
        }
        ReadLine();
    } else if (*errorType == 8 && !error) {
        errorType++;
        while(unit.key != "EOP" && unit.key != "RESERVED"){
            ReadLine();
        }
        ReadLine();
    }
    if(Blocksign&&unit.value!="begin")
        BlockAddFunc();



    if (!error){
        Body();
    }
}

/**
 * <prog> → program <id>; <block>
 */
void Prog() {
    ReadLine();
    if ((unit.value == "program" && unit.key == "RESERVED") || *errorType == 0){
        if (*errorType == 0) errorType++;
        ReadLine();
        if (unit.key == "ID" || *errorType == 1) {
            if (*errorType == 1) errorType++; else ReadLine();
//            ReadLine();
            if ((unit.value == ";" && unit.key == "EOP") || *errorType == 2) {
                if (*errorType == 2 && unit.value != ";") errorType++; else ReadLine();
                Block();
            } else {
                ThrowError(2);
            }
        } else {
            ThrowError(1);
        }
    } else {
        ThrowError(0);
    }

}

void OpenFile() {
    gaSource.open("la_output", ios::in); // Read file
    gaOutput.open("ga_output", ios::out | ios::trunc); // Write file

    if (!gaSource.is_open()) {
        cout << "Cannot open the gaSource file!\a" << endl;
        exit(1);
    }
    if (!gaOutput.is_open()) {
        cout << "Cannot open the gaOutput file!\a" << endl;
    } else {
        // Header of the file (DateTime & File name & Lang set)

        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);

        gaOutput << "# Grammar Analysis Result" << endl;
        gaOutput << "# Generated Time: " << asctime(timeinfo);
        gaOutput << "# Language Set: PL/0" << endl;
        gaOutput << endl;
    }
}

void CloseFile() {
    gaSource.close();
    gaOutput.close();
}

/**
 * Print the error stack out.
 */
 /*
void PrintErrorStack() {
    cout << "[DEBUG] Error Stack" << endl;
    cout << endl << "|<<<< ERROR STACK <<<<<" << endl;
    int *p;
    cout << "|";
    for (p = errorStack; p != errorType; p++) {
        cout << *p << " ";
    }
    cout << endl << "|<<<<<<<<<<<<<<<<<<<<<<" << endl;
}
  ：*/



int GA() {
cout<<"Write Something about GA?"<<endl;
int counthh=0;
     int nummm=0;
     int thinkingga=1;
     while(thinkingga) {
         string writing;
         cin>>writing;
         if(writing=="No"||writing=="no"){
             thinkingga=0;
             cout<<"Okay"<<endl<<endl;
             break;
         }else if(writing=="ADD"){
             cin>>writing;
             counthh++;
             if(writing=="Block"){
                 while(cin>>writing){
                     if(writing=="ENDENDEND")
                         break;
                     if(counthh==1)
                        nameArray[nummm]=writing;
                     if(counthh==2)
                         nameArray2[nummm]=writing;
                     if(counthh==3)
                         nameArray3[nummm]=writing;
                     nummm++;
                 }
                 Blocksign++;
                 nummm=0;
                 cout<<"Good, Another One? "<<endl;
             }else if(writing=="Body"){
                 cin>>writing;
                 while(cin>>writing){
                     nameArray[nummm]=writing;
                     nummm++;
                     cin>>writing;
                 }
             }
         }else{
             cout<<"Invalid Request, Enter No to skip."<<endl;
         }

     }
    OpenFile();
    Prog();
    CloseFile();
    while (error) {
        errorc=1;
        error = false;
        errorType = errorStack;
        OpenFile();
        Prog();
        CloseFile();
    }
    if(errorc==0)
        cout<<"Passed Grammar Check!"<<endl;
    if(!error)
        cout<<"Finish!"<<endl;

//    PrintErrorStack();
    return 0;
}