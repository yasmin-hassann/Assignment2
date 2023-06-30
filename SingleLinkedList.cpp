

#include "SingleLinkedList.h"
#include <iostream>
#include <cstddef>

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
    : head(nullptr), tail(nullptr), num_items(0) {}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    // Destructor to deallocate memory for all nodes in the list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void SingleLinkedList<T>::push_front(const T& item) {
    // Insert a new node at the front of the list
    Node* newNode = new Node{ item, head };
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    num_items++;
}

template <typename T>
void SingleLinkedList<T>::push_back(const T& item) {
    // Insert a new node at the end of the list
    Node* newNode = new Node{ item, nullptr };
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

template <typename T>
void SingleLinkedList<T>::pop_front() {
    // Remove the first node in the list
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

template <typename T>
void SingleLinkedList<T>::pop_back() {
    // Remove the last node in the list
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        num_items = 0;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        num_items--;
    }
}

template <typename T>
T& SingleLinkedList<T>::front() {
    // Get the data of the first node in the list (non-const version)
    return head->data;
}

template <typename T>
const T& SingleLinkedList<T>::front() const {
    // Get the data of the first node in the list (const version)
    return head->data;
}

template <typename T>
T& SingleLinkedList<T>::back() {
    // Get the data of the last node in the list (non-const version)
    return tail->data;
}

template <typename T>
const T& SingleLinkedList<T>::back() const {
    // Get the data of the last node in the list (const version)
    return tail->data;
}

template <typename T>
bool SingleLinkedList<T>::empty() const {
    // Check if the list is empty
    return num_items == 0;
}

template <typename T>
void SingleLinkedList<T>::insert(size_t index, const T& item) {
    if (index == 0) {
        // Insert at the front of the list
        push_front(item);
    }
    else if (index >= num_items) {
        // Insert at the end of the list
        push_back(item);
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* newNode = new Node{ item, current->next };
        current->next = newNode;
        num_items++;
    }
}

template <typename T>
bool SingleLinkedList<T>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }

    if (index == 0) {
        pop_front();
    }
    else {
        // Remove a node at the specified index
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

        if (current->next == nullptr) {
            tail = current;
        }

        num_items--;
    }

    return true;
}

template <typename T>
size_t SingleLinkedList<T>::find(const T& item) const {
    // Find the position of the first occurrence of an item in the list
    Node* current = head;
    size_t index = 0;

    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }

        current = current->next;
        index++;
    }
    // If the item is not found, return the size of the list
    return num_items;
}

template <typename T>
void SingleLinkedList<T>::displayList() const {
    // Display the contents of the list
    Node* current = head;

    std::cout << "List: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

}
//// Explicit SingleLinkedList instantiation for int type
template class SingleLinkedList<int>;