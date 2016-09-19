#include "CApp.h"

bool CApp::OnInit() {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if ((Surf_Display = SDL_CreateWindow("My Game Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640, 480,
		SDL_WINDOW_OPENGL)) == NULL) {
		return false;
	} //This replaces an SDL 1.2 function "SDL_SetVideoMode()" and works with SDL 2.0

	return true;

}