const prompt = require('prompt-sync')();
class UtilsMethod {
    static askUser(messages) {
        messages.forEach(message => console.log(message));
        const input = prompt("");
        return this.takeIntValueFromString(input);
    }

    static askDate() {
        console.log("Année ");
        let year = this.takeIntValueFromString(prompt(""));
        while (year < 0) {
            console.log("Année invalide, réécrire l'année");
            year = this.takeIntValueFromString(prompt(""));
        }
        console.log("Mois");
        let month = this.takeIntValueFromString(prompt(""));
        while (month < 0 || month > 12) {
            console.log("Mois invalide, réécrire le mois");
            month = this.takeIntValueFromString(prompt(""));
        }
        console.log("Jour");
        let day = this.takeIntValueFromString(prompt(""));
        while (day < 0 || day > 28) {
            console.log("Jour invalide, réécrire le jour");
            day = this.takeIntValueFromString(prompt(""));
        }
        return new Date(year, month - 1, day);
    }

    static useUniqueItem( uniqueItem, actualFunction, createUniqueItemFunction) {
        if (uniqueItem === null) {
            const choice = this.askUser([
                "1. Ajouter un item",
                "2. Revenir au menu principal"
            ]);

            switch (choice) {
                case 1:
                    createUniqueItemFunction("actualWallet");
                    break;
                case 2:
                    break;
                default:
                    console.log("Choix invalide. Veuillez réessayer.");
                    actualFunction();
                    break;
            }
        } else {
            const choice = this.askUser([
                "Quel événement s'est passé?",
                "1. Utilisé",
                "2. Revenir au menu principal"
            ]);

            switch (choice) {
                case 1:
                    uniqueItem.usedItem(uniqueItem.toString());
                    break;
                case 2:
                    break;
                default:
                    console.log("Choix invalide. Veuillez réessayer.");
                    actualFunction();
                    break;
            }
        }
        return null;
    }

    static useMultiItems( multipleItem, actualFunction, createMultiItemFunction, useFunction, addFunction) {
        if (multipleItem === null) {
            const choice = this.askUser([
                "1. Ajouter un item",
                "2. Revenir au menu principal"
            ]);

            switch (choice) {
                case 1:
                    createMultiItemFunction("actualWallet");
                    break;
                case 2:
                    break;
                default:
                    console.log("Choix invalide. Veuillez réessayer.");
                    actualFunction();
                    break;
            }
        } else {
            const choice = this.askUser([
                "1. Utiliser",
                "2. Ajouter",
                "3. Consulter la quantité actuelle",
                "4. Revenir au menu principal"
            ]);

            switch (choice) {
                case 1:
                    console.log("Combien voulez-vous utiliser?");
                    const quantityUsed = this.takeIntValueFromString(prompt());
                    if (multipleItem.getQuantity() < quantityUsed) {
                        console.log("Vous n'avez pas la quantité suffisante");
                    } else {
                        useFunction(quantityUsed);
                        console.log("Opération réussie");
                        console.log("Votre compte est de");
                        console.log(`${multipleItem.getQuantity()} ${multipleItem.getUnity()}`);
                    }
                    break;
                case 2:
                    console.log("Combien voulez-vous ajouter?");
                    const quantityToAdd = this.takeIntValueFromString(prompt());
                    addFunction(quantityToAdd);
                    console.log("Opération réussie");
                    console.log("Votre compte est de");
                    console.log(`${multipleItem.getQuantity()} ${multipleItem.getUnity()}`);
                    break;
                case 3:
                    console.log("Votre compte est de");
                    console.log(multipleItem.getQuantityWithUnity());
                    break;
                case 4:
                    break;
                default:
                    console.log("Choix invalide. Veuillez réessayer.");
                    actualFunction();
                    break;
            }
        }
        return null;
    }

    static isNotConvertibleToNumber(str) {
        try {
            const number = parseInt(str);
            return isNaN(number) || number < 0;
        } catch (e) {
            return true;
        }
    }

    static takeIntValueFromString(str) {
        let value = str;
        let isValid;
        do {
            if (this.isNotConvertibleToNumber(value)) {
                isValid = false;
            } else {
                isValid = parseInt(value) >= 0;
            }
            if (!isValid) {
                console.log("Entrée invalide, veuillez entrer une nouvelle valeur.");
                value = prompt("");
            }
        } while (!isValid);
        return parseInt(value);
    }
}

module.exports = UtilsMethod;
