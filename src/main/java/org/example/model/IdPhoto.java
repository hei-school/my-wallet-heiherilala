package org.example.model;

public class IdPhoto extends UniqueItem {

    public IdPhoto(String newName) {
        super(newName);
    }

    @Override
    public String toString() {
        return "IdPhoto{" +
                "name='" + getName() + '\'' +
                '}';
    }
}
