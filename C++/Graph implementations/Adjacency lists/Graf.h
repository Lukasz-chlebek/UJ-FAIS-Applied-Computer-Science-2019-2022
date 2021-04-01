#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "edge.h"


class Graf
{
    std::vector<std::vector<edge>> vertexList;
    int size =0;
public:
    Graf() = default;
    void createVertices(int howmany);
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx);
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path);
};

void Graf::createVertices(int howmany) {
    size =howmany;
    vertexList.resize(size);
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    for(int i=0; i<vertexList.size(); i++){
        if(vertexList[i].empty()){
            vertexList[i].push_back( edge(i_Vertex_Index_1,i_Vertex_Index_2));
            break;
        } else if(vertexList[i][0].vertex_Index1==i_Vertex_Index_1){
            vertexList[i].push_back( edge(i_Vertex_Index_1,i_Vertex_Index_2));
            break;
        }
    }
}

bool Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    for(int i =0; i<vertexList.size();  i++){
        if(!vertexList[i].empty() && vertexList[i][0].vertex_Index1==i_Vertex_Index_1){
            for(int j =0; j<vertexList[i].size(); j++){
                if(vertexList[i][j].vertex_Index2==i_Vertex_Index_2){
                    vertexList[i].erase(vertexList[i].begin()+j);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    for(int i =0; i<vertexList.size();  i++) {
        if (!vertexList[i].empty() && vertexList[i][0].vertex_Index1 == i_Vertex_Index_1) {
            for(int j =0; j<vertexList[i].size(); j++){
                if(vertexList[i][j].vertex_Index2==i_Vertex_Index_2){
                    return true;
                }
            }
        }
    }
    return false;
}

int Graf::vertexDegree(int idx) {
    int result=0;
    for(int i =0; i<vertexList.size(); i++){
        if( !vertexList[i].empty()&& vertexList[i][0].vertex_Index1==idx){
            result = vertexList[i].size();
        }
    }
    return result;
}

std::vector<int> Graf::getNeighbourIndices(int idx) {
    int temp=0;
    std::vector<int> result;
    for(int i =0; i<vertexList.size(); i++){
        if(!vertexList[i].empty() && vertexList[i][0].vertex_Index1==idx){
            temp =i;
        }
    }
    for(int j=0 ;j<vertexList[temp].size(); j++){
        result.push_back(vertexList[temp][j].vertex_Index2);
    }
    return result;
}

void Graf::printNeighbourIndices(int idx) {
    auto vec = getNeighbourIndices(idx);
    for(int i=0; i <vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<"\n";
}

int Graf::getNumberOfEdges() {
    int count=0;
    for(int i =0; i<vertexList.size(); i++){
        count += vertexList[i].size();
    }
    return count;
}

void Graf::readFromFile(std::string path) {
    int amount=0;
    int a, b;
    std::fstream in(path);
    in >> amount;
    size = amount;
    this->createVertices(size);
    while(in>>a>>b){
        this->addEdge(a,b);
    }
}










