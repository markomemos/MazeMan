#include "CTexture.h"

CTexture::CTexture() {
}

SDL_Texture* CTexture::OnLoad(char* File, CApp* CApp) {
	SDL_Surface* Surf_Temp = NULL;
	//SDL_Surface* Surf_Return = NULL;
	SDL_Texture* Text_Return = NULL;

	//Load the surface. For some reason cannot load as texture. Return NULL pointer if it failed.
	if ((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
		return NULL;
	}

	//This line magically makes pink transparent
	SDL_SetColorKey(Surf_Temp, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Temp->format, 225, 0, 200));

	//Turn surface into texture
	Text_Return = SDL_CreateTextureFromSurface(CApp->GetRenderer(), Surf_Temp);

	//MUST FREE MEMORY FOR SURFACES OURSELVES! Bad decision by SDL in my opinion...
	SDL_FreeSurface(Surf_Temp);

	return Text_Return;
}