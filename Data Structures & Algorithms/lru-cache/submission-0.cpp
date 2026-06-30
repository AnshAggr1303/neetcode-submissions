class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:

    int cap;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        cap = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {

        Node* first = head->next;

        head->next = node;
        node->prev = head;

        node->next = first;
        first->prev = node;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        Node* node = new Node(key, value);

        mp[key] = node;

        insert(node);

        if(mp.size() > cap) {

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};