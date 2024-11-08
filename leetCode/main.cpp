#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include <queue>
#include<unordered_set>
using namespace std;



struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
vector<int> removeDuplicates(const std::vector<int>& arr) {

	unordered_set<int> seen;
	vector<int> result;
	for (int num : arr) {
		if (seen.find(num) == seen.end()) {
			seen.insert(num);
			result.push_back(num);
		}
	}
	return result;
}
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* dummy = new ListNode(0); 
	vector<int>ab;
	dummy->next = head; 
	ListNode* temp = head;
	ListNode* temp2 = head;
	int i = 0, j=0; 
	while (temp != nullptr) {
		int c = temp->val;
		ab.push_back(c);
		temp = temp->next;
	}
	vector<int>temp3 = removeDuplicates(ab);
	ListNode* result = new ListNode(0); 
	ListNode* retRes = result;
	for (int i = 0; i < temp3.size(); i++) {
		result->next = new ListNode(0);
		result->val = temp3[i];
		result = result->next;
	}
	return retRes;
}
int main() {
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(1);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d; 
	d->next = e;
	ListNode* res = new ListNode();
	res = deleteDuplicates(a);

	while (res->next != nullptr) {
		cout << res->val;
		res = res->next;
	}


}