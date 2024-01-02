#include <iostream>
#include <unistd.h>
#include "Board.h"
#include "Generator.h"
using namespace std;

int main() {
  string file;
  int choice;
  cout << "1. Generate Sudoku \n2. Solve Sudoku\n";
  cin >> choice;
  cin.ignore();

  cout << "Enter file name: ";
  cin >> file;

  //generates new sudoku
  if (choice == 1){
    int difficulty;
    cout << "Enter Difficulty Level (1-10): ";
    cin >> difficulty;
    difficulty *= 9;
    
    Generator newSudoku(file); //generates empty board
    newSudoku.randomizeBoard(); //solve with random iteration
    newSudoku.removeRandomCell(difficulty); 
    newSudoku.getBoardMatrix();
    newSudoku.printToFile();
  }

  if (choice == 2){

  Board Sudoku(file);
  //Sudoku.initializeSubzones();
  bool test = Sudoku.Solve();
  //boardData sudokuInfo= Sudoku.getBoardData();

  for (int i=0;i<4;i++){
    cout << "calculating...\n";
    sleep(1);
  }

  Sudoku.getBoardMatrix();

  if (test == false)
    cout << "\nNo Solution\n";
}
  }