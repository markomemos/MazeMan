#ifndef _CTEXTURE_H_
#define _CTEXTURE_H_

#include <SDL.h>
#include "CApp.h"

class CTexture {
public:
	CTexture();

public:
	static SDL_Texture* OnLoad(char* File, CApp* CApp);

};

#endif