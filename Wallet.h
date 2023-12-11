// Wallet.h
#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <vector>
#include "CIN.h"
#include "CreditCard.h"
#include "DrivingLicense.h"
#include "IdPhoto.h"
#include "Money.h"
#include "VisitCard.h"

class Wallet {
private:
    std::string id;
    std::string owner;
    bool isLost;
    CIN* cin;
    std::vector<CreditCard*> creditCards;
    DrivingLicense* drivingLicense;
    IdPhoto* idPhoto;
    Money* money;
    VisitCard* visitCard;

public:
    Wallet(const std::string& owner);

    Wallet(std::istream& input);

    void setLost(bool lost);

    bool getLost() const;

    void setCin(CIN* cin);

    void setCreditCards(const std::vector<CreditCard*>& creditCards);

    void setDrivingLicense(DrivingLicense* drivingLicense);

    void setIdPhoto(IdPhoto* idPhoto);

    void setMoney(Money* money);

    void setVisitCard(VisitCard* visitCard);

    const CIN* getCin() const;

    const DrivingLicense* getDrivingLicense() const;

    const IdPhoto* getIdPhoto() const;

    Money* getMoney() const;

    const std::vector<CreditCard*>& getCreditCards() const;

    VisitCard* getVisitCard() const;

    const UniqueItem* getCinUnic() const;

    const UniqueItem* getDrivingLicenseUnic() const;

    const UniqueItem* getIdPhotoUnic() const;

    const MultipleItem* getMoneyUnic() const;

    const std::vector<CreditCard*>& getCreditCardsUnic() const;

    const MultipleItem* getVisitCardUnic() const;

    void printWallet() const;

private:
    static std::string generateUUID();
};

#endif // WALLET_H
