#pragma once

#include <vector>
#include <iostream>
using namespace std;
#include <string>


enum STATE{EMPTY, EXIST, DELETE};

template<class T>
struct Elem
{
	Elem(const T& data = T())
	: _data(data)
	, _state(EMPTY)
	{}

	T _data;
	STATE _state;
};



// 自己约定：哈希表格中的元素必须唯一
// T: 表示元素的类型
// DF: 表示将T类型的对象转换为整数数据的方法的类型
// isLine: 选择用线性探测还是二次探测来解决哈希冲突
template<class T, class DF = DFDef<T>, bool isLine = true>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		: _size(0)
		, _table(0)
	{
		_table.resize(GetNextPrime(10));
	}

	bool Insert(const T& data)
	{
		CheckCapacity();

		// 1. 通过哈希函数，计算哈希地址
		size_t hashAddr = HashFunc(data);

		size_t i = 0;

		// 2. 找合适位置
		while (_table[hashAddr]._state != EMPTY)
		{
			// 元素已经存在
			if (_table[hashAddr]._state == EXIST && _table[hashAddr]._data == data)
				return false;

			// 位置状态：DELETE
			// 位置状态：EXIST，发生哈希冲突

			if (isLine)
			{
				// 线性探测
				hashAddr++;
				// 方式二：
				if (hashAddr == _table.capacity())
					hashAddr = 0;
			}
			else
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _table.capacity();
			}
		}

		// 找到了一个空位置，插入元素
		_table[hashAddr]._data = data;
		_table[hashAddr]._state = EXIST;
		++_size;
		_total++；
		return true;
	}

	int Find(const T& data)
	{
		// 1. 通过哈希函数，计算元素在表格中的位置
		size_t hashAddr = HashFunc(data);
		size_t i = 0;
		// 2. 查找
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST && _table[hashAddr]._data == data)
				return hashAddr;

			// 需要继续往后探测：线性探测
			if (isLine)
			{
				// 线性探测
				hashAddr++;
				// 方式二：
				if (hashAddr == _table.capacity())
					hashAddr = 0;
			}
			else
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _table.capacity();
			}
		}

		return -1;
	}

	bool Erase(const T& data)
	{
		int pos = Find(data);
		if (pos != -1)
		{
			_table[pos]._state = DELETE;
			_size--;
			return true;
		}

		return false;
	}

	size_t Size()const
	{
		return _size;
	}

	void Swap(HashTable<T, DF, isLine>& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}

private:
	void CheckCapacity()
	{
		//if (_size*10 / _table.capacity() >= 7)    // 如果删除位置可以插入元素
		if (_total * 10 / _table.capacity() >= 7)   // 如果删除位置不可以插入元素
		{
			// 1. 新创建一个哈希表
			HashTable<T, DF, isLine> newHT(GetNextPrime(_table.capacity()));
			
			// 2. 将旧哈希表中状态为存在的元素向新哈希表格中插入
			for (auto e : _table)
			{
				if (e._state == EXIST)
					newHT.Insert(e);
			}

			Swap(newHT);
		}
	}

	size_t HashFunc(const T& data)
	{
		//DF df;
		//return df(data) % 10;
		return DF()(data) % _table.capacity();
	}

private:
	vector<Elem<T>> _table;
	size_t _size;  // 表示哈希表中存储的有效元素个数
	size_t _total;  // 表示哈希表格中已经存储元素个数：有效元素+删除元素之和
};


void TestHashTable1()
{
	int array[] = {21,67,112,99,5,13,44};
	HashTable<int> ht;
	for (auto e : array)
		ht.Insert(e);

	cout << ht.Size() << endl;
	ht.Insert(87);
	ht.Insert(77);
	cout << ht.Size() << endl;

	if (ht.Find(87) != -1)
	{
		cout << "87 is in hashtable" << endl;
	}
	else
	{
		cout << "87 is not in hashtable" << endl;
	}

	ht.Erase(67);
	if (ht.Find(67) != -1)
	{
		cout << "67 is in hashtable" << endl;
	}
	else
	{
		cout << "67 is not in hashtable" << endl;
	}

	if (ht.Find(87) != -1)
	{
		cout << "87 is in hashtable" << endl;
	}
	else
	{
		cout << "87 is not in hashtable" << endl;
	}
}

void TestHashTable2()
{
	HashTable<string, DFStr, false> ht;
	ht.Insert("1111");
	ht.Insert("2222");
	ht.Insert("3333");
	ht.Insert("4444");
}