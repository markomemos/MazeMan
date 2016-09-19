#include "CApp.h"

void CApp::OnLoop() {

	if (Draw) {
		if (curPosX + moveDirX < 19 || curPosX + moveDirX > 0) {
			curPosX += moveDirX;
		}
		else {
			moveDirX = 0;
		}
		if (curPosY + moveDirY < 14 || curPosY + moveDirY > 0) {
			curPosY += moveDirY;
		}
		else {
			moveDirY = 0;
		}
		if (!moveDirX && !moveDirY) {
			Draw = false;
		}
	}

}