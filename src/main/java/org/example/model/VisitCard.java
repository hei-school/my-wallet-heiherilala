package org.example.model;

import org.example.utils.UtilsMethod;

import java.util.Scanner;

import static org.example.utils.UtilsMethod.takeIntValueFromString;

public class VisitCard extends MultipleItem {

    // Attributes
    private String companyName;
    private String post;
    private String version;

    private static UtilsMethod utilsMethod = new UtilsMethod();

    // Constructor
    public VisitCard(String companyName, String post, String version, int quantity, String name) {
        super(name, quantity);
        this.companyName = companyName;
        this.post = post;
        this.version = version;
    }

    public VisitCard(Scanner scanner) {
        super("carte de visite", "unités");
        System.out.println("Enter company name: ");
        this.companyName = scanner.next();
        System.out.println("Enter post: ");
        this.post = scanner.next();
        System.out.println("Enter version: ");
        this.version = scanner.next();
        System.out.println("Enter quantity: ");
        super.setQuantity(takeIntValueFromString(scanner.next(), scanner));
    }

    // Accessor methods (getters and setters)
    public String getCompanyName() {
        return companyName;
    }

    public void setCompanyName(String companyName) {
        this.companyName = companyName;
    }

    public String getPost() {
        return post;
    }

    public void setPost(String post) {
        this.post = post;
    }

    public String getVersion() {
        return version;
    }

    public void setVersion(String version) {
        this.version = version;
    }

    // Other methods if needed

    @Override
    public String toString() {
        return "VisitCard{" +
                "companyName='" + companyName + '\'' +
                ", post='" + post + '\'' +
                ", version='" + version + '\'' +
                '}';
    }

    // You can add other methods or functionalities as needed.
}
