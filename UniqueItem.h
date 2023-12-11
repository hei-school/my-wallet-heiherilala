#ifndef UNIQUEITEM_H
#define UNIQUEITEM_H

#include <iostream>
#include <string>
#include "Item.h"

class UniqueItem : public Item {
private:
    bool isLost;

public:
    void setLost(bool lost);

    bool getLost() const;

    void usedItem(const std::string& message) const;

    UniqueItem(const std::string& name);
};

#endif // UNIQUEITEM_H
