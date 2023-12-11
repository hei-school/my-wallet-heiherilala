const Item = require("./Item");

class UniqueItem extends Item {
    constructor(name) {
        super(name);
        this.isLost = false;
    }

    setLost(lost) {
        this.isLost = lost;
    }

    getLost() {
        return this.isLost;
    }

    usedItem(message) {
        if (this.isLost) {
            console.log("Cet item est perdu, donc tu ne peux pas l'utiliser");
            return null;
        }
        console.log(`${this.getName()} a été utilisé. '${message}'`);
        return null;
    }
}

module.exports = UniqueItem;