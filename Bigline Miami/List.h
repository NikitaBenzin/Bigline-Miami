#pragma once


// Box class (list item) 
template <typename T>
class Item
{
public:
    T value;
    Item* data = nullptr;
};

// My vector
template <typename T>
class List
{
private:

    // Variables
    unsigned Size;
    Item<T>* first;
    Item<T>* current;

    unsigned counter;
    Item<T>* iterator;

public:
    List();
    ~List();

    bool empty(void);
    void push_back(T value);
    unsigned int size(void);
    T& operator[](const int index);
    void pop_front(void);
    void clear(void);
    Item<T>* begin();
    void push_front(T value);
    void erase(int index);
};