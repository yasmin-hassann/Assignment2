
#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <cstddef>

template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;         // Data of the node
        Node* next;     // Pointer to the next node
    };

    Node* head;         // Pointer to the first node
    Node* tail;         // Pointer to the last node
    size_t num_items;   // Number of items in the list

public:
    SingleLinkedList();                         // Constructor
    ~SingleLinkedList();                        // Destructor

    void push_front(const T& item);              // Add item to the front of the list
    void push_back(const T& item);               // Add item to the end of the list
    void pop_front();                            // Remove the first item from the list
    void pop_back();                             // Remove the last item from the list
    T& front();                                  // Get the data of the first item (non-const version)
    const T& front() const;                      // Get the data of the first item (const version)
    T& back();                                   // Get the data of the last item (non-const version)
    const T& back() const;                       // Get the data of the last item (const version)
    bool empty() const;                          // Check if the list is empty
    void insert(size_t index, const T& item);     // Insert item at the specified index
    bool remove(size_t index);                    // Remove item at the specified index
    size_t find(const T& item) const;             // Find the position of the first occurrence of item
    void displayList() const;                     // Display the contents of the list
};

#endif // SINGLELINKEDLIST_H
