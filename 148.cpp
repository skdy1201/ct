#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        vector<int> temp;


        while (head) {
            temp.push_back(head->val);
            head = head->next;
        }

        sort(temp.begin(), temp.end());

        ListNode* newHead = new ListNode(temp[0]);
        ListNode* current = newHead;
        //그냥 넣어주면 오류떠서 전달할것 만들고, 동작할 것 따로 만듬

        for (int i = 1; i < temp.size(); ++i) {
            current->next = new ListNode(temp[i]);
            current = current->next;
        }

        return newHead;
    }
};
