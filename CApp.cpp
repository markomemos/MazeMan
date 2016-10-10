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

	tileSizeX = 8;
	tileSizeY = 8;

	if (displaySizeX % tileSizeX != 0  || displaySizeY % tileSizeY != 0) {
		throw std::exception("aaahahaha");
	}
	//map.resize(displaySizeY / 32, std::vector<CTile>(displaySizeX / 32));
	map.initMap(displaySizeX / tileSizeX, displaySizeY / tileSizeY);
}

void CApp::DrawTexture(int textureId, int destX, int destY) {
	SDL_Rect destRect;
	destRect.x = destX * tileSizeX;//640 
	destRect.y = destY * tileSizeY;//480 
	destRect.w = tileSizeX;//width of test texture
	destRect.h = tileSizeY;//height of textTexture

	SDL_Rect srcRect;
	srcRect.x = textureId % 10 * 32;// tileSizeX;//gives xpos of tile in tileset
	srcRect.y = textureId / 10 * 32;// tileSizeY;//gives ypos of tile in tileset 
	srcRect.w = 32;// tileSizeX;//width of tile id
	srcRect.h = 32;// tileSizeY;//height of textTexture
	SDL_RenderCopy(sdlRenderer, bkgdTexture, &srcRect, &destRect);
}


void CApp::DrawMap(CMap* map) {
	std::vector<std::vector<CTile>> mMap = map->GetMap();
	for (std::vector<std::vector<CTile>>::iterator itRow = mMap.begin(); itRow != mMap.end(); ++itRow) {
		std::vector<CTile> row = *itRow;
		for (std::vector<CTile>::iterator itCol = row.begin(); itCol != row.end(); ++itCol) {
			CTile tile = *itCol;
			DrawTexture(tile.GetTextureId(), tile.GetXPos(), tile.GetYPos());
		}
	}
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