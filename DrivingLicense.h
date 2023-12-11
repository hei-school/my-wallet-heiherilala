#ifndef DRIVINGLICENSE_H
#define DRIVINGLICENSE_H

#include <iostream>
#include <string>
#include <ctime> // pour gérer la date d'expiration
#include "UniqueItem.h"
#include "UtilsDate.h"

class DrivingLicense : public UniqueItem {
private:
    std::string lastName;
    std::string firstName;
    std::tm expirationDate;

public:
    DrivingLicense(const std::string& lastName, const std::string& firstName, const std::tm& expirationDate, const std::string& name);

    DrivingLicense();

    std::string getLastName() const;

    void setLastName(const std::string& lastName);

    std::string getFirstName() const;

    void setFirstName(const std::string& firstName);

    std::tm getExpirationDate() const;

    void setExpirationDate(const std::tm& expirationDate);

    virtual std::string toString();
};

#endif // DRIVINGLICENSE_H
