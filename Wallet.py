from CIN import CIN;
from DrivingLicense import DrivingLicense;
from IdPhoto import IdPhoto;
from CreditCard import CreditCard;
from Money import Money;
from VisitCard import VisitCard;

from UtilsMethod import UtilsMethod
import uuid

class Wallet:
    def __init__(self, owner):
        self.id = str(uuid.uuid4())
        self.owner = owner
        self.is_lost = False
        self.cin = None
        self.credit_cards = []
        self.driving_license = None
        self.id_photo = None
        self.money = Money("money")
        self.visit_card = None

    @classmethod
    def from_user_input():
        print("Enter owner: ")
        owner = input()
        return Wallet(owner)

    def set_lost(self, lost):
        self.is_lost = lost

    def get_lost(self):
        return self.is_lost

    def set_cin(self, cin):
        self.cin = cin

    def set_credit_cards(self, credit_cards):
        self.credit_cards = credit_cards

    def set_driving_license(self, driving_license):
        self.driving_license = driving_license

    def set_id_photo(self, id_photo):
        self.id_photo = id_photo

    def set_money(self, money):
        self.money = money

    def set_visit_card(self, visit_card):
        self.visit_card = visit_card

    def get_cin(self):
        return self.cin

    def get_driving_license(self):
        return self.driving_license

    def get_id_photo(self):
        return self.id_photo

    def get_money(self):
        return self.money

    def get_credit_cards(self):
        return self.credit_cards

    def get_visit_card(self):
        return self.visit_card

    def print_wallet(self):
        # CIN
        print("-- CIN --")
        if self.cin is not None:
            print(str(self.cin))
        print()

        # Credit Cards
        print("-- creditCards --")
        if self.credit_cards:
            for credit_card in self.credit_cards:
                print(str(credit_card))
                print()
        print()

        # Driving License
        print("-- drivingLicense --")
        if self.driving_license is not None:
            print(str(self.driving_license))
        print()

        # IdPhoto
        print("-- idPhoto --")
        if self.id_photo is not None:
            print(str(self.id_photo))
        print()

        # Money
        print("-- money --")
        if self.money is not None:
            print(str(self.money))
        print()

        # VisitCard
        print("-- visitCard --")
        if self.visit_card is not None:
            print(str(self.visit_card))
        print()

        # Other members can be added similarly...
