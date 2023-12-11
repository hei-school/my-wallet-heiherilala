#include <iostream>
#include <string>
#include <vector>
#include "CIN.h"
#include "CreditCard.h"
#include "DrivingLicense.h"
#include "IdPhoto.h"
#include "Money.h"
#include "VisitCard.h"
#include "Wallet.h"

    Wallet::Wallet(const std::string& owner)
        : owner(owner), creditCards(std::vector<CreditCard*>()), id(generateUUID()), isLost(false), money(new Money("money")) {}

    Wallet::Wallet(std::istream& input)
        : creditCards(std::vector<CreditCard*>()), id(generateUUID()), isLost(false), money(new Money("money")) {
        std::cout << "Enter owner: ";
        input >> owner;
    }

    void Wallet::setLost(bool lost) {
        isLost = lost;
    }

    bool Wallet::getLost() const {
        return isLost;
    }

    void Wallet::setCin(CIN* cin) {
        this->cin = cin;
    }

    void Wallet::setCreditCards(const std::vector<CreditCard*>& creditCards) {
        this->creditCards = creditCards;
    }

    void Wallet::setDrivingLicense(DrivingLicense* drivingLicense) {
        this->drivingLicense = drivingLicense;
    }

    void Wallet::setIdPhoto(IdPhoto* idPhoto) {
        this->idPhoto = idPhoto;
    }

    void Wallet::setMoney(Money* money) {
        this->money = money;
    }

    void Wallet::setVisitCard(VisitCard* visitCard) {
        this->visitCard = visitCard;
    }

    const CIN* Wallet::getCin() const {
        return cin;
    }

    const DrivingLicense* Wallet::getDrivingLicense() const {
        return drivingLicense;
    }

    const IdPhoto* Wallet::getIdPhoto() const {
        return idPhoto;
    }

     Money* Wallet::getMoney() const {
        return money;
    }

    const std::vector<CreditCard*>& Wallet::getCreditCards() const {
        return creditCards;
    }

     VisitCard* Wallet::getVisitCard() const {
        return visitCard;
    }

    const UniqueItem* Wallet::getCinUnic() const {
        return cin;
    }

    const UniqueItem* Wallet::getDrivingLicenseUnic() const {
        return drivingLicense;
    }

    const UniqueItem* Wallet::getIdPhotoUnic() const {
        return idPhoto;
    }

    const MultipleItem* Wallet::getMoneyUnic() const {
        return money;
    }

    const std::vector<CreditCard*>& Wallet::getCreditCardsUnic() const {
        return creditCards;
    }

    const MultipleItem* Wallet::getVisitCardUnic() const {
        return visitCard;
    }

    std::string Wallet::generateUUID() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 15);

        const char* hex_chars = "0123456789abcdef";
        std::string uuid = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx";

        for (char& c : uuid) {
            if (c == 'x' || c == 'y') {
                int rand_num = dis(gen);
                c = hex_chars[(c == 'x') ? rand_num : (rand_num & 0x3) | 0x8];
            }
        }

        return uuid;
    }

    void Wallet::printWallet() const {
        // CIN
        std::cout << "-- CIN \'";
        if (cin != nullptr) {
            std::cout << cin->toString() << '\'';
        }
        std::cout << "\'\n";

        // Credit Cards
        std::cout << "-- creditCards \'";
        if (!creditCards.empty()) {
            for (const CreditCard* creditCard : creditCards) {
                std::cout << creditCard->toString() << '\'';
                std::cout << "\'\n";
            }
        }
        std::cout << "\'\n";

        // Driving License
        std::cout << "-- drivingLicense \'";
        if (drivingLicense != nullptr) {
            std::cout << drivingLicense->toString() << '\'';
        }
        std::cout << "\'\n";

        // IdPhoto
        std::cout << "-- idPhoto \'";
        if (idPhoto != nullptr) {
            std::cout << idPhoto->to_string() << '\'';
        }
        std::cout << "\'\n";

        // Money
        std::cout << "-- money \'";
        if (money != nullptr) {
            std::cout << money->to_string() << '\'';
        }
        std::cout << "\'\n";

        // VisitCard
        std::cout << "-- visitCard \'";
        if (visitCard != nullptr) {
            std::cout << visitCard->toString() << '\'';
        }
        std::cout << "\'\n";

        // Other members can be added similarly...
    }