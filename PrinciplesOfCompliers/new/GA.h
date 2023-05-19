//
// Created by Anthony Wong on 2023/5/5.
//

#ifndef GFHKSDGM_GA_H
#define GFHKSDGM_GA_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>

/**
 * @class Unit character properties
 */
class Unit {
public:
    std::string value;
    std::string key;
    int line;
    int column;

    void print();
};

/**
 * Print all properties of a unit
 */
void Unit::print() {
    std::cout << "-----------------" << std::endl;
    std::cout << "Value: " << value << std::endl;
    std::cout << "Key: " << key << std::endl;
    std::cout << "Position: [" << line << "," << column << "]" << std::endl;
    std::cout << "-----------------" << std::endl;
}

#endif //GFHKSDGM_GA_H
