#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
namespace key{
	template<class K>
	class vector{
	public:
		// vector�ĵ�������һ��ԭ��ָ��,�����������ض��巽��ʵ��
		typedef K* iterator;
		typedef const K* const_iterator;
		vector()                             //�޲ι���
			:_start(nullptr)                 //��ʼ���б�
			, _finish(nullptr)
			, _endofstorage(nullptr){}

		vector(int n, const K& value = K())  //���������죬�ҳ�ʼ��������n��valueԪ�أ��ڶ���������ȱʡֵ�ɲ���
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr){
			reserve(n);
			while (n--)
			{
				push_back(value);         //�����еڶ��������������ʼ��Ԫ��
			}
		}
		
		//������������������������������[first,last]���������������ĵ�����
		template<class InIterator>
		vector(InIterator first, InIterator last){
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<K>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr){
			reserve(v.capacity());
			K* it = begin();
			K* vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}
		vector<K>& operator= (vector<K> v){
			swap(v);
			return *this;
		}
		~vector(){
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		// capacity
		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endofstorage - _start; }

		void reserve(size_t n){  //���ݣ��ı�capacity��ֵ
			if (n > capacity())
			{
				size_t oldSize = size();
				K* tmp = new K[n];
				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const K& value = K()){   //�����趨��С����ʼ�������֣�
			// 1.���nС�ڵ�ǰ��size�������ݸ�����С��n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.�ռ䲻��������
			if (n > capacity())
				reserve(n);
			// 3.��size����n        //����Ĳ���Ҫ��ʼ��
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		///////////////����������///////////////////////////////
		T& operator[](size_t pos){ 
			return _start[pos]; 
		}
		const T& operator[](size_t pos)const {
			return _start[pos]; 
		}

		///////////////��ɾ���/////////////////////////////
		void push_back(const K& x){     //���
			insert(end(), x); 
		}
		void pop_back(){             //��ɾ
			erase(--end()); 
		}

		void swap(vector<K>& v){           //��������vector��������ݿռ�
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
		}

		iterator insert(iterator pos, const K& x){   //����
			assert(pos <= _finish);
			// �ռ䲻���Ƚ�������
			if (_finish == _endofstorage)
			{
				size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);
				// ������������ݣ���Ҫ����pos
				pos = _start + size;
			}
			K* end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		// ����ɾ�����ݵ���һ������
		// ������:һ�߱���һ��ɾ���ĵ�����ʧЧ����
		iterator erase(Iterator pos)
		{
			// Ų�����ݽ���ɾ��
			iterator begin = pos + 1;
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}

		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator cbegin() const { return _start; }
		const_iterator cend() const { return _finish; }

		private:
			iterator _start; // ָ�����ݿ�Ŀ�ʼ
			iterator _finish; // ָ����Ч���ݵ�β
			iterator _endofstorage; //ָ��洢�ļ���β

	};
}

int main(){
	
	return 0;
}