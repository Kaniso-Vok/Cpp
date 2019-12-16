template<class K>
struct BStreeNode{
	BStreeNode(const K& date = K())    //节点的定义
	:leftC(nullptr),    // 初始化
	rightC(nullptr),
	date_(date)
	{}
	BStreeNode<K> *leftC;      //左孩子
	BStreeNode<K> *rightC;    //右孩子
	K date_;
};

template<class K>
class BStree{
	typedef BStreeNode<K> BsNode;
public:
	BStree() :
		_root(nullptr)    
	{}
	BsNode* Find(const K& date){       //查找节点
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
		if (_root == nullptr){      //空树时开辟空间定义为根节点
			_root = new BsNode(date);
			return true;
		}
		else if (Find(date)){   //存在相同结点不进行插入
			return false;
		}
		else{
			while (pNode){         //找到插入位置，但是这里循环结束后只确认了父母结点，是做左孩子还是右孩子不确认( 因为此时值为nullptr )
				parent = pNode;
				if (pNode->date_ > date){
					pNode = pNode->leftC;
				}
				else{
					pNode = pNode->rightC;
				}
			}
			pNode = new BsNode(date);    //构造结点
			if (parent->date_ > date){       //确认是做左孩子还是右孩子
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
		if (pNode == nullptr){    //空树情况
			return false;
		}
		while (pNode){      //找到要删除的结点
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
		if (pNode == parent){      //要删除的点是根节点
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
		if (pNode == nullptr){   // 没有找到要删除的节点
			return false;
		}
		if (pNode->rightC && pNode->leftC == nullptr){  //结点只有右子树
			if (pNode == parent->leftC){
				parent->leftC = pNode->rightC;
			}
			else{
				parent->rightC = pNode->rightC;
			}
		}
		else if (pNode->leftC && pNode->rightC == nullptr){   //结点只有左子树
			if (pNode == parent->leftC){
				parent->leftC = pNode->leftC;
			}
			else{
				parent->rightC = pNode->leftC;
			}
		}
		else if (pNode->leftC && pNode->rightC){    //儿女俱全
			if (pNode == parent->leftC){   //要删除的节点是父母节点的左孩子，删除后的位置要由原先节点的右孩子替代
				pNode->rightC->leftC = pNode->leftC;
				parent->leftC = pNode->rightC;
			}
			else{
				pNode->leftC->rightC= pNode->rightC;  //要删除的节点是父母节点的右孩子，删除后的位置要由原先节点的左孩子替代
				parent->rightC = pNode->leftC;
			}
		}
		else{                                        //无子可依
			if (pNode == parent->leftC){
				parent->leftC = nullptr;
			}
			else{
				parent->rightC = nullptr;
			}
		}
		delete pNode;     //在连接完成后最后再进行删除
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
	void InOrder(){  //定义一个借口给外部调用，因为根节点在这里是private权限
		InOrder(_root);
		cout << endl;
	}

private:
	void InOrder(BsNode *pNode){    //二叉树的中序遍历，用来检查结果（二叉搜索树中序遍历应该是一个有序序列）
		if (pNode){
			InOrder(pNode->leftC);
			cout << pNode->date_ << ' ';
			InOrder(pNode->rightC);
		}
	}
private:
	BsNode *_root;
};