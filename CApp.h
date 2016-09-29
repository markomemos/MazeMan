#ifndef _CAPP_H_
#define _CAPP_H_
#include <SDL.h>
#ifdef __cplusplus
extern "C"
#endif

#include "CEvent.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include "CTile.h"
#include "CMap.h"

class CApp : CEvent {

private:

	//should probably put these global vars into their own struct/class, then make those classes global. Less namespace pollution. Or at least put a "g" in front!

	//loop flags
	bool Running;
	bool Draw;

	//internal game vars
	int moveDirX;
	int moveDirY;
	int curPosX;
	int curPosY;

	//std::vector< std::vector<CTile> > map;//we should make this into char* or string?

	//display vars
	int displaySizeX;
	int displaySizeY;

	int tileSizeX;//in pixels
	int tileSizeY;

	CMap map;// = CMap(displaySizeX / tileSizeX, displaySizeY / tileSizeY);


	SDL_Window *sdlWindow;

	SDL_Renderer *sdlRenderer;

	SDL_Texture* testTexture;
	SDL_Texture* bkgdTexture;
	//SDL_Window* Surf_Display;
	//SDL_Texture paaaants[20] = {};

public:

	CApp();

	int OnExecute();

	void DrawTexture(int textureId, int destX, int destY);

	bool OnInit();
	//bool initMap();
	void DrawMap(CMap* map);

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