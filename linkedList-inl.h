#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

template <typename T> LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

template <typename T> LinkedList<T>::~LinkedList() {
    LinkedListNode<T>* temp = this->head;
    LinkedListNode<T>* temp2 = this->head;
    while(temp != NULL){
        temp = temp->next;
        delete temp2;
        temp2 = temp;
    }
}

template <typename T> void LinkedList<T>::checkInvariants() {
    int counter = 0;
    if(this->isEmpty() && this->head != NULL){
        throw runtime_error("Invariant error: LinkedList head pointer should point to NULL");
    }
    else{
        LinkedListNode<T>* temp = this->head;
        while(temp != NULL){
            counter++;
            temp = temp->next;
        }
    }
    if(counter != this->size){
        throw runtime_error("Invariant error: LinkedList size doesn't match actual number of nodes in LinkedList");
    }
}

template <typename T> int LinkedList<T>::getSize() {
    return this->size;
}

template <typename T> bool LinkedList<T>::isEmpty() {
    if(this->size == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename T> T LinkedList<T>::getFirst() {
    if(this->getSize() == 0){
        throw runtime_error("Error: can't get first element from empty LinkedList");
    }
    return this->head->value;
}

template <typename T> T LinkedList<T>::getLast() {
    if(this->getSize() == 0){
        throw runtime_error("Error: can't get last element from empty LinkedList");
    }
    return this->tail->value;
}

template <typename T> T LinkedList<T>::get(int index) {
    if(this->getSize() == 0){
        throw runtime_error("Error: can't get element from empty LinkedList");
    }
    if(index < 0 || index >= this->size){
        throw runtime_error("Error: indexOutOfBounds");
    }
    int counter = 0;
    LinkedListNode<T>* temp = this->head;
    while(counter != index){
        counter++;
        temp = temp->next;
    }
    return temp->value;
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, this->head);
    this->head = node;
    if(this->getSize() == 0){
        this->tail = node;
        node->next = NULL;
    }
    this->size++;
}

template <typename T> void LinkedList<T>::insertLast(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, this->head);
    if(this->getSize() == 0){
        this->tail = node;
        this->head = node;
        node->next = NULL;
    }
    else{
        LinkedListNode<T>* temp = this->tail;
        this->tail = node;
        temp->next = node;
        node->next = NULL;
    }
    this->size++;
}

template <typename T> T LinkedList<T>::removeFirst() {
    if(this->getSize() == 0){
        throw runtime_error("Error: can't remove first element from empty array");
    }
    T temp = this->head->value;
    if(this->getSize() == 1){
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    else{
        LinkedListNode<T>* tempHead = this->head;
        this->head = this->head->next;
        delete tempHead;
    }
    this->size--;
    return temp;
}

template <typename T> T LinkedList<T>::removeLast() {
    if(this->getSize() == 0){
        throw runtime_error("Error: can't remove last element from empty array");
    }
    T temp = this->tail->value;
    if(this->getSize() == 1){
        delete this->tail;
        this->head = NULL;
        this->tail = NULL;
    }
    else{
        LinkedListNode<T>* tempTail = this->tail;
        LinkedListNode<T>* temp2 = this->head;
        while(temp2->next != this->tail){
            temp2 = temp2->next;
        }
        this->tail = temp2;
        temp2->next = NULL;
        delete tempTail;
    }
    this->size--;
    return temp;
}
