#ifndef _CMAP_H_
#define _CMAP_H_

#include <vector>
#include "CTile.h"
#include <time.h>

class CMap {
public:
	CMap();
	void initMap(int nTilesX, int nTilesY);
	std::vector<std::vector<CTile>> GetMap();
	void SetMap(std::vector<std::vector<CTile>>);
	void SetUniformTexture(int textureId);
	//void DrawMap();
	void GetNTilesXY(int &x, int &y);
	void SetImpassable();//be sure not to spell as impass-I-ble!
	void MatchTextureToPassable();

private:
	std::vector<std::vector<CTile>> mMap;


};

#endif