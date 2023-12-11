#include <iostream>
#include <string>
#include <ctime> // pour gérer la date d'expiration
#include "UniqueItem.h" 
#include "UtilsDate.h" 
#include "DrivingLicense.h" 

    DrivingLicense::DrivingLicense(const std::string& lastName, const std::string& firstName, const std::tm& expirationDate, const std::string& name)
        : UniqueItem(name), lastName(lastName), firstName(firstName), expirationDate(expirationDate) {}

    DrivingLicense::DrivingLicense() : UniqueItem("permis de conduire") {
        std::cout << "Entrez le nom de famille : ";
        std::cin >> lastName;
        std::cout << "Entrez le prénom : ";
        std::cin >> firstName;
        expirationDate = UtilsDate::askDate();
    }

    std::string DrivingLicense::getLastName() const {
        return lastName;
    }

    void DrivingLicense::setLastName(const std::string& lastName) {
        this->lastName = lastName;
    }

    std::string DrivingLicense::getFirstName() const {
        return firstName;
    }

    void DrivingLicense::setFirstName(const std::string& firstName) {
        this->firstName = firstName;
    }

    std::tm DrivingLicense::getExpirationDate() const {
        return expirationDate;
    }

    void DrivingLicense::setExpirationDate(const std::tm& expirationDate) {
        this->expirationDate = expirationDate;
    }

    std::string DrivingLicense::toString() {
        std::ostringstream oss;
        oss << "DrivingLicense{" <<
            "lastName='" << lastName << '\'' <<
            ", firstName='" << firstName << '\'' <<
            ", expirationDate=" << std::asctime(&expirationDate) <<
            '}';

        std::string result = oss.str();
        std::cout << result << std::endl;
        return result;
    }
