#include "CApp.h"
#include "CTexture.h"

#include "CMaze.h"

//bool CApp::initMap() {
//	
//	//initialize a basic map
//	for (int iRow = 0; iRow < displaySizeY / 32; iRow++) {
//		//loop through 15 rows
//		std::vector<CTile> xvect;// = *it_ytile;
//		for (int iCol = 0; iCol < displaySizeX / 32; iCol++) {
//			//loop through 20 columns
//			CTile tile;
//			tile.SetTextureId(0);
//			tile.SetXPos(iCol);
//			tile.SetYPos(iRow);
//
//
//			//set every direction to be passable at start
//			for (int i = 0; i < 4; i++) {
//				tile.SetPassable(i, true);
//			}
//
//			if (iRow == 0) {
//				tile.SetPassable(1, false);//can't go up from top row
//				tile.SetTextureId(2);
//			}
//			else if (iRow == (displaySizeY / 32) -1) {
//				tile.SetPassable(3, false);//can't go down from bottom row
//				tile.SetTextureId(6);
//			}
//			if (iCol == 0) {
//				tile.SetPassable(2, false);//can't go left from first column
//				tile.SetTextureId(8);
//			}
//			else if (iCol == (displaySizeX / 32) - 1) {
//				tile.SetPassable(0, false);//can't go right from last column
//				tile.SetTextureId(4);
//			}
//
//			//corners
//			//if xtile=xvect.begin, we are in first COLUMN. Probably should rename stuff.
//			if (iCol == 0 && iRow == 0) {
//				tile.SetPassable(1, false);
//				tile.SetPassable(2, false);
//				tile.SetTextureId(1);
//			}
//			else if (iCol == (displaySizeX / 32) - 1 && iRow == 0) {
//				tile.SetPassable(1, false);
//				tile.SetPassable(0, false);
//				tile.SetTextureId(3);
//			}
//			else if (iCol == (displaySizeX / 32) - 1 && iRow == (displaySizeY / 32) - 1) {
//				tile.SetPassable(3, false);
//				tile.SetPassable(0, false);
//				tile.SetTextureId(5);
//			}
//			else if (iCol == 0 && iRow == (displaySizeY / 32) - 1) {
//				tile.SetPassable(3, false);
//				tile.SetPassable(2, false);
//				tile.SetTextureId(7);
//			}
//
//			DrawTexture(tile.GetTextureId(), tile.GetXPos(), tile.GetYPos());
//
//
//			xvect.push_back(tile);
//		}
//		map.push_back(xvect);
//	}
//	return true;
//}

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

	if (SDL_CreateWindowAndRenderer(displaySizeX, displaySizeY, 0, &sdlWindow, &sdlRenderer) != 0) {
		return false;
	}

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);

	if ((testTexture = CTexture::OnLoad("C:\\Users\\Mark\\Documents\\Visual Studio 2015\\Projects\\game1\\Resources\\test.bmp",this)) == NULL) {
		return false;
	}
	if ((bkgdTexture = CTexture::OnLoad("C:\\Users\\Mark\\Documents\\Visual Studio 2015\\Projects\\game1\\Resources\\bkgd.bmp", this)) == NULL) {
		return false;
	}

	//initMap();
	CMaze Maze;
	//CMap* newMap;

	Maze.makeMaze(map);
	DrawMap(&map);
	
	//init game variables
	moveDirX = 0;
	moveDirY = 0;
	curPosX = 0;//should range from 0-19. Multiply by 32 to get left pixel position of the box thing.
	curPosY = 0;//should range from 0-14. Multiply by 32 to get top pixel position of the box thing.

	//init the bkgd
	SDL_Rect destRect;
	destRect.x = curPosX * tileSizeX;//640 / 2 - 16;
	destRect.y = curPosY * tileSizeY;//480 / 2 - 16;
	destRect.w = tileSizeX;//width of test texture
	destRect.h = tileSizeY;//height of textTexture
	SDL_RenderCopy(sdlRenderer, testTexture, NULL, &destRect);
	//DrawTexture(1, 1, 1);
	SDL_RenderPresent(sdlRenderer);



	return true;

}