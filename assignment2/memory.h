class memory {
public:
	memory();
	int get_shape(int x, int y) {return boardLayout[x][y];};
 	int getCellPlayed(int x, int y) {return boardPlayedLayout[x][y];};//gets value at positon of cell
	void setup();
	void cellPlayed(int x, int y, int i); 
	void startCell(int x, int y, int boardx, int boardy);
	void increasePairs(); 
	int getCellX() {return startX;};//returns first click cords
	int getCellY() {return startY;};
	int getChoiceX() {return choiceX;};//getting row
	int getChoiceY() {return choiceY;};
 	int getTotalRemaining() {return totalPairs;};//gets total reamining 
	int getTotalMatched() {return correct;};//gets number of matched pairs

private:
	int boardLayout[5][5]; 
	int boardPlayedLayout[5][5]; 
	int totalPairs;
	int correct;
	int startX;
	int startY;
	int choiceX;
	int choiceY;

};