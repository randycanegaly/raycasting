#include <stdio.h>
#include <SDL2/SDL.h>

void initializeWindow(void);
void processInput(void);
void update(void);
void render(void);
void setup(void);

int main(void) {
    //puts("Program is running.");
    initializeWindow();

	setup();
	
	while(1) {
		processInput();
		update();
		render();
	}

	return 0;
}

void initializeWindow(void) {
	SDL_Init(SDL_INIT_EVERYTHING);

	
}

void processInput(void) {

}

void update(void) {

}

void render(void) {

}

void setup(void) {

}

