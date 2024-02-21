#include <queue.hpp>
 

template<class T>
QueueNode<T>::QueueNode(T value, QueueNode<T>* next, QueueNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
QueueNode<T>::~QueueNode() {
    this->next = this->prev = nullptr;
}

template<class T>
Queue<T>::Queue() {
    this->head = this->tail = nullptr;
}

template<class T>
Queue<T>::~Queue() {
    // Destructor needs to delete all nodes in the queue
    while (head != nullptr) {
        QueueNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;  // Set tail to nullptr after deleting all nodes
}

template<class T>
bool Queue<T>::empty() {
    return head == nullptr;  // The queue is empty if the head is nullptr
}

template<class T>
T Queue<T>::pop() {
    if (this->empty()) {
        throw std::out_of_range("Queue is empty");
    }
    T value = this->head->value;
    QueueNode<T>* temp = this->head;

    // Update head to the next node
    this->head = this->head->next;

    // If the queue becomes empty after popping, update tail to nullptr
    if (this->head == nullptr) {
        this->tail = nullptr;
    }

    delete temp;
    return value;
}

template<class T>
void Queue<T>::push(T value) {
    QueueNode<T>* newNode = new QueueNode<T>(value, nullptr, nullptr);

    // If the queue is empty, both head and tail point to the new node
    if (this->empty()) {
        this->head = this->tail = newNode;
    } else {
        // Update the tail to point to the new node
        this->tail->next = newNode;
        // Update the tail to be the new node
        this->tail = newNode;
    }
}

template class Queue<int>;
