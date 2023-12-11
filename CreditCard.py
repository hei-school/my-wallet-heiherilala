from datetime import date
from UniqueItem import UniqueItem
from UtilsMethod import UtilsMethod

class CreditCard(UniqueItem):

    def __init__(self, bank, card_type, expiration_date, owner_name, name):
        super().__init__(name)
        self.bank = bank
        self.card_type = card_type
        self.expiration_date = expiration_date
        self.owner_name = owner_name

    @classmethod
    def from_user_input():
        print("Enter bank: ")
        bank = input()
        print("Enter card type: ")
        card_type = input()
        print("Enter expiration date: ")
        expiration_date = UtilsMethod.ask_date(input)
        print("Enter owner name: ")
        owner_name = input()

        return CreditCard(bank, card_type, expiration_date, owner_name, "CreditCard")

    def __str__(self):
        return f"CreditCard{{bank='{self.bank}', cardType='{self.card_type}', " \
               f"expirationDate={self.expiration_date}, ownerName='{self.owner_name}'}}"

