package org.example.utils;

import org.example.model.MultipleItem;
import org.example.model.UniqueItem;

import java.time.LocalDate;
import java.util.List;
import java.util.Scanner;
import java.util.function.Consumer;

public class UtilsMethod {

    public int askUser(List<String> messages) {
        Scanner scanner = new Scanner(System.in);
        for (String message : messages) {
            System.out.println(message);
        }
        int choice = takeIntValueFromString(scanner.next(),scanner);
        return choice;
    }
;
    public LocalDate askDate(Scanner scanner) {
        System.out.println("Année ");
        int year = takeIntValueFromString(scanner.next(), scanner);
        while (year < 0) {
            System.out.println("Année invalide, réécrire l'année");
            year = takeIntValueFromString(scanner.next(), scanner);
        }
        System.out.println("Mois");
        int month = takeIntValueFromString(scanner.next(), scanner);
        while (month < 0 || month > 12) {
            System.out.println("Mois invalide, réécrire le mois");
            month = takeIntValueFromString(scanner.next(), scanner);
        }
        System.out.println("Jour");
        int day = takeIntValueFromString(scanner.next(), scanner);
        while (day < 0 || day > 28) {
            System.out.println("Jour invalide, réécrire le jour");
            day = takeIntValueFromString(scanner.next(), scanner);
        }
        return LocalDate.of(year, month, day);
    }

    public Void useUniqueItem(Scanner scanner, UniqueItem uniqueItem, Consumer<Scanner> actualFunction, Consumer<String> createUniqueItemFunction) {
        if (uniqueItem == null) {
            int choice = askUser(List.of(
                    "1. Ajouter un item",
                    "2. Revenir au menu principal"
            ));

            switch (choice) {
                case 1:
                    createUniqueItemFunction.accept("actualWallet");
                    break;
                case 2:
                    break;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
                    actualFunction.accept(scanner);
                    break;
            }
        } else {
            int choice = askUser(List.of(
                    "Quel événement s'est passé?",
                    "1. Utilisé",
                    "2. Revenir au menu principal"
            ));

            switch (choice) {
                case 1:
                    uniqueItem.usedItem(uniqueItem.toString());
                    break;
                case 2:
                    break;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
                    actualFunction.accept(scanner);
                    break;
            }
        }
        return null;
    }

    public Void useMultiItems(Scanner scanner, MultipleItem multipleItem, Consumer<Scanner> actualFunction, Consumer<String> createMultiItemFunction, Consumer<Integer> useFunction, Consumer<Integer> addFunction) {
        if (multipleItem == null) {
            int choice = askUser(List.of(
                    "1. Ajouter un item",
                    "2. Revenir au menu principal"
            ));

            switch (choice) {
                case 1:
                    createMultiItemFunction.accept("actualWallet");
                    break;
                case 2:
                    break;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
                    actualFunction.accept(scanner);
                    break;
            }
        } else {
            int choice = askUser(List.of(
                    "1. Utiliser",
                    "2. Ajouter",
                    "3. Consulter la quantité actuelle",
                    "4. Revenir au menu principal"
            ));

            switch (choice) {
                case 1:
                    System.out.println("Combien voulez-vous utiliser?");
                    int quantityUsed = takeIntValueFromString(scanner.next(), scanner);
                    if (multipleItem.getQuantity() < quantityUsed) {
                        System.out.println("Vous n'avez pas la quantité suffisante");
                    } else {
                        useFunction.accept(quantityUsed);
                        System.out.println("Opération réussie");
                        System.out.println("Votre compte est de");
                        System.out.println((multipleItem.getQuantity() - quantityUsed) + " " + multipleItem.getUnity());
                    }
                    break;
                case 2:
                    System.out.println("Combien voulez-vous ajouter?");
                    int quantityToAdd = takeIntValueFromString(scanner.next(), scanner);
                    addFunction.accept(quantityToAdd);
                    System.out.println("Opération réussie");
                    System.out.println("Votre compte est de");
                    System.out.println((multipleItem.getQuantity() + quantityToAdd) + " " + multipleItem.getUnity());
                    break;
                case 3:
                    System.out.println("Votre compte est de");
                    System.out.println(multipleItem.getQuantityWithUnity());
                    break;
                case 4:
                    break;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
                    actualFunction.accept(scanner);
                    break;
            }
        }
        return null;
    }

    public static boolean isNotConvertibleToNumber(String str) {
        try {
            double number = Integer.parseInt(str);
            return number <= 0;
        } catch (NumberFormatException e) {
            return true;
        }
    }

    public static int takeIntValueFromString(String str, Scanner scanner) {
        String value = str;
        boolean isValid;
        do {
            if (isNotConvertibleToNumber(value)) {
                isValid = false;
            }else {
                isValid = Integer.parseInt(value) >= 0;
            }
            if (!isValid) {
                System.out.println("Entrée invalide, veuillez entrer une nouvelle valeur.");
                value = scanner.next();
            }
        } while (!isValid);
        return Integer.parseInt(value);
    }

    public UtilsMethod() {
    }
}
