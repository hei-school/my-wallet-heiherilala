#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <random>
#include <sstream>

class Item {

private:
    std::string id;
    std::string name;

public:
    Item(const std::string& name);

    std::string getName() const;
    std::string getId() const;
    void setName(const std::string& name);

private:
    static std::string generateUUID();
};

#endif // ITEM_H
