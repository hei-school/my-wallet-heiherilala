#ifndef CIN_H
#define CIN_H

#include <iostream>
#include <string>
#include "UniqueItem.h"
#include <ctime>
#include "UtilsDate.h" 
class CIN : public UniqueItem {
private:
    std::string lastName;
    std::string firstName;
    std::tm dateOfBirth;
    std::string placeOfBirth;
    std::string idNumber;

public:
    CIN(std::string lastName, std::string firstName, std::tm dateOfBirth, std::string placeOfBirth, std::string idNumber, std::string name);

    CIN();

    std::string getLastName() const;

    void setLastName(const std::string& lastName);

    std::string getFirstName() const;

    void setFirstName(const std::string& firstName);

    std::tm getDateOfBirth() const;

    void setDateOfBirth(const std::tm& dateOfBirth);

    std::string getPlaceOfBirth() const;

    void setPlaceOfBirth(const std::string& placeOfBirth);

    std::string getIdNumber() const;

    void setIdNumber(const std::string& idNumber);

    virtual std::string toString();
};

#endif // CIN_H
