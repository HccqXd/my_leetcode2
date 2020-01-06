#include"../utils/utils/List.h"

/*�ⷨ1������ⷨ���е����ԣ�
�������շ��ص��ǵ�1������,�޶���ռ�*/
class Solution1 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1, *p2 = l2, *pre1 = l1, *pre2 = l2;	//preָ������ָ�����������һ�����ǿ�ָ��Ľڵ�λ��
		int flag = 0;
		while (p1 != nullptr&&p2 != nullptr) {
			if (flag == 1)
				++p1->val;
			p1->val = p1->val + p2->val;
			flag = (p1->val > 9) ? 1 : 0;
			if (flag == 1)
				p1->val = (p1->val) % 10;
			p1 = p1->next;
			p2 = p2->next;
			if (p1 != nullptr)
				pre1 = p1;
			if (p2 != nullptr)
				pre2 = p2;
		}
		if (p1 == nullptr&&p2 == nullptr) {	//����������ȵ������
			if (flag == 1)	//�����λΪ1��l1ĩβ��������ֵΪ1�Ľڵ�
			{
				ListNode* node = new ListNode(1);
				pre2->next = node;
				pre1->next = pre2->next;
			}
		}
		if (p2 != nullptr) { //��2�������Ƚϳ����
			ListNode* pp2 = p2, *pre = pre2;
			while (pp2 != nullptr) {
				if (flag == 1)
					++(pp2->val);
				flag = (pp2->val > 9) ? 1 : 0;
				if (flag == 1) {
					pp2->val = (pp2->val) % 10;
				}
				if (pp2 != nullptr)	//pre����ָ������l2�����Ϊ�սڵ�
					pre = pp2;
				pp2 = pp2->next;
			}
			if (flag == 1)
			{
				ListNode* node = new ListNode(1);
				pre->next = node;
			}
			pre1->next = pre2;	//������l2ʣ��ڵ㸳������l1
		}
		if (p1 != nullptr) {	//��1�������Ƚϳ����
			ListNode* pp1 = p1, *pre = pre1;
			while (pp1 != nullptr) {
				if (flag == 1)
					++(pp1->val);
				flag = (pp1->val > 9) ? 1 : 0;
				if (flag == 1) {
					pp1->val = (pp1->val) % 10;
				}
				if (pp1 != nullptr)
					pre = pp1;
				pp1 = pp1->next;

			}
			if (flag == 1)
			{
				ListNode* node = new ListNode(1);
				pre->next = node;
			}
		}
		return l1;
	}
};

/*�ⷨ2(�ٷ����):�½�һ�������������ؽ��*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(-1);
		ListNode* p1 = l1, *p2 = l2, *p = res;
		int flag = 0;
		while (p1 != nullptr || p2 != nullptr) {
			int x = (p1 != nullptr) ? p1->val : 0;
			int y = (p2 != nullptr) ? p2->val : 0;
			int sum = flag + x + y;
			flag = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			if (p1 != nullptr)
				p1 = p1->next;
			if (p2 != nullptr)
				p2 = p2->next;
		}
		if (flag > 0) {
			p->next = new ListNode(flag);
		}
		return res->next;
	}
};

int main(int argc, char** argv) {
	ListNode* l1, *l2;
	Solution1 s;
	l1 = initlist();
	l2 = initlist();
	s.addTwoNumbers(l1->next, l2->next);
	ListNode* p1 = l1->next;
	while (p1 != nullptr) {
		cout << p1->val << " ";
		p1 = p1->next;
	}
	destroylist(p1);
	cout << endl;
	return 0;
}