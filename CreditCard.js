const UniqueItem = require('./UniqueItem');
const UtilsMethod = require('./UtilsMethod');

const prompt = require('prompt-sync')();
class CreditCard  extends UniqueItem {
    constructor(bank, cardType, expirationDate, ownerName) {
        super("CreditCard");
        this.bank = bank;
        this.cardType = cardType;
        this.expirationDate = expirationDate;
        this.ownerName = ownerName;
    }

    static createCreditCard() {
        const bank = prompt('Entrez la banque de la carte de crédit : ');
        const cardType = prompt('Entrez le type de carte de crédit : ');
        console.log("Entrez la date d\'expiration : ");
        const expirationDate = UtilsMethod.askDate();
        const ownerName = prompt('Entrez le nom du propriétaire : ');

        // Vous pouvez ajouter une logique de validation pour la date d'expiration si nécessaire

        return new CreditCard(bank, cardType, expirationDate, ownerName);
    }

    displayInfo() {
        console.log('Informations de la carte de crédit :');
        console.log(`Banque : ${this.bank}`);
        console.log(`Type de carte : ${this.cardType}`);
        console.log(`Date d'expiration : ${this.expirationDate}`);
        console.log(`Propriétaire : ${this.ownerName}`);
    }

    toString() {
        console.log('Informations de la carte de crédit :');
        console.log(`Banque : ${this.bank}`);
        console.log(`Type de carte : ${this.cardType}`);
        console.log(`Date d'expiration : ${this.expirationDate}`);
        console.log(`Propriétaire : ${this.ownerName}`);
        return "";
    }
}


module.exports = CreditCard;