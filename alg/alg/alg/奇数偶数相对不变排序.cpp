#define _CRT_SECURE_NO_WARNINGS 1
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
//���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		int a = 0;
//		int temp;
//		for (int i = 0; i<array.size(); i++){
//			if (array[i] & 1){
//				temp = array[i];
//				int j = i;
//				while (j>a){
//					array[j] = array[j - 1];
//					j--;
//				}
//				array[a++] = temp;
//			}
//		}
//	}
//};