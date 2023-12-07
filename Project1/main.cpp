

#include <vector> 
using std::vector;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    bool isPalindrome(ListNode* head) {
       
        ListNode* m_list = head;

        int count = 0;
        int devide = 0;

        vector<int> front = {};
        vector<int> back = {};

        for (; m_list != nullptr; ++count)
        {

            m_list = m_list->next;

        }

        devide = count % 2;
      
       if (devide == 1)// È¦¼ö
       {
           ListNode* frontstart = head;
           
           for (int i = 0; i < (count / 2) + 1; ++i)
           {
               front.push_back(frontstart->val);
               frontstart = frontstart->next;
               
            }

           while (frontstart != nullptr)
           {
               back.push_back(frontstart->val);
               frontstart = frontstart->next;
           }

           for (int i = 0; i < back.size(); ++i) {
               if (front[back.size() - i - 1] != back[i])
                   return false;
           }

           //for (int i = 0; i < (count / 2) + 1; ++i)
           //{
           //    back.push_back(head->val);
           //}
       }
       else//Â¦¼ö
       {
           ListNode* frontstart = head;

           for (int i = 0; i < (count / 2) ; ++i)
           {
               front.push_back(frontstart->val);
               frontstart = frontstart->next;

           }

           while (frontstart != nullptr)
           {
               back.push_back(frontstart->val);
               frontstart = frontstart->next;
           }

           for (int i = 0; i < back.size(); ++i) {
               if (front[back.size() - i - 1] != back[i])
                   return false;
           }
       }
       return true;
    }
};

int main()
{


}