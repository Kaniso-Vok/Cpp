#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
namespace key{
	template<class K>
	class vector{
	public:
		// vector的迭代器是一个原生指针,所以做以下重定义方便实用
		typedef K* iterator;
		typedef const K* const_iterator;
		vector()                             //无参构造
			:_start(nullptr)                 //初始化列表
			, _finish(nullptr)
			, _endofstorage(nullptr){}

		vector(int n, const K& value = K())  //含参数构造，且初始化，插入n个value元素，第二个参数做缺省值可不填
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr){
			reserve(n);
			while (n--)
			{
				push_back(value);         //若是有第二个参数输入则初始化元素
			}
		}
		
		//所以重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器
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

		void reserve(size_t n){  //扩容，改变capacity的值
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

		void resize(size_t n, const K& value = K()){   //重新设定大小并初始化（部分）
			// 1.如果n小于当前的size，则数据个数缩小到n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.空间不够则增容
			if (n > capacity())
				reserve(n);
			// 3.将size扩大到n        //扩大的部分要初始化
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		///////////////操作符重载///////////////////////////////
		T& operator[](size_t pos){ 
			return _start[pos]; 
		}
		const T& operator[](size_t pos)const {
			return _start[pos]; 
		}

		///////////////增删查改/////////////////////////////
		void push_back(const K& x){     //后插
			insert(end(), x); 
		}
		void pop_back(){             //后删
			erase(--end()); 
		}

		void swap(vector<K>& v){           //交换两个vector对象的数据空间
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
		}

		iterator insert(iterator pos, const K& x){   //插入
			assert(pos <= _finish);
			// 空间不够先进行增容
			if (_finish == _endofstorage)
			{
				size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);
				// 如果发生了增容，需要重置pos
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
		// 返回删除数据的下一个数据
		// 方便解决:一边遍历一边删除的迭代器失效问题
		iterator erase(Iterator pos)
		{
			// 挪动数据进行删除
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
			iterator _start; // 指向数据块的开始
			iterator _finish; // 指向有效数据的尾
			iterator _endofstorage; //指向存储文件的尾

	};
}

int main(){
	
	return 0;
}