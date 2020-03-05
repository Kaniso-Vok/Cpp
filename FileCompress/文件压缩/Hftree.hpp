#pragma once

#include <queue>   //�������ȼ����д���ɭ��
#include <vector>
using namespace std;

template<class K>
struct HfNode{
	HfNode(const K& x = K()):   //�������������Զ���0���Զ�����������Ҫ�ṩ �޲ι��캯�� ���� ȫȱʡ���캯��
	pLeft(nullptr),
	pRight(nullptr),
	pParent(nullptr),
	_W(x)
	{}
	//���췽��

	HfNode<K>* pLeft;
	HfNode<K>* pRight;
	HfNode<K>* pParent;
	K _W;   //Ȩֵ
	//�����Ϣ
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
		//1.����ɭ��
		priority_queue<node*,vector<node*>,Less<K>> Sen;  //���ȼ����д洢ɭ��,Ĭ���Ǵ��
		for (auto e : Hfw){
			if (e == Fhfw){
				continue;
			}
			Sen.push(new node(e));
		}
		//2.����2�Ż����ϵ�����ȡ��Ȩֵ��С�����Ų�����Ϊһ���½ڵ�����������ټ���ɭ�֣�
		//�½���ȨֵΪ��������Ȩֵ֮��
		while (Sen.size() > 1){   
			node *left = Sen.top();        //�õ�Ȩֵ��С��
			Sen.pop();
			node *right = Sen.top();       //�õ�Ȩֵ�ڶ�С����
			Sen.pop();

			node *parent = new node(left->_W + right->_W);  //�½��
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
	void Destory(node*& x){   //����������ٶ�����
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






