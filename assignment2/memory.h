
class memory {

public:
	int boardLayout[5][5];
	int boardPlayedLayout[5][5];
	//void draw_objects(int randShape); //moved to main 
	int get_shape(int row, int column, bool checkShapeStatus);
	int set_shape(int row, int column, int shape, bool setShapeStatus);
	bool compare(int rowOne, int columnOne, int rowTwo, int columnTwo);
	void reset();
	void create(); //done 

};