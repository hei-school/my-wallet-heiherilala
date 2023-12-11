from datetime import date
from typing import List, Callable

class UtilsMethod:
    @staticmethod
    def ask_user(messages: List[str]) -> int:
        for message in messages:
            print(message)
        return UtilsMethod.take_int_value_from_string(input())

    def ask_date(self) -> date:
        print("Année")
        year = UtilsMethod.take_int_value_from_string(input())
        while year < 0:
            print("Année invalide, réécrire l'année")
            year = UtilsMethod.take_int_value_from_string(input())

        print("Mois")
        month = UtilsMethod.take_int_value_from_string(input())
        while month < 0 or month > 12:
            print("Mois invalide, réécrire le mois")
            month = UtilsMethod.take_int_value_from_string(input())

        print("Jour")
        day = UtilsMethod.take_int_value_from_string(input())
        while day < 0 or day > 28:
            print("Jour invalide, réécrire le jour")
            day = UtilsMethod.take_int_value_from_string(input())

        return date(year, month, day)

    @staticmethod
    def use_unique_item(unique_item, actual_function: Callable, create_unique_item_function: Callable):
        if unique_item is None:
            choice = UtilsMethod.ask_user([
                "1. Ajouter un item",
                "2. Revenir au menu principal"
            ])

            if choice == 1:
                create_unique_item_function("actualWallet")
            elif choice ==2:
                print("revenir")
            else:
                actual_function()
        else:
            choice = UtilsMethod.ask_user([
                "Quel événement s'est passé?",
                "1. Utilisé",
                "2. Revenir au menu principal"
            ])

            if choice == 1:
                unique_item.used_item(unique_item.__str__())
            elif choice ==2:
                print("revenir")
            else:
                actual_function()

    def use_multi_items(
        multiple_item,
        actual_function: Callable,
        create_multi_item_function: Callable,
        use_function: Callable,
        add_function: Callable
    ):
        if multiple_item is None:
            choice = UtilsMethod.ask_user([
                "1. Ajouter un item",
                "2. Revenir au menu principal"
            ])

            if choice == 1:
                create_multi_item_function("actualWallet")

        else:
            choice = UtilsMethod.ask_user([
                "1. Utiliser",
                "2. Ajouter",
                "3. Consulter la quantité actuelle",
                "4. Revenir au menu principal"
            ])

            if choice == 1:
                print("Combien voulez-vous utiliser?")
                quantity_used = UtilsMethod.take_int_value_from_string(input())
                if multiple_item.get_quantity() < quantity_used:
                    print("Vous n'avez pas la quantité suffisante")
                else:
                    use_function(quantity_used)
                    print("Opération réussie")
                    print("Votre compte est de")
                    print(f"{multiple_item.get_quantity() - quantity_used} {multiple_item.get_unity()}")

            elif choice == 2:
                print("Combien voulez-vous ajouter?")
                quantity_to_add = UtilsMethod.take_int_value_from_string(input())
                add_function(quantity_to_add)
                print("Opération réussie")
                print("Votre compte est de")
                print(f"{multiple_item.get_quantity() + quantity_to_add} {multiple_item.get_unity()}")

            elif choice == 3:
                print("Votre compte est de")
                print(multiple_item.get_quantity_with_unity())

    @staticmethod
    def is_not_convertible_to_number(string_value: str) -> bool:
        try:
            number = int(string_value)
            return number <= 0
        except ValueError:
            return True

    @staticmethod
    def take_int_value_from_string(string_value: str) -> int:
        value = string_value
        is_valid = not UtilsMethod.is_not_convertible_to_number(value)
        while not is_valid:
            print("Entrée invalide, veuillez entrer une nouvelle valeur.")
            value = input()
            is_valid = not UtilsMethod.is_not_convertible_to_number(value) and int(value) >= 0
        return int(value)

    def __init__(self):
        pass
