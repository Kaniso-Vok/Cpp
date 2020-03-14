#pragma once

#include "HashBucket.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace bite
{
	template<class K>
	class unordered_set
	{
	public:
		// δ��typename֮ǰ�����������ܻὫHashBucket<ValueType, KOFV>::iterator���������еĳ�Ա���������д���
		// ��Ϊ��Ա����Ҳ�Ǹ�������::��̬��Ա��������
		// typename: �ڴ˴������þ�����ȷ���߱��������˴���iterator�ǹ�ϣͰ�е�һ������
		typedef K ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data;
			}
		};

		typename typedef HashBucket<ValueType, KOFV>::iterator iterator;

	public:
		unordered_set()
			: _ht()
		{}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool empty()const
		{
			return _ht.empty();
		}

		size_t size()const
		{
			return _ht.size();
		}

		pair<iterator, bool> insert(const ValueType& key)
		{
			return _ht.insertunique(key);
		}

		size_t erase(const K& key)
		{
			return _ht.eraseunique(key);
		}

		iterator find(const K& key)
		{
			return _ht.find(key);
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(const unordered_set<K>& m)
		{
			_ht.swap(m._ht);
		}

		size_t bucket_count()const
		{
			return _ht.bucket_count();
		}

		size_t bucket_size(size_t n)const
		{
			return _ht.bucket_size(n);
		}

		size_t bucket(const K& key)
		{
			return _ht.bucket(key);
		}

	private:
		HashBucket<ValueType, KOFV> _ht;
	};
}




void TestUnorderedSet()
{
	bite::unordered_set<string> m;

	// �����ֵ�Ե����ַ�ʽ��pair�ṹ��  make_pair
	m.insert("apple");
	m.insert("banana");
	m.insert("orange");
	m.insert("peach");

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;  // Ͱ�ĸ���
	cout << m.bucket_size(0) << endl;  // 0��Ͱ�е�Ԫ�ظ���
	cout << m.bucket("orange") << endl;   // ��ȡkey���ڵ�Ͱ��

	// key�����ظ�
	m.insert("apple");
	cout << m.size() << endl;

	m.erase("orange");
	cout << m.size() << endl;

	m.clear();
}