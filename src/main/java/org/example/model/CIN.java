package org.example.model;

import org.example.utils.UtilsMethod;

import java.time.LocalDate;
import java.util.Scanner;

public class CIN extends UniqueItem {

    // Attributes
    private String lastName;
    private String firstName;
    private LocalDate dateOfBirth;
    private String placeOfBirth;
    private String idNumber;

    private static UtilsMethod utilsMethod = new UtilsMethod();

    // Constructor
    public CIN(String lastName, String firstName, LocalDate dateOfBirth, String placeOfBirth, String idNumber, String name) {
        super(name);
        this.lastName = lastName;
        this.firstName = firstName;
        this.dateOfBirth = dateOfBirth;
        this.placeOfBirth = placeOfBirth;
        this.idNumber = idNumber;
    }

    public CIN(Scanner scanner) {
        super("CIN");
        System.out.println("Entrez le prénom : ");
        String firstName = scanner.next();
        System.out.println("Entrez le nom : ");
        String lastName = scanner.next();
        LocalDate dateOfBirth = utilsMethod.askDate(scanner);
        System.out.println("Entrez le lieu de naissance : ");
        String placeOfBirth = scanner.next();
        System.out.println("Entrez le numéro d'identité national : ");
        String idNumber = scanner.next();
        this.lastName = lastName;
        this.firstName = firstName;
        this.dateOfBirth = dateOfBirth;
        this.placeOfBirth = placeOfBirth;
        this.idNumber = idNumber;
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

    public LocalDate getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(LocalDate dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public String getPlaceOfBirth() {
        return placeOfBirth;
    }

    public void setPlaceOfBirth(String placeOfBirth) {
        this.placeOfBirth = placeOfBirth;
    }

    public String getIdNumber() {
        return idNumber;
    }

    public void setIdNumber(String idNumber) {
        this.idNumber = idNumber;
    }

    @Override
    public String toString() {
        return "CIN{" +
                "lastName='" + lastName + '\'' +
                ", firstName='" + firstName + '\'' +
                ", dateOfBirth=" + dateOfBirth +
                ", placeOfBirth='" + placeOfBirth + '\'' +
                ", idNumber='" + idNumber + '\'' +
                '}';
    }
}
