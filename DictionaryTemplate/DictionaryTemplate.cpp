#include <iostream>
#include <cstdlib>
template <class K, class V>
struct KV
{
    K key;
    V val;
    KV* Next;
    KV(K key, V val)
    {
        this->key = key;
        this->val = val;
    }
};
template <class K, class V>
class Dictionary
{
    KV<K, V>* headptr;
    KV<K, V>* tailptr;
    int numElements = 0;
public:
    Dictionary() {};

    bool exists(K key)//Something here is broken
    {
        int i = 0;
        KV<K, V>* temp = headptr;
        while (i < numElements)
        {
            if (temp->key == key)
            {
                return true;
            }
            i++;
        }
        return false;
    }

    void add(K key, V val)
    {
        KV<K, V>* pair = new KV<K, V>(key, val);
        if (headptr == nullptr)
        {
            headptr = pair;
            tailptr = pair;
        }
        else if (this->exists(key))
        {
            std::cerr << "Key already exists in this dictionary" << std::endl;
        }
        else
        {
            tailptr->Next = pair;
            tailptr = pair;
        }
        numElements++;
    }

    void remove(K key)
    {

        KV<K, V>* temp = headptr;
        if (headptr->key == key)
        {
            temp = headptr->Next;
            delete headptr;
            headptr = temp;
            numElements--;
            return;
        }
        int i = 0;
        while (i < numElements - 1)
        {
            if (temp->Next->key == key)
            {
                temp->Next = temp->Next->Next;
                delete temp->Next;
            }
            temp = temp->Next;
            i++;
        }
    }

    /*KV<K, V>* pairAt(int i)
    {
        if (i == 0)
        {
            return headptr;
        }
        if (i == numElements - 1)
        {
            return tailptr;
        }

        KV<K, V>* temp = headptr;
        int r = 0;
        if (i > 0 && i < numElements)
        {
            while (r < i)
            {
                temp = temp->Next;
                r++;
            }
            return temp;
        }
        else if (i < 0 && i >= -numElements)
        {
            i = numElements + i;
            while (r < i)
            {
                temp = temp->Next;
                r++;
            }
            return temp;
        }
    }*/

    V getValue(K key)
    {
        int i = 0;
        KV<K, V>* temp = headptr;
        while (i < numElements-1)
        {
            if (temp->key == key)
            {
                return temp->val;
            }
            temp = temp->Next;
            i++;
        }
        return NULL;
    }

    int size()
    {
        return this->numElements;
    }

    

};

int main()
{
    Dictionary<char, int> dict;
    dict.add('a', 1);
    dict.add('b', 2);
    dict.add('c', 3);
    dict.add('c', 4);
    dict.add('d', 4);
    dict.add('e', 5);
    dict.remove('a');
    std::cout << dict.getValue('c') << std::endl;
    std::cout << dict.size() << std::endl;
}
