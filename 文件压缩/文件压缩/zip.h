#pragma once

template<class K>
struct HfNode{
	HfNode<K>* pLeft;
	HfNode<K>* pRight;
	HfNode<K>* pParent; 

	K _W;
	//�����Ϣ

	HfNode(const K& x) :
		pLeft(nullptr),
		pRight(nullptr),
		pParent(nullptr),
		_W(0)
	{}
	//���췽��

};

template<class K>
class HfTree{
public:
	HfTree():
		_Root(nullptr)
	{}

	~HfTree(){
		Destory(_Root);
	}
	void Destory(HfNode<K>* x){
		if (x == nullptr){
			return;
		}
		Destory(x->pLeft);
		Destory(x->pRight);
		delete x;
		x = nullptr;
	}











private:
	HfNode<K>* _Root;
};









