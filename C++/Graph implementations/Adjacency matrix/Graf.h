#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Graf
{
    int matrix[100][100];
    int numberOfVertices;

public:
    Graf();
    void createVertices(int ile);
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx);
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path);

private:
    void clear();
};

Graf::Graf() {
    for(int i =0; i < numberOfVertices; i++){
        for( int j =0; j<numberOfVertices; j++){
            matrix[i][j] = 0;
        }
    }
}

void Graf::clear() {
    for(int i =0; i < numberOfVertices; i++){
        for( int j =0; j<numberOfVertices; j++){
            matrix[i][j] = 0;
        }
    }
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    matrix[i_Vertex_Index_1][i_Vertex_Index_2]=1;
}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    matrix[i_Vertex_Index_1][i_Vertex_Index_2]=0;
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    return matrix[i_Vertex_Index_1][i_Vertex_Index_2]==1;
}

std::vector<int> Graf::getNeighbourIndices(int idx) {
    std::vector<int> result;
    for(int i=0; i<numberOfVertices; i++){
        if(matrix[idx][i]==1){
            result.push_back(i);
        }
    }
    return result;
}

int Graf::vertexDegree(int idx) {
    std::vector<int> ind = getNeighbourIndices(idx);
    return ind.size();
}

void Graf::printNeighbourIndices(int idx) {
    std::vector<int> ind = getNeighbourIndices(idx);
    for(int i=0; i<ind.size(); i++){
        std::cout<<ind[i]<<" ";
    }
    std::cout<<"\n";
}

int Graf::getNumberOfEdges() {
    int count=0;
    for(int i=0; i<numberOfVertices; i++){
        for(int j=0; j<numberOfVertices; j++){
            if(matrix[i][j]==1){
                count++;
            }
        }
    }
    return count;
}

void Graf::createVertices(int ile) {
    numberOfVertices = ile;
}

void Graf::readFromFile(std::string path) {
    int amount=0;
    int a, b;
    std::fstream in(path);
    in >> amount;
    numberOfVertices = amount;
    while(in>>a>>b){
        matrix[a][b]=1;
    }
}


