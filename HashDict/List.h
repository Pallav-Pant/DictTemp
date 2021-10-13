#include <iostream>
#include "Pair.h"


template <class V>
class List
{
    Pair<V>* headptr = nullptr;
    Pair<V>* tailptr = nullptr;
    int size = 0;
public:

    List() {}


    bool exists(std::string k)
    {
        int i = 0;
        Pair<V>* temp = headptr;
        while (i < this->size)
        {
            if (temp->key == k)
            {
                return true;
            }
            i++;
            if (temp == tailptr)
            {
                return false;
            }
            temp = temp->Next;

        }
        return false;
    }

    void add(std::string key, V value)
    {
        Pair<V>* pair = new Pair<V>(key, value);
        if (headptr == nullptr || tailptr == nullptr)
        {
            headptr = pair;
            tailptr = pair;
        }
        else if (this->exists(key))
        {
            std::cerr << "Key already exists" << std::endl;
        }
        else
        {
            tailptr->Next = pair;
            tailptr = pair;
        }
        size++;
    }

    void remove(std::string key)
    {
        Pair<V>* temp = headptr;
        if (headptr->key == key)
        {
            headptr = headptr->Next;
            delete temp;
            size--;
            return;
        }
        for (int i = 1; i < this->size; i++)
        {
            if (temp->Next->key == key)
            {
                Pair<V>* hold = temp->Next;
                temp->Next = hold->Next;
                delete hold;
                size--;
            }
            temp = temp->Next;
        }
    }

    V getValue(std::string key)
    {
        int i = 0;
        Pair<V>* temp = headptr;
        while (i < size)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->Next;
            i++;
        }
        std::cerr << "The key was not found" << std::endl;
        return NULL;
    }

    int legnth()
    {
        return this->size;
    }
    //Fix this
   /* ~List()
    {
        Pair<V>* temp;
        while (this->headptr != nullptr)
        {
            temp = headptr;
            headptr = headptr->Next;
            delete temp;
        }
    }*/
};
