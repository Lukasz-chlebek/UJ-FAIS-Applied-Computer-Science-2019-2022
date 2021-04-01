#include <iostream>

class PriorityQueue {
    int  aktSize =0;
    int const maxsize = 1000;
    int *table;

    void shiftUp(int i);
    int getChildrenL(int i);
    int getChildrenP(int i);
    int getParent(int i);
    void swap(int &a, int &b);
    void shiftDown(int i);
public:
    PriorityQueue();
    void insert(int elem);
    void removeRoot();
    void wypisz();
    int getSize(){return aktSize;}
};

PriorityQueue::PriorityQueue(): table(new int [maxsize]){}

void PriorityQueue::wypisz() {
    std::cout<<"Position ";
    for(int i=0; i< aktSize; i++){
        std::cout<<i+1<<"   ";
    }
    std::cout<<"\n";
    std::cout<<"Value ";
    for(int i=0; i<aktSize; i++){
        std::cout<<table[i]<<"   ";
    }
    std::cout<<"\n\n";
}

int PriorityQueue::getChildrenL(int i) {
    if(i>=0 && ((2*i)+1)<aktSize)
        return (2*i)+1;
    return i;
}

int PriorityQueue::getChildrenP(int i) {
    if(i>=0 && ((2*i)+2)<aktSize)
        return (2*i)+2;
    return i;
}

int PriorityQueue::getParent(int i) {
    if(i>=0 && (i/2)<aktSize)
        return (i/2);
    return i;
}

void PriorityQueue::shiftUp(int i) {
    while( i > 0 && table[getParent(i)]< table[i]){
        swap(table[getParent(i)],table[i]);
        i = getParent(i);
    }
}

void PriorityQueue::swap(int &a, int &b) {
    int t = a;
    a =b;
    b= t;
}

void PriorityQueue::insert(int elem) {
    table[aktSize] = elem;
    shiftUp(aktSize);
    aktSize++;
}

void PriorityQueue::shiftDown(int i) {
    int temp_max = i;
    int left =getChildrenL(i);
    int right = getChildrenP(i);

    if(table[left]> table[temp_max]){
        temp_max = left;
    }
    if(table[right]> table[temp_max]){
        temp_max = right;
    }

    if(i!=temp_max){
        swap(table[i], table[temp_max]);
        shiftDown(temp_max);
    }
}

void PriorityQueue::removeRoot() {
    swap(table[0],table[aktSize-1]);
    aktSize--;
    shiftDown(0);

}


