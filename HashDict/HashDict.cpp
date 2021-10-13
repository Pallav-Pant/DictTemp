#include <iostream>

template<class V>
struct Pair
{
    std::string key;
    V value;
    Pair* Next;
    Pair(std::string key = NULL, V value = NULL)
    {
        this->key = key;
        this->value = value;
    }
};

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

template <class V>
class Dictionary
{
    List<V> dict[10];

    int hash(std::string key)
    {
        int index = 0;
        for (int i = 0; i < key.length(); i++)
        {
            index += key[i];
        }
        index %= 10;
        return index;
    }


public:
    Dictionary() {}

    

    void add(std::string key, V value)
    {
        dict[hash(key)].add(key, value);

    }

    V read(std::string key)
    {
        return dict[hash(key)].getValue(key);
    }

    void remove(std::string key)
    {
        dict[hash(key)].remove(key);
    }

    void exists(std::string key)
    {
        if (dict[hash(key)].exists(key))
        {
            std::cout << "The key " << key << " exists in this dictionary." << std::endl;
            return;
        }
        std::cout << "The key " << key << " does not exist in this dictionary." << std::endl;
    }

    ~Dictionary() {}//Work on this
};

int main()
{
    Dictionary<int> dictNum;
    dictNum.add("Hello", 120);
    std::cout << dictNum.read("Hello") << std::endl;
    dictNum.remove("Hello");
    std::cout << dictNum.read("Hello") << std::endl;
}