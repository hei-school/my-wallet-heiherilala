#include <iostream>
#include <string>
#include "Item.h"
#include "MultipleItem.h"

    MultipleItem::MultipleItem(const std::string& newName, const std::string& unity) : Item(newName), quantity(0), unity(unity) {}

    MultipleItem::MultipleItem(const std::string& newName, int quantity) : Item(newName), quantity(quantity), unity("") {}

    MultipleItem MultipleItem::add(int quantityToAdd) {
        this->quantity += quantityToAdd;
        return *this;
    }

    MultipleItem MultipleItem::take(int quantityToTake) {
        if (this->quantity > quantityToTake) {
            this->quantity -= quantityToTake;
            return *this;
        } else {
            std::cout << this->getName() + " does not have sufficient quantity for this transaction." << std::endl;
            return *this; // Vous pouvez choisir de retourner autre chose selon vos besoins.
        }
    }

    int MultipleItem::get_quantity() const {
        return quantity;
    }

    std::string MultipleItem::get_quantity_with_unity() const {
        return std::to_string(quantity) + " " + unity;
    }

    void MultipleItem::set_quantity(int quantity) {
        this->quantity = quantity;
    }

    void MultipleItem::set_unity(const std::string& unity) {
        this->unity = unity;
    }

    std::string MultipleItem::get_unity() const {
        return unity;
    }

