#ifndef UTILSMETHOD_H
#define UTILSMETHOD_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <ctime>

#include "MultipleItem.h"
#include "UniqueItem.h"
#include "UtilsDate.h"


class UtilsMethod {
public:
    static int askUser(const std::vector<std::string>& messages);

    static void useUniqueItem(const UniqueItem* uniqueItem, std::function<void()> actualFunction, std::function<void(const std::string&)> createUniqueItemFunction);

    static void useMultiItems(const MultipleItem* multipleItem, std::function<void()> actualFunction,
                       std::function<void(const std::string&)> createMultiItemFunction,
                       std::function<void(int)> useFunction, std::function<void(int)> addFunction);

    UtilsMethod();
};

#endif // UTILSMETHOD_H
