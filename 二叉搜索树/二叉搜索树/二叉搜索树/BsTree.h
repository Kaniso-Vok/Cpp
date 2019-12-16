template<class K>
struct BStreeNode{
	BStreeNode(const K& date = K())    //�ڵ�Ķ���
	:leftC(nullptr),    // ��ʼ��
	rightC(nullptr),
	date_(date)
	{}
	BStreeNode<K> *leftC;      //����
	BStreeNode<K> *rightC;    //�Һ���
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
		if (_root == nullptr){      //����ʱ���ٿռ䶨��Ϊ���ڵ�
			_root = new BsNode(date);
			return true;
		}
		else if (Find(date)){   //������ͬ��㲻���в���
			return false;
		}
		else{
			while (pNode){         //�ҵ�����λ�ã���������ѭ��������ֻȷ���˸�ĸ��㣬�������ӻ����Һ��Ӳ�ȷ��( ��Ϊ��ʱֵΪnullptr )
				parent = pNode;
				if (pNode->date_ > date){
					pNode = pNode->leftC;
				}
				else{
					pNode = pNode->rightC;
				}
			}
			pNode = new BsNode(date);    //������
			if (parent->date_ > date){       //ȷ���������ӻ����Һ���
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
		if (pNode == nullptr){    //�������
			return false;
		}
		while (pNode){      //�ҵ�Ҫɾ���Ľ��
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
		if (pNode == nullptr){   // û���ҵ�Ҫɾ���Ľڵ�
			return false;
		}
		if (pNode->rightC && pNode->leftC == nullptr){  //���ֻ��������
			if (pNode == parent->leftC){
				parent->leftC = pNode->rightC;
			}
			else{
				parent->rightC = pNode->rightC;
			}
		}
		else if (pNode->leftC && pNode->rightC == nullptr){   //���ֻ��������
			if (pNode == parent->leftC){
				parent->leftC = pNode->leftC;
			}
			else{
				parent->rightC = pNode->leftC;
			}
		}
		else if (pNode->leftC && pNode->rightC){    //��Ů��ȫ
			if (pNode == parent->leftC){   //Ҫɾ���Ľڵ��Ǹ�ĸ�ڵ�����ӣ�ɾ�����λ��Ҫ��ԭ�Ƚڵ���Һ������
				pNode->rightC->leftC = pNode->leftC;
				parent->leftC = pNode->rightC;
			}
			else{
				pNode->leftC->rightC= pNode->rightC;  //Ҫɾ���Ľڵ��Ǹ�ĸ�ڵ���Һ��ӣ�ɾ�����λ��Ҫ��ԭ�Ƚڵ���������
				parent->rightC = pNode->leftC;
			}
		}
		else{                                        //���ӿ���
			if (pNode == parent->leftC){
				parent->leftC = nullptr;
			}
			else{
				parent->rightC = nullptr;
			}
		}
		delete pNode;     //��������ɺ�����ٽ���ɾ��
		return true;
	}

	BsNode* IfLeftMost(){
		if (_root == nullptr){
			return nullptr;
		}
		BsNode *pNode = _root;
		while (pNode->leftC){
			pNode = pNode->leftC;
		}
		return pNode;
	}
	BsNode* IfRightMost(){
		if (_root == nullptr){
			return nullptr;
		}
		BsNode *pNode = _root;
		while (pNode->rightC){
			pNode = pNode->rightC;
		}
		return pNode;
	}
	void InOrder(){  //����һ����ڸ��ⲿ���ã���Ϊ���ڵ���������privateȨ��
		InOrder(_root);
		cout << endl;
	}

private:
	void InOrder(BsNode *pNode){    //���������������������������������������������Ӧ����һ���������У�
		if (pNode){
			InOrder(pNode->leftC);
			cout << pNode->date_ << ' ';
			InOrder(pNode->rightC);
		}
	}
private:
	BsNode *_root;
};