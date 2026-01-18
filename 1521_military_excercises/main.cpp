#include <iostream>

int main()
{
	int n, k;
	struct node {
		int num;
		node *next;
	};

	std::cin >> n >> k;

	if (n == 1) {
		std::cout << 1;
		return 0;
	}
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			std::cout << i ;
			if (i != n) {
				std::cout << " ";
			}
		}
		return 0;
	}
	node *headNode = new node;
	headNode->num = 1;
	headNode->next = NULL;
	node *prevNode = NULL; 
	for (int i = 2; i <= n; i++) {
		node *newNode = new node;
		newNode->num = i;
		newNode->next = NULL;
		if (prevNode) {
			prevNode->next = newNode;
		}
		if (i == 2) {
			headNode->next = newNode;
		}
		else if (i == n) {
			newNode->next = headNode;
		}

		prevNode = newNode;
	}

	node *curr = headNode;
	node *prev = NULL;
	while (true) {
		if (curr == NULL) {
			std::cout << prev->num;
			delete prev;
			return 0;
		}
		if (curr == prev) {
			std::cout << curr->num;
			delete curr;
			return 0;
		}
		int i = 0;
		while (++i < k) {
			prev = curr;
			curr = curr->next;
		}

		std::cout << curr->num << " ";

		prev->next = curr->next;
		delete curr;
		curr = prev->next;
	}
}