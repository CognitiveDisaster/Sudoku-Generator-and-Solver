#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>
#include "Board.h"
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


class Generator : public Board{
  private:
    string difficulty;
    string newFile;
    int random1;
    int random2;
    vector<int> randomRow;
    vector<int> randomColumn;
    vector<int> numberArrangement; //numbers on current board

  public:
    string getDifficulty(){
      return difficulty;
    }

    Generator(string);

    void printToFile();
    void removeRandomCell(int);

    //randomizes iteration order
    bool findRandomEmptyCell(int &, int &); 

    //solve function with findRandomEmptyCell
    bool randomizeBoard();
};

#endif