#include "Term.h"
#include <iostream>

template<typename T>
class Poly{
    Term<T> *head, *tail;
public:
    Poly(): head(nullptr), tail(nullptr){}
    ~Poly() {clear();}
    Poly(const Poly& other);
    Poly(Poly&& other);
    Poly& operator=(const Poly& other);
    Poly& operator=(Poly&& other);
    bool empty() const {return head== nullptr;}
    void clear();
    void push(const T& item, int pow);
    void push(T&& item, int pow);
    T horner(T x);
    T& operator[](int pow);
    const T& operator[](int pow) const;
    Poly<T> operator+(const Poly& poly1 ) const;
    Poly<T> operator-(const Poly& poly1 ) const;
    Poly<T> operator*(const Poly& poly1 ) const;
    friend std::ostream &operator<< (std::ostream &stream, const Poly &v1){
        Term<T> *node = v1.head;
        while (node != nullptr){
            if(node==v1.head && node->at_x>0)
                stream<<node->at_x <<"x^"<<node->power;
            else if(node->at_x>0)
                stream <<"+"<< node->at_x <<"x^"<<node->power;
            else if(node->at_x<0)
                stream<<node->at_x<<"x^"<<node->power;
            node = node->next;
        }
        return stream;
    }
};

template<typename T>
void Poly<T>::push(const T &item, int pow) {
    if(empty()){
        head =tail = new Term<T> (item, pow);
    }else if(pow> head->power){
        head = new Term<T> (item, pow, head);
    }else {
        Term<T> *temp = head;
        auto *input = new Term<T> (item, pow);
        while(temp->next!= nullptr && temp->next->power >= pow){
            temp = temp->next;
        }
        if(temp->power == pow){
            temp->at_x = temp->at_x + item;
        } else{
            input -> next = temp ->next;
            temp->next = input;
        }
    }
}
template<typename T>
void Poly<T>::push(T&& item, int pow) {
    if(empty()){
        head =tail = new Term<T> (std::move(item), pow);
    }else if(pow> head->power){
        head = new Term<T> (std::move(item), pow, head);
    }else {
        Term<T> *temp = head;
        auto *input = new Term<T> (std::move(item), pow);
        while(temp->next!= nullptr && temp->next->power >= pow){
            temp = temp->next;
        }
        if(temp->power == pow){
            temp->at_x = temp->at_x + std::move(item);
        } else{
            input -> next = temp ->next;
            temp->next = input;
        }
    }
}
template<typename T>
T Poly<T>::horner(T x) {
    if(empty())
        return T();
    Term<T> * temp = head;
    T w = temp->at_x;
    if(temp->next!= nullptr && temp->power - temp->next->power >1){
        for(int i =1; i< temp->power - temp->next->power; i++){
            w = w*x;
        }
    }
    temp=temp->next;
    while(temp!= nullptr){
        if(temp->next!= nullptr && temp->power - temp->next->power >1) {
            w = temp->at_x + w*x;
                for (int i = 0; i < temp->power - temp->next->power-1; i++) {
                    w = w * x;
                }
        }
        else if(temp->next== nullptr  ){
                w = temp->at_x + w*x;
                for(int i =0; i< temp->power; i++){
                    w = w*x;
                }
        }else{
            w = temp->at_x + w*x;
        }
        temp=temp->next;
    }
    return w;
}

template<typename T>
void Poly<T>::clear() {
    for (Term<T> *temp; !empty(); ) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

template<typename T>
Poly<T> &Poly<T>::operator=(const Poly &other) {
    if(other.head== nullptr){
        head=tail= nullptr;
    }
    else {
        head = new Term<T>(other.head->at_x, other.head->power);
        Term<T> *temp_other = other.head->next;
        Term<T> *temp = head;
        while (temp_other != nullptr) {
            temp->next = new Term<T>(temp_other->at_x, temp_other->power);
            temp = temp->next;
            temp_other = temp_other->next;
        }
        tail = temp;
    }
        return *this;
}

template<typename T>
Poly<T> &Poly<T>::operator=(Poly &&other) {
    head = other.head;
    tail = other.tail;
    other.head= nullptr;
    other.tail = nullptr;
    return *this;
}

template<typename T>
Poly<T>::Poly(const Poly &other) {
    if(other.head== nullptr){
        head=tail= nullptr;
    }
    else{
        head = new Term<T>(other.head->at_x, other.head->power);
        Term<T> *temp_other = other.head->next;
        Term<T> *temp = head;
        while(temp_other!= nullptr){
            temp->next = new Term<T> (temp_other->at_x, temp_other->power);
            temp=temp->next;
            temp_other=temp_other->next;
        }
        tail=temp;
    }
}

template<typename T>
Poly<T>::Poly(Poly &&other) : head(other.head), tail(other.tail) {
    other.head = nullptr;
    other.tail = nullptr;
}

template<typename T>
Poly<T> Poly<T>::operator+( const Poly &poly1) const {
    Poly<T> result;
    Term<T> *temp1 = head;
    Term<T> *temp2 = poly1.head;
    while (temp1->next && temp2->next) {
        if (temp1->power > temp2->power) {
            result.push(temp1->at_x, temp1->power);
            temp1 = temp1->next;
        } else if (temp1->power < temp2->power) {
            result.push(temp2->at_x, temp2->power);
            temp2 = temp2->next;
        } else {
            result.push( temp2->at_x+temp1->at_x, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1->next || temp2->next) {
        if (temp1->next) {
            result.push(temp1->at_x, temp1->power);
            temp1 = temp1->next;
        }
        if (temp2->next) {
            result.push(temp2->at_x, temp2->power);
            temp2 = temp2->next;
        }
    }
    if (temp1->next == nullptr && temp2->next == nullptr) {
        if (temp1->power < temp2->power) {
            result.push(temp2->at_x, temp2->power);
            result.push(temp1->at_x,temp1->power);
        } else if (temp1->power > temp2->power) {
            result.push(temp1->at_x, temp1->power);
            result.push(temp2->at_x, temp2->power);
        }else{
            result.push(temp1->at_x+temp2->at_x, temp1->power);
        }
    }
    return result;
}

template<typename T>
Poly<T> Poly<T>::operator*(const Poly &poly1) const {
    Poly<T> result;
    Term<T>* temp1 = head;
    Term<T>* temp2 = poly1.head;
    while(temp1!= nullptr){
        while(temp2!= nullptr){
            result.push(temp1->at_x*temp2->at_x,temp1->power+temp2->power);
            temp2 = temp2->next;
        }
        temp2 = poly1.head;
        temp1 = temp1->next;
    }
    return result;
}

template<typename T>
Poly<T> Poly<T>::operator-(const Poly &poly1) const {
    Poly<T> result;
    Term<T> *temp1 = head;
    Term<T> *temp2 = poly1.head;
    while (temp1->next && temp2->next) {
        if (temp1->power > temp2->power) {
            result.push(temp1->at_x,temp1->power);
            temp1 = temp1->next;
        } else if (temp1->power < temp2->power) {
            result.push(-temp2->at_x, temp2->power);
            temp2 = temp2->next;
        } else {
            result.push( temp1->at_x-temp2->at_x, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1->next || temp2->next) {
        if (temp1->next) {
            result.push(temp1->at_x, temp1->power);
            temp1 = temp1->next;
        }
        if (temp2->next) {
            result.push(-temp2->at_x, temp2->power);
            temp2 = temp2->next;
        }
    }
    if (temp1->next == nullptr && temp2->next == nullptr) {
        if (temp1->power < temp2->power) {
            result.push(-temp2->at_x, temp2->power);
            result.push(temp1->at_x, temp1->power);
        } else if (temp1->power > temp2->power) {
            result.push(temp1->at_x, temp1->power);
            result.push(- temp2->at_x, temp2->power);

        }else{
            result.push(temp1->at_x-temp2->at_x, temp1->power);
        }
    }
    return  result;
}

template<typename T>
T &Poly<T>::operator[](int pow) {
    if(empty()){
        throw  std::out_of_range("List is empty!");
    }else{
        Term<T> * temp = head;
        while(temp!= nullptr){
            if(temp->power!=pow){
                if(temp->next!= nullptr)
                    temp= temp->next;
                else
                    break;
            } else{
                return temp->at_x;
            }
        }
        if(temp->next== nullptr && temp->power==pow){
            return  temp->at_x;
        }
        throw  std::out_of_range("No power like that");
    }

}

template<typename T>
const T &Poly<T>::operator[](int pow) const {
    if(empty()){
        throw  std::out_of_range("List is empty!");
    }else{
        Term<T> * temp = head;
        while(temp!= nullptr){
            if(temp->power!=pow){
                if(temp->next!= nullptr)
                    temp= temp->next;
                else
                    break;
            } else{
                return temp->at_x;
            }
        }
        if(temp->next== nullptr && temp->power==pow){
            return  temp->at_x;
        }
        throw  std::out_of_range("No power like that");
    }

}

