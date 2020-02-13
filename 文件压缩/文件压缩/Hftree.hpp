#pragma once

#include <queue>   //采用优先级队列储存森林
#include <vector>
using namespace std;

template<class K>
struct HfNode{
	HfNode(const K& x = K()):   //若是内置类型自动赋0，自定义类型则需要提供 无参构造函数 或者 全缺省构造函数
	pLeft(nullptr),
	pRight(nullptr),
	pParent(nullptr),
	_W(x)
	{}
	//构造方法

	HfNode<K>* pLeft;
	HfNode<K>* pRight;
	HfNode<K>* pParent;
	K _W;   //权值
	//结点信息
};

template<class K>
class Less{
	typedef HfNode<K> node;
public:
	bool operator()(const node* left, const node* right){
		return left->_W> right->_W;
	}
};

template<class K>
class HfTree{
	typedef HfNode<K> node;
public:
	HfTree():
		_Root(nullptr)
	{}

	HfTree(const vector<K>& hfw,const K& Fhfw){
		createHfTree(hfw,Fhfw);
	}

	node* GetRoot(){
		return _Root;
	}

	void createHfTree(const vector<K>& Hfw, const K& Fhfw){
		//1.构建森林
		priority_queue<node*,vector<node*>,Less<K>> Sen;  //优先级队列存储森林,默认是大堆
		for (auto e : Hfw){
			if (e == Fhfw){
				continue;
			}
			Sen.push(new node(e));
		}
		//2.当有2颗或以上的数，取出权值最小的两颗并且作为一个新节点的左右子树再加入森林，
		//新结点的权值为左右子树权值之和
		while (Sen.size() > 1){   
			node *left = Sen.top();        //拿到权值最小树
			Sen.pop();
			node *right = Sen.top();       //拿到权值第二小的树
			Sen.pop();

			node *parent = new node(left->_W + right->_W);  //新结点
			parent->pLeft = left;
			parent->pRight = right;
			left->pParent = parent;
			right->pParent = parent;

			Sen.push(parent);
		}
		_Root = Sen.top();
	}

	~HfTree(){
		Destory(_Root);
	}
	void Destory(node*& x){   //后序遍历销毁二叉树
		if (x == nullptr){
			return;
		}
		Destory(x->pLeft);
		Destory(x->pRight);
		delete x;
		x = nullptr;
	}

private:
	node* _Root;
};






