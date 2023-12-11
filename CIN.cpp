#include <iostream>
#include <string>
#include "UniqueItem.h" 
#include "UtilsDate.h" 
#include "CIN.h" 

    CIN::CIN(std::string lastName, std::string firstName, std::tm dateOfBirth, std::string placeOfBirth, std::string idNumber, std::string name)
        : UniqueItem(name), lastName(lastName), firstName(firstName), dateOfBirth(dateOfBirth), placeOfBirth(placeOfBirth), idNumber(idNumber) {}

    CIN::CIN() : UniqueItem("CIN") {
        std::cout << "Entrez le prénom : ";
        std::cin >> firstName;
        std::cout << "Entrez le nom : ";
        std::cin >> lastName;
        dateOfBirth = UtilsDate::askDate();
        std::cout << "Entrez le lieu de naissance : ";
        std::cin >> placeOfBirth;
        std::cout << "Entrez le numéro d'identité national : ";
        std::cin >> idNumber;
    }

    std::string CIN::getLastName() const {
        return lastName;
    }

    void CIN::setLastName(const std::string& lastName) {
        this->lastName = lastName;
    }

    std::string CIN::getFirstName() const {
        return firstName;
    }

    void CIN::setFirstName(const std::string& firstName) {
        this->firstName = firstName;
    }

    std::tm CIN::getDateOfBirth() const {
        return dateOfBirth;
    }

    void CIN::setDateOfBirth(const std::tm& dateOfBirth) {
        this->dateOfBirth = dateOfBirth;
    }

    std::string CIN::getPlaceOfBirth() const {
        return placeOfBirth;
    }

    void CIN::setPlaceOfBirth(const std::string& placeOfBirth) {
        this->placeOfBirth = placeOfBirth;
    }

    std::string CIN::getIdNumber() const {
        return idNumber;
    }

    void CIN::setIdNumber(const std::string& idNumber) {
        this->idNumber = idNumber;
    }

    std::string CIN::toString() {
        std::ostringstream oss;
        oss << "CIN{" <<
            "lastName='" << lastName << '\'' <<
            ", firstName='" << firstName << '\'' <<
            ", dateOfBirth=" << std::asctime(&dateOfBirth) <<
            ", placeOfBirth='" << placeOfBirth << '\'' <<
            ", idNumber='" << idNumber << '\'' <<
            '}';

        std::string result = oss.str();
        std::cout << result << std::endl;
        return result;
    }