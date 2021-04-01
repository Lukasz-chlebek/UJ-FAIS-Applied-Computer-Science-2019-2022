#include <iostream>     
#include <cassert>    

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *next, *prev;
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
            : value(item), next(nptr), prev(pptr) {} 
    ~DoubleNode() = default;  
};


template <typename T>
class DoubleList {
    int length=0;
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(); 
    DoubleList(const DoubleList& other); 
    DoubleList(DoubleList&& other);
    DoubleList& operator=(const DoubleList& other); 
    DoubleList& operator=(DoubleList&& other); 
    bool empty() const { return head == nullptr; }
    int size() const; 
    void push_front(const T& item); 
    void push_front(T&& item); 
    void push_back(const T& item); 
    void push_back(T&& item); 
    T& front() const { return head->value; } 
    T& back() const { return tail->value; } 
    void pop_front(); 
    void pop_back(); 
    void clear();
    void display(); 
    void display_reversed(); 
    
    int erase(int pos); 
    T& operator[](int pos); 
    const T& operator[](int pos) const; 
    int index(const T& item); 
    int insert(int pos, const T& item); 
    int insert(int pos, T&& item); 
    
};

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
    length++;
}

template <typename T>
void DoubleList<T>::push_front(T&& item) {
    if (!empty()) {
        head = new DoubleNode<T>(std::move(item), head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
    length++;
}

template<typename T>
DoubleList<T>::~DoubleList() {
    for (DoubleNode<T> *node; !empty(); ) {
        node = head->next;
        delete head;
        head = node;
    }
    length=0;
}

template<typename T>
int DoubleList<T>::size() const {
    return length;
}

template<typename T>
void DoubleList<T>::display() {
    DoubleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template<typename T>
void DoubleList<T>::pop_front() {
    if (head == tail) {
        head = tail = nullptr;
    } else {
        DoubleNode<T> *node = head;
        head = head->next;
        head->prev = nullptr;
    }
    length--;

}

template<typename T>
void DoubleList<T>::pop_back() {
    if (head == tail) {
        head = tail = nullptr;
    } else {
        DoubleNode<T> *node = tail->prev;
        delete tail;
        tail = node;
        tail->next =nullptr;
        }

    length--;
}

template<typename T>
void DoubleList<T>::clear() {
    DoubleNode<T> * temp;
    for(DoubleNode<T> *node; !empty();){
        temp = head;
        head = head->next;
        delete temp;
    }
    length =0;
}

template<typename T>
void DoubleList<T>::display_reversed() {
    DoubleNode<T> *node = tail;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->prev;
    }
    std::cout << std::endl;
}

template<typename T>
void DoubleList<T>::push_back(T &&item) {
    if(!empty()){
        DoubleNode<T> *node = new DoubleNode<T>(std::move(item));
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail =node;
    }
    else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
    length++;
}

template<typename T>
void DoubleList<T>::push_back(const T &item) {
    if(!empty()){
        DoubleNode<T> *node = new DoubleNode<T>(item);
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail =node;
    }
    else {
        head = tail = new DoubleNode<T>(item);
    }
    length++;
}

template<typename T>
int DoubleList<T>::index(const T &item) {
    DoubleNode<T> *temp = head;
    bool flag = false;
    int i=0;
    for(i; temp!= nullptr; i++){
        if(temp->value==item){
            flag= true;
            break;
        }
        temp=temp->next;
    }
    if(flag)
        return i;
    else
        return -1;
}

template<typename T>
T &DoubleList<T>::operator[](int pos) {
    if(!empty()) {
        DoubleNode<T> *temp = head;
        for (int i = 0; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }
        return temp->value;
    }
}

template<typename T>
const T &DoubleList<T>::operator[](int pos) const {
    if(!empty()) {
        DoubleNode<T> *temp = head;
        for (int i = 0; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }
        return temp->value;
    }
}

template<typename T>
int DoubleList<T>::erase(int pos) {
    if(head== nullptr)
        return -1;
    DoubleNode<T> *temp = head;
    if(pos ==0){
        head = temp->next;
        head->prev = nullptr;
        delete temp;
        return 0;
    }
    for (int i=0; temp!= nullptr && i<pos-1; i++) {
        temp = temp->next;
    }
    if(temp== nullptr || temp->next== nullptr)
        return -1;
    if(pos<length-1) {
        DoubleNode<T> *next = temp->next->next;
        next->prev = temp;
        delete temp->next;
        temp->next = next;
    }
    else{
        this->pop_back();

    }
    return pos;
}

template<typename T>
int DoubleList<T>::insert(int pos, T &&item) {
    DoubleNode<T> * input = new DoubleNode<T>(std::move(item));
    if(pos==0){
    input-> next = head;
    input->prev = nullptr;
    head = input;
    }
    else if (pos >0){
        DoubleNode<T> *temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        input -> next = temp->next;
        input ->prev = temp;
        temp->next = input;
    }
    return pos;
}

template<typename T>
int DoubleList<T>::insert(int pos, const T &item) {
    DoubleNode<T> * input = new DoubleNode<T>(item);
    if(pos==0){
        input-> next = head;
        input->prev = nullptr;
        head = input;
    }
    else if (pos >0){
        DoubleNode<T> *temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        input -> next = temp->next;
        input ->prev = temp;
        temp->next = input;
    }
    return pos;
}

template<typename T>
    DoubleList<T>::DoubleList(const DoubleList &other) {
        if(other.head== nullptr){
            head=tail= nullptr;
        }
        else{
            head = new DoubleNode<T>(other.head->value);
            DoubleNode<T> *temp_other = other.head->next;
            DoubleNode<T> *temp = head;
            while(temp_other){
                temp->next = new DoubleNode<T> (temp_other->value, nullptr, temp);
                temp=temp->next;
                temp_other=temp_other->next;
            }
            tail=temp;
            length = other.length;

        }
    }


template<typename T>
DoubleList<T> &DoubleList<T>::operator=(const DoubleList &other) {
    if(this!= &other){

        head = new DoubleNode<T>(other.head->value);
        DoubleNode<T> *temp_other = other.head->next;
        DoubleNode<T> *temp = head;
        while(temp_other){
            temp->next = new DoubleNode<T> (temp_other->value, nullptr, temp);
            temp=temp->next;
            temp_other=temp_other->next;
        }
        tail=temp;
        length = other.length;
    }
    return *this;
}

template<typename T>
DoubleList<T>::DoubleList(DoubleList &&other) : head(other.head), tail(other.tail) {
    length = other.length;
    other.length = 0;
    other.head= nullptr;
    other.tail= nullptr;
}

template<typename T>
DoubleList<T> &DoubleList<T>::operator=(DoubleList &&other) {
    length = other.length;
    head = other.head;

    other.head= nullptr;
    other.tail = nullptr;
    other.length = 0;
    return *this;
}

