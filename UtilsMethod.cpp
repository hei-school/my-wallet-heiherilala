#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <ctime>

#include "MultipleItem.h"
#include "UniqueItem.h"
#include "UtilsMethod.h"
#include "UtilsDate.h"

    int UtilsMethod::askUser(const std::vector<std::string>& messages) {
        std::cout << "Choisissez une option : " << std::endl;
        for (const auto& message : messages) {
            std::cout << message << std::endl;
        }
        std::string choice;
        std::cin >> choice;
        while (UtilsDate::isNotConvertibleToNumber(choice))
        {
            std::cout << "Votre valeur n'est pas un nombre, donner une autre valeur" << std::endl;
            std::cin >> choice;
        }
        return std::stod(choice, 0);
    }

    void UtilsMethod::useUniqueItem(const UniqueItem* uniqueItem, std::function<void()> actualFunction, std::function<void(const std::string&)> createUniqueItemFunction) {
        if (uniqueItem == nullptr) {
            int choice = askUser({"1. Ajouter un item", "2. Revenir au menu principal"});

            switch (choice) {
                case 1:
                    createUniqueItemFunction("actualWallet");
                    break;
                case 2:
                    break;
                default:
                    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                    actualFunction();
                    break;
            }
        } else {
            int choice = askUser({"Quel événement s'est passé?", "1. Utilisé", "2. Revenir au menu principal"});

            switch (choice) {
                case 1:
                    uniqueItem->usedItem("");
                    break;
                case 2:
                    break;
                default:
                    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                    actualFunction();
                    break;
            }
        }
    }

    void UtilsMethod::useMultiItems(const MultipleItem* multipleItem, std::function<void()> actualFunction,
                       std::function<void(const std::string&)> createMultiItemFunction,
                       std::function<void(int)> useFunction, std::function<void(int)> addFunction) {
        if (multipleItem == nullptr) {
            int choice = askUser({"1. Ajouter un item", "2. Revenir au menu principal"});

            switch (choice) {
                case 1:
                    createMultiItemFunction("actualWallet");
                    break;
                case 2:
                    break;
                default:
                    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                    actualFunction();
                    break;
            }
        } else {
            int choice = askUser({"1. Utiliser", "2. Ajouter", "3. Consulter la quantité actuelle", "4. Revenir au menu principal"});

            switch (choice) {
                case 1:{
                    std::string quantityUsed;
                    std::cout << "Combien voulez-vous utiliser? ";
                    std::cin >> quantityUsed;
                    while (UtilsDate::isNotConvertibleToNumber(quantityUsed))
                    {
                        std::cout << "Valeur invalide. Combien voulez-vous utiliser? ";
                        std::cin >> quantityUsed;
                    }
                    if (multipleItem->get_quantity() < std::stod(quantityUsed)) {
                        std::cout << "Vous n'avez pas la quantité suffisante" << std::endl;
                    } else {
                        useFunction(std::stod(quantityUsed));
                        std::cout << "Opération réussie" << std::endl;
                        std::cout << "Votre compte est de " << (multipleItem->get_quantity() - std::stod(quantityUsed)) << " " << multipleItem->get_unity() << std::endl;
                    }
                    break;
                }
                case 2:{
                    std::string quantityToAdd;
                    std::cout << "Combien voulez-vous ajouter? ";
                    std::cin >> quantityToAdd;
                    while (UtilsDate::isNotConvertibleToNumber(quantityToAdd))
                    {
                        std::cout << "Valeur invalide. Combien voulez-vous ajouter? ";
                        std::cin >> quantityToAdd;
                    }
                    addFunction(std::stod(quantityToAdd));
                    std::cout << "Opération réussie" << std::endl;
                    std::cout << "Votre compte est de " << (multipleItem->get_quantity() + std::stod(quantityToAdd)) << " " << multipleItem->get_unity() << std::endl;
                    break;
                }
                case 3:
                    std::cout << "Votre compte est de " << multipleItem->get_quantity_with_unity() << std::endl;
                    break;
                case 4:
                    break;
                default:
                    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                    actualFunction();
                    break;
            }
        }
    }