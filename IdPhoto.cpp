#include <iostream>
#include <string>
#include "UniqueItem.h" 
#include "IdPhoto.h" 

    IdPhoto::IdPhoto(const std::string& new_name) : UniqueItem(new_name) {}

    std::string IdPhoto::to_string() {
        return "IdPhoto{name=" + getName() + "}";
    }
