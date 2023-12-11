#include <iostream>
#include <string>
#include "MultipleItem.h"
#include "VisitCard.h"

    VisitCard::VisitCard(const std::string& companyName, const std::string& post, const std::string& version, int quantity, const std::string& name)
        : MultipleItem(name, "unités"), companyName(companyName), post(post), version(version) {
        set_quantity(quantity);
    }

    VisitCard::VisitCard() : MultipleItem("carte de visite", "unités") {
        std::cout << "Entrez le nom de l'entreprise : ";
        std::cin >> companyName;
        std::cout << "Entrez le poste : ";
        std::cin >> post;
        std::cout << "Entrez la version : ";
        std::cin >> version;
        std::cout << "Entrez la quantité : ";
        int quantity;
        std::cin >> quantity;
        set_quantity(quantity);
    }

    std::string VisitCard::get_company_name() const {
        return companyName;
    }

    void VisitCard::set_company_name(const std::string& companyName) {
        this->companyName = companyName;
    }

    std::string VisitCard::get_post() const {
        return post;
    }

    void VisitCard::set_post(const std::string& post) {
        this->post = post;
    }

    std::string VisitCard::get_version() const {
        return version;
    }

    void VisitCard::set_version(const std::string& version) {
        this->version = version;
    }

    std::string VisitCard::toString() {
        std::string result = "VisitCard{companyName='" + companyName + '\'' + ", post='" + post + '\'' + ", version='" + version + '\'' +", quantity=" + std::to_string(get_quantity()) +'}';
        return result;
    }