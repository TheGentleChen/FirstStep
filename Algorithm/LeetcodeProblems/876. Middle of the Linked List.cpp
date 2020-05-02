#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {                                //空间换回时间，避免重新遍历
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head};
        while (A.back()-> != null)
        {
            A.push_back(A.back()->next);
        }
        return A[A.size() / 2];
    }
};

class Solution {                                //Good Answer.运用增长率
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
