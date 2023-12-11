const UniqueItem = require('./UniqueItem');

const prompt = require('prompt-sync')();
class DrivingLicense  extends UniqueItem {
    constructor(lastName, firstName, expirationDate) {
        super("CreditCard");
        this.lastName = lastName;
        this.firstName = firstName;
        this.expirationDate = expirationDate;
    }

    static createDrivingLicense() {
        const lastName = prompt('Entrez le nom sur le permis de conduire : ');
        const firstName = prompt('Entrez le prénom sur le permis de conduire : ');
        const expirationDate = prompt('Entrez la date d\'expiration du permis de conduire (MM/YYYY) : ');

        // Vous pouvez ajouter une logique de validation pour la date d'expiration si nécessaire

        return new DrivingLicense(lastName, firstName, expirationDate);
    }

    displayInfo() {
        console.log('Informations du permis de conduire :');
        console.log(`Nom : ${this.lastName}`);
        console.log(`Prénom : ${this.firstName}`);
        console.log(`Date d'expiration : ${this.expirationDate}`);
    }
}

module.exports = DrivingLicense;