package org.example.model;

import org.example.utils.UtilsMethod;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.UUID;

public class Wallet {
    private String id;
    private String owner;
    private Boolean isLost;
    private CIN cin;
    private List<CreditCard> creditCards;
    private DrivingLicense drivingLicense;
    private IdPhoto idPhoto;
    private Money money;
    private VisitCard visitCard;

    private static UtilsMethod utilsMethod = new UtilsMethod();

    public void setLost(Boolean lost) {
        isLost = lost;
    }

    public Boolean getLost() {
        return isLost;
    }

    public Wallet(String owner) {
        this.owner = owner;
        this.creditCards = new ArrayList<>();
        this.id = UUID.randomUUID().toString();
        this.isLost = false;
        this.money = new Money("money");
    }

    public Wallet(Scanner scanner) {
        System.out.println("Enter owner: ");
        this.owner = scanner.next();
        this.creditCards = new ArrayList<>();
        this.id = UUID.randomUUID().toString();
        this.isLost = false;
        this.money = new Money("money");
    }

    public void setCin(CIN cin) {
        this.cin = cin;
    }

    public void setCreditCards(List<CreditCard> creditCards) {
        this.creditCards = creditCards;
    }

    public void setDrivingLicense(DrivingLicense drivingLicense) {
        this.drivingLicense = drivingLicense;
    }

    public void setIdPhoto(IdPhoto idPhoto) {
        this.idPhoto = idPhoto;
    }

    public void setMoney(Money money) {
        this.money = money;
    }

    public void setVisitCard(VisitCard visitCard) {
        this.visitCard = visitCard;
    }

    public CIN getCin() {
        return cin;
    }

    public DrivingLicense getDrivingLicense() {
        return drivingLicense;
    }

    public IdPhoto getIdPhoto() {
        return idPhoto;
    }

    public Money getMoney() {
        return money;
    }

    public List<CreditCard> getCreditCards() {
        return creditCards;
    }

    public VisitCard getVisitCard() {
        return visitCard;
    }

    public void printWallet() {
        // CIN
        System.out.println("-- CIN " + '\'');
        if (cin != null) {
            System.out.println(cin.toString() + '\'');
        }
        System.out.println('\'');

        // Credit Cards
        System.out.println("-- creditCards " + '\'');
        if (!creditCards.isEmpty()) {
            for (CreditCard creditCard : creditCards) {
                System.out.println(creditCard.toString() + '\'');
                System.out.println('\'');
            }
        }
        System.out.println('\'');

        // Driving License
        System.out.println("-- drivingLicense " + '\'');
        if (drivingLicense != null) {
            System.out.println(drivingLicense.toString() + '\'');
        }
        System.out.println('\'');

        // IdPhoto
        System.out.println("-- idPhoto " + '\'');
        if (idPhoto != null) {
            System.out.println(idPhoto.toString() + '\'');
        }
        System.out.println('\'');

        // Money
        System.out.println("-- money " + '\'');
        if (money != null) {
            System.out.println(money.toString() + '\'');
        }
        System.out.println('\'');

        // VisitCard
        System.out.println("-- visitCard " + '\'');
        if (visitCard != null) {
            System.out.println(visitCard.toString() + '\'');
        }
        System.out.println('\'');

        // Other members can be added similarly...
    }
}
