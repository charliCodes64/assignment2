#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>



int main()
{
	al_init();

	int width = 800;
	int height = 800;
	bool already_played = false;
	bool done = false;

	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_FONT* font24 = al_load_font("GoldenAge.ttf", 24, 0);

	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	if (!font24) {
		al_show_native_message_box(NULL, NULL, "ERROR", "Connot initalize Font!", NULL, NULL);
	}
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, "ERROR", "Connot initalize Allegro!", NULL, NULL);
	}
	if (!display) {
		al_show_native_message_box(NULL, NULL, "ERROR", "Connot initalize Allegro DIsplay!", NULL, NULL);
	}
	if (!al_install_mouse) {
		al_show_native_message_box(NULL, NULL, "ERROR", "Connot initalize Jerry!", NULL, NULL);
	}

 
	
	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
	}
} 




