#include<iostream>
using namespace std;
// https://leetcode-cn.com/problems/add-two-numbers
// Definition for singly-linked list.
struct ListNode{
    int val;    // 当前结点的值
    ListNode *next; // 指向下一个节点的指针
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}   // 初始化当前节点值为x，指针为空
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
    // 时间复杂度：O(max(m,n))，其中 m,n 为两个链表的长度。我们要遍历两个链表的全部位置，而处理每个位置只需要 O(1) 的时间。
    // 空间复杂度：O(max(m,n))。答案链表的长度最多为较长链表的长度 +1。
};
void PrintListNode(ListNode* head)
{
    if (head == nullptr) return;
    cout << head->val << " "; //顺序输出
    PrintListNode(head->next);  
    // cout << head->val << " "; //逆序输出
   
}

ListNode* inputListNode(){
    cout << "input elements in ListNode" << endl; 
    char c;
    int num;
    ListNode* temp1 = new ListNode; //创建新元素，
    ListNode* l1 = temp1;           //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
    cin >> num;
    temp1 ->val = num;
    while ((c = getchar()) != '\n'){   //以空格区分各个结点的值
        if (c != ' '){
            ungetc(c, stdin);       //把不是空格的字符丢回去
            cin >> num;
            ListNode* newnode = new ListNode;
            newnode->val = num;     //创建新的结点存放键盘中读入的值
            newnode->next = NULL;
            temp1->next = newnode;  //并将其赋值给temp2
            temp1 = newnode;        //此处也可以写成  temp2=temp2->next,使指针指向下一个，以待接收新元素
        }
    }
    return l1;
}
int main(){
    ListNode* l1 = inputListNode(); //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
    // PrintListNode(l1);
    // cout << endl;
    ListNode* l2 = inputListNode(); //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
    // PrintListNode(l1);
    // cout << endl;
    Solution solution;
    ListNode* answer = solution.addTwoNumbers(l1,l2);
    PrintListNode(answer);
    cout << endl;

}