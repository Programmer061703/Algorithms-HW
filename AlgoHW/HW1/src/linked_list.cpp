#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = NULL;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    LinkedListNode<T>* current = this->root;
    while (current != NULL) {
        LinkedListNode<T>* next = current->next;
        delete current;
        current = next;
    }
    this->root = NULL;

}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    //Insert at beginning of list
   LinkedListNode<T>* newNode = new LinkedListNode<T>(value,root);
    root = newNode;
    return newNode;

}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
   LinkedListNode<T>* current = root;
    while (current != NULL){
        if (current->value == value){
            return current; // Node is found
        }
        current = current->next;

    }
    return NULL; // Returns null when value is not found
}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
   LinkedListNode<T>* current = root;
   LinkedListNode<T>* prev = NULL;
    while (current != NULL){
        if (current->value == value){
            if (prev == NULL){
                root = current->next;
            }
            else{
                prev->next = current->next;
            }
            delete current;
            return current; // Node is found
        }
        prev = current;
        current = current->next;
    }
    return NULL; // Returns null when value is not found
}

template<class T>
int LinkedList<T>::size() {
    int count = 0;
    LinkedListNode<T>* current = root;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

template class LinkedListNode<int>;
template class LinkedList<int>;
