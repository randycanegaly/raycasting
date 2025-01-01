#include <stdio.h>
#include </opt/homebrew/include/SDL2/SDL.h>
#include "constants.h"

int initializeWindow(void);
void destroyWindow();
void processInput(void);
void update(void);
void render(void);
void setup(void);

SDL_Window *window = NULL;//window is a pointer to an SDL_Window
SDL_Renderer *renderer = NULL;
int isGameRunning = FALSE;

int main(void) {
    //puts("Program is running.");
    isGameRunning = initializeWindow();

	setup();
	
	while(isGameRunning) {
		processInput();
		//update();
		render();
	}

	destroyWindow();

	return 0;
}

int initializeWindow(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "Error initializing SDL.\n");
		return FALSE;	
	}

	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_BORDERLESS
	);
	
	if (!window) {
		fprintf(stderr, "Error creating SDL window.\n");
		return FALSE;	
	}

	renderer = SDL_CreateRenderer(window, -1, 0);//-1 means use the default driver, 0 means I have no flags to set
	if (!renderer) {
		fprintf(stderr, "Error creating SDL renderer.\n");
		return FALSE;	
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);			
	
	return TRUE;
}

void destroyWindow(void) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void processInput(void) {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isGameRunning = FALSE;
			break;
		case SDL_KEYDOWN:
			if ( event.key.keysym.sym == SDLK_ESCAPE)
				isGameRunning = FALSE;
			printf("I saw an escape key. Closing down game.\n");	
			break;
	}
}

void update(void) {

}

void render(void) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//TO DO:
	//render all game objects for the current frame

	SDL_RenderPresent(renderer);
}

void setup(void) {

}

