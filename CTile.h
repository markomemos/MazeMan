#ifndef _CTILE_H_
#define _CTILE_H_

//#include "CApp.h"
#include "SDL.h"

//This class should hold information about a given tile. Like what objects are here, which directions can you move in, what's the bkgd texture, etc.

class CTile {
public:
	CTile();
	bool IsPassable(int side);
	void SetPassable(int side, bool passable);
	int GetTextureId();
	void SetTextureId(int textureId);

	void SetXPos(int xpos);
	void SetYPos(int ypos);
	int GetXPos();
	int GetYPos();

private:
	bool mPassable[4];//0,1,2,3 = right, up, left, down
	int mTextureId;
	int mXPos;
	int mYPos;

	
};

#endif