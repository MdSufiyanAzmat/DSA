class Solution {
public:

Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;  

    unordered_map<Node*, Node*> m;
    Node* newNode = new Node(head->val);
    m[head] = newNode;
    Node* oldTemp = head -> next;
    Node* newTemp = newNode;

    while(oldTemp != nullptr){
        Node* copyNode = new Node(oldTemp -> val);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;
        oldTemp = oldTemp -> next;
        newTemp = newTemp -> next;
    }

    oldTemp = head;
    newTemp = newNode;
    while(oldTemp != nullptr){
        newTemp -> random = m[oldTemp -> random];
        oldTemp = oldTemp -> next;
        newTemp = newTemp -> next;
    }
    return newNode;
}
};