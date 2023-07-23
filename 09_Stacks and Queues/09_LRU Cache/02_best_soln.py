class LRUCache:
    def __init__(self, capacity: int):
        self.mp = {}
        self.container = []
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1
        else:
            # Move the accessed key-value pair to the end of the container
            self.container.remove((key, self.mp[key]))
            self.container.append((key, self.mp[key]))

            return self.mp[key]

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            # Remove the existing key-value pair from the container
            self.container.remove((key, self.mp[key]))
        elif len(self.mp) >= self.capacity:
            # Evict the least recently used key-value pair from the container and the map
            del self.mp[self.container[0][0]]
            self.container.pop(0)

        # Add the new key-value pair to the end of the container and update the map
        self.container.append((key, value))
        self.mp[key] = value
