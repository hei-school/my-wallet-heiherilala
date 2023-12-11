from datetime import date
from UniqueItem import UniqueItem
from UtilsMethod import UtilsMethod

class CIN(UniqueItem):

    def __init__(self, last_name, first_name, date_of_birth, place_of_birth, id_number, name):
        super().__init__(name)
        self.last_name = last_name
        self.first_name = first_name
        self.date_of_birth = date_of_birth
        self.place_of_birth = place_of_birth
        self.id_number = id_number

    @classmethod
    def from_user_input():
        print("Entrez le prénom : ")
        first_name = input()
        print("Entrez le nom : ")
        last_name = input()
        date_of_birth = UtilsMethod.ask_date(input)
        print("Entrez le lieu de naissance : ")
        place_of_birth = input()
        print("Entrez le numéro d'identité national : ")
        id_number = input()

        return CIN(last_name, first_name, date_of_birth, place_of_birth, id_number, "CIN")

    def __str__(self):
        return f"CIN{{lastName='{self.last_name}', firstName='{self.first_name}', " \
               f"dateOfBirth={self.date_of_birth}, placeOfBirth='{self.place_of_birth}', " \
               f"idNumber='{self.id_number}'}}"
