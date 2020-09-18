//
// Created by Anna on 12.09.2020.
//

#include "MapReader.h"
#include <iostream>
#include <fstream>
#include <utility>

convertation::MapReader::MapReader() {
    this->fileIn = "input.txt";
}

convertation::MapReader::MapReader(const std::string &fileIn) {
    this->fileIn = fileIn;
}

std::map<std::string, int> convertation::MapReader::fillMap() const {
    std::ifstream input;                                    // создали входной поток
    input.open(getFileIn());                             // открыли поток на вход с файла
    std::map<std::string, int> mp;                          // создаем MAP

    std::string newString;                                  // строка, в к-ю считываем с потока (до первого \n, считывая, но не включая его)
    std::string newWord;                                    // очередное слово
    while (std::getline(input, newString)) {        // считываем строку с потока
        for (const auto curSymbol : newString) {
            if (!isPermissibleSymbol(curSymbol)) {
                if (!newWord.empty()) {
                    mp[newWord]++;
                    newWord.clear();
                }
            } else newWord += curSymbol;
        }
    }

    input.close();                                          // закрыли входной поток
    return mp;
}

bool convertation::MapReader::isPermissibleSymbol(char symbol) {
    return (betweenLimits(symbol, '0', '9') ||
            betweenLimits(symbol, 'a', 'z') ||
            betweenLimits(symbol, 'A', 'Z'));
}

bool convertation::MapReader::betweenLimits(char symbol, char limit_1, char limit_2) {
    return (symbol >= limit_1 && symbol <= limit_2);
}

std::string convertation::MapReader::getFileIn() const {
    return fileIn;
}
