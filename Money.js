const MultipleItem = require("./MultipleItem");

class Money  extends MultipleItem {
    constructor(name, unity) {
        super(name, unity)
        this.quantity = 0;
    }

    add(quantityToAdd) {
        this.quantity += quantityToAdd;
        return this;
    }

    take(quantityToTake) {
        if (this.quantity >= quantityToTake) {
            this.quantity -= quantityToTake;
            return this;
        } else {
            console.log(`${this.name} n'a pas une quantité suffisante pour cette opération.`);
            return null;
        }
    }

    getQuantity() {
        return this.quantity;
    }

    getQuantityWithUnity() {
        return `${this.quantity} ${this.unity}`;
    }

    displayInfo() {
        console.log(`Informations de l'argent :`);
        console.log(`Nom : ${this.name}`);
        console.log(`Quantité : ${this.quantity} ${this.unity}`);
    }
}

module.exports = Money;
