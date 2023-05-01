#include "List.h"


// -------------------------------- CONSTRUCTOR / DESTRUCTOR -------------------------------- //
template<typename T>
List<T>::List()
{
    this->Size = 0;
    this->first = nullptr;
    this->current = this->first;
}


template<typename T>
List<T>::~List()
{
    iterator = nullptr;
    delete iterator;

    this->current = this->first;

    while (current != nullptr)
    {
        this->first = this->first->data;
        delete current;
        this->current = this->first;
    }
}

// ------------------------------------ PUBLIC FUNCTIONS ------------------------------------ //

template<typename T>
bool List<T>::empty(void)
{
    if (first == nullptr) return true; else return false;
}


/**
*   @ return void
*   - push back in List element which was given
*/
template<typename T>
void List<T>::push_back(T value)
{
    if (empty())
    {
        this->first = new Item<T>;
        this->first->value = value;
        this->current = this->first;
        this->Size++;
    }
    else
    {
        this->current->data = new Item<T>;
        this->current = this->current->data;
        this->current->value = value;
        this->Size++;
    }
}


template<typename T>
unsigned int List<T>::size(void)
{
    return this->Size;
}


template<typename T>
T& List<T>::operator[](const int index)
{
    counter = 0;
    iterator = this->first;

    // return value of first el if index == 0
    // counting while counter != index
    while (iterator != nullptr)
    {
        if (counter == index)
        {
            return iterator->value;
        }
        // change pointer of iterator
        iterator = iterator->data;
        ++counter;
    }
}

template<typename T>
void List<T>::pop_front(void)
{
    iterator = this->first;
    this->first = this->first->data;
    delete iterator;
    --Size;
}

template<typename T>
void List<T>::clear(void)
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
Item<T>* List<T>::begin()
{
    return first;
}

template<typename T>
void List<T>::push_front(T value)
{
    iterator = this->first;
    this->first = new Item<T>;
    this->first->value = value;
    this->first->data = iterator;
    ++Size;
}


template<typename T>
void List<T>::erase(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        counter = 0;
        iterator = first;
        Item<T>* whichDelete;

        while (counter != index - 1)
        {
            iterator = iterator->data;
            ++counter;
        }
        whichDelete = iterator->data;
        iterator->data = whichDelete->data;
        delete whichDelete;
        --Size;
    }

}