#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;

    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = result;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int current_val = sum % 10;

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = current_val;
        node->next = NULL;

        head->next = node;
        head = head->next;
    }

    return result->next;
}


// Solution
struct ListNode* solution(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0;
    int carry = 0;

    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = l3;

    while (l1 || l2) {
        sum = 0;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        sum %= 10;
        
        l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3->next->val = sum;
        l3->next->next = NULL;
        l3 = l3->next;
    }

    if (carry != 0) {
        l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3->next->val = carry;
        l3->next->next = NULL;
    }

    return head->next;
}
