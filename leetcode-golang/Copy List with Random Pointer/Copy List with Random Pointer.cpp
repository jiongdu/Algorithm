class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node* newNode(Node* src) {
    Node* node = new Node(src->val, nullptr, nullptr);
    return node;
}

Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    std::unordered_map<Node*, Node*> m;
    Node* cur = head;
    while(cur != nullptr) {
        m[cur] = newNode(cur);          //m[src, copy]
        cur = cur->next;
    }
    cur = head;
    while(cur != nullptr) {
        Node* clone = m[cur];
        clone->next = m[cur->next];     //和原来对应的映射关系
        clone->random = m[cur->random];
        cur = cur->next;
    }
    return m[head];
}

