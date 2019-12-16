template<class K>
struct BStreeNode{
	BStreeNode(const K& date = K())
	:leftC(nullptr),
	rightC(nullptr),
	date_(date)
	{}
	BStreeNode<K> *leftC;
	BStreeNode<K> *rightC;
	K date_;
};

template<class K>
class BStree{
	typedef BStreeNode<K> BsNode;
public:
	BStree() :
		_root(nullptr)
	{}
	BsNode* Find(const K& date){       //���ҽڵ�
		BsNode* pNode = _root;
		while (pNode){
			if (pNode->date_ == date){
				return pNode;
			}
			else if (pNode->date_ > date){
				pNode = pNode->rightC;
			}
			else
				pNode = pNode->leftC;
		}
		return nullptr;
	}
	bool Insert(const K& date){
		BsNode *pNode = _root;
		BsNode *parent=nullptr;
		if (_root == nullptr){
			_root = new BsNode(date);
			return true;
		}
		else if (Find(date)){
			return false;
		}
		else{
			while (pNode){
				parent = pNode;
				if (pNode->date_ > date){
					pNode = pNode->leftC;
				}
				else{
					pNode = pNode->rightC;
				}
			}
			pNode = new BsNode(date);
			if (parent->date_ > date){
				parent->leftC = pNode;
			}
			else{
				parent->rightC = pNode;
			}
			return true;
		}
	}

	bool Delete(const K& date){
		BsNode *pNode = _root;
		BsNode *parent = nullptr;
		if (pNode == nullptr){    //����
			return false;
		}
		while (pNode){
			if (pNode->date_ == date){
				break;
			}
			else if (pNode->date_ < date){
				parent = pNode;
				pNode = pNode->rightC;
			}
			else{
				parent = pNode;
				pNode = pNode->leftC;
			}
		}
		//BsNode *pdel=pNode;
		if (pNode == parent){      //Ҫɾ���ĵ��Ǹ��ڵ�
			if (pNode->leftC){
				pNode = pNode->leftC;
			}
			else if (pNode->rightC){
				pNode = pNode->rightC;
			}
			else{
				pNode = nullptr;
			}
		}
		if (pNode == nullptr){   // û���ҵ�Ԫ��
			return false;
		}
		if (pNode->rightC && pNode->leftC == nullptr){  //ֻ��������
			if (pNode = parent->leftC){
				parent->leftC = pNode->rightC;
			}
			else{
				parent->rightC = pNode->rightC;
			}
		}
		else if (pNode->leftC && pNode->rightC == nullptr){   //ֻ��������
			if (pNode = parent->leftC){
				parent->leftC = pNode->leftC;
			}
			else{
				parent->rightC = pNode->leftC;
			}
		}
		else if (pNode->leftC && pNode->rightC){    //��Ů��ȫ
			if (pNode = parent->leftC){
				pNode->rightC->leftC = pNode->leftC;
				parent->leftC = pNode->rightC;
			}
			else{
				pNode->leftC->rightC= pNode->rightC;
				parent->rightC = pNode->leftC;
			}
		}
		else{                                        //���ӿ���
			if (pNode = parent->leftC){
				parent->leftC = nullptr;
			}
			else{
				parent->rightC = nullptr;
			}
		}
		delete pNode;
		return true;
	}

	BsNode* IfLeftMost(){
		if (_root == nullptr){
			return nullptr;
		}
		BsNode &pNode = _root;
		while (pNode->leftC){
			pNode = pNode->leftC;
		}
		return pNode;
	}
	BsNode* IfRightMost(){
		if (_root == nullptr){
			return nullptr;
		}
		BsNode &pNode = _root;
		while (pNode->rightC){
			pNode = pNode->rightC;
		}
		return pNode;
	}
	void InOrder(){
		InOrder(_root);
		cout << endl;
	}

private:
	void InOrder(BsNode *pNode){
		if (pNode){
			InOrder(pNode->leftC);
			cout << pNode->date_ << ' ';
			InOrder(pNode->rightC);
		}
	}
private:
	BsNode *_root;
};