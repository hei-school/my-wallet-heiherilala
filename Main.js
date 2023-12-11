const CIN = require('./CIN');
const CreditCard = require('./CreditCard');
const DrivingLicense = require('./DrivingLicense');
const IdPhoto = require('./IdPhoto');
const Money = require('./Money');
const UtilsMethod = require('./UtilsMethod');
const VisitCard = require('./VisitCard');
const Wallet = require('./Wallet'); 
const prompt = require('prompt-sync')();

class Main {

    constructor(wallet) {
        this.actualWallet = wallet;
        this.walletsLost = null;
    }

    
    static main() {

        while (true) {
            this.principalMenu();
        }
    }

    static principalMenu() {
        let choice = 0;

        if (!this.actualWallet) {
            choice = UtilsMethod.askUser([
                "Vous n'avez pas de portefeuille à votre possession",
                "1. Acheter",
                "2. Quitter"
            ]);

            switch (choice) {
                case 1:
                    this.actualWallet = Wallet.createWallet();
                    break;
                case 2:
                    console.log("Au revoir !");
                    process.exit(0);
                    break;
                default:
                    console.log("Choix invalide. Veuillez réessayer.");
            }
        } else {
            choice = UtilsMethod.askUser([
                "Quel item voulez-vous manipuler?",
                "1. CIN",
                "2. Carte de crédit",
                "3. Permis de conduire",
                "4. Photo d'identité",
                "5. Argent",
                "6. Carte de visite",
                "7. Le portefeuille",
                "8. Quitter"
            ]);

            switch (choice) {
                case 1:
                    this.useCIN(this.actualWallet);
                    break;
                case 2:
                    this.useCreditCard(this.actualWallet);
                    break;
                case 3:
                    this.useDrivingLicense(this.actualWallet);
                    break;
                case 4:
                    this.useIdPhoto(this.actualWallet);
                    break;
                case 5:
                    this.useMoney(this.actualWallet);
                    break;
                case 6:
                    this.useVisitCard(this.actualWallet);
                    break;
                case 7:
                    this.useWallet(this.actualWallet, );
                    break;
                case 8:
                    console.log("Au revoir !");
                    process.exit(0);
                    break;
                default:
                    console.log("Choix invalide. Veuillez réessayer.");
            }
        }
    }


    static useWallet() {
        const choice = UtilsMethod.askUser([
            "Quel événement s'est-il passé?",
            "1. Vous avez perdu votre portefeuille",
            "2. Regardé ce qu'il y a dans le portefeuille.",
            "3. Revenir au menu principal"
        ]);

        switch (choice) {
            case 1:
                this.actualWallet.setLost(true);
                walletsLost.push(this.actualWallet);
                this.actualWallet = null;
                break;
            case 2:
                this.actualWallet.printWallet();
                break;
            case 3:
                break;
            default:
                console.log("Choix invalide. Veuillez réessayer.");
                this.useWallet();
                break;
        }
    }

    static  useCIN() {

        UtilsMethod.useUniqueItem(
            
            this.actualWallet.getCin(),
             () => this.useCIN(),
             () => {
                const newCIN = CIN.createFromScanner();
                this.actualWallet.setCin(newCIN);
            }
        );
    }

    static  useCreditCard() {

        const choice =  UtilsMethod.askUser([
            "1. Ajouter une carte de crédit",
            "2. Utiliser les cartes de crédit existantes",
            "3. Retour au menu principal"
        ]);

        switch (choice) {
            case 1:
                const creditCards = this.actualWallet.getCreditCards();
                creditCards.push(CreditCard.createCreditCard());
                this.actualWallet.setCreditCards(creditCards);
                break;
            case 2:
                if (this.actualWallet.getCreditCards().length === 0) {
                    console.log("Vous ne possédez pas de cartes de crédit.");
                    break;
                }

                const messages = ["Choisissez la carte à utiliser :"];
                this.actualWallet.getCreditCards().forEach((creditCard, index) => {
                    messages.push(`${index}. ${creditCard.ownerName}`);
                });

                const choice2 =  UtilsMethod.askUser(messages);

                if (this.actualWallet.getCreditCards().length > choice2) {
                     UtilsMethod.useUniqueItem(
                        this.actualWallet.getCreditCards()[choice2],
                         () =>  this.useCreditCard(),
                        null
                    );
                } else {
                    console.log("Choix invalide. Veuillez réessayer.");
                     this.useCreditCard();
                }
                break;
            case 3:
                break;
            default:
                console.log("Choix invalide. Veuillez réessayer.");
                 this.useCreditCard();
                break;
        }
    }


    static  useDrivingLicense() {

         UtilsMethod.useUniqueItem(
            
            this.actualWallet.getDrivingLicense(),
             () =>  this.useDrivingLicense(),
             () => this.actualWallet.setDrivingLicense(DrivingLicense.createDrivingLicense())
        );
    }


    static  useIdPhoto() {

         UtilsMethod.useUniqueItem(
            
            this.actualWallet.getIdPhoto(),
             () =>  this.useIdPhoto(),
             () => this.actualWallet.setIdPhoto(new IdPhoto("new"))
        );
    }

    static  useMoney() {

         UtilsMethod.useMultiItems(
            
            this.actualWallet.getMoney(),
             () =>  this.useMoney(),
             (s) => this.actualWallet.setMoney(new Money(s)),
             (integer) => {
                const money = this.actualWallet.getMoney();
                money.take(integer);
                this.actualWallet.setMoney(money);
            },
             (integer) => {
                const money = this.actualWallet.getMoney();
                money.add(integer);
                this.actualWallet.setMoney(money);
            }
        );
    }


    static  useVisitCard() {

         UtilsMethod.useMultiItems(
            
            this.actualWallet.getVisitCard(),
             () =>  this.useVisitCard(),
             (s) => this.actualWallet.setVisitCard(VisitCard.createVisitCard()),
             (integer) => {
                const visitCard = this.actualWallet.getVisitCard();
                visitCard.take(integer);
                this.actualWallet.setVisitCard(visitCard);
            },
             (integer) => {
                const visitCard = this.actualWallet.getVisitCard();
                visitCard.add(integer);
                this.actualWallet.setVisitCard(visitCard);
            }
        );
    }

}

Main.main();
