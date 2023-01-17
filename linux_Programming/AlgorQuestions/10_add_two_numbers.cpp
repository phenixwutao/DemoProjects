struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

  ListNode *answer = new ListNode(0);
  ListNode *curr = answer;

  int carry = 0;
  while (l1 && l2)
  {
    int val = l1->val + l2->val + carry;
    int digit = val % 10;
    carry = val / 10;

    ListNode *node = new ListNode(digit);
    curr->next = node;
    curr = node;

    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1)
  {
    int val = l1->val + carry;
    int digit = val % 10;
    carry = val / 10;

    ListNode *node = new ListNode(digit);
    curr->next = node;
    curr = node;

    l1 = l1->next;
  }

  while (l2)
  {
    int val = l2->val + carry;
    int digit = val % 10;
    carry = val / 10;

    ListNode *node = new ListNode(digit);
    curr->next = node;
    curr = node;
    l2 = l2->next;
  }

  if (carry)
    curr->next = new ListNode(carry);

  return answer->next;
}
