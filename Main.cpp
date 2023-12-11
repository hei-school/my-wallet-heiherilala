#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "UtilsMethod.h"
#include "Wallet.h"


class Main {
private:
    static Wallet* actualWallet;
    static std::vector<Wallet*> walletsLost;

public:
    static void main() {
        while (true) {
            principalMenu();
        }
    }

    static void useWallet() {
        int choice = UtilsMethod::askUser({"Quel événement s'est-il passé?", "1. Vous avez perdu votre portefeuille", "2. Regardé ce qu'il y a dans le portefeuille.", "3. Revenir au menu principal"});

        switch (choice) {
            case 1:
                actualWallet->setLost(true);
                walletsLost.push_back(actualWallet);
                actualWallet = nullptr;
                break;
            case 2:
                actualWallet->printWallet();
                break;
            case 4:
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                useWallet();
                break;
        }
    }

    

    static void useCIN() {
        UtilsMethod::useUniqueItem(actualWallet->getCinUnic(), [&]() { useDrivingLicense(); }, [&](const std::string& s) { actualWallet->setCin(new CIN()); });
    }

    

    // Méthode pour la carte de crédit
    static void useCreditCard() {
        int choice = UtilsMethod::askUser({"1. Ajouter une carte de crédit", "2. Utiliser les cartes de crédit existantes", "3. Retour au menu principal"});
        std::vector<std::string> messages;

        switch (choice) {
            case 1: {
                std::vector<CreditCard*> creditCards = actualWallet->getCreditCards();
                creditCards.push_back(new CreditCard());
                actualWallet->setCreditCards(creditCards);
                break;
            }
            case 2: {
                if (actualWallet->getCreditCards().empty()) {
                    std::cout << "Vous ne possédez pas de cartes de crédit." << std::endl;
                    break;
                }
                messages.push_back("Choisissez la carte à utiliser :");
                for (CreditCard* creditCard : actualWallet->getCreditCards()) {
                    messages.push_back(std::to_string(actualWallet->getCreditCards().size()) + ". " + creditCard->getName());
                }
                int choice2 = UtilsMethod::askUser(messages);
                if (choice2 < actualWallet->getCreditCards().size()) {
                    UtilsMethod::useUniqueItem(actualWallet->getCreditCards()[choice2], [&]() { useCreditCard(); }, nullptr);
                    break;
                } else {
                    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                    useCreditCard();
                    break;
                }
            }
            case 3:{
                break;
            }
            default:{
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                useCreditCard();
                break;
            }
        }
    }

    // Méthode pour le permis de conduire
    static void useDrivingLicense() {
        UtilsMethod::useUniqueItem(actualWallet->getDrivingLicenseUnic(), [&]() { useDrivingLicense(); }, [&](const std::string& s) { actualWallet->setDrivingLicense(new DrivingLicense()); });
    }

    // Méthode pour la photo d'identité
    static void useIdPhoto( ) {
        UtilsMethod::useUniqueItem(actualWallet->getIdPhotoUnic(), [&]() { useDrivingLicense(); }, [&](const std::string& s) { actualWallet->setIdPhoto(new IdPhoto("ma photo")); });
    }

    // Méthode pour l'argent
    static void useMoney( ) {
        UtilsMethod::useMultiItems(actualWallet->getMoneyUnic(), [&]() { useMoney(); }, [&](const std::string& s) { actualWallet->setMoney(new Money(s)); },
                                  [&](int quantity) {
                                      Money* money = actualWallet->getMoney();
                                      money->take(quantity);
                                      actualWallet->setMoney(money);
                                  },
                                  [&](int quantity) {
                                      Money* money = actualWallet->getMoney();
                                      money->add(quantity);
                                      actualWallet->setMoney(money);
                                  });
    }

    // Méthode pour la carte de visite
    static void useVisitCard( ) {
        UtilsMethod::useMultiItems(actualWallet->getVisitCardUnic(), [&]() { useVisitCard(); }, [&](const std::string& s) { actualWallet->setVisitCard(new VisitCard()); },
                                  [&](int quantity) {
                                      VisitCard* visitCard = actualWallet->getVisitCard();
                                      visitCard->take(quantity);
                                      actualWallet->setVisitCard(visitCard);
                                  },
                                  [&](int quantity) {
                                      VisitCard* visitCard = actualWallet->getVisitCard();
                                      visitCard->add(quantity);
                                      actualWallet->setVisitCard(visitCard);
                                  });
    }

    static void principalMenu() {
        int choice = 0;

        if (actualWallet == nullptr) {
            choice = UtilsMethod::askUser({"Vous n'avez pas de portefeuille à votre possession", "1. Acheter", "2. Quitter"});

            switch (choice) {
                case 1:{
                    std::cout << "Entrez le surnom de votre portefeuille : ";
                    std::string name;
                    std::cin >> name;
                    actualWallet = new Wallet(name);
                    break;
                }
                case 2:
                    std::cout << "Au revoir !" << std::endl;
                    std::exit(0);   
                    break;
                default:
                    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
            }

        } else {
            choice = UtilsMethod::askUser({"Quel item voulez-vous manipuler?", "1. CIN", "2. Carte de crédit", "3. Permis de conduire", "4. Photo d'identité", "5. Argent", "6. Carte de visite", "7. Le portefeuille", "8. Quitter"});

            switch (choice) {
                case 1:
                    useCIN();
                    break;
                case 2:
                    useCreditCard();
                    break;
                case 3:
                    useDrivingLicense();
                    break;
                case 4:
                    useIdPhoto();
                    break;
                case 5:
                    useMoney();
                    break;
                case 6:
                    useVisitCard();
                    break;
                case 7:
                    useWallet();
                    break;
                case 8:
                    std::cout << "Au revoir !" << std::endl;
                    std::exit(0);
                    break;
                default:
                    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
            }

        }

        
    }
};

Wallet* Main::actualWallet = nullptr;
std::vector<Wallet*> Main::walletsLost;

int main() {
    Main::main();
    return 0;
}
