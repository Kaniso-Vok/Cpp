#define _CRT_SECURE_NO_WARNINGS 1
//����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
//class Solution {
//public:
//	void solve(vector<int> &v, ListNode* cur){
//		if (cur == nullptr){
//			return;
//		}
//		solve(v, cur->next);
//		v.push_back(cur->val);
//	}
//
//	vector<int> printListFromTailToHead(ListNode* head) {
//		vector<int> end;
//		solve(end, head);
//		return end;
//	}
//};