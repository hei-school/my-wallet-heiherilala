#ifndef UTILSDATE_H
#define UTILSDATE_H

#include <iostream>
#include <functional>
#include <ctime>

class UtilsDate {
public:
    static std::tm askDate();
    static bool isNotConvertibleToNumber( std::string& str);
};

#endif // UTILSDATE_H
