package org.example.model;

public class MultipleItem extends Item {
    private int quantity;
    private String unity;

    public MultipleItem add(int quantityToAdd) {
        this.quantity += quantityToAdd;
        return this;
    }

    public MultipleItem take(int quantityToTake) {
        if (this.quantity > quantityToTake) {
            this.quantity -= quantityToTake;
            return this;
        } else {
            System.out.println(super.getName() + " does not have sufficient quantity for this transaction.");
        }
        return null;
    }

    public int getQuantity() {
        return quantity;
    }

    public String getQuantityWithUnity() {
        return quantity + " " + unity;
    }

    public MultipleItem(String newName, String unity) {
        super(newName);
        this.unity = unity;
        this.quantity = 0;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public MultipleItem(String newName, int quantity) {
        super(newName);
        this.quantity = quantity;
    }

    public void setUnity(String unity) {
        this.unity = unity;
    }

    public String getUnity() {
        return unity;
    }
}
