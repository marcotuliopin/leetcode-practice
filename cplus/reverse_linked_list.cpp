struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 *OPTIMAL ATTEMPT
 *TIME COMPLEXITY: O(n)
 *SPACE COMPLEXITY: O(1)
 */
ListNode*reverseList(ListNode* head) {

    ListNode *it = head, // The current node.
             *next_node = nullptr; // The previous node.
    while (it != nullptr) 
    {
        ListNode *tmp = it->next; 
        it->next = next_node; // Reverse the node.
        next_node = it; // Move foward in the list.

        if (tmp == nullptr) // Reached the end of the list.
            return it;

        it = tmp; // Move to the next node.
    }
    return nullptr;
}
