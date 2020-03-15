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



// �Լ�Լ������ϣ����е�Ԫ�ر���Ψһ
// T: ��ʾԪ�ص�����
// DF: ��ʾ��T���͵Ķ���ת��Ϊ�������ݵķ���������
// isLine: ѡ��������̽�⻹�Ƕ���̽���������ϣ��ͻ
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

		// 1. ͨ����ϣ�����������ϣ��ַ
		size_t hashAddr = HashFunc(data);

		size_t i = 0;

		// 2. �Һ���λ��
		while (_table[hashAddr]._state != EMPTY)
		{
			// Ԫ���Ѿ�����
			if (_table[hashAddr]._state == EXIST && _table[hashAddr]._data == data)
				return false;

			// λ��״̬��DELETE
			// λ��״̬��EXIST��������ϣ��ͻ

			if (isLine)
			{
				// ����̽��
				hashAddr++;
				// ��ʽ����
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

		// �ҵ���һ����λ�ã�����Ԫ��
		_table[hashAddr]._data = data;
		_table[hashAddr]._state = EXIST;
		++_size;
		_total++��
		return true;
	}

	int Find(const T& data)
	{
		// 1. ͨ����ϣ����������Ԫ���ڱ���е�λ��
		size_t hashAddr = HashFunc(data);
		size_t i = 0;
		// 2. ����
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST && _table[hashAddr]._data == data)
				return hashAddr;

			// ��Ҫ��������̽�⣺����̽��
			if (isLine)
			{
				// ����̽��
				hashAddr++;
				// ��ʽ����
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
		//if (_size*10 / _table.capacity() >= 7)    // ���ɾ��λ�ÿ��Բ���Ԫ��
		if (_total * 10 / _table.capacity() >= 7)   // ���ɾ��λ�ò����Բ���Ԫ��
		{
			// 1. �´���һ����ϣ��
			HashTable<T, DF, isLine> newHT(GetNextPrime(_table.capacity()));
			
			// 2. ���ɹ�ϣ����״̬Ϊ���ڵ�Ԫ�����¹�ϣ����в���
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
	size_t _size;  // ��ʾ��ϣ���д洢����ЧԪ�ظ���
	size_t _total;  // ��ʾ��ϣ������Ѿ��洢Ԫ�ظ�������ЧԪ��+ɾ��Ԫ��֮��
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