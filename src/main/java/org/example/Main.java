package org.example;

import org.example.model.*;
import org.example.utils.UtilsMethod;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private final static UtilsMethod utilsMethod = new UtilsMethod();
    private static Wallet actualWallet = new Wallet("Me");
    private static List<Wallet> walletsLost = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            principalMenu(scanner);
        }
    }

    public static void principalMenu(Scanner scanner) {
        int choice = 0;

        if (actualWallet == null) {
            choice = utilsMethod.askUser(List.of(
                    "Vous n'avez pas de portefeuille à votre possession",
                    "1. Acheter",
                    "2. Quitter"
            ));
            switch (choice) {
                case 1:
                    System.out.println("Entrez le surnom de votre portefeuille : ");
                    String name = scanner.next();
                    actualWallet = new Wallet(name);
                    break;
                case 2:
                    System.out.println("Au revoir !");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
            }
        } else {
            choice = utilsMethod.askUser(List.of(
                    "Quel item voulez-vous manipuler?",
                    "1. CIN",
                    "2. Carte de crédit",
                    "3. Permis de conduire",
                    "4. Photo d'identité",
                    "5. Argent",
                    "6. Carte de visite",
                    "7. Le portefeuille",
                    "8. Quitter"
            ));
            switch (choice) {
                case 1:
                    useCIN(scanner);
                    break;
                case 2:
                    useCreditCard(scanner);
                    break;
                case 3:
                    useDrivingLicense(scanner);
                    break;
                case 4:
                    useIdPhoto(scanner);
                    break;
                case 5:
                    useMoney(scanner);
                    break;
                case 6:
                    useVisitCard(scanner);
                    break;
                case 7:
                    useWallet(scanner);
                    break;
                case 8:
                    System.out.println("Au revoir !");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
            }
        }
    }

    // Autres méthodes...

    public static void useWallet(Scanner scanner) {
        int choice = utilsMethod.askUser(List.of(
                "Quel événement s'est-il passé?",
                "1. Vous avez perdu votre portefeuille",
                "2. Regardé ce qu'il y a dans le portefeuille.",
                "3. Revenir au menu principal"
        ));

        switch (choice) {
            case 1:
                actualWallet.setLost(true);
                walletsLost.add(actualWallet);
                actualWallet = null;
                break;
            case 2:
                actualWallet.printWallet();
                break;
            case 3:
                break;
            default:
                System.out.println("Choix invalide. Veuillez réessayer.");
                useWallet(scanner);
                break;
        }
    }

    public static void useCIN(Scanner scanner) {
        utilsMethod.useUniqueItem(scanner, actualWallet.getCin(), scanner1 -> useCIN(scanner1), s -> actualWallet.setCin(new CIN(scanner)));
    }

    // Méthode pour la carte de crédit
    public static void useCreditCard(Scanner scanner) {
        int choice = utilsMethod.askUser(List.of(
                "1. Ajouter une carte de crédit",
                "2. Utiliser les cartes de crédit existantes",
                "3. Retour au menu principal"
        ));

        switch (choice) {
            case 1:
                List<CreditCard> creditCards = actualWallet.getCreditCards();
                creditCards.add(new CreditCard(scanner));
                actualWallet.setCreditCards(creditCards);
                break;
            case 2:
                if (actualWallet.getCreditCards().isEmpty()) {
                    System.out.println("Vous ne possédez pas de cartes de crédit.");
                    break;
                }
                List<String> messages = new ArrayList<>();

                messages.add("Choisissez la carte à utiliser :");
                for (CreditCard creditCard : actualWallet.getCreditCards()) {
                    messages.add("" + actualWallet.getCreditCards().indexOf(creditCard) + ". " + creditCard.getName());
                }
                int choice2 = utilsMethod.askUser(messages);
                if (actualWallet.getCreditCards().size() > choice2) {
                    utilsMethod.useUniqueItem(scanner, actualWallet.getCreditCards().get(choice2), scanner1 -> useCreditCard(scanner1), null);
                } else {
                    System.out.println("Choix invalide. Veuillez réessayer.");
                    useCreditCard(scanner);
                }
                break;
            case 3:
                break;
            default:
                System.out.println("Choix invalide. Veuillez réessayer.");
                useCreditCard(scanner);
                break;
        }
    }

    // Méthode pour le permis de conduire
    public static void useDrivingLicense(Scanner scanner) {
        utilsMethod.useUniqueItem(scanner, actualWallet.getDrivingLicense(), scanner1 -> useDrivingLicense(scanner1), s -> actualWallet.setDrivingLicense(new DrivingLicense(scanner)));
    }

    // Méthode pour la photo d'identité
    public static void useIdPhoto(Scanner scanner) {
        utilsMethod.useUniqueItem(scanner, actualWallet.getIdPhoto(), scanner1 -> useIdPhoto(scanner1), s -> actualWallet.setIdPhoto(new IdPhoto("ma photo")));
    }

    // Méthode pour l'argent
    public static void useMoney(Scanner scanner) {
        utilsMethod.useMultiItems(scanner, actualWallet.getMoney(), scanner1 -> useMoney(scanner1), s -> actualWallet.setMoney(new Money(s)),
                integer -> {
                    Money money = actualWallet.getMoney();
                    money.take(integer);
                    actualWallet.setMoney(money);
                }, integer -> {
                    Money money = actualWallet.getMoney();
                    money.add(integer);
                    actualWallet.setMoney(money);
                });
    }

    // Méthode pour la carte de visite
    public static void useVisitCard(Scanner scanner) {
        utilsMethod.useMultiItems(scanner, actualWallet.getVisitCard(), scanner1 -> useVisitCard(scanner1), s -> actualWallet.setVisitCard(new VisitCard(scanner)),
                integer -> {
                    VisitCard visitCard = actualWallet.getVisitCard();
                    visitCard.take(integer);
                    actualWallet.setVisitCard(visitCard);
                }, integer -> {
                    VisitCard visitCard = actualWallet.getVisitCard();
                    visitCard.add(integer);
                    actualWallet.setVisitCard(visitCard);
                });
    }




}
