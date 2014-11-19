/*
 * =====================================================================================
 *
 *       Filename:  swap-nodes-in-paris.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年11月19日 20时42分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        
        ListNode *anchor = head;
        if (head != NULL && head->next != NULL)
            anchor = head->next;
        
        
        ListNode *p = NULL;
        while (head != NULL && head->next != NULL) {
            ListNode *former = head;
            ListNode *letter = former->next;
            
            if (p != NULL) p->next = letter;
            letter->next = former;
            former->next = third;
            
            head = former->next;
            p = former;
        }
        return anchor;
    }
};

int main()
{
    Solution test;
}
