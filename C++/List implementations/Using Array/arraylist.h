#include <iostream>
#include <cassert>
#include <bits/stdc++.h>

template <typename T>
class ArrayList {
    T* tab;
    int msize; 
    int last; 
public:
    ArrayList(int s=10) : msize(s), last(0) {
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    ~ArrayList() { delete [] tab; }
    ArrayList(const ArrayList& other); 
    ArrayList(ArrayList&& other); 
    ArrayList& operator=(const ArrayList& other); 
    ArrayList& operator=(ArrayList&& other); 
    bool empty() const { return last == 0; } 
    bool full() const { return last == msize; } 
    int size() const { return last; } 
    int max_size() const { return msize; } 
    void push_front(const T& item); 
    void push_back(const T& item); 
    T& front(){return tab[0];} 
    T& back(){return tab[last-1];} 
    void pop_front(); 
    void pop_back(); 
    void clear(); 
    void display(); 
    void reverse(); 
    void sort(); 
    void merge(ArrayList& other); 
    int erase(int pos); 
    T& operator[](int pos); 
    const T& operator[](int pos) const; 
    int index(const T& item); 
    int insert(int pos, const T& item);
};

template<typename T>
void ArrayList<T>::push_front(const T &item) {
    if(!full()){
    T * tab_temp = new T [msize];
    tab_temp[0]=item;
    for(int  i = 0; i<last; i++){
        tab_temp[i+1] = tab[i];
    }
    delete [] tab;
    tab = tab_temp;
    last++;
    }
}
template<typename T>
void ArrayList<T>::push_back(const T &item) {
    if(!full()){
        T * tab_temp = new T [msize];
        for(int i =0; i<last; i++){
            tab_temp[i]= tab[i];
        }

        tab_temp[last]=item;
        last++;
        delete [] tab;
        tab = tab_temp;
    }
}
template<typename T>
void ArrayList<T>::pop_front() {
    if(!empty()) {
        T *tab_temp = new T[msize];
        for (int i = 0; i < last; i++) {
            tab_temp[i] = tab[i + 1];
        }
        last--;
        delete[]  tab;
        tab = tab_temp;
    }
}
template<typename T>
void ArrayList<T>::pop_back() {
    if(!empty()) {
        T *tab_temp = new T[msize];
        for (int i = 0; i < last - 1; i++) {
            tab_temp[i] = tab[i];
        }
        last--;
        delete[] tab;
        tab = tab_temp;
    }
}
template<typename T>
void ArrayList<T>::display() {
    std::cout<<"[";
    for(int i =0; i<last; i++){
        std::cout<<tab[i]<<", ";
    }
    std::cout<<"]";
    std::cout<<std::endl;
}

template<typename T>
void ArrayList<T>::clear() {
    if(!empty()) {
        T *tab_temp = new T[msize];
        last = 0;
        delete[]  tab;
        tab = tab_temp;
    }

}

template<typename T>
void ArrayList<T>::reverse() {
    T * tab_temp = new T [msize];
    T temp;
    int j = last -1;
    int i=0;
    while(i<j){
        temp=tab[i];
        tab[i]=tab[j];
        tab[j]=temp;
        i++;
        j--;
    }
}

template<typename T>
void ArrayList<T>::sort() {
    std::sort(tab, tab+last);
}

template<typename T>
int ArrayList<T>::index(const T &item) {
    int to_find;
    bool to_find_bool = false;
    for(int i=0; i<last; i++){
        if(tab[i]==item) {
            to_find = i;
            to_find_bool = true;
        }
    }
    if(to_find_bool)
        return to_find;
    else
        return -1;
}

template<typename T>
int ArrayList<T>::insert(int pos, const T &item) {
    if(!full()) {
        T *tab_temp = new T[msize];
        for (int i = 0; i < pos; i++) {
            tab_temp[i] = tab[i];
        }
        tab_temp[pos] = item;
        for (int i = pos; i < last; i++) {
            tab_temp[i + 1] = tab[i];
        }
        delete[] tab;
        tab = tab_temp;
        last++;
        return pos;
    }
    else return -1;
}

template<typename T>
void ArrayList<T>::merge(ArrayList &other) {
    if(last+other.last>msize){
        std::cout<<"Error"<<std::endl;
    }
    else{
        T * tab_temp = new T[msize];
        for(int i=0 ; i<last; i++){
            tab_temp[i]=tab[i];
        }
        for(int i=0; i<other.last;i++){
            tab_temp[i+last]= other.tab[i];
        }
        std::sort(tab_temp, tab_temp+(last+other.last));
        delete [] tab;
        tab = tab_temp;
        last = last+ other.last;
    }

}

template<typename T>
const T &ArrayList<T>::operator[](int pos) const {
    return tab[pos];
}

template<typename T>
T &ArrayList<T>::operator[](int pos) {
    return tab[pos];
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList &other):  tab(new T[msize]) {
    for(int i = 0; i < last; ++i) tab[i] = other.tab[i];
}

template<typename T>
ArrayList<T>::ArrayList(ArrayList &&other): tab(other.tab) {
    other.msize = 0;
    other.tab = nullptr;
}

template<typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList &&other){
    if(this != &other){
        delete [] tab;
        last = other.last;
        tab = other.tab;
        other.last = 0;
        other.tab = nullptr;
    }
    return *this;
}

template<typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList &other){
    if(this != &other) {
        delete [] tab;
        last = other.last;
        tab= new T[msize];
        for(std::size_t i = 0u; i < last; ++i) tab[i] = other.tab[i];
    }
    return *this;
}

template<typename T>
int ArrayList<T>::erase(int pos) {
    if(!empty()){
        T* tab_temp = new T [msize];
        for(int i=0; i< pos; i++){
            tab_temp[i]= tab[i];
        }
        for(int i=pos; i< last; i++){
            tab_temp[i]= tab[i+1];
        }
        delete []tab;
        tab = tab_temp;
        last--;
        return pos;
    } else if(last==1)
        return -1;
    else if(empty())
        return -1;
}

