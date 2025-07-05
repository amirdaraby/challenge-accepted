#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sumList = new ListNode(0);
        ListNode *current = sumList;

        int remain = 0;

        do
        {
            int l1Val = (l1 != nullptr) ? l1->val : 0;
            int l2Val = (l2 != nullptr) ? l2->val : 0;

            int sum = l1Val + l2Val + remain;

            remain = sum / 10;
            current->val = sum % 10;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;

            if (l1 == nullptr && l2 == nullptr && remain == 0)
            {
                break;
            }

            current->next = new ListNode(0);
            current = current->next;
        } while (true);

        return sumList;
    }
};

void printList(ListNode *node)
{
    while (node)
    {
        cout << node->val;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    // Creating l1 = [2, 4, 3]
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));

    // Creating l2 = [5, 6, 4]
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}