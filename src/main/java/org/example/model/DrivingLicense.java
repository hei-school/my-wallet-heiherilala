package org.example.model;

import org.example.utils.UtilsMethod;

import java.time.LocalDate;
import java.util.Scanner;

public class DrivingLicense extends UniqueItem {

    // Attributes
    private String lastName;
    private String firstName;
    private LocalDate expirationDate;

    private static UtilsMethod utilsMethod = new UtilsMethod();

    // Constructor
    public DrivingLicense(String lastName, String firstName, LocalDate expirationDate, String name) {
        super(name);
        this.lastName = lastName;
        this.firstName = firstName;
        this.expirationDate = expirationDate;
    }

    public DrivingLicense(Scanner scanner) {
        super("permis de conduire");
        System.out.println("Enter last name: ");
        String lastName = scanner.next();
        System.out.println("Enter first name: ");
        String firstName = scanner.next();
        System.out.println("Enter expiration date: ");
        LocalDate expirationDate = utilsMethod.askDate(scanner);

        // Assuming 'name' is the name of the driving license
        this.lastName = lastName;
        this.firstName = firstName;
        this.expirationDate = expirationDate;
    }

    // Accessor methods (getters and setters)
    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public LocalDate getExpirationDate() {
        return expirationDate;
    }

    public void setExpirationDate(LocalDate expirationDate) {
        this.expirationDate = expirationDate;
    }

    // Other methods if needed

    @Override
    public String toString() {
        return "DrivingLicense{" +
                "lastName='" + lastName + '\'' +
                ", firstName='" + firstName + '\'' +
                ", expirationDate=" + expirationDate +
                '}';
    }

    // You can add other methods or functionalities as needed.
}
