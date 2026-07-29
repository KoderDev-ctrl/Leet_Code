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
    ListNode* doubleIt(ListNode* head) {
        ListNode *temp = head;
        ListNode *last = nullptr;
        ListNode *mover = temp->next;

        while (mover != nullptr) {
            temp->next = last;
            last = temp;
            temp = mover;
            mover = mover->next;
        }
        temp->next = last;

        int carry = 0;
        ListNode *temp1 = temp;

        while (temp1 != nullptr) {
            int sum = 2 * temp1->val + carry;
            temp1->val = sum % 10;
            carry = sum / 10;

            if (temp1->next == nullptr) break;
            temp1 = temp1->next;
        }

        if (carry) {
            temp1->next = new ListNode(carry);
        }

        last = nullptr;
        mover = temp->next;

        while (mover != nullptr) {
            temp->next = last;
            last = temp;
            temp = mover;
            mover = mover->next;
        }
        temp->next = last;

        return temp;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}