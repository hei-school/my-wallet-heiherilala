package org.example.model;

public class Money extends MultipleItem {

    public Money(String newName) {
        super(newName, "$");
    }

    @Override
    public String toString() {
        return "Argent{"+ ", Argent=" + getQuantity() + " " + getUnity() + '\'' + '}';
    }
}

