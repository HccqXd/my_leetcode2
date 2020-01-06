#include"../utils/utils/List.h"

/*
题目描述：
	反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
	1 ≤ m ≤ n ≤ 链表长度。

示例:
	输入: 1->2->3->4->5->NULL, m = 2, n = 4
	输出: 1->4->3->2->5->NULL
*/

using namespace std;

/*解法1：前插法*/
class Solution1 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* pre_head = new ListNode(-1); //创建一个头结点，方便处理
		pre_head->next = head;
		ListNode* pre_m = pre_head, *curr = pre_head, *tmp=pre_head, *curr_m=pre_head; //pre_m指向第m个节点前一个节点,curr当前遍历的节点,tmp指向curr下一个节点
																						//curr_m指向第m个节点
		int i = 0;
		while (i <= n) {	
			tmp = curr->next; //tmp保存curr下一个节点
			if (i == m - 1) { //当遍历到第m-1个节点时，用pre_m保存当前节点，并令pre_m指向空节点
				pre_m = curr;
				pre_m->next = nullptr;
			}
			if (i == m) 
				curr_m = curr;
			if (i >= m) { //前插法，插入到pre_m前面
				curr->next = pre_m->next;
				pre_m->next = curr;
			}
			curr = tmp; 
			i++;
		}
		curr_m->next = curr; //第m个节点最终指向第m+1个节点
		return pre_head->next; //因为添加了头结点，所以返回头结点下一个节点
	}
};

/*解法2(官方解答):递归*/

int main(int argc, char** argv) {
	Solution1 s;
	ListNode* head = initlist();
	ListNode* p=s.reverseBetween(head->next, 1, 2);
	while (p != nullptr) {
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}