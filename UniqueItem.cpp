#include <iostream>
#include <string>
#include "Item.h"
#include "UniqueItem.h"

    UniqueItem::UniqueItem(const std::string& name) : Item(name) {}

    void UniqueItem::setLost(bool lost) {
        isLost = lost;
    }

    bool UniqueItem::getLost() const {
        return isLost;
    }

    void UniqueItem::usedItem(const std::string& message) const {
        if (isLost == true) {
            std::cout << "Cet item est perdu, donc tu ne peux pas l'utiliser" << std::endl;
            return;
        }
        std::cout << this->getName() + " a été utilisé. '" + message + "'" << std::endl;
    }

