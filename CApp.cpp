#include "CApp.h"

CApp::CApp() {

	//Should these guys be in "OnInit()"?
	Running = true;
	Draw = true;
	//Surf_Display = NULL;
	testTexture = NULL;
	bkgdTexture = NULL;
	displaySizeX = 640;
	displaySizeY = 480;

	//map.resize(displaySizeY / 32, std::vector<CTile>(displaySizeX / 32));

}

void CApp::DrawTexture(int textureId, int destX, int destY) {
	SDL_Rect destRect;
	destRect.x = destX * 32;//640 
	destRect.y = destY * 32;//480 
	destRect.w = 32;//width of test texture
	destRect.h = 32;//height of textTexture

	SDL_Rect srcRect;
	srcRect.x = textureId % 10 * 32;//gives xpos of tile in tileset
	srcRect.y = textureId / 10 * 32;//gives ypos of tile in tileset 
	srcRect.w = 32;//width of tile id
	srcRect.h = 32;//height of textTexture
	SDL_RenderCopy(sdlRenderer, bkgdTexture, &srcRect, &destRect);
}

int CApp::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	SDL_Event Event;

	while (Running) {
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

int main(int argc, char *argv[])
{
	CApp theApp;
	return 	theApp.OnExecute();
}