class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def length(self):
        current = self.head
        count = 0
        while current is not None:
            count += 1
            current = current.next
        return count

    def add_first(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def add_last(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        current = self.head
        while current.next is not None:
            current = current.next
        current.next = new_node

    def add_at_position(self, data, position):
        if position < 0 or position > self.length():
            raise ValueError("Invalid position")
        if position == 0:
            self.add_first(data)
            return
        new_node = Node(data)
        current = self.head
        for i in range(position - 1):
            current = current.next
        new_node.next = current.next
        current.next = new_node

    def remove(self, data):
        if self.head is None:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current = self.head
        while current.next is not None:
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next

    def remove_at_position(self, position):
        if position < 0 or position >= self.length():
            raise ValueError("Invalid position")
        if position == 0:
            self.head = self.head.next
            return
        current = self.head
        for i in range(position - 1):
            current = current.next
        current.next = current.next.next

    def search(self, data):
        current = self.head
        while current is not None:
            if current.data == data:
                return True
            current = current.next
        return False

    def get_position(self, data):
        current = self.head
        position = 0
        while current is not None:
            if current.data == data:
                return position
            position += 1
            current = current.next
        return -1

    def display(self):
        current = self.head
        while current is not None:
            print(current.data, end=' ')
            current = current.next
        print()

# Initialize a new linked list
my_list = LinkedList()

# Display the menu
menu = """
1. Add element to the beginning of the list
2. Add element to the end of the list
3. Add element at a specific position in the list
4. Remove element from the list
5. Remove element at a specific position in the list
6. Search for an element in the list
7. Get the position of an element in the list
8. Display the list
9. Reverse the list
0. Exit
"""

# Loop until the user chooses to exit
while True:
    print(menu)
    choice = input("Enter your choice: ")
    
    # Add element to the beginning of the list
    if choice == '1':
        data = input("Enter the element to add: ")
        my_list.add_first(data)
    
    # Add element to the end
