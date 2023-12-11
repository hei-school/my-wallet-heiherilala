const Item = require("./Item");

class MultipleItem extends Item {
    constructor(name, unity) {
        super(name);
        this.quantity = 0;
        this.unity = unity;
    }

    add(quantityToAdd) {
        this.quantity += quantityToAdd;
        return this;
    }

    take(quantityToTake) {
        if (this.quantity > quantityToTake) {
            this.quantity -= quantityToTake;
            return this;
        } else {
            console.log(`${this.getName()} does not have sufficient quantity for this transaction.`);
        }
        return null;
    }

    getQuantity() {
        return this.quantity;
    }

    getQuantityWithUnity() {
        return `${this.quantity} ${this.unity}`;
    }

    setQuantity(quantity) {
        this.quantity = quantity;
    }

    setUnity(unity) {
        this.unity = unity;
    }

    getUnity() {
        return this.unity;
    }
}

module.exports = MultipleItem;