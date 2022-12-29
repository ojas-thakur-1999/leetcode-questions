# Link to solutions
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/867480504/?envType=study-plan&id=data-structure-ii

# Insights
* we use an extra node situated outside the current list. this is because we want the address of head after we have finished iterating through the loop. 
* make 2 pointers pointing the the newly made node. one will store this node's address and one will store the address of the previous node, so that current node may be deleted in case of duplicates.
* iterate throught the array, and if head.next == head then remove head.next, leaving head unchanged.
* once we reach a case when head.next != head, then we need to check whether current head needs to be deleted, keep a boolean for the same
* if current head needs to be deleted, then prev.next = head.next and head = head.next
* finally return dummy.next, since it will point to the head of this list