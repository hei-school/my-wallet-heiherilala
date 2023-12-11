package org.example.model;

public class UniqueItem extends Item {
    private Boolean isLost;

    public void setLost(Boolean lost) {
        isLost = lost;
    }

    public Boolean getLost() {
        return isLost;
    }

    public Void usedItem(String message) {
        if (isLost == true) {
            System.out.println("Cet item est perdu, donc tu ne peux pas l'utiliser");
            return null;
        }
        System.out.println(this.getName() + " a été utilisé. '" + message + "'");
        return null;
    }

    public UniqueItem(String name) {
        super(name);
    }
}
