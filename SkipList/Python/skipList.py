import random

class Node:
    def __init__(self, key, level):
        self.key = key
        self.forward = [None] * (level + 1)

class SkipList:
    MAX_LEVEL = 16

    def __init__(self):
        self.header = Node(float("-inf"), self.MAX_LEVEL)
        self.level = 0

    def random_level(self):
        level = 0
        while level < self.MAX_LEVEL and random.random() < 0.5:
            level += 1
        return level

    def insert_element(self, key):
        level = self.random_level()
        update = [None] * (level + 1)
        current = self.header

        for i in range(level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current

        current = current.forward[0]

        if not current or current.key != key:
            new_node = Node(key, level)
            for i in range(level + 1):
                new_node.forward[i] = update[i].forward[i]
                update[i].forward[i] = new_node

    def delete_element(self, key):
        update = [None] * (self.level + 1)
        current = self.header

        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current

        current = current.forward[0]

        if current and current.key == key:
            for i in range(self.level + 1):
                if update[i].forward[i] != current:
                    break
                update[i].forward[i] = current.forward[i]

    def search_element(self, key):
        current = self.header
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
        current = current.forward[0]
        if current and current.key == key:
            print("Found key:", key)
        else:
            print("Not Found key:", key)

    def display_list(self):
        print("Skip List:")
        for i in range(self.level + 1):
            node = self.header.forward[i]
            print("Level", i, end=": ")
            while node:
                print(node.key, end=" ")
                node = node.forward[i]
            print()

if __name__ == "__main__":
    skip_list = SkipList()

    for i in range(0, 25):
        key = random.randrange(1000)
        skip_list.insert_element(key)
        skip_list.display_list()

    # Insert elements
    # skip_list.insert_element(3)
    # skip_list.insert_element(6)
    # skip_list.insert_element(7)
    # skip_list.insert_element(9)
    # skip_list.insert_element(12)
    # skip_list.insert_element(19)
    # skip_list.insert_element(17)
    # skip_list.insert_element(26)
    # skip_list.insert_element(21)
    # skip_list.insert_element(25)

    # # Display the skip list
    # skip_list.display_list()

    # # Search for an element
    # skip_list.search_element(19)

    # # Delete an element
    # skip_list.delete_element(19)
    # skip_list.display_list()