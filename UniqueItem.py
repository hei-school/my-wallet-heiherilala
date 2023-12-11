from Item import Item;

class UniqueItem(Item):
    def __init__(self, name):
        super().__init__(name)
        self.is_lost = False

    def set_lost(self, lost):
        self.is_lost = lost

    def get_lost(self):
        return self.is_lost

    def used_item(self, message):
        if self.is_lost:
            print("Cet item est perdu, donc tu ne peux pas l'utiliser")
        else:
            print(f"{self.name} a été utilisé. '{message}'")
