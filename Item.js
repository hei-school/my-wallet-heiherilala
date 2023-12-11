class Item {
    constructor(name) {
        this.name = name;
        this.id = this.generateUUID();
    }

    getName() {
        return this.name;
    }

    getId() {
        return this.id;
    }

    setName(name) {
        this.name = name;
    }

    generateUUID() {
        return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
            var r = Math.random() * 16 | 0,
                v = c === 'x' ? r : (r & 0x3 | 0x8);
            return v.toString(16);
        });
    }
}

module.exports = Item;