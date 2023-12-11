#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include <string>
#include <ctime> // pour gérer la date d'expiration
#include "UniqueItem.h"
#include "UtilsDate.h"

class CreditCard : public UniqueItem {
private:
    std::string bank;
    std::string cardType;
    std::tm expirationDate;
    std::string ownerName;
public:
    CreditCard(std::string bank, std::string cardType, std::tm expirationDate, std::string ownerName, std::string name);

    CreditCard();

    std::string getBank() const;

    void setBank(const std::string& bank);

    std::string getCardType() const;

    void setCardType(const std::string& cardType);

    std::tm getExpirationDate() const;

    void setExpirationDate(const std::tm& expirationDate);

    std::string getOwnerName() const;

    void setOwnerName(const std::string& ownerName);

    virtual std::string toString() const;
};

#endif // CREDITCARD_H
