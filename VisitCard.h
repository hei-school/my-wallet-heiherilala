// VisitCard.h
#ifndef VISITCARD_H
#define VISITCARD_H

#include <string>
#include "MultipleItem.h"

class VisitCard : public MultipleItem {
private:
    std::string companyName;
    std::string post;
    std::string version;

public:
    VisitCard(const std::string& companyName, const std::string& post, const std::string& version, int quantity, const std::string& name);

    VisitCard();

    std::string get_company_name() const;

    void set_company_name(const std::string& companyName);

    std::string get_post() const;

    void set_post(const std::string& post);

    std::string get_version() const;

    void set_version(const std::string& version);

    virtual std::string toString();
};

#endif // VISITCARD_H
