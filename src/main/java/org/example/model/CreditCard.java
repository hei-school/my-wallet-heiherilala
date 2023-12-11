package org.example.model;

import org.example.utils.UtilsMethod;

import java.time.LocalDate;
import java.util.Scanner;

public class CreditCard extends UniqueItem {

    // Attributes
    private String bank;
    private String cardType;
    private LocalDate expirationDate;
    private String ownerName;

    private static UtilsMethod utilsMethod = new UtilsMethod();

    // Constructor
    public CreditCard(String bank, String cardType, LocalDate expirationDate, String ownerName, String name) {
        super(name);
        this.bank = bank;
        this.cardType = cardType;
        this.expirationDate = expirationDate;
        this.ownerName = ownerName;
    }

    public CreditCard(Scanner scanner) {
        super("carte de crédit");

        System.out.println("Enter bank: ");
        String bank = scanner.next();
        System.out.println("Enter card type: ");
        String cardType = scanner.next();
        System.out.println("Enter expiration date: ");
        LocalDate expirationDate = utilsMethod.askDate(scanner);
        System.out.println("Enter owner name: ");
        String ownerName = scanner.next();

        this.bank = bank;
        this.cardType = cardType;
        this.expirationDate = expirationDate;
        this.ownerName = ownerName;
    }

    // Accessor methods (getters and setters)
    public String getBank() {
        return bank;
    }

    public void setBank(String bank) {
        this.bank = bank;
    }

    public String getCardType() {
        return cardType;
    }

    public void setCardType(String cardType) {
        this.cardType = cardType;
    }

    public LocalDate getExpirationDate() {
        return expirationDate;
    }

    public void setExpirationDate(LocalDate expirationDate) {
        this.expirationDate = expirationDate;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    // Other methods if needed

    @Override
    public String toString() {
        return "CreditCard{" +
                "bank='" + bank + '\'' +
                ", cardType='" + cardType + '\'' +
                ", expirationDate=" + expirationDate +
                ", ownerName='" + ownerName + '\'' +
                '}';
    }

    // You can add other methods or functionalities as needed.
}
