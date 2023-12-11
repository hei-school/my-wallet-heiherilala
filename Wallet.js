const Money = require('./Money');

const prompt = require('prompt-sync')();
class Wallet {
    constructor(owner) {
        this.id = generateUUID();
        this.owner = owner;
        this.isLost = false;
        this.cin = null;
        this.creditCards = [];
        this.drivingLicense = null;
        this.idPhoto = null;
        this.money = new Money('money', '$');
        this.visitCard = null;
    }

    static createWallet() {
        console.log("Entrez le nom du propriétaire du portefeuille : ");
        const owner = prompt(' ');
        return new Wallet(owner);
    }

    setCin(cin) {
        this.cin = cin;
    }

    setCreditCards(creditCards) {
        this.creditCards = creditCards;
    }

    setDrivingLicense(drivingLicense) {
        this.drivingLicense = drivingLicense;
    }

    setIdPhoto(idPhoto) {
        this.idPhoto = idPhoto;
    }

    setMoney(money) {
        this.money = money;
    }

    setVisitCard(visitCard) {
        this.visitCard = visitCard;
    }

    getCin() {
        return this.cin;
    }

    getDrivingLicense() {
        return this.drivingLicense;
    }

    getIdPhoto() {
        return this.idPhoto;
    }

    getMoney() {
        return this.money;
    }

    getCreditCards() {
        return this.creditCards;
    }

    getVisitCard() {
        return this.visitCard;
    }

    printWallet() {
        console.log('-- CIN --');
        if (this.cin !== null) {
            console.log(this.cin.toString());
        }

        console.log('-- creditCards --');
        if (this.creditCards.length > 0) {
            this.creditCards.forEach(creditCard => {
                console.log(creditCard.toString());
            });
        }

        console.log('-- drivingLicense --');
        if (this.drivingLicense !== null) {
            console.log(this.drivingLicense.toString());
        }

        console.log('-- idPhoto --');
        if (this.idPhoto !== null) {
            console.log(this.idPhoto.toString());
        }

        console.log('-- money --');
        if (this.money !== null) {
            console.log(this.money.toString());
        }

        console.log('-- visitCard --');
        if (this.visitCard !== null) {
            console.log(this.visitCard.toString());
        }
    }
}

function generateUUID() {
    return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
        const r = Math.random() * 16 | 0,
            v = c === 'x' ? r : (r & 0x3 | 0x8);
        return v.toString(16);
    });
}

module.exports = Wallet;
