#define _CRT_SECURE_NO_WARNINGS 1
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
//��������{ 3, 4, 5, 1, 2 }Ϊ{ 1, 2, 3, 4, 5 }��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rota) {
//		int a = 0;
//		int b = rota.size() - 1;
//		int mid = a + ((b - a) >> 1);
//		if (rota.size() == 0)return 0;
//		while (a<b){
//			if (b - a == 1){
//				break;
//			}
//			else if (rota[mid] >= rota[a]){
//				a = mid;
//			}
//			else if (rota[mid] <= rota[a]){
//				b = mid;
//			}
//			mid = a + ((b - a) >> 1);
//		}
//		return rota[b];
//	}
//};