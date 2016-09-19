#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
	Draw = false;
	CEvent::OnEvent(Event);
	return;
}

void CApp::OnExit() {
	Running = false;
}

void CApp::OnKeyDown(SDL_Event* Event) {
	switch (Event->key.keysym.sym) {
		case SDLK_RIGHT: {
			Draw = true;
			moveDirX = 1;
			break;
		}
		case SDLK_UP: {
			Draw = true;
			moveDirY = -1;//because pixel number is low at the top, high at the bottom;
			break;
		}
		case SDLK_LEFT: {
			Draw = true;
			moveDirX = -1;
			break;
		}
		case SDLK_DOWN: {
			Draw = true;
			moveDirY = 1;
			break;
		}
	}
}