 #include <random>
#include "memory.h"
#include <iostream>

memory::memory() {
    //https://stackoverflow.com/questions/15520880/initializing-entire-2d-array-with-one-value
    //https://www.geeksforgeeks.org/c/how-to-initialize-2d-array-in-c/
	for (int i = 0; i < 5; i++) {//setting all the spots in the arrays to empty so that they can be filled
		for (int j = 0; j < 5; j++) {
			boardLayout[i][j] = -1;//for shapes
			boardPlayedLayout[i][j] = -1;//for played cells
		}
	}
}
  
void memory::setup() {//sets up the board and cells
    correct = 0;
    totalPairs = 12;
    srand(time(0));

    int index = 0;
    int index2 = 0;
    int duplicant[24];
    //making a copy of each shape to have 2 of the same 
    for (int i = 0; i < 12; i++) {
        duplicant[index] = i;
        index++;
        duplicant[index] = i;
        index++;
    }
    //going through all object in array to be shuffled
    for (int i = 0; i < 23; i++) {
        int j = rand() % (i + 1);
        int temp = duplicant[i];//going through i and randomly replacing spots with j
        duplicant[i] = duplicant[j];
        duplicant[j] = temp;
    }
    //passing the now shuffeled duplicants and orignals into boardLayout 
     for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            boardLayout[row][col] = duplicant[index2];
            index2++;
        }
    }
}
 
 void memory::cellPlayed(int x, int y, int val) {//setting position
    int& cell = boardPlayedLayout[x][y];
    cell = val;
}
void memory::startCell(int x, int y, int row, int column) {//used to get the position of the first cell the user clicks on 
	startX = x;
	startY = y;
	choiceX = row;
	choiceY = column;
}
void memory::increasePairs() {//used to track score
	correct += 1;
	totalPairs -= 1;
}
 