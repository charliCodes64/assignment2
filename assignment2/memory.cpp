#include <iostream>
#include "memory.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>

int boradLayout[5][5];
int boardPlayedLayout[5][5];

void memory::draw_objects(int randShape) {
	randShape = rand() % 9;
	switch (randShape) {
	case 0:
		al_draw_filled_ellipse(8, 8, 56, 56, al_map_rgb(50, 50, 50));
		break;
	case 1:
		al_draw_filled_ellipse(8, 8, 56, 56, al_map_rgb(200, 50, 200));
		break;
	case 2:
		al_draw_filled_rectangle(5, 5, 25, 15, al_map_rgb(75, 75, 75));
		break;
	case 3:
		al_draw_filled_rectangle(5, 5, 25, 15, al_map_rgb(5, 100, 5));
		break;
	case 4:
		al_draw_filled_triangle(20, 20, 25, 5, 30, 20, al_map_rgb(50, 50, 50));
		break;
	case 5:
		al_draw_filled_triangle(20, 20, 25, 5, 30, 20, al_map_rgb(150, 50, 150));
		break;
	case 6:
		al_draw_ellipse(8, 8, 56, 56, al_map_rgb(75, 100, 70), 2);
		break;
	case 7:
		al_draw_ellipse(8, 8, 56, 56, al_map_rgb(225, 100, 270), 2);
		break;
	case 8:
		al_draw_filled_pieslice(5, 10, 10, 15, 20, al_map_rgb(50, 50, 50));
		break;
	case 9:
		al_draw_filled_pieslice(5, 10, 10, 15, 20, al_map_rgb(150, 150, 150));
		break;
	}
}
int get_shape(int row, int column, bool checkShapeStatus) {

}
bool set_shape(int rowOne, int columnOne, int rowTwo, int columnTwo) {

}
void reset() {

}
void create() {

}