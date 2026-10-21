#pragma once
#include "Node.h"

template <class T>
class List {
    private:
        Node<T>* start;
    public:
        List();

        void insert(T value, int index);
        void insertFirst(T value);
        void insertLast(T value);

        T get(int index);
        T getFirst();
        T getLast();
        int getSize();

        void remove(int index);
        void clear();

        T& getRef(int index);

        ~List();
};

#include "List.cpp"