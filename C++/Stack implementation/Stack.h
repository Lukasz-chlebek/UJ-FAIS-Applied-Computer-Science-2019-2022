#include "arraylist.h"
#include <iostream>

template<typename T>
class Stack{
    ArrayList<T> arr;
public:
    Stack(){ArrayList<T>();}
    ~Stack(){arr.clear();}
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    bool empty(){return  arr.empty();}
    bool full(){return arr.full();}
    int size(){return arr.size();}
    int max_size(){return arr.max_size();}
    void push(const T &item){arr.push_front(item);}
    void pop(){arr.pop_front();}
    T& top(){return arr.front();}
    void clear(){arr.clear();}
    void display();
};

template<typename T>
Stack<T>::Stack(const Stack &other): Stack() {
    arr = other.arr;
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &other) {
    arr = other.arr;
    return *this;
}

template<typename T>
void Stack<T>::display() {
    std::cout<<"Top of stack->   ";
    arr.display();
}


