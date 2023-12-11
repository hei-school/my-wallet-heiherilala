# WalletApp Java

WalletApp est une application simple de gestion de portefeuille en Java.

## Fonctionnalités

la portefeulle peut manipuler les instance suivante

- CIN
- Money
- CB
- PC
- CV
- ID Photo

Tout ces instances peuvent enlever et entre de la portefeulle

- l'argent à un montant, donc voiciet les activiter que l'on peut faire avec:
   * Affichage du solde
   * Dépôt d'argent (ne peut plus entre de l'argent si depace le monten qu'il peut suporter)
   * sortir de l'argent (ne peut pas enlever de l'argent si c'est superieur au monton actuel)

- le carte bencaire puet erte plusieur et à de detail particulier (quelle banck, quelle genre de carte, quelle date d'expiration', dice si il y à de d'argent dedans, non du proprietaire)
  * On poura y maitre une nouveau CB en speficient tout ces detail
  * On poura en retirer un pour l'utilisé 
  * On poura le remetre dans la portefeull apré utilisation (apres utilisation)
  * On poure le jeter definiment
  * On poura en definir un comme perdu

* Le CV aussi pourai etre plusieur et aura des detalai particulier (societre, post, vertion)
   * On poura faire le meme actifvité que la CB desus
   * sauf que on in ajoutera la notion de quantité
   * et il poura etre o et non pertu ou jeter ou retirer 

- Pour les autre instance il n'y aure que 1 unité par prrtefeull donc
  * On poura le renplacer
  * On pourar l'utiliser
  * On pour le definir comme perdu (se qui est perdu n'est pas retouvable)
  * On pura le retouver si perdu
  * peut aussion etre vide, et poure en rentrer un seulment si c'est vide ou perdu

Un portefeul aura aussi des proprierter qui lui sont unique:
- son propriretaire
- son capaciter de stoquege 
- lui atribuer un reference
- peut etre perdu (si perdut tout ce qui est dedans est perdu)
- 
## Comment utiliser

1. **Compilation :** Assurez-vous d'avoir Java installé sur votre système. Utilisez la commande suivante pour compiler le programme :

    ```bash
    javac SimpleWalletApp.class
    ```

2. **Exécution : tout ce que vous avez à faire est de lancer la classe Main

3. **Suivez les instructions à l'écran :** Le programme vous guidera pour créer un compte, vous connecter et effectuer des opérations de portefeuille.

## Notes supplémentaires

- Ce projet est un exemple éducatif simple et peut être étendu pour inclure des fonctionnalités plus avancées.
- Assurez-vous de respecter les conventions de nommage et de commentaires lors de l'extension du projet.

## Remarque importante

Pour accéder à votre portefeuille, assurez-vous d'avoir créé un compte au préalable. Si vous n'avez pas encore de compte, choisissez l'option "Créer un Compte" avant de vous connecter.

## Conventions de Codage (Coding Standards) et Formatage du Code

Nous suivons le [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html).

### Comment formater le code

Le code Java est automatiquement formaté en utilisant `google-java-format`. Assurez-vous de l'avoir installé.

Pour formater le code manuellement, exécutez le script suivant :

```bash
./format.sh
