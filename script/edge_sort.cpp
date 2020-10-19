#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define NVERTEX 128
#define FILENAME "../Dataset/output-v7-d8.txt"
#define SORTEDFILE "../Dataset/output-v7-d8_sorted.txt"

int main(){
    int from, to;
    int **graph = new int *[NVERTEX];
    for (int i = 0; i < NVERTEX; i++){
        graph[i] = new int[NVERTEX];
        for (int j = 0; j < NVERTEX; j++){
            graph[i][j] = 0;
        }
    }
    ifstream edgeListFile;
    edgeListFile.open(FILENAME);
    while(!edgeListFile.eof()){
        edgeListFile >> from >> to;
        graph[from][to] = 1;
    }
    edgeListFile.close();
    ofstream sortedEdgeListFile;
    sortedEdgeListFile.open(SORTEDFILE);
    for (int i = 0; i < NVERTEX; i++){
        for (int j = 0; j < NVERTEX; j++){
            if (graph[i][j] == 1){
                sortedEdgeListFile << i << "\t" << j << endl;
            }
        }
    }
    sortedEdgeListFile.close();
    for (int i = 0; i < NVERTEX; i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;
}