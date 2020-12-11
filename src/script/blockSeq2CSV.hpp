/** 
 * @Author: Hongzheng-Li 
 * @Email: Ethan.Lee.QNL@gmail.com
 * @Date:  12/11/20
 */

#ifndef GRAPHWALKER_BLOCKSEQ2CSV_HPP
#define GRAPHWALKER_BLOCKSEQ2CSV_HPP

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

void blockSeq2CSV(string blockSeqFileName, string csvFileName){
    map<int, int>blockIO;
    ifstream blockSeqFile(blockSeqFileName);
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

    ofstream csvFile(csvFileName);
    csvFile << "blockID" << ',' << "IOTimes" << endl;
    for (auto it: blockIO){
        csvFile << it.first << ',' << it.second << endl;
    }
    csvFile.close();
}

#endif //GRAPHWALKER_BLOCKSEQ2CSV_HPP
