const UniqueItem = require("./UniqueItem");

class IdPhoto  extends UniqueItem{
    constructor(name) {
        super(name);
    }

    displayInfo() {
        console.log(`Informations de la photo d'identité :`);
        console.log(`Nom : ${this.name}`);
    }
}

module.exports = IdPhoto;