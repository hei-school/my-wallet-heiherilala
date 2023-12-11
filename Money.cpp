#include <iostream>
#include <string>
#include "MultipleItem.h"
#include "Money.h"

    Money::Money(const std::string& new_name) : MultipleItem(new_name, "$") {}

    std::string Money::to_string() {
        std::ostringstream oss;
        oss << "Money{"
            << "name='" << getName() << '\''
            << ", quantity=" << get_quantity()
            << ", unity='" << get_unity() << '\''
            << '}';
        return oss.str();
    }

