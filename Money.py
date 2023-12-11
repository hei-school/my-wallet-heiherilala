from MultipleItem import MultipleItem

class Money(MultipleItem):
    def __init__(self, new_name):
        super().__init__(new_name, "$")

    def __str__(self):
        return f"Money{{quantity={self.get_quantity()} {self.get_unity()}}}"

