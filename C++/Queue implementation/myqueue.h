#include <iostream>
#include <cassert>
template <typename T>
class MyQueue {
    T* tab;
    int msize; 
    int head; 
    int tail; 
public:
    MyQueue(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } 
    ~MyQueue() { delete [] tab; }
    MyQueue(const MyQueue& other); 
    MyQueue(MyQueue&& other) noexcept ; 
    MyQueue& operator=(const MyQueue& other); 
    MyQueue& operator=(MyQueue&& other) noexcept ; 
    bool empty() const { return head == tail; }
    bool full() const { return (head + msize -1) % msize == tail; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push(const T& item); 
    void push(T&& item); 
    T& front() { return tab[head]; } 
    T& back() { return tab[(tail + msize -1) % msize]; } 
    void pop(); 
    void clear(); 
    void display();
};
template <typename T>
void MyQueue<T>::push(const T& item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}
template <typename T>
void MyQueue<T>::push(T&& item) {
    tab[tail] = std::move(item);
    tail = (tail + 1) % msize;
}
template <typename T>
void MyQueue<T>::display() {
    for (int i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void MyQueue<T>::pop() {
    if(!empty()) {
        T *tab_temp = new T[msize];
        for (int i = 0; i < tail; i++) {
            tab_temp[i] = tab[i + 1];
        }
        tail--;
        delete[]  tab;
        tab = tab_temp;
    }
}

template<typename T>
void MyQueue<T>::clear() {
    while(tail != 0){
        pop();
    }
}

template<typename T>
MyQueue<T>::MyQueue(const MyQueue &other): msize(other.msize),head(other.head), tail(other.tail), tab(new T[msize]) {
    for(int i = 0; i < other.tail; ++i) tab[i] = other.tab[i];
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue &&other) noexcept : msize(other.msize),head(other.head), tail(other.tail), tab(new T[msize]){
    for(int i = 0; i < other.tail; ++i) tab[i] = other.tab[i];
    other.msize =0;
    other.tail =0;
    other.tab = nullptr;
}

template<typename T>
MyQueue<T> &MyQueue<T>::operator=(const MyQueue &other) {
    for(int i = 0; i < other.tail; ++i) tab[i] = other.tab[i];
    head = other.head;
    tail = other.tail;
    return *this;
}

template<typename T>
MyQueue<T> &MyQueue<T>::operator=(MyQueue &&other)noexcept {
    for(int i = 0; i < other.tail; ++i) tab[i] = other.tab[i];
    head = other.head;
    tail = other.tail;
    other.head=0;
    other.tail=0;
    other.tab = nullptr;
    return *this;
}
