#include <iostream>

// Define a struct for the Node in the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    // Add a new node to the front of the list
    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        count++;
    }

    // Add a new node to the end of the list
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        count++;
    }

    // Get the number of elements in the list
    int size() const {
        return count;
    }

    // Check if the list contains a given value
    bool contains(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Remove the first occurrence of a given value from the list
    void remove(int value) {
        if (head == nullptr) {
            return; // Empty list, nothing to remove
        }

        // Handle the case where the value to remove is at the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
            return;
        }

        // Search for the value in the rest of the list
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                count--;
                return;
            }
            current = current->next;
        }
    }

    // Remove first element if any
    void pop_front() {
        if( head == nullptr ) {
            return;
        }

        Node* tmpNode = head;
        head = head->next;
        count--;
        delete tmpNode;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};
