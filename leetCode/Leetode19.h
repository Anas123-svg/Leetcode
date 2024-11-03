#pragma once
#include<iostream>
#include<stack>
#include<string>
#include <queue>
using namespace std;



 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* temp = head;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		int ind = count - n;
		ListNode* temp2 = dummy;
		for (int i = 0; i < ind; i++) {
			temp2 = temp2->next;
		}
		ListNode* nodeToRemove = temp2->next;
		temp2->next = nodeToRemove->next;
		delete nodeToRemove;

		return dummy->next;
	}

};