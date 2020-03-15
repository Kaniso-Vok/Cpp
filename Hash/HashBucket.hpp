#pragma once
#include <vector>
#include "Common.h"

template<class T>
struct HashNode
{
	// T():
	// T���������͵�Ԫ�أ�T()--->0
	// T���Զ������͵�Ԫ�أ� T()--->����T����޲ι��캯��
	HashNode(const T& data = T())
	: _pNext(nullptr)
	, _data(data)
	{}

	HashNode<T>* _pNext;
	T _data;
};


template<class T, class KOFV, class DF = DFStr>
class HashBucket;

// ����������ʵ��ԭ���Ϸ���---1. ԭ��ָ̬��   2. ��ԭ��ָ̬����з�װ

template<class T, class KOFV, class DF = DFStr>
struct HBIterator
{
	typedef HashNode<T> Node;
	typedef HBIterator<T, KOFV, DF> Self;
	HBIterator(Node* pNode = nullptr, HashBucket<T, KOFV, DF>* ht=nullptr)
		: _pNode(pNode)
		, _ht(ht)
	{}

	// ��������ָ��Ĳ���
	T& operator*()
	{
		return _pNode->_data;
	}

	T* operator->()
	{
		return &(_pNode->_data)
	}

	// �ܹ��ƶ�
	// ǰ��++
	Self& operator++()
	{
		Next();
		return *this;
	}
	
	// ����++
	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	// �Ƚ�
	bool operator!=(Self& s)
	{
		return _pNode != s._pNode;
	}

	bool operator==(Self& s)
	{
		return _pNode == s._pNode;
	}

	void Next()
	{
		if (_pNode->_pNext)
		{
			// _pNode��Ӧ����������нڵ�
			_pNode = _pNode->_pNext;
		}
		else
		{
			// pNode�ǵ�ǰ�����е����һ���ڵ�
			// ��pNode�����һ���ǿ�Ͱ
			// ���⣺���pNode�����ĸ�Ͱ�У��򵥣�����ܹ�֪����ϣ���������ܹ�֪��pNode��Ͱ��
			// ����ܹ��õ���ǰ��������Ӧ�Ĺ�ϣ���Ϳ����õ���ϣ����
			size_t bucketNo = _ht->HashFunc(_pNode->_data)+1;
			for (; bucketNo < _ht->_table.capacity(); ++bucketNo)
			{
				if (_ht->_table[bucketNo])
				{
					// �ǿ�Ͱ�Ѿ��ҵ�
					_pNode = _ht->_table[bucketNo];
					return;
				}
			}

			_pNode = nullptr;
		}
	}


	HashNode<T>* _pNode;
	HashBucket<T, KOFV, DF>* _ht;
};

// ��������������ϣ�
// 1. Ϊ���ඨ�������
// 2. ���������¸�����������
// 3. ����begin/end
template<class T, class KOFV, class DF>
class HashBucket
{
	friend struct HBIterator<T, KOFV, DF>;
	typedef HashNode<T> Node;

public:
	typedef HBIterator<T, KOFV, DF> iterator;

public:
	HashBucket(size_t capacity = 10)
		: _size(0)
	{
		_table.resize(GetNextPrime(10));
	}

	~HashBucket()
	{
		clear();
	}

	// �ڲ���ʱ����ϣͰ�е�Ԫ����Ψһ��
	std::pair<iterator, bool> insertunique(const T& data)
	{
		CheckCapacity();

		// 1. ͨ����ϣ����������Ͱ��
		size_t bucketNo = HashFunc(data);

		// 2. ���ֵΪdata��Ԫ���ڹ�ϣͰ���Ƿ����
		Node* pCur = _table[bucketNo];
		while (pCur)
		{
			if (KOFV()(pCur->_data) == KOFV()(data))
				return make_pair(iterator(pCur, this), false);

			pCur = pCur->_pNext;
		}

		// 3. �����½ڵ�---����ͷ��
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		++_size;

		return make_pair(iterator(pCur, this), true);
	}

	// ����п��Բ�����ͬ��Ԫ��
	bool insertEqual(const T& data);

	size_t eraseunique(const T& data)
	{
		// 1. ͨ����ϣ��������data���ڵ�ͬ��
		size_t bucketNo = HashFunc(data);

		// 2. ��bucketNo����Ӧ����������ֵΪdata�Ľڵ�
		Node* pCur = _table[bucketNo];
		Node* pPre = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				// ɾ��pCur�ڵ�ɾ��
				if (nullptr == pPre)
				{
					// ɾ�����ǵ�һ���ڵ�
					_table[bucketNo] = pCur->_pNext;
				}
				else
				{
					// ɾ���ǵ�һ���ڵ�
					pPre->_pNext = pCur->_pNext;
				}

				delete pCur;
				--_size;
				return 1;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->_pNext;
			}
		}

		return 0;
	}

	// ������ֵΪdata�Ľڵ�ɾ��
	bool eraseEqual(const T& data);

	// O(1)
	iterator find(const T& data)const
	{
		// 1. ����data���ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		// 2. ��bucketNo����Ӧ����������ֵΪdata�Ľڵ�
		Node* pCur = _table[bucketNo];
		while (pCur)
		{
			if (KOFV()(pCur->_data) == KOFV()(data))
				return iterator(pCur, this);

			pCur = pCur->_pNext;
		}

		return end();
	}

	size_t size()const
	{
		return _size;
	}

	bool empty()const
	{
		return 0 == _size
	}

	iterator begin()
	{
		// �ҵ�һ���ǿ�Ͱ
		for (size_t bucket = 0; bucket < _table.capacity(); ++bucket)
		{
			if (_table[bucket])
				return iterator(_table[bucket], this);
		}

		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	void clear()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			Node* cur = _table[bucketNo];
			while (cur)
			{
				_table[bucketNo] = cur->_pNext;
				delete cur;
				cur = _table[bucketNo];
			}
		}

		_size = 0;
	}

	// Ͱ���ܵĸ���
	size_t bucket_count()const
	{
		return _table.capacity();
	}

	// bucketNo�а����Ľڵ�����
	size_t bucket_size(size_t bucketNo)const
	{
		if (bucketNo >= bucket_count())
			return 0;

		size_t count = 0;
		Node* cur = _table[bucketNo];
		while (cur)
		{
			count++;
			cur = cur->_pNext;
		}

		return count;
	}

	// ��ȡkey���ڵ�Ͱ
	size_t bucket(const T& data)
	{
		return HashFunc(data);
	}

	// ����
	void PrintHashBucket()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); bucketNo++)
		{
			Node* pCur = _table[bucketNo];
			cout << "_table[" << bucketNo << "]:";
			while (pCur)
			{
				cout << pCur->_data << "--->";
				pCur = pCur->_pNext;
			}

			cout << "NULL" << endl;
		}
	}

	void swap(HashBucket<T, KOFV, DF>& ht)
	{
		_table.swap(ht._table);
		std::swap(_size, ht._size);
	}

private:
	// �����ϣͰ�����洢��Ԫ�ظ�����Ͱ�ĸ������ʱ
	// ԭ���ҹ�ϣͰ���״̬--->ÿ��Ͱ�ж��洢һ��Ԫ��
	// >> ÿ��Ͱ�ж���һ��Ԫ�أ������������һ���ᷢ����ͻ
	// >> Ͱ�����������
	void CheckCapacity()
	{
		if (_size == _table.capacity())
		{
			HashBucket<T, KOFV,DF> newHT(GetNextPrime(_size));

			// ���ɹ�ϣͰ�еĽڵ��������ӵ��¹�ϣͰ��
			// ���ڵ�Ӿɹ�ϣͰ��ɾ����������뵽�¹�ϣͰ��
			for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
			{
				Node* cur = _table[bucketNo];
				while (cur)
				{
					// ����cur���¹�ϣͰ�е�Ͱ��
					size_t newBucketNo = newHT.HashFunc(cur->_data);

					// �Ȱ�cur�Ӿ�Ͱ��ɾ��
					_table[bucketNo] = cur->_pNext;

					// ������뵽�¹�ϣnewBucketNo��
					cur->_pNext = newHT._table[newBucketNo];
					newHT._table[newBucketNo] = cur;
					newHT._size++;

					// ȡ�ɹ�ϣͰ�е���һ���ڵ�
					cur = _table[bucketNo];
				}
			}

			this->swap(newHT);

			/*
			// �÷�ʽ���ԣ�ȱ�ݣ�ֱ�Ӳ������ǽ���ϣͰ�еĽڵ㷭��
			for (size_t bucketNo = 0; i < _table.capacity(); ++bucketNo)
			{
				// ��bucketNoͰ��Ԫ�ز��뵽�¹�ϣͰnewHT��
				Node* cur = _table[bucketNo];
				while (cur)
				{
					newHT.insertunique(cur->_data);
					cur = cur->_pNext;
				}
			}

			this->swap(newHT);
			*/
		}
	}

	size_t HashFunc(const T& data)const
	{
		return DF()(KOFV()(data)) % _table.capacity();
	}
private:
	std::vector<Node*> _table;
	size_t _size;
};
