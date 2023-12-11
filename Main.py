from CIN import CIN;
from UtilsMethod import UtilsMethod;
from Wallet import Wallet;
from DrivingLicense import DrivingLicense;
from IdPhoto import IdPhoto;
from CreditCard import CreditCard;
from Money import Money;
from VisitCard import VisitCard;


actual_wallet = Wallet("Me")
wallets_lost = []


def main():
    while True:
        principal_menu()


def principal_menu():
    global actual_wallet
    choice = 0

    if actual_wallet is None:
        choice = UtilsMethod.ask_user([
            "Vous n'avez pas de portefeuille à votre possession",
            "1. Acheter",
            "2. Quitter"
        ])

        if choice == 1:
            print("Entrez le surnom de votre portefeuille : ")
            name = input()
            actual_wallet = Wallet(name)
        elif choice == 2:
            print("Au revoir !")
            exit(0)
        else:
            print("Choix invalide. Veuillez réessayer.")
    else:
        choice = UtilsMethod.ask_user([
            "Quel item voulez-vous manipuler?",
            "1. CIN",
            "2. Carte de crédit",
            "3. Permis de conduire",
            "4. Photo d'identité",
            "5. Argent",
            "6. Carte de visite",
            "7. Le portefeuille",
            "8. Quitter"
        ])

        if choice == 1:
            use_cin()
        elif choice == 2:
            use_credit_card()
        elif choice == 3:
            use_driving_license()
        elif choice == 4:
            use_id_photo()
        elif choice == 5:
            use_money()
        elif choice == 6:
            use_visit_card()
        elif choice == 7:
            use_wallet()
        elif choice == 8:
            print("Au revoir !")
            exit(0)
        else:
            print("Choix invalide. Veuillez réessayer.")


def use_wallet():
    global actual_wallet
    choice = UtilsMethod.ask_user([
        "Quel événement s'est-il passé?",
        "1. Vous avez perdu votre portefeuille",
        "2. Regardé ce qu'il y a dans le portefeuille.",
        "3. Revenir au menu principal"
    ])

    if choice == 1:
        actual_wallet.set_lost(True)
        wallets_lost.append(actual_wallet)
        actual_wallet = None
    elif choice == 2:
        actual_wallet.print_wallet()
    elif choice == 3:
        pass
    else:
        print("Choix invalide. Veuillez réessayer.")


def use_cin():
    global actual_wallet
    UtilsMethod.use_unique_item(actual_wallet.get_cin(), use_cin, lambda s: actual_wallet.set_cin(CIN.from_user_input()))


def use_credit_card():
    global actual_wallet
    choice = UtilsMethod.ask_user([
        "1. Ajouter une carte de crédit",
        "2. Utiliser les cartes de crédit existantes",
        "3. Retour au menu principal"
    ])

    if choice == 1:
        credit_cards = actual_wallet.get_credit_cards()
        credit_cards.append(CreditCard(input))
        actual_wallet.set_credit_cards(credit_cards)
    elif choice == 2:
        if not actual_wallet.get_credit_cards():
            print("Vous ne possédez pas de cartes de crédit.")
        else:
            messages = ["Choisissez la carte à utiliser :"]
            for credit_card in actual_wallet.get_credit_cards():
                messages.append(str(actual_wallet.get_credit_cards().index(credit_card)) + ". " + credit_card.get_name())

            choice2 = UtilsMethod.ask_user(messages)
            if actual_wallet.get_credit_cards().__len__() > choice2:
                UtilsMethod.use_unique_item(actual_wallet.get_credit_cards()[choice2], use_credit_card, None)
            else:
                print("Choix invalide. Veuillez réessayer.")
                use_credit_card()
    elif choice == 3:
        pass
    else:
        print("Choix invalide. Veuillez réessayer.")
        use_credit_card()


def use_driving_license():
    global actual_wallet
    UtilsMethod.use_unique_item(actual_wallet.get_driving_license(), use_driving_license, lambda s: actual_wallet.set_driving_license(DrivingLicense(input)))


def use_id_photo():
    global actual_wallet
    UtilsMethod.use_unique_item(actual_wallet.get_id_photo(), use_id_photo, lambda s: actual_wallet.set_id_photo(IdPhoto("ma photo")))


def use_money():
    global actual_wallet
    UtilsMethod.use_multi_items(
        actual_wallet.get_money(),
        use_money,
        lambda s: actual_wallet.set_money(Money(s)),
        lambda integer: actual_wallet.get_money().take(integer),
        lambda integer: actual_wallet.get_money().add(integer)
    )


def use_visit_card():
    global actual_wallet
    UtilsMethod.use_multi_items(
        actual_wallet.get_visit_card(),
        use_visit_card,
        lambda s: actual_wallet.set_visit_card(VisitCard(input)),
        lambda integer: actual_wallet.get_visit_card().take(integer),
        lambda integer: actual_wallet.get_visit_card().add(integer)
    )


if __name__ == "__main__":
    main()
