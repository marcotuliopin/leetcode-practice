struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 *TWO POINTERS APROACH
 *TIME COMPLEXITY: O(n)
 *SPACE COMPLEXITY: O(1) 
 */
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    ListNode *list3;

    // Test any of the lists are empty. If so, returns the other one.
    if (!list1)
        return list2;
    else if (!list2)
        return list1;
    
    // Defines the head of the new list.
    if (list1->val < list2->val)
    {
        list3 = list1;
        list1 = list1->next;
    }
    else
    {
        list3 = list2; 
        list2 = list2->next;
    }

    ListNode *it3 = list3; // Creates an iterator for the new list.
    
    // Decides whether to pick the next element of the list1 or of the list2.
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            it3->next = list1;
            list1 = list1->next;
        }
        else
        {
            it3->next = list2;
            list2 = list2->next;
        }
        it3 = it3->next;
    }

    // Finishes the new list with the last values of list1 or list2.
    if (list1)
        it3->next = list1;
    else if (list2)
        it3->next = list2;

    return list3;
}
