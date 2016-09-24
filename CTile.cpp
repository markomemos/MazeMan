#include "CTile.h"

CTile::CTile() {
	mTextureId = -1;
	mXPos = -1;
	mYPos = -1;
	for (int i = 0; i < 4; i++) {
		mPassable[i] = true;
	}
}

int CTile::GetTextureId() {
	
	return mTextureId;
}

void CTile::SetTextureId(int textureId) {
	mTextureId = textureId;
	return;
}

bool CTile::IsPassable(int side) {
	return mPassable[side];
}

void CTile::SetPassable(int side, bool passable) {
	mPassable[side] = passable;
	return;
}

void CTile::SetXPos(int xpos) {
	mXPos = xpos;
}

int CTile::GetXPos() {
	return mXPos;
}

void CTile::SetYPos(int ypos) {
	mYPos = ypos;
}

int CTile::GetYPos() {
	return mYPos;
}