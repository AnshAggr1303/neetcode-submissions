/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> mp;

        // STEP 1: Create copy nodes
        Node* temp = head;

        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // STEP 2: Connect next and random pointers
        temp = head;

        while(temp){

            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};