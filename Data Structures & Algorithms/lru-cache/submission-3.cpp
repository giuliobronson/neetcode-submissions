class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node() : key(-1), val(-1), next(nullptr), prev(nullptr) {}
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node*> m;
    Node *head, *tail;
    int capacity;

    LRUCache(int capacity) : capacity(capacity) {
        this->tail = new Node();
        this->head = new Node();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void removeNode(Node* target) {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }

    void bringToFront(Node* target) {
        target->prev = this->head;
        target->next = this->head->next;
        this->head->next->prev = target;
        this->head->next = target;
    }
    
    int get(int key) {
        if (this->m.count(key)) {
            Node* target = this->m[key];
            removeNode(target);
            bringToFront(target);
            return target->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* target = nullptr;

        if (!m.count(key)) {
            if (m.size() >= capacity) {
                target = this->tail->prev;
                removeNode(target);
                this->m.erase(target->key);
                delete target;
            }

            target = new Node(key, value);
            this->m[key] = target;
        }
        else {
            target = this->m[key];
            removeNode(target);
            target->val = value;
        }

        bringToFront(target);
    }
};
