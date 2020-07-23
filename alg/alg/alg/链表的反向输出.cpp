#define _CRT_SECURE_NO_WARNINGS 1
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
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