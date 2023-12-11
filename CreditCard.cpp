#include <iostream>
#include <string>
#include <ctime> // pour gérer la date d'expiration
#include "UniqueItem.h" 
#include "UtilsDate.h" 
#include "CreditCard.h" 

    CreditCard::CreditCard(std::string bank, std::string cardType, std::tm expirationDate, std::string ownerName, std::string name)
        : UniqueItem(name), bank(bank), cardType(cardType), expirationDate(expirationDate), ownerName(ownerName) {}

    CreditCard::CreditCard() : UniqueItem("carte de crédit") {
        std::cout << "Entrez le nom de la banque : ";
        std::cin >> bank;
        std::cout << "Entrez le type de carte : ";
        std::cin >> cardType;
        std::cout << "Entrez la date d'expiration : ";
        this->expirationDate = UtilsDate::askDate();
        std::cout << "Entrez surnome du CC : ";
        std::cin >> ownerName;
    }

    std::string CreditCard::getBank() const {
        return bank;
    }

    void CreditCard::setBank(const std::string& bank) {
        this->bank = bank;
    }

    std::string CreditCard::getCardType() const {
        return cardType;
    }

    void CreditCard::setCardType(const std::string& cardType) {
        this->cardType = cardType;
    }

    std::tm CreditCard::getExpirationDate() const {
        return expirationDate;
    }

    void CreditCard::setExpirationDate(const std::tm& expirationDate) {
        this->expirationDate = expirationDate;
    }

    std::string CreditCard::getOwnerName() const {
        return ownerName;
    }

    void CreditCard::setOwnerName(const std::string& ownerName) {
        this->ownerName = ownerName;
    }

    std::string CreditCard::toString() const{
        std::ostringstream oss;
        oss << "CreditCard{" <<
            "bank='" << bank << '\'' <<
            ", cardType='" << cardType << '\'' <<
            ", expirationDate=" << std::asctime(&expirationDate) <<
            ", ownerName='" << ownerName << '\'' <<
            '}';

        std::string result = oss.str();
        std::cout << result << std::endl;
        return result;
    }