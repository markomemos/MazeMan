#include "CApp.h"

void CApp::OnRender() {
	
	//if (init) {
	//	SDL_Rect destRect;
	//	destRect.x = 640 / 2 - 16;
	//	destRect.y = 480 / 2 - 16;
	//	destRect.w = 32;
	//	destRect.h = 32;
	//	SDL_RenderCopy(sdlRenderer, testTexture, NULL, &destRect);
	//	SDL_RenderPresent(sdlRenderer);
	//}
	if(Draw) {
		//erase the old box by drawing a black box overtop
		//SDL_Rect startRect;
		//startRect.x = (curPosX - moveDirX) * 32;//640 / 2 - 16;
		//startRect.y = (curPosY - moveDirY) * 32;//480 / 2 - 16;
		//startRect.w = 32;
		//startRect.h = 32;
		//SDL_RenderCopy(sdlRenderer, bkgdTexture, NULL, &startRect);
		//SDL_RenderPresent(sdlRenderer);

		//redraw background behind us
		if ((curPosY - moveDirY) >= 0 && (curPosY - moveDirY) < displaySizeY / tileSizeY
			&& (curPosX - moveDirX) >= 0 && (curPosX - moveDirX) < displaySizeX / tileSizeX) {
			std::vector<std::vector<CTile>> mapArray = map.GetMap();
			CTile* tile = &(mapArray.at(curPosY - moveDirY).at(curPosX - moveDirX));
			DrawTexture(tile->GetTextureId(), tile->GetXPos(), tile->GetYPos());
		}

		//draw a new box
		SDL_Rect destRect;
		destRect.x = curPosX*tileSizeX;//640 / 2 - 16-32;
		destRect.y = curPosY*tileSizeY;//480 / 2 - 16 - 32;
		destRect.w = tileSizeX;
		destRect.h = tileSizeY;
		SDL_RenderCopy(sdlRenderer, testTexture, NULL, &destRect);

		SDL_RenderPresent(sdlRenderer);
	}
	//reset
	moveDirX = 0;
	moveDirY = 0;
}