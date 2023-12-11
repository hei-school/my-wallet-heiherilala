const UniqueItem = require('./UniqueItem');
const UtilsMethod = require('./UtilsMethod');
const prompt = require('prompt-sync')();

class CIN extends UniqueItem {
    constructor(lastName, firstName, dateOfBirth, placeOfBirth, idNumber, name) {
        super(name);
        this.lastName = lastName;
        this.firstName = firstName;
        this.dateOfBirth = dateOfBirth;
        this.placeOfBirth = placeOfBirth;
        this.idNumber = idNumber;
    }

    static  createFromScanner() {
        console.log("Entrez le prénom : ");
        const firstName = prompt("");
        console.log("Entrez le nom : ");
        const lastName = prompt("");
        const dateOfBirth = UtilsMethod.askDate();
        console.log("Entrez le lieu de naissance : ");
        const placeOfBirth = prompt("");
        console.log("Entrez le numéro d'identité national : ");
        const idNumber =prompt("");

        return new CIN(lastName, firstName, dateOfBirth, placeOfBirth, idNumber, "CIN");
    }

    // Accessor methods (getters and setters)
    getLastName() {
        return this.lastName;
    }

    setLastName(lastName) {
        this.lastName = lastName;
    }

    getFirstName() {
        return this.firstName;
    }

    setFirstName(firstName) {
        this.firstName = firstName;
    }

    getDateOfBirth() {
        return this.dateOfBirth;
    }

    setDateOfBirth(dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    getPlaceOfBirth() {
        return this.placeOfBirth;
    }

    setPlaceOfBirth(placeOfBirth) {
        this.placeOfBirth = placeOfBirth;
    }

    getIdNumber() {
        return this.idNumber;
    }

    setIdNumber(idNumber) {
        this.idNumber = idNumber;
    }

    toString() {
        return `CIN{lastName='${this.lastName}', firstName='${this.firstName}', dateOfBirth=${this.dateOfBirth}, placeOfBirth='${this.placeOfBirth}', idNumber='${this.idNumber}'}`;
    }
}

module.exports = CIN;