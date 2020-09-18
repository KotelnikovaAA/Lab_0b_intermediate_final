//
// Created by Anna on 12.09.2020.
//

#ifndef LAB_0B_OPERATIONWITHMAP_H
#define LAB_0B_OPERATIONWITHMAP_H

#include <vector>
#include <string>
#include <map>
#include "MapReader.h"

namespace convertation {
    class OperationWithMap {

    public:
        void setMap(const convertation::MapReader &reader);
        // можем написать const, т.к. единственное поле MapReader - имя файла - уже заполнено перед вызовом setMap

        [[nodiscard]] unsigned int getWordCounter() const;

        std::map<int, std::vector<std::string>, std::greater<>> sortMap();

    private:
        std::map<std::string, int> mp;
        unsigned int wordCounter = 0;
    };
}

#endif //LAB_0B_OPERATIONWITHMAP_H
