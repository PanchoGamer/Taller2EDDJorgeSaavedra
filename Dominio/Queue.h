#pragma once
#include "List.h"

template <class T>
class Queue : private List<T> {
    private:
        Node<T>* start;
    public:
        Queue() : List<T>() {};

        bool empty(){
            return this->getSize() == 0;
        }

        void push(T value){
            this->insertLast(value);
        }

        void pop(){
            this->remove(0);
        }

        T front(){
            return this->getFirst();
        }
        
        void clear(){
            List<T>::clear();
        }

        int size(){
            return this->getSize();
        }

        T& consultar(int index) {
            return this->getRef(index);
        }

        ~Queue() {}
};