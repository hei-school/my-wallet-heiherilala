#ifndef MULTIPLEITEM_H
#define MULTIPLEITEM_H

#include <iostream>
#include <string>
#include "Item.h"

class MultipleItem : public Item {
private:
    int quantity;
    std::string unity;

public:
    MultipleItem(const std::string& newName, const std::string& unity);

    MultipleItem(const std::string& newName, int quantity);

    MultipleItem add(int quantityToAdd);

    MultipleItem take(int quantityToTake);

    int get_quantity() const;

    std::string get_quantity_with_unity() const;

    void set_quantity(int quantity);

    void set_unity(const std::string& unity);

    std::string get_unity() const;
};

#endif // MULTIPLEITEM_H
