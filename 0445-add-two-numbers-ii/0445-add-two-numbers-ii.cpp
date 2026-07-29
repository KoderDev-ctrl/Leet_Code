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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * temp2=l2;
        ListNode * mover=temp2->next;
        ListNode * last2=nullptr;
        while(mover!=nullptr){
            temp2->next=last2;
            last2=temp2;
            temp2=mover;
            mover=mover->next;
        }
        temp2->next=last2;
        ListNode * temp1=l1;
        ListNode * mover1=temp1->next;
        ListNode * last1=nullptr;
        while(mover1!=nullptr){
            temp1->next=last1;
            last1=temp1;
            temp1=mover1;
            mover1=mover1->next;
        }
        temp1->next=last1;
        ListNode* head=new ListNode();
        ListNode* temp=head;
        ListNode* last=temp;
        int carry=0;
        while(!(temp1==nullptr && temp2==nullptr)){
            if(temp1==nullptr){
                temp->val=(temp2->val+carry)%10;
                carry=(temp2->val+carry)/10;
                temp2=temp2->next;
                ListNode* mover=new ListNode();
                last=temp;
                temp->next=mover;
                temp=mover;
            }
            else if(temp2==nullptr){
                temp->val=(temp1->val+carry)%10;
                carry=(temp1->val+carry)/10;
                temp1=temp1->next;
                ListNode* mover=new ListNode();
                last=temp;
                temp->next=mover;
                temp=mover;
            }
            else{
                temp->val=(temp1->val+temp2->val+carry)%10;
                carry=(temp1->val+temp2->val+carry)/10;
                temp1=temp1->next;
                temp2=temp2->next;
                ListNode* mover=new ListNode();
                last=temp;
                temp->next=mover;
                temp=mover;
            }
            
        }
        if(carry){temp->val=carry;}
        else{
            ListNode* x=temp;
            last->next=nullptr;
        }
        ListNode * temp3=head;
        ListNode * mover3=temp3->next;
        ListNode * last3=nullptr;
        while(mover3!=nullptr){
            temp3->next=last3;
            last3=temp3;
            temp3=mover3;
            mover3=mover3->next;
        }
        temp3->next=last3;
        return temp3;
        
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}