//
// Created by Anna on 12.09.2020.
//


#ifndef LAB_0B_MAPREADER_H
#define LAB_0B_MAPREADER_H

#include <string>
#include <map>
#include "MapReader.h"

namespace convertation {
    class MapReader {

    public:
        MapReader();

        MapReader(const std::string &fileIn);

        std::string getFileIn() const;

        std::map<std::string, int> fillMap() const;

        static bool betweenLimits(char symbol, char limit_1, char limit_2);

        static bool isPermissibleSymbol(char symbol);

    private:
        std::string fileIn;
    };
}

#endif //LAB_0B_MAPREADER_H
