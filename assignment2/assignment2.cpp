#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>
#include "memory.h"

void Draw_Grid(){
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
///used to hold objects at random and to store the x/y axis toggle to use for positioning when the map is created
void draw_objects(int randShapeHolder, int xAxisTog, int yAxisTog) {
	switch (randShapeHolder) {
	case 0:
		al_draw_filled_ellipse(xAxisTog + 8, yAxisTog + 8, 5, 5, al_map_rgb(50, 50, 50));
		break;
	case 1:
		al_draw_filled_ellipse(xAxisTog + 8, yAxisTog + 8, 5, 5, al_map_rgb(200, 50, 200));
		break;
	case 2:
		al_draw_filled_rectangle(xAxisTog + 5, yAxisTog + 5, xAxisTog + 25, yAxisTog + 15, al_map_rgb(75, 75, 75));
		break;
	case 3:
		al_draw_filled_rectangle(xAxisTog + 5, yAxisTog + 5, xAxisTog + 25, yAxisTog + 15, al_map_rgb(5, 100, 5));
		break;
	case 4:
		al_draw_filled_triangle(xAxisTog + 20, yAxisTog + 20, xAxisTog + 25, yAxisTog + 5, xAxisTog + 30, yAxisTog + 20, al_map_rgb(50, 50, 50));
		break;
	case 5:
		al_draw_filled_triangle(xAxisTog + 20, yAxisTog + 20, xAxisTog + 25, yAxisTog + 5, xAxisTog + 30, yAxisTog + 20, al_map_rgb(150, 50, 150));
		break;
	case 6:
		al_draw_ellipse(xAxisTog + 25, yAxisTog + 5, 5, 5, al_map_rgb(255, 0, 0), 2);
		break;
	case 7:
		al_draw_ellipse(xAxisTog + 8, yAxisTog + 8, 5, 5, al_map_rgb(225, 100, 270), 2);
		break;
	case 8:
        al_draw_filled_pieslice(xAxisTog + 2, yAxisTog + 2, 50, 2, ALLEGRO_PI + 2, al_map_rgb(150, 150, 150));
		break;
	case 9:
		al_draw_filled_pieslice(xAxisTog + 2, yAxisTog + 2, 50, 2, ALLEGRO_PI - 2, al_map_rgb(150, 15, 150));
		break;
	case 10:
		al_draw_rectangle(xAxisTog + 5, yAxisTog + 5, xAxisTog + 25, yAxisTog + 15, al_map_rgb(5, 255, 5), 3);
		break;
    case 11:
        al_draw_rectangle(xAxisTog + 12, yAxisTog + 8, xAxisTog + 21, yAxisTog + 16, al_map_rgb(255, 0, 5), 3);
        break;
	}
}
void add_objects_to_Board(memory & game, int cellWidth, int cellHeight) {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            int currShape = game.boardLayout[row][col];
            int centerX = col * cellWidth + cellWidth / 2;
            int centerY = row * cellHeight + cellHeight / 2;
            
            draw_objects(currShape, centerX, centerY);
        }
    }
}

void Draw_Status() {

}


int main()
{
    const int width = 800;
    const int height = 650;
    const int cellWidth = 160;
    const int cellHeight = 130;

    al_init();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT* font24 = al_load_font("GoldenAge.ttf", 24, 0);
    ALLEGRO_DISPLAY* display = al_create_display(width, height);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    if (!al_install_mouse()) {
        al_show_native_message_box(NULL, NULL, "ERROR", "Could not initialize mouse!", NULL, 0);
        return -1;
    }
    if (!display) {
        al_show_native_message_box(NULL, NULL, "ERROR", "Could not create display!", NULL, 0);
        return -1;
    }
    if (!font24) {
        al_show_native_message_box(NULL, NULL, "ERROR", "Could not load font!", NULL, 0);
        return -1;
    }  

	Draw_Grid();
    memory gameLog;
    gameLog.create(); 

    add_objects_to_Board(gameLog, cellWidth, cellHeight); 
    al_flip_display();

    bool done = false;
    while (!done) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
    }
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    return 0;
} 




