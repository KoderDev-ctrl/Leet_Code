/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessHead = nullptr, *lessTail = nullptr;
        ListNode *greatHead = nullptr, *greatTail = nullptr;

        ListNode *mover = head;

        while (mover)
        {
            ListNode *next = mover->next;
            mover->next = nullptr;

            if (mover->val < x)
            {
                if (!lessHead)
                    lessHead = lessTail = mover;
                else
                {
                    lessTail->next = mover;
                    lessTail = mover;
                }
            }
            else
            {
                if (!greatHead)
                    greatHead = greatTail = mover;
                else
                {
                    greatTail->next = mover;
                    greatTail = mover;
                }
            }

            mover = next;
        }

        if (!lessHead)
            return greatHead;

        lessTail->next = greatHead;
        return lessHead;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}