#include "Generator.h"
#include <fstream>
#include <ctime>

Generator::Generator(string filename){
  //initializes vectors for findRandomEmptyCell
  for (int i=0; i < 9; i++)
    randomRow.push_back(i);
  randomColumn = randomRow; //copy row vector to col vector
  
  newFile = filename;
  fstream file(filename, ios::out);
    file.close();  

  for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++)
          boardMatrix[i][j] = 0;
};

//findEmptyCell() with random iteration
bool Generator::findRandomEmptyCell(int &row, int &column){
  random_shuffle(randomRow.begin(), randomRow.end());
  random_shuffle(randomColumn.begin(), randomColumn.end());
  
  for (int i : randomRow)
    for (int j : randomColumn){
      if (isEmpty(i, j)){
        row = i; column = j; //sets address to index
        return true;
        }
    }      
  return false;
};

//prints sudoku to file
void Generator::printToFile(){
  ofstream outputFile(newFile);
  
  for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++)
          outputFile << boardMatrix[i][j] << " ";
    outputFile << "\n";
    }    
}

//removes random cells -- very buggy
void Generator:: removeRandomCell(int removeValue){
  bool overflow = false;
  srand((unsigned) time(NULL));
  for (int i=0; i<removeValue; i++){
    random1 = rand() % 9;
    random2 = rand() % 9;
    boardMatrix[random1][random2] = 0;
    }
}

//solve with findRandomEmptyCell instead of findEmptyCell
bool Generator::randomizeBoard(){
  int row, column;
  if (!(findRandomEmptyCell(row, column))){//iterates cells
    return true; //if all cells filled
    }
  for (int i=1; i<=9; i++){ //tries all numbers 1-9
    counter++;
      if (isValid(i, row, column)){ 
        boardMatrix[row][column] = i;
        if (randomizeBoard()) //goes to next cell.   
          return true;
        //if there's empty cells with no valid number
        boardMatrix[row][column] = 0; //cell is empty
    }
  }
  //cout << "\nerror\n";
  return false;
}
