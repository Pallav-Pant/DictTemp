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
		return vals.at(keys.getIndex(key));
	}
};
