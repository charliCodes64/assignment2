#include <iostream>
#include "memory.h"
#include <cstdlib> 
#include <ctime> 
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>

int boardLayout[5][5];
int boardPlayedLayout[5][5];

//int get_shape(int row, int column, bool checkShapeStatus) {
//
//}
//bool set_shape(int rowOne, int columnOne, int rowTwo, int columnTwo) {
//
//}
void reset() {

}
void memory::create() {
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
    //passing the now shuffeled duplicants and orignals into boardLayout wich is passed to the add_objects_to_Board function in main class
    //index = 0;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            boardLayout[row][col] = duplicant[index2];
            index2++;
        }
    }
}