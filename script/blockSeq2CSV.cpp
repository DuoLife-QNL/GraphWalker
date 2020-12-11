//
// Created by lihz on 12/6/20.
//

#include <fstream>
#include <map>
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>

using namespace std;

string csvName(string baseFileName){
    if (baseFileName.substr(baseFileName.size() - 4) == ".txt"){
        return baseFileName.substr(0, baseFileName.size() - 4) + ".csv";
    }else{
        cout << "Input file should be \".txt\" file" << endl;
        abort();
    }
}

int main(int argc, char *argv[]){
    int opt;
    string baseFileName;
    opt = getopt (argc, argv, "f:");
    if(opt){
        baseFileName = optarg;
    }else{
        cout << "Use -f to declare input file name!" << endl;
        return 0;
    }
    map<int, int>blockIO;
    ifstream blockSeqFile(baseFileName);
    int blockId = 0;
    string line;
    while (blockSeqFile.good()){
        getline(blockSeqFile, line);
        if (line.empty())
            continue;
        blockId = stoi(line);
        auto it = blockIO.find(blockId);
        if (it == blockIO.end()){
            blockIO[blockId] = 1;
        }else{
            it->second++;
        }
    }
    blockSeqFile.close();

    string csvFileName = csvName(baseFileName);
    ofstream csvFile(csvFileName);
    csvFile << "blockID" << ',' << "IOTimes" << endl;
    for (auto it: blockIO){
        csvFile << it.first << ',' << it.second << endl;
    }
    csvFile.close();
    return 0;
}