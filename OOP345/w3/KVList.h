#pragma once
#include <iostream>
#include <string>

template <typename K, typename V, size_t N>
class KVList {
	K key_array[N];
	size_t key_size;
	V value_array[N];
	size_t value_size;
public:
	KVList();
	size_t size() const;
	const K& key(int) const;
	const V& value(int) const;
	KVList& add(const K& param_k, const V& param_v)
	{
		if (key_size < N && value_size < N)
		{
			key_array[key_size] = param_k;
			value_array[key_size] = param_v;
			key_size++;
			value_size++;
		}
		return *this;
	};
	int find(const K&) const;
	KVList& replace(int i, const K& param_k, const V& param_v)
	{
		key_array[i] = param_k;
		value_array[i] = param_v;
		return *this;
	};
};

template<typename K, typename V, size_t N>
KVList<K, V, N>::KVList()
{
	key_size = 0;
	value_size = 0;
}

template<typename K, typename V, size_t N>
size_t KVList<K, V, N>::size() const
{
	return key_size;
}

template<typename K, typename V, size_t N>
const K& KVList<K, V, N>::key(int i) const
{
	return i < N ? key_array[i] : key_array[0];
}

template<typename K, typename V, size_t N>
const V & KVList<K, V, N>::value(int i) const
{
	return i < N ? value_array[i] : value_array[0];
}

//template<typename K, typename V, size_t N>
//KVList& KVList<K, V, N>::add(const K& param_k, const V& param_v)
//{
//	if (key_size < N && value_size < N)
//	{
//		key_array[key_size] = param_k;
//		value_array[key_size] = param_v;
//		key_size++;
//		value_size++;
//	}
//	return this*;
//}

template<typename K, typename V, size_t N>
int KVList<K, V, N>::find(const K& k) const
{
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		if (key_array[i] == k)
		{
			index = i;
		}
	}
	return index;
}

//template<typename K, typename V, size_t N>
//KVList& KVList<K, V, N>::replace(int i, const K& k, const V& v)
//{
//	key_array[i] = k;
//	value_array[i] = v;
//	return this*;
//}
