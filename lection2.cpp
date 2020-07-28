 #include <iostream>
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Output = l1;
        int balance = 0;
        ListNode WWE = ListNode(1);
        while(l1->next != nullptr && l2->next != nullptr) {
            if (l1->val + l2->val + balance >= 10) {
                l1->val = (l1->val + l2->val + balance) % 10;
                balance = 1;
            } else {
                l1->val = l1->val + l2->val + balance;
                balance = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1->val + l2->val + balance >= 10) {
            l1->val = (l1->val + l2->val + balance) % 10;
            balance = 1;
        } else {
            l1->val = l1->val + l2->val + balance;
            balance = 0;
        }
        if (l1->next != nullptr && l2->next == nullptr) {
            l1 = l1->next;
            while(balance != 0 && l1->next != nullptr) {
                if (l1->val + balance >= 10) {
                    l1->val = 0;
                    l1 = l1->next;
                } else {
                    l1->val = l1->val + balance;
                    balance = 0;
                    break;
                } 
            }
            if (l1->val + balance >= 10 && l1->next == nullptr) {
                l1->val = 0;
                balance = 1;
            } else {
                l1->val = l1->val + balance;
                balance = 0;
            }
            if (balance == 1) {
                l1->next = WWW;
            }
            return Output;
        }
        if (l1->next == nullptr && l2->next != nullptr) {
            l1 = l2->next;
            while(balance != 0 && l1->next != nullptr) {
                if (l1->val + balance >= 10) {
                    l1->val = 0;
                    l1 = l1->next;
                } else {
                    l1->val = l1->val + balance;
                    balance = 0;
                    break;
                } 
            }
            if (l1->val + balance >= 10 && l1->next == nullptr) {
                l1->val = 0;
                balance = 1;
            } else {
                l1->val = l1->val + balance;
                balance = 0;
            }
            if (balance == 1) {
                l1->next = WWW;
            }
            return Output;
        }
        if (l1->next == nullptr && l2->next == nullptr) {
            if (balance == 1) {
                l1->next = WWW;
                return Output;
            }
            return Output;
        }
        return Output;
    }

int main() {
    ListNode l1_ = ListNode(5);
    ListNode l2_ = ListNode(5);
    ListNode* l1 = &l1_;
    ListNode* l2 = &l2_;
    ListNode* l3 = addTwoNumbers(l1, l2);
    std::cout << l3->val << std::endl;
    l3 = l3->next;
    std::cout << l3->val << std::endl;
}