template<typename T>
struct Node {
    T value;
    int priority;
    Node *next;
    Node() : value(T()),priority(int()), next(nullptr) {}
    Node(const T& item, const int& priority_input ,Node *ptr=nullptr) : value(item), priority(priority_input), next(ptr) {}
    ~Node() = default;
};

template<typename T>
class PriorityQueue{
    int length =0;
    Node<T> *head, *tail;
public:
    PriorityQueue(): head(nullptr), tail(nullptr){}
    ~PriorityQueue();
    bool empty() const{return head== nullptr;}
    int size() const{return length;}
    void push(const T& item, int priority_input);
    void push(T&& item,int priority_input);
    T& top(); 
    void pop();
    void clear();  
    void display();
};

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    for (Node<T> *node; !empty(); ) {
        node = head->next;
        delete head;
        head = node;
    }
    length =0;
}

template<typename T>
void PriorityQueue<T>::push(const T &item, int priority_input) {
    if(empty()){
        head =tail = new Node<T> (std::move(item),priority_input);
    }else if(priority_input> head->priority){
        head = new Node<T> (item,priority_input,head);
    }else {
        Node<T> *temp = head;
        auto *input = new Node<T> ( item,priority_input);
        while(temp->next!= nullptr && temp->next->priority > priority_input){
            temp = temp->next;
        }
        input -> next = temp ->next;
        temp->next = input;
    }
    length++;
}
template<typename T>
void PriorityQueue<T>::display() {
    Node<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << "("<<node->priority<<") ";
        node = node->next;
    }
    std::cout << std::endl;
}

template<typename T>
void PriorityQueue<T>::push(T &&item, int priority_input) {
    if(empty()){
        head =tail = new Node<T> (std::move(item),priority_input);
    }else if(priority_input> head->priority){
        head = new Node<T> (std::move(item),priority_input,head);
    }else {
        Node<T> *temp = head;
        auto *input = new Node<T> ( std::move(item),priority_input);
        while(temp->next!= nullptr && temp->next->priority > priority_input){
            temp = temp->next;
        }
        input -> next = temp ->next;
        temp->next = input;
    }
    length++;
}

template<typename T>
T &PriorityQueue<T>::top() {
    return head->value;
}

template<typename T>
void PriorityQueue<T>::pop() {
    Node<T> *node = head;
    if (head ->next == nullptr) {
        head = tail = nullptr;
    } else {
        head = head->next;
    }
    length--;
    delete node;

}

template<typename T>
void PriorityQueue<T>::clear() {
    while(head!= nullptr){
        pop();
    }
}

