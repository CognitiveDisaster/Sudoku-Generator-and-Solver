#include "Board.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
using namespace std;


void Board::setBoardData(int rows = 9, int columns = 9, string fileName = "sudoku2", string gameType = "Normal"){
};


Board::Board(string fileName){ //generates board from file
  fstream file;
  file.open(fileName);
  if (!file) 
    cout << "Error";

  for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++)
          file >> boardMatrix[i][j];
  file.close();
  };

Board::Board(){ //generates empty board with sudokuX title
  string versionString = "sudoku" + to_string(version);

  while (!("sudoku"))
    versionString = to_string(version++);

  fstream file("newSudoku");

  for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++)
          file >> boardMatrix[i][j];
  file.close();  
}


//checks if number is in subzone
bool Board::inRow(int value, int row){ 
  //if value in row
  for (int i=0; i<9; i++)
    if (boardMatrix[row][i] == value)
      return true;
  return false;
};

bool Board::inColumn(int value, int column){
  //if value in column
  for (int i=0; i<9; i++)
    if (boardMatrix[i][column] == value)
      return true;
  return false;
};


bool Board::inBox(int value, int row, int column){
//check whether num is present in 3x3 box or not

   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         if (boardMatrix[i+row][j+column] == value)
            return true;
   return false;
  };
  


//returns ture if boardMatrix = 0
bool Board::isEmpty(int row, int column){
  return boardMatrix[row][column] == 0;
}; 

//finds first empty cell
bool Board::findEmptyCell(int &row, int &column){
  for (row=0; row<9; row++)
    for (column=0; column<9; column++){
      if (isEmpty(row, column))
        return true;
    }      
  return false;
};

//checks if number is valid
bool Board::isValid(int value, int row, int column){
  return !(inRow(value, row) || inColumn(value, column) || inBox(value, row-row%3, column-column%3));
}; 

int counter = 0;
bool Board::Solve(){
  int row, column;
  if (!(findEmptyCell(row, column))){ 
    //if all cells filled
    return true;
    }
  for (int i=1; i<=9; i++){ //tries all numbers 1-9
    counter++;
      if (isValid(i, row, column)){ //if number works
        boardMatrix[row][column] = i;
        if (Solve()) //goes to next cell
          return true; 
        boardMatrix[row][column] = 0; //cell becomes empty if future cells have error   
    }
  }
  return false;
}

