#ifndef _CAPP_H_
#define _CAPP_H_
#include <SDL.h>
#ifdef __cplusplus
extern "C"
#endif

class CApp {

private:

	bool Running;

	SDL_Window* Surf_Display;

public:

	CApp();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();

};

#endif