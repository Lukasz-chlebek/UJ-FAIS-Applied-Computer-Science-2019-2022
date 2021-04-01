#ifndef SETIMPLEMENTATION_SETARR_H
#define SETIMPLEMENTATION_SETARR_H
class setArr
{
    int size;
    const int universeSize = 100;
    bool* table;
    bool checkRangeCorrectness(int x);
public:
    setArr();
    ~setArr();
    setArr(const setArr& object);
    void insert(int x);
    void withdraw(int x);
    bool isInSet(int i);
    int getSize();
    void clearSet();
    void printSet();
    setArr operator+(setArr& object);
    setArr operator*(setArr& object);
    setArr operator-(setArr& object);
    bool operator==(setArr& object);
    bool operator <= (setArr& object);
};

setArr::setArr(): size(0), table(new bool [universeSize]){
    for(int i =0; i<universeSize; i++){
        table[i]= false;
    }
}

bool setArr::checkRangeCorrectness(int x) {
    return x>=0 && x <=100;
}

void setArr::insert(int x) {
    if(checkRangeCorrectness(x)){
        if (!table[x]){
            table[x] = true;
            size++;
        }
    }
}

void setArr::withdraw(int x) {
    if(checkRangeCorrectness(x)){
        if(table[x]){
            table[x]=false;
        }
    }
}

bool setArr::isInSet(int i) {
    if(checkRangeCorrectness(i)) {
        return table[i];
    }
    return false;
}

int setArr::getSize() {
    return size;
}

void setArr::printSet() {
    std::cout<<"{ ";
    for(int i =0; i<universeSize; i++){
        if(table[i]){
            std::cout<<i<<" ";
        }
    }
    std::cout<<" }";
}

void setArr::clearSet() {
    for(int i =0; i<universeSize; i++){
        table[i]= false;
    }
    size =0;
}

bool setArr::operator==(setArr &object) {
    for(int i =0; i<universeSize; i++){
        if(table[i]!=object.table[i]){
            return false;
        }
    }
    return true;
}

setArr setArr::operator+(setArr &object) {
    setArr a = setArr();
    for(int i =0; i<universeSize; i++){
        if(table[i]){
            a.table[i]= table[i];
        }
        else if(object.table[i]){
            a.table[i] = object.table[i];
        }
    }
    return a;
}

setArr setArr::operator*(setArr &object) {
    setArr a = setArr();
    for(int i =0; i<universeSize; i++) {
      if(table[i] && object.table[i]){
          a.table[i]= table[i];
      }
    }
    return a;
}

setArr setArr::operator-(setArr &object) {
    setArr a = setArr();
    for(int i =0; i<universeSize; i++) {
        if(table[i] && !object.table[i]){
            a.table[i]=table[i];
        }
    }
    return a;
}

setArr::~setArr() {
    delete table;
    size=0;
}

setArr::setArr(const setArr &object):size(object.size), table(new bool [universeSize]) {
    for(int i =0; i<universeSize; i++){
        table[i] = object.table[i];
    }
}

bool setArr::operator<=(setArr &object) {
    for( int i=0; i<universeSize; i++){
        if(table[i] && !object.table[i]){
            return false;
        }
    }
    return true;
}


#endif //SETIMPLEMENTATION_SETARR_H
