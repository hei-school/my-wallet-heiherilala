#include <iostream>
#include <functional>
#include <ctime>
#include "UtilsDate.h"


bool UtilsDate::isNotConvertibleToNumber( std::string& str) {
    try {
        size_t pos = 0;
        std::stod(str, &pos);
        return std::stod(str, &pos) <= 0;
    } catch (const std::invalid_argument&) {
        return true;
    } catch (const std::out_of_range&) {
        return true;
    }
}

std::tm UtilsDate::askDate() {
    std::tm date;
    std::cout << "Année : ";
    std::string year;
    std::cin >> year;
    while (isNotConvertibleToNumber(year))
    {
        std::cout << "Année fause, redoner une nouvelle valeur : ";
        std::cin >> year;
    }
    date.tm_year = std::stod(year, 0);
    
    std::cout << "Entrez le mois : ";
    std::string month;   
    bool isValid;
    do {
        std::cin >> month;

        // Check if the month is not convertible to a number or if the value is greater than 12
        if (UtilsDate::isNotConvertibleToNumber(month)) {
            isValid = false;
        } else {
            isValid = std::stod(month) < 12;
        }

        // If the month is not valid, prompt the user to enter a new value
        if (!isValid) {
            std::cout << "Mois invalide, veuillez entrer une nouvelle valeur." << std::endl;
        }
    } while (!isValid);
    date.tm_mon = std::stod(month, 0);

    std::cout << "Entrez le Jour : ";
    std::string day; 
    do {
        std::cin >> day;
        // Check if the day is not convertible to a number or if the value is greater than 12
        if (UtilsDate::isNotConvertibleToNumber(day)) {
            isValid = false;
        } else {
            isValid = std::stod(day) < 28;
        }

        // If the day is not valid, prompt the user to enter a new value
        if (!isValid) {
            std::cout << "Jour invalide, veuillez entrer une nouvelle valeur." << std::endl;
        }
    } while (!isValid);
    date.tm_mday = std::stod(day, 0);
    return date;
}

