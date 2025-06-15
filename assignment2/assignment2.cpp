#include <allegro5/allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>	
#include <allegro5\allegro_native_dialog.h> 
#include "memory.h"
#include <iostream>
//Charlton Infinger
int mx = 0, my = 0;  

void draw_Grid() {//grid layout
	//vertical box divider
	al_draw_line(160, 0, 160, 800, al_map_rgb(100, 150, 100), 2);
	al_draw_line(320, 0, 320, 800, al_map_rgb(100, 150, 100), 2);
	al_draw_line(480, 0, 480, 800, al_map_rgb(100, 150, 100), 2);
	al_draw_line(640, 0, 640, 800, al_map_rgb(100, 150, 100), 2);

	//Horizontal box divider
	al_draw_line(0, 130, 800, 130, al_map_rgb(100, 150, 100), 2);
	al_draw_line(0, 260, 800, 260, al_map_rgb(100, 150, 100), 2);
	al_draw_line(0, 390, 800, 390, al_map_rgb(100, 150, 100), 2);
	al_draw_line(0, 520, 800, 520, al_map_rgb(100, 150, 100), 2);

	//outline for matching squares
	al_draw_line(1, 1, 800, 1, al_map_rgb(5, 150, 255), 3);
	al_draw_line(1, 1, 1, 800, al_map_rgb(5, 150, 255), 3);
	al_draw_line(1, 649, 640, 649, al_map_rgb(5, 150, 255), 3);
	al_draw_line(799, 1, 799, 520, al_map_rgb(5, 150, 255), 3);
	al_draw_line(640, 800, 640, 520, al_map_rgb(5, 150, 255), 3);
	al_draw_line(640, 520, 800, 520, al_map_rgb(5, 150, 255), 3);
	//outline for stat square
	al_draw_line(641, 649, 800, 649, al_map_rgb(255, 5, 150), 3);
	al_draw_line(799, 650, 799, 522, al_map_rgb(255, 5, 150), 3);
	al_draw_line(641, 523, 800, 523, al_map_rgb(255, 5, 150), 3);
	al_draw_line(643, 522, 643, 650, al_map_rgb(255, 5, 150), 3);
}

void draw_objects(int randShapeHolder, int xAxisTog, int yAxisTog) {//used to hold multiple shape types
	switch (randShapeHolder) {
	case 0:
		al_draw_filled_ellipse(xAxisTog + 8, yAxisTog + 8, 35, 35, al_map_rgb(50, 50, 50));
		break;
	case 1:
		al_draw_filled_ellipse(xAxisTog + 8, yAxisTog + 8, 45, 35, al_map_rgb(200, 50, 200));
		break;
	case 2:
		al_draw_filled_rectangle(xAxisTog - 25, yAxisTog - 10, xAxisTog + 55, yAxisTog + 30, al_map_rgb(75, 125, 75));
		break;
	case 3:
		al_draw_filled_rectangle(xAxisTog - 25, yAxisTog - 10, xAxisTog + 55, yAxisTog + 30, al_map_rgb(5, 100, 5));
		break;
	case 4:
		al_draw_filled_triangle(xAxisTog - 30, yAxisTog + 25, xAxisTog, yAxisTog - 25, xAxisTog + 25, yAxisTog + 50, al_map_rgb(50, 150, 50));
		al_draw_filled_triangle(xAxisTog - 28, yAxisTog + 23, xAxisTog, yAxisTog - 23, xAxisTog + 23, yAxisTog + 48, al_map_rgb(100, 50, 75));
		break;
	case 5:
		al_draw_filled_triangle(xAxisTog + 15, yAxisTog + 45, xAxisTog + 40, yAxisTog + 5, xAxisTog + 65, yAxisTog + 45, al_map_rgb(150, 50, 150));
		break;
	case 6:
		al_draw_ellipse(xAxisTog + 25, yAxisTog + 5, 30, 30, al_map_rgb(255, 0, 0), 3);
		break;
	case 7:
		al_draw_ellipse(xAxisTog + 25, yAxisTog + 2, 30, 30, al_map_rgb(225, 100, 270), 2);
		break;
	case 8:
		al_draw_filled_pieslice(xAxisTog + 2, yAxisTog + 2, 50, 2, ALLEGRO_PI + 2, al_map_rgb(150, 150, 150));
		break;
	case 9:
		al_draw_filled_pieslice(xAxisTog + 2, yAxisTog + 2, 50, 2, ALLEGRO_PI - 2, al_map_rgb(150, 15, 150));
		break;
	case 10:
		al_draw_rectangle(xAxisTog - 25, yAxisTog - 10, xAxisTog + 55, yAxisTog + 30, al_map_rgb(5, 255, 5), 3);
		break;
	case 11:
		al_draw_rectangle(xAxisTog - 25, yAxisTog - 10, xAxisTog + 55, yAxisTog + 30, al_map_rgb(255, 0, 5), 3);
		break;
	}
}
 
void firstShapeChoice(int x, int y, int cellx, int celly, int shape, memory& memorys, int& userChoice) {
	draw_objects(shape, x, y);//draws shape at coords 
	memorys.cellPlayed(cellx, celly, shape);//sets this cell as being played and cant be played again in turn
	memorys.startCell(x, y, cellx, celly);//used for comparison 
	userChoice = 1;//males chioces equal to 1 out of 2 in tuen 
}

void secondShapeChoice(int x, int y, int cellx, int celly, int shape, memory& memorys, int& userChoice) {
	draw_objects(shape, x, y);
	userChoice = 0;

	al_flip_display();
	al_rest(0.5);

	int choiceX = memorys.getCellX();
	int choiceY = memorys.getCellY();
	int cardAtX = memorys.getChoiceX();
	int cardAtY = memorys.getChoiceY();

	if (shape == memorys.get_shape(cardAtX, cardAtY)) {//comparing the 2 choices
		int shapeCen[2][2] = { { choiceX, choiceY }, { x, y } };
		for (int i = 0; i < 2; ++i) {//gets the x and y of first and second card and draws the rectagle over them
			int tempX = shapeCen[i][0];
			int tempY = shapeCen[i][1];
			al_draw_filled_rectangle(tempX - 79, tempY - 64, tempX + 79, tempY + 64, al_map_rgb(15, 255, 15));
		}
		memorys.cellPlayed(cellx, celly, shape);//marks shape as played if correct 
		memorys.increasePairs();
	}
	else {
		al_draw_filled_rectangle(choiceX - 70, choiceY - 50, choiceX + 70, choiceY + 50, al_map_rgb(0, 0, 0));//recovers wrong choices 
		al_draw_filled_rectangle(x - 70, y - 50, x + 70, y + 50, al_map_rgb(0, 0, 0));
		memorys.cellPlayed(cardAtX, cardAtY, -1);//resetting both cards
		memorys.cellPlayed(cellx, celly, -1);
	}
}
//uncovers card based on the cell user clicks
void covers(int x, int y, int cellx, int celly, memory& memorys, int& userChoice) {
	if (memorys.getCellPlayed(cellx, celly) != -1) {//makes sure cell hasn't been played
		return;
	}
	int shape = memorys.get_shape(cellx, celly);

	if (userChoice == 0) {
		firstShapeChoice(x, y, cellx, celly, shape, memorys, userChoice);//calls firstShapeChoice when first click
	}
	else if (userChoice == 1) {
		secondShapeChoice(x, y, cellx, celly, shape, memorys, userChoice);
	}
}
 
void get_mouse_input(int x, int y, memory& memorys, int& click) {
	int cellWidth = 160;//simple math take width and height and divide by 5 (number of cells)
	int cellHeight = 130;
	int totalWidth = 800;
	int totalHeight = 650;

	if (x < totalWidth && y < totalHeight) {//checking if mouse is within display
		int column = x / cellWidth;//this is calculating position clicked by saying if user click on x of 255 / 160 (cell width) = 2 (finds the ceiling) so this implys they are in column 2
		int row = y / cellHeight;

 		int centerX = (column * cellWidth) + 80; //find center x cord of cell adding 80 because 160/2 = 80
		int centerY = (row * cellHeight) + 65;

		covers(centerX, centerY, row, column, memorys, click);//sending location for cover
	}
}
 
 
int main()
{
 	int width = 800;
	int height = 650;

	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT* font24 = al_load_font("GoldenAge.ttf", 16, 0);
	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

 	if (!al_install_mouse()) {
		al_show_native_message_box(NULL, NULL, "ERROR", "Could not initialize mouse!", NULL, 0);
	}
	if (!display) {
		al_show_native_message_box(NULL, NULL, "ERROR", "Could not create display!", NULL, 0);
	}
	if (!font24) {
		al_show_native_message_box(NULL, NULL, "ERROR", "Could not load font!", NULL, 0);
	}
	 
	al_install_keyboard();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	 
 	bool draw = false;
	bool done = false;

	int click = 0;

	memory memorys;
	memorys.setup();

	al_clear_to_color(al_map_rgb(0, 0, 0));
	draw_Grid();
  	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (ev.mouse.button & 1)) {//detecting mouse
			mx = ev.mouse.x;
			my = ev.mouse.y;
			draw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_R) {
			if (memorys.getTotalMatched() == 12) {//grabbing everything needed to restart and reset
				memorys = memory();//new instance 
				memorys.setup();
				//click = 0;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				draw_Grid();
				al_flip_display();
			}
		}
		draw_Grid();

		int correct = memorys.getTotalMatched();
		int totalPairs = memorys.getTotalRemaining();
		al_draw_filled_rectangle(650, 530, 780, 580, al_map_rgb(0, 0, 0));//cover
		al_draw_textf(font24, al_map_rgb(255, 255, 255), 650, 535, 0, "Remaining: %d", totalPairs);//cosmetics
		al_draw_textf(font24, al_map_rgb(255, 255, 255), 650, 560, 0, "Correct4: %d", correct);

		if (correct == 12) {//checker
			al_draw_textf(font24, al_map_rgb(0, 0, 255), width / 2, height / 2, ALLEGRO_ALIGN_CENTER, "Press \"R\" to restart!");
		}

		if (draw) {
			get_mouse_input(mx, my, memorys, click);
			draw = false;
		}

		al_flip_display();
	}

	al_destroy_font(font24);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
}

