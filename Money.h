#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>
#include "MultipleItem.h"

class Money : public MultipleItem {
public:
    Money(const std::string& new_name);

    virtual std::string to_string();
};

#endif // MONEY_H
