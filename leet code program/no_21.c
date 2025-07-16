#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;};
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* hasil;
    if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }
    else{
        while(list1->next != NULL && list2->next != NULL){
            if(list1->val < list2->val){
                if(hasil == NULL){
                    hasil = list1;
                } else {
                    hasil->next = list1;
                }
                list1 = list1->next;
            } else {
                if(hasil == NULL){
                    hasil = list2;
                } else {
                    hasil->next = list2;
                }
                list2 = list2->next;
            }
            hasil = hasil->next;
        }
        if(list1->next == NULL){
            while(list2 != NULL){
                if(hasil == NULL){
                    hasil = list2;
                } else {
                    hasil->next = list2;
                }
                list2 = list2->next;
            }
        } else {
            while(list1 != NULL){
                if(hasil == NULL){
                    hasil = list1;
                } else {
                    hasil->next = list1;
                }
                list1 = list1->next;
            }
        }
    }
    return hasil;
}