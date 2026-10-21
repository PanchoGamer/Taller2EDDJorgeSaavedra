#pragma once
#include "List.h"

template <class T>
List<T>::List(){
     this->start = nullptr;
}

template <class T>
void List<T>::insert(T value, int index){
    if (index < 0) throw 0;
    if (index == 0){
        this->insertFirst(value); return;
    }

    Node<T>* cursor = this->start;
    for(int i = 0; i < index-1; i++){
        cursor = cursor->getNext();
        if(!cursor) throw 0;
    }

    Node<T>* nuevo = new Node<T>(value);
    nuevo->setNext(cursor->getNext());
    cursor->setNext(nuevo);
}

template <class T>
void List<T>::insertFirst(T value){
    Node<T>* node = new Node<T>(value);
    node->setNext(this->start);
    this->start = node;
}

template <class T>
void List<T>::insertLast(T value){
    if (this->start == nullptr){
        this->start = new Node<T>(value);
        return;
    }

    Node<T>* cursor = this->start;
    while (cursor->getNext() != nullptr){
        cursor = cursor->getNext();
    }
    cursor->setNext(new Node<T>(value));
}

template <class T>
T List<T>::get(int index){
    if (!this->start || index < 0) throw 0;
    Node<T>* cursor = this->start;
    int i = 0;
    while (i < index){
        cursor = cursor->getNext();
        if(!cursor) throw 0;
        i++;
    }
    return cursor->getValue();
}

template <class T>
T List<T>::getFirst(){
    if (this->start == nullptr) throw 0;
    return this->start->getValue();
}

template <class T>
T List<T>::getLast(){
    if (this->start == nullptr) throw 0;
    Node<T>* cursor = this->start;
    while (cursor->getNext() != nullptr){
        cursor = cursor->getNext();
    }
    return cursor->getValue();
}

template <class T>
int List<T>::getSize(){
    int c = 0;
    Node<T>* actual = this->start;
    while(actual!=nullptr){
        c++;
        actual = actual->getNext();
    }
    return c;
}

template <class T>
void List<T>::remove(int index){
    if (!this->start || index < 0) throw 0;
    if (index == 0) {
        Node<T>* toDel = this->start;
        this->start = toDel->getNext();
        delete toDel; return;
    }

    Node<T>* cursor = this->start;
    for(int i = 0; i < index-1 ; i++){
        cursor = cursor->getNext();
        if(!cursor) throw 0;
    }

    Node<T>* toDelete = cursor->getNext();
    cursor->setNext(
        toDelete ? toDelete->getNext() : nullptr
    );
    delete toDelete;
}

template <class T>
void List<T>::clear(){
    while (this->start != nullptr){
        Node<T>* temp = this->start->getNext();
        delete this->start;
        this->start = temp;
    }
}

template <class T>
List<T>::~List(){
    Node<T>* actual = this->start;
    while(actual!=nullptr){
        Node<T>* temp = actual;
        actual = actual->getNext();
        delete temp;
    }
}

template <class T>
T& List<T>::getRef(int index){
    if (!this->start || index < 0) throw 0;
    Node<T>* cursor = this->start;
    for (int i = 0; i < index; i++) {
        cursor = cursor->getNext();
        if (!cursor) throw 0;
    }
    return cursor->getValueRef();
}