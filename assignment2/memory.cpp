 #include <random>
#include "memory.h"
#include <iostream>

memory::memory() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			boardLayout[i][j] = -1;
			boardPlayedLayout[i][j] = -1;
		}
	}
	correct = 0;
	totalPairs = 12;

}
  
void memory::setup() {
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
 
int memory::get_shape(int x, int y) { 
	return boardLayout[x][y];
}
//gets value at positon of cell
int memory::getCellPlayed(int x, int y) {
	return boardPlayedLayout[x][y];
}
//setting position
void memory::cellPlayed(int x, int y, int val) {
    int& cell = boardPlayedLayout[x][y];
    cell = val;
}
void memory::startCell(int x, int y, int row, int column) {//used to get the position of the first cell the user clicks on 
	startX = x;
	startY = y;
	firstCardBoardX = row;
	firstCardBoardY = column;
}
void memory::increasePairs() {//used to track score
	correct += 1;
	totalPairs -= 1;
}
int memory::getTotalMatched() {//gets number of matched pairs
	return correct;
}
int memory::getTotalRemaining() {//gets total reamining 
	return totalPairs;
}