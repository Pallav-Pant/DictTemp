#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

template <class K, class V>
class Dictionary
{
	DynamicList<K> keys;
	DynamicList<V> vals;
public:


	Dictionary() {}

	void addPair(K ke, V val)
	{
		keys.addEnd(ke);
		vals.addEnd(val);
	}
	V getValue(K key)
	{
		if (keys.getIndex(key) != NULL)
		{
			return vals.at(keys.getIndex(key));
		}
		else
		{
			std::cerr << "Not found" << std::endl;
			return NULL;
		}
	}
	void remove(K key)
	{
		keys.removeat(keys.getIndex(key));
		vals.removeat(keys.getIndex(key));
	}
};
