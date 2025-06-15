class memory {
public:
	memory();
	int get_shape(int x, int y);
 	int getCellPlayed(int x, int y);
	void setup();
	void cellPlayed(int x, int y, int i); 
	void startCell(int x, int y, int boardx, int boardy);
	void increasePairs(); 
	int getCellX() {return startX;};
	int getCellY() {return startY;};
	int getChoiceX() {return firstCardBoardX;};
	int getChoiceY() {return firstCardBoardY;};
 	int getTotalRemaining(); 
	int getTotalMatched();  

private:
	int boardLayout[5][5]; 
	int boardPlayedLayout[5][5]; 
	int totalPairs;
	int correct;
	int startX;
	int startY;
	int firstCardBoardX;
	int firstCardBoardY;

};