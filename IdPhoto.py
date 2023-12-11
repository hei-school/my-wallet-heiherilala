from UniqueItem import UniqueItem

class IdPhoto(UniqueItem):
    def __init__(self, new_name):
        super().__init__(new_name)

    def __str__(self):
        return f"IdPhoto{{name='{self.get_name()}'}}"

