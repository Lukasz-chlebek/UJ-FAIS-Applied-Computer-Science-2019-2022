#include<iostream>
#include <vector>

class set
{
    std::vector<int> vec;
public:
    int getSize(){return vec.size();}
    void printSet();
    void insert(int x);
    void withdraw(int x);
    bool isInSet(int x);
    set operator+(set& obj);
    set operator*(set& obj);
    set operator-(set& obj);
    bool operator==(set& obj);
    bool operator<=(set& obj);
};

void set::printSet() {
    std::cout<<"{ ";
    for(int i =0; i<vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<" }";
}

void set::insert(int x) {
    bool flag = isInSet(x);
    if(!flag){
        vec.push_back(x);
    }
}

void set::withdraw(int x) {
    for(int i =0; i<vec.size(); i++){
        if(vec[i]==x){
            vec.erase(vec.begin()+i);
        }
    }
}

bool set::isInSet(int x) {
    for(int i =0; i<vec.size(); i++){
        if(vec[i]==x){
            return true;
        }
    }
    return false;
}

set set::operator*(set &obj) {
    set a = set();
    for(int i =0; i<vec.size(); i++){
        for(int j=0; j<obj.getSize(); j++){
            if(vec[i]==obj.vec[j])
                a.vec.push_back(vec[i]);
        }
    }
    return a;
}

bool set::operator==(set &obj) {
    if(vec.size()==obj.vec.size()){
        for(int i=0; i<vec.size();i++){
            if(vec[i]!=obj.vec[i])
                return false;
        }
        return true;
    }
    return false;
}

set set::operator-(set &obj) {
    set a = set();
    bool flag = false;
    for(int i=0; i<vec.size(); i++){
        for(int j =0; j<obj.getSize();j++){
            if(vec[i]==obj.vec[j]){
                flag = true;
                break;
            }
        }
        if(!flag)
            a.vec.push_back(vec[i]);
        flag = false;
    }
    return a;
}

bool set::operator<=(set &obj) {
    bool flag = false;
    if(vec.size() <= obj.getSize()){
        for(int i =0; i<vec.size();i++){
            for(int j=0; j<obj.getSize();j++){
                if(vec[i]==obj.vec[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag)
                return false;
            flag = false;
        }
        return true;

    }
    return false;
}

set set::operator+(set &obj) {
    set a = set();
    for(int i=0; i<vec.size(); i++){
        a.vec.push_back(vec[i]);
    }
    for(int i =0; i<obj.getSize(); i++){
        if(!a.isInSet(obj.vec[i]))
            a.vec.push_back(obj.vec[i]);
    }
    return a;
}







