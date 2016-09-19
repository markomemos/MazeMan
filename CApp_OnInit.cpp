#include "CApp.h"
#include "CTexture.h"

bool CApp::OnInit() {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	//if ((Surf_Display = SDL_CreateWindow("My Game Window",
	//	SDL_WINDOWPOS_UNDEFINED,
	//	SDL_WINDOWPOS_UNDEFINED,
	//	640, 480,
	//	SDL_WINDOW_OPENGL)) == NULL) {
	//	return false;
	//} //This replaces an SDL 1.2 function "SDL_SetVideoMode()" and works with SDL 2.0

	if (SDL_CreateWindowAndRenderer(640, 480, 0, &sdlWindow, &sdlRenderer) != 0) {
		return false;
	}

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);

	if ((testTexture = CTexture::OnLoad("C:\\Users\\Mark\\Documents\\Visual Studio 2015\\Projects\\game1\\Resources\\test.bmp",this)) == NULL) {
		return false;
	}
	if ((bkgdTexture = CTexture::OnLoad("C:\\Users\\Mark\\Documents\\Visual Studio 2015\\Projects\\game1\\Resources\\black.bmp", this)) == NULL) {
		return false;
	}


	//init game variables
	moveDirX = 0;
	moveDirY = 0;
	curPosX = 9;//should range from 0-19. Multiply by 32 to get left pixel position of the box thing.
	curPosY = 6;//should range from 0-14. Multiply by 32 to get top pixel position of the box thing.

	//init the bkgd
	SDL_Rect destRect;
	destRect.x = curPosX * 32;//640 / 2 - 16;
	destRect.y = curPosY * 32;//480 / 2 - 16;
	destRect.w = 32;//width of test texture
	destRect.h = 32;//height of textTexture
	SDL_RenderCopy(sdlRenderer, testTexture, NULL, &destRect);
	SDL_RenderPresent(sdlRenderer);

	return true;

}