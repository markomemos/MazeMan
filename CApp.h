#ifndef _CAPP_H_
#define _CAPP_H_
#include <SDL.h>
#ifdef __cplusplus
extern "C"
#endif

#include "CEvent.h"

class CApp : CEvent {

private:

	bool Running;
	bool Draw;
	int moveDirX;
	int moveDirY;
	int curPosX;
	int curPosY;

	SDL_Window *sdlWindow;

	SDL_Renderer *sdlRenderer;

	SDL_Texture* testTexture;
	SDL_Texture* bkgdTexture;
	//SDL_Window* Surf_Display;

public:

	CApp();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();

	void OnExit();

	void CApp::OnKeyDown(SDL_Event* Event);

	SDL_Renderer* GetRenderer() {
		return sdlRenderer;
	}
};

#endif