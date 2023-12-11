from MultipleItem import MultipleItem
from UtilsMethod import UtilsMethod

class VisitCard(MultipleItem):
    def __init__(self, company_name, post, version, quantity, name):
        super().__init__(name, "unités", quantity)
        self.company_name = company_name
        self.post = post
        self.version = version

    @classmethod
    def from_user_input():
        print("Enter company name: ")
        company_name = input()
        print("Enter post: ")
        post = input()
        print("Enter version: ")
        version = input()
        print("Enter quantity: ")
        quantity = UtilsMethod.take_int_value_from_string(input())

        return VisitCard(company_name, post, version, quantity, "carte de visite")

    def __str__(self):
        return f"VisitCard{{companyName='{self.company_name}', post='{self.post}', " \
               f"version='{self.version}', quantity={self.get_quantity()}}}"
