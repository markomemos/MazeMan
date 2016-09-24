#include "CApp.h"

void CApp::OnLoop() {

	if (Draw) {
		CTile* tile = &(map.at(curPosY).at(curPosX));// current tile

		//zero movement if moving illegally
		if ((moveDirX == 1 && !tile->IsPassable(0)) || (moveDirX == -1 && !tile->IsPassable(2))) {
			moveDirX = 0;
		}

		curPosX += moveDirX;

		//Remember, positive Y is downwards
		if ((moveDirY == -1 && !tile->IsPassable(1)) || (moveDirY == 1 && !tile->IsPassable(3))) {
			moveDirY = 0;
		}

		curPosY += moveDirY;

		//if ((curPosX + moveDirX < displaySizeX/32) && (curPosX + moveDirX >= 0)) {
		//	curPosX += moveDirX;
		//	//std::cout << "Moving! curposX=" << curPosX << ", moveDirX=" << moveDirX << std::endl;
		//}
		//else {
		//	moveDirX = 0;
		//	//std::cout<<"Not Moving! curposX=" << curPosX << ", moveDirX=" << moveDirX << std::endl; 
		//}
		//if ((curPosY + moveDirY < displaySizeY/32) && (curPosY + moveDirY >= 0)) {
		//	curPosY += moveDirY;
		//}
		//else {
		//	moveDirY = 0;
		//}
		if (!moveDirX && !moveDirY) {
			Draw = false;
		}
	}

}