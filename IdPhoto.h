#ifndef IDPHOTO_H
#define IDPHOTO_H

#include <iostream>
#include <string>
#include "UniqueItem.h"

class IdPhoto : public UniqueItem {
public:
    IdPhoto(const std::string& new_name);

    virtual std::string to_string();
};

#endif // IDPHOTO_H
