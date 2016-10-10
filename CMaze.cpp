#include "CMaze.h"



void CMaze::makeMaze(CMap &map){


	//We'll use the texture to signify if the tile has been incorporated into the maze yet.
	//15 = not incorporated, 16 = incorporated
	//While creating maze, we'll set everything impassable then slowly make things passable as we incorporate tiles
	//At the end we'll make the textures match passability
	map.SetUniformTexture(15);
	map.SetImpassable();

	int nTilesX = 0;
	int nTilesY = 0;

	map.GetNTilesXY(nTilesX, nTilesY);

	std::vector<std::vector<CTile>> mapArray = map.GetMap();

	/* initialize random seed: */
	srand(time(NULL));
	int seedxpos = rand() % nTilesX;
	int seedypos = rand() % nTilesY;

	//seedxpos = 2;
	//
	seedypos = 2;

	std::vector<CTile> potentialTiles;

	//add the <= 4 tiles surrounding the initial one to the potential list
	if (seedxpos + 1 < nTilesX) potentialTiles.push_back(mapArray.at(seedypos).at(seedxpos + 1));
	if (seedxpos - 1 >= 0) potentialTiles.push_back(mapArray.at(seedypos).at(seedxpos - 1));
	if (seedypos + 1 < nTilesY) potentialTiles.push_back(mapArray.at(seedypos+1).at(seedxpos));
	if (seedypos - 1 >= 0) potentialTiles.push_back(mapArray.at(seedypos-1).at(seedxpos));

	//set seed tile to "incorporated"
	mapArray.at(seedypos).at(seedxpos).SetTextureId(16);

	int xpos = -999;
	int ypos = -999;
	while (potentialTiles.size() != 0) {
		int index = rand() % potentialTiles.size(); //should go from 0 to size - 1
		xpos = potentialTiles.at(index).GetXPos();
		ypos = potentialTiles.at(index).GetYPos();
		
		//remove tile from list of potential tiles
		potentialTiles.erase(potentialTiles.begin() + index);

		//set tile to "incorporated"
		mapArray.at(ypos).at(xpos).SetTextureId(16);

		//Now add surrounding tiles to potentialTiles if unincorporated and not a potential tile already.
		//If surrounding tile already incorporated, pick one and create a passage

		std::vector<int> potPassage;//contains dir from new incorporated tile to already incorporated tile
		

		//check if tile is off the map
		if (xpos + 1 < nTilesX) {
			//check if tile is unincorporated yet
			if (mapArray.at(ypos).at(xpos + 1).GetTextureId() == 15) {
				bool not_used = true;
				//check if tile is in potentialTiles list
				for (std::vector<CTile>::iterator it = potentialTiles.begin(); it != potentialTiles.end(); ++it) {
					if ((*it).GetXPos() == xpos + 1 && (*it).GetYPos() == ypos) {
						not_used = false;
						break;
					}
				}
				//hooray, everything seems fine, let's add this tile
				if(not_used) potentialTiles.push_back(mapArray.at(ypos).at(xpos + 1));
			}
			else {//this tile is already incorporated. Should we add a passage?
				potPassage.push_back(0);//move right to go from xpos to xpos+1
			}
		}
		if (xpos - 1 >= 0){
			if (mapArray.at(ypos).at(xpos - 1).GetTextureId() == 15) {
				bool not_used = true;
				//check if tile is in potentialTiles list
				for (std::vector<CTile>::iterator it = potentialTiles.begin(); it != potentialTiles.end(); ++it) {
					if ((*it).GetXPos() == xpos - 1 && (*it).GetYPos() == ypos) {
						not_used = false;
						break;
					}
				}
				//hooray, everything seems fine, let's add this tile
				if (not_used) potentialTiles.push_back(mapArray.at(ypos).at(xpos - 1));
			}
			else {//this tile is already incorporated. Should we add a passage?
				potPassage.push_back(2);//move left to go from xpos to xpos - 1
			}
		}
		if (ypos + 1 < nTilesY) {
			if (mapArray.at(ypos+1).at(xpos).GetTextureId() == 15) {
				bool not_used = true;
				//check if tile is in potentialTiles list
				for (std::vector<CTile>::iterator it = potentialTiles.begin(); it != potentialTiles.end(); ++it) {
					if ((*it).GetXPos() == xpos&& (*it).GetYPos() == ypos+1) {
						not_used = false;
						break;
					}
				}
				//hooray, everything seems fine, let's add this tile
				if (not_used) potentialTiles.push_back(mapArray.at(ypos+1).at(xpos));
			}
			else {//this tile is already incorporated. Should we add a passage?
				potPassage.push_back(3); //move DOWN to go from ypos to ypos+1
			}
		}
		if (ypos - 1 >= 0) {
			if (mapArray.at(ypos-1).at(xpos).GetTextureId() == 15) {
				bool not_used = true;
				//check if tile is in potentialTiles list
				for (std::vector<CTile>::iterator it = potentialTiles.begin(); it != potentialTiles.end(); ++it) {
					if ((*it).GetXPos() == xpos && (*it).GetYPos() == ypos-1) {
						not_used = false;
						break;
					}
				}
				//hooray, everything seems fine, let's add this tile
				if (not_used) potentialTiles.push_back(mapArray.at(ypos-1).at(xpos));
			}
			else {//this tile is already incorporated. Should we add a passage?
				potPassage.push_back(1); //move UP to go from ypos to ypos -1
			}
		}
		//fun fact, could just say if(potPassage.size()), but I want to be verbose
		if (potPassage.size() != 0) {
			int indexPassage = rand() % potPassage.size();
			int dirFromNewTile = -1;//right, up, left, down = 0,1,2,3
			dirFromNewTile = potPassage.at(indexPassage);
			int oldxpos = xpos - ((dirFromNewTile + 1) % 2)*(dirFromNewTile - 1);
			int oldypos = ypos + (dirFromNewTile % 2)*(dirFromNewTile - 2);//remember, up should give ypos-1
			mapArray.at(oldypos).at(oldxpos).SetPassable((dirFromNewTile + 2) % 4, true);
			mapArray.at(ypos).at(xpos).SetPassable(dirFromNewTile, true);
			/*switch (dirFromNewTile) {
			case 0:
				mapArray.at(ypos).at(xpos).SetPassable(2, true);
				mapArray.at(ypos).at(xpos + 1).SetPassable(0, true);
			case 1:
				mapArray.at(ypos).at(xpos).SetPassable(3, true);
				mapArray.at(ypos+1).at(xpos).SetPassable(1, true);
			}*/
		}
		else {
			//orphan tile with no incorporated neighbours? how does this happen?
			//crash and burn!
			throw std::exception("orphan tile");
		}
	}//end while(potentialTiles.size()!=0)

	//To give the maze an "entrance" and "exit"
	mapArray.at(0).at(0).SetPassable(1, true);
	mapArray.at(nTilesY - 1).at(nTilesX - 1).SetPassable(3, true);

	map.SetMap(mapArray);
	map.MatchTextureToPassable();

	//probably the least efficient way to do this!
	mapArray = map.GetMap();
	mapArray.at(0).at(0).SetPassable(1, false);
	mapArray.at(nTilesY - 1).at(nTilesX - 1).SetPassable(3, false);
	map.SetMap(mapArray);

	return;



}