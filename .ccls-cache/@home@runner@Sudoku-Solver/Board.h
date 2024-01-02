#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

struct boardData{
  int rows;
  int columns;

  string gameFile;
  string gameType;
  
};

class Board{
   protected:
    boardData board_data();
    const int ROW_NUM = 9;
    const int COLUMN_NUM = 9;
    int version = 0; //for default constructor
    int counter = 0;

    int boardMatrix[9][9];

  public:
  
    Board(string);
    Board();

    void vectorBoardData(int, int, string, string){}
    boardData getBoardData(string){return board_data();};

    //print board in nice way
    void getBoardMatrix(){
      for (int i=0; i<9; i++){
        cout << "\n";
        if (i%3==0)
          cout << "-----------------------------------";
        cout << "\n";
        for (int j=0; j<9; j++){
          cout << boardMatrix[i][j] << "  ";
          if (j%3==2)
            cout << "|  ";
          
          }
       }
      };
    
    void setBoardData(int, int, string, string);
    boardData getBoardData(){
      return board_data();
    };

//checks if number is in subzone
    bool inRow(int, int);
    bool inColumn(int, int);
    bool inBox(int, int, int);

//checks if cell is empty
    bool isEmpty(int, int); 
//finds first empty cell
    bool findEmptyCell(int &, int &); 
//checks if number entered is valid
    bool isValid(int, int, int); 

//solves sudoku
    bool Solve();    
};

#endif