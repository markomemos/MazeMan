#include "CTexture.h"

CTexture::CTexture() {
}

SDL_Texture* CTexture::OnLoad(char* File, CApp* CApp) {
	SDL_Surface* Surf_Temp = NULL;
	//SDL_Surface* Surf_Return = NULL;
	SDL_Texture* Text_Return = NULL;

	if ((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
		return NULL;
	}

	//This line magically makes pink transparent
	SDL_SetColorKey(Surf_Temp, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Temp->format, 225, 0, 200));

	Text_Return = SDL_CreateTextureFromSurface(CApp->GetRenderer(), Surf_Temp);

	SDL_FreeSurface(Surf_Temp);

	return Text_Return;
}