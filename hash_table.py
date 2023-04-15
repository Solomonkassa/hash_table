class HashTable:
    def __init__(self, capacity=16):
        self.capacity = capacity
        self.size = 0
        self.buckets = [None] * self.capacity

    def __len__(self):
        return self.size

    def _hash(self, key):
        return hash(key) % self.capacity

    def insert(self, key, value):
        index = self._hash(key)
        node = self.buckets[index]

        while node is not None:
            if node.key == key:
                node.value = value
                return
            node = node.next

        self.size += 1
        self.buckets[index] = ListNode(key, value, self.buckets[index])

        if self.size / self.capacity > 0.7:
            self._resize()

    def get(self, key):
        index = self._hash(key)
        node = self.buckets[index]

        while node is not None:
            if node.key == key:
                return node.value
            node = node.next

        raise KeyError(key)

    def remove(self, key):
        index = self._hash(key)
        node = self.buckets[index]
        prev = None

        while node is not None:
            if node.key == key:
                if prev is None:
                    self.buckets[index] = node.next
                else:
                    prev.next = node.next
                self.size -= 1
                return node.value
            prev, node = node, node.next

        raise KeyError(key)

    def contains(self, key):
        index = self._hash(key)
        node = self.buckets[index]

        while node is not None:
            if node.key == key:
                return True
            node = node.next

        return False

    def _resize(self):
        self.capacity *= 2
        new_buckets = [None] * self.capacity

        for node in self._iter_nodes():
            index = self._hash(node.key)
            node.next = new_buckets[index]
            new_buckets[index] = node

        self.buckets = new_buckets

    def _iter_nodes(self):
        for node in self.buckets:
            while node is not None:
                yield node
                node = node.next

class ListNode:
    def __init__(self, key, value, next=None):
        self.key = key
        self.value = value
        self.next = next
