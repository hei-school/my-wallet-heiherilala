const MultipleItem = require('./MultipleItem');
const prompt = require('prompt-sync')();

class VisitCard  extends MultipleItem{
    constructor(companyName, post, version, quantity, name) {
        super(name, unity);
        this.companyName = companyName;
        this.post = post;
        this.version = version;
        this.quantity = quantity;
    }

    static createVisitCard() {
        const companyName = prompt('Entrez le nom de l\'entreprise sur la carte de visite : ');
        const post = prompt('Entrez le poste sur la carte de visite : ');
        const version = prompt('Entrez la version de la carte de visite : ');
        const quantity = parseInt(prompt('Entrez la quantité de cartes de visite : '), 10);

        // Vous pouvez ajouter une logique de validation pour la quantité si nécessaire

        return new VisitCard(companyName, post, version, quantity, "name");
    }

    displayInfo() {
        console.log('Informations de la carte de visite :');
        console.log(`Nom de l'entreprise : ${this.companyName}`);
        console.log(`Poste : ${this.post}`);
        console.log(`Version : ${this.version}`);
        console.log(`Quantité : ${this.quantity}`);
    }
}

module.exports = VisitCard;