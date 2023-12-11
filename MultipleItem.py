from Item import Item;

class MultipleItem(Item):
    def __init__(self, new_name, unity):
        super().__init__(new_name)
        self.unity = unity
        self.quantity = 0

    def add(self, quantity_to_add):
        self.quantity += quantity_to_add
        return self

    def take(self, quantity_to_take):
        if self.quantity > quantity_to_take:
            self.quantity -= quantity_to_take
            return self
        else:
            print(f"{super().name} does not have sufficient quantity for this transaction.")
            return None

    def get_quantity(self):
        return self.quantity

    def get_quantity_with_unity(self):
        return f"{self.quantity} {self.unity}"

    def set_quantity(self, quantity):
        self.quantity = quantity

    def set_unity(self, unity):
        self.unity = unity

    def get_unity(self):
        return self.unity
