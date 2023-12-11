from datetime import date
from UniqueItem import UniqueItem
from UtilsMethod import UtilsMethod

class DrivingLicense(UniqueItem):
    def __init__(self, last_name, first_name, expiration_date, name):
        super().__init__(name)
        self.last_name = last_name
        self.first_name = first_name
        self.expiration_date = expiration_date

    @classmethod
    def from_user_input():
        print("Enter last name: ")
        last_name = input()
        print("Enter first name: ")
        first_name = input()
        print("Enter expiration date: ")
        expiration_date = UtilsMethod.ask_date(input)

        # Assuming 'name' is the name of the driving license
        return DrivingLicense(last_name, first_name, expiration_date, "DrivingLicense")

    def __str__(self):
        return f"DrivingLicense{{lastName='{self.last_name}', firstName='{self.first_name}', " \
               f"expirationDate={self.expiration_date}}}"

