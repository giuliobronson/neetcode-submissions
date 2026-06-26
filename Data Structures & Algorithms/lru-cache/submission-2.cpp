class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node() : key(-1), val(-1), next(nullptr), prev(nullptr) {}
        Node(int key, int val, Node* next, Node* prev) : key(key), val(val), next(next), prev(prev) {}
    };

    unordered_map<int, Node*> m;
    Node *head, *tail;
    int capacity;


    LRUCache(int capacity) : capacity(capacity) {
        this->tail = new Node();
        this->head = new Node(-1, -1, this->tail, nullptr);
        this->tail->prev = this->head;
    }
    
    int get(int key) {
        if (this->m.count(key)) {
            Node* target = this->m[key];

            target->prev->next = target->next;
            target->next->prev = target->prev;

            target->prev = this->head;
            target->next = this->head->next;

            this->head->next->prev = target;
            this->head->next = target;
            return this->m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (!m.count(key) && m.size() < capacity) { // insertion of new node
            Node* newNode = new Node(key, value, this->head->next, this->head);
            this->head->next->prev = newNode;
            this->head->next = newNode;
            this->m[key] = newNode;
        } 
        else if (!m.count(key) && m.size() >= capacity) { // deletion of the last
            Node* target = this->tail->prev;

            target->prev->next = target->next;
            target->next->prev = target->prev;

            this->m.erase(target->key);
            delete target;


            Node* newNode = new Node(key, value, this->head->next, this->head);
            this->head->next->prev = newNode;
            this->head->next = newNode;
            this->m[key] = newNode;
        }
        else if (m.count(key)) { // update of node
            Node* target = this->m[key];

            target->prev->next = target->next;
            target->next->prev = target->prev;

            target->prev = this->head;
            target->next = this->head->next;

            this->head->next->prev = target;
            this->head->next = target;

            target->val = value;
        }
    }
};
