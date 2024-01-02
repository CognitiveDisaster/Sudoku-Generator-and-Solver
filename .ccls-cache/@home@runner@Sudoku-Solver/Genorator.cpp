#include "Generator.h"

bool Generator::findRandomEmptyCell(int &row, int &column){
  vector<int> randomRow;
  vector<int> randomColumn;
  for (int i=0; i < 9; i++)
    randomRow.push_back(i);
  randomColumn = randomRow; //copy row vector to col vector

  random_shuffle(randomRow.begin(), randomRow.end());
  random_shuffle(randomColumn.begin(), randomColumn.end());
  
  for (int i : randomRow)
    for (int j : randomColumn){
      if (isEmpty(i, j)){
        row = i; column = j;
        return true;
        }
    }      
  return false;
};


bool Generator::Solve(int row, int column){

  if (!(findEmptyCell(row, column))){ //if all cells filled
    //cout << "\n" << counter << " calculations\n";
    return true;
    }
  for (int i=1; i<=9; i++){ //tries all numbers 1-9
    counter++;
      if (isValid(i, row, column)){ //if number works
        boardMatrix[row][column] = i;
        //cout << " (" << row << ", " << column << ", " << boardMatrix[row][column] << ") ";
        if (Solve()) //goes to next cell. if  following numbers fail
          return true;
        boardMatrix[row][column] = 0; //cell becomes empty
        
    }
  }
  return false;
}
