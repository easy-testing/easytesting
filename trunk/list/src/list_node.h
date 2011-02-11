#ifndef LIST_NODE_INCLUDED
#define LIST_NODE_INCLUDED

template<class Type>
struct ListNode {
  // Cria um no sentinela em O(1).
  ListNode() {
    left = right = this;
  }

 // Cria um novo no em O(1).
  ListNode(Type k, ListNode* l, ListNode* r) {
    key = k;
    left = l;
    right = r;
  }

  Type key;  // Valor associado ao no da lista.
  ListNode* left;  // Ponteiro para o proximo no da lista.
  ListNode* right;  // Ponteiro para o no anterior da lista.
};  // end struct Node;


#endif // LIST_NODE_INCLUDED