#include "CMap.h"

CMap::CMap() {
	return;
}

void CMap::initMap(int nTilesX, int nTilesY) {
	//initialize a basic map
	for (int iRow = 0; iRow < nTilesY/*displaySizeY / 32*/; iRow++) {
		//loop through 15 rows
		std::vector<CTile> xvect;// = *it_ytile;
		for (int iCol = 0; iCol < nTilesX/*displaySizeX / 32*/; iCol++) {
			//loop through 20 columns
			CTile tile;
			tile.SetTextureId(0);
			tile.SetXPos(iCol);
			tile.SetYPos(iRow);


			//set every direction to be passable at start
			for (int i = 0; i < 4; i++) {
				tile.SetPassable(i, true);
			}

			xvect.push_back(tile);
		}
		mMap.push_back(xvect);
	}
}

std::vector<std::vector<CTile>> CMap::GetMap() {
	return mMap;
}

void CMap::SetMap(std::vector<std::vector<CTile>> map) {
	mMap = map;
}

void CMap::SetUniformTexture(int textureId) {
	for (std::vector<std::vector<CTile>>::iterator itRow = mMap.begin(); itRow != mMap.end(); ++itRow) {
		
		//NOTE: The following line creates a local copy of the thing we want to change! This copy gets deleted when going out of scope and therefore changes to it don't help! Hence we replace "row" with (*itRow).
		//std::vector<CTile> row = *itRow;

		for (std::vector<CTile>::iterator itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol) {
			//CTile tile = *itCol;
			(*itCol).SetTextureId(textureId);
		}

	}
	return;
}

void CMap::SetImpassable() {
	for (std::vector<std::vector<CTile>>::iterator itRow = mMap.begin(); itRow != mMap.end(); ++itRow) {

		//NOTE: The following line creates a local copy of the thing we want to change! This copy gets deleted when going out of scope and therefore changes to it don't help! Hence we replace "row" with (*itRow).
		//std::vector<CTile> row = *itRow;

		for (std::vector<CTile>::iterator itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol) {
			//CTile tile = *itCol;
			for (int i = 0; i < 4; i++) {
				(*itCol).SetPassable(i, false);
			}
		}

	}
	return;
}

void CMap::MatchTextureToPassable() {
	for (std::vector<std::vector<CTile>>::iterator itRow = mMap.begin(); itRow != mMap.end(); ++itRow) {
		for (std::vector<CTile>::iterator itCol = (*itRow).begin(); itCol != (*itRow).end(); ++itCol) {
			//let's convert passability (kinda binary-like) to decimal
			int dec = 0;
			for (int i = 0; i < 4; i++) {
				dec += pow(2,i)*(*itCol).IsPassable(i);
			}

			//perhaps we should have made the tile-set match this binary thing? Could have avoided this crazy switch-case.
			switch (dec) {
			case 0:
				//nothing is passable?
				(*itCol).SetTextureId(15);
				break;
			case 1:
				//only passable to right
				(*itCol).SetTextureId(11);
				break;
			case 2:
				//passable to up only
				(*itCol).SetTextureId(12);
				break;
			case 3:
				//passable to right and up
				(*itCol).SetTextureId(7);
				break;
			case 4:
				//passable to left only
				(*itCol).SetTextureId(13);
				break;
			case 5:
				//left and right
				(*itCol).SetTextureId(9);
				break;
			case 6:
				//left and up
				(*itCol).SetTextureId(5);
				break;
			case 7:
				//left, right, and up
				(*itCol).SetTextureId(6);
				break;
			case 8:
				//down only
				(*itCol).SetTextureId(14);
				break;
			case 9:
				//down and right
				(*itCol).SetTextureId(1);
				break;
			case 10:
				//down and up
				(*itCol).SetTextureId(10);
				break;
			case 11:
				//down, right, up
				(*itCol).SetTextureId(8);
				break;
			case 12:
				//down, left
				(*itCol).SetTextureId(3);
				break;
			case 13:
				//down left right
				(*itCol).SetTextureId(2);
				break;
			case 14:
				//down left up
				(*itCol).SetTextureId(4);
				break;
			case 15:
				//down left up and right, aka all directions ok!
				(*itCol).SetTextureId(0);
				break;
			default:
				//we failed somehow! Let's crash and burn!!
				throw std::exception("setting texture after passability failed");

			}
		}

	}
	return;

}

void CMap::GetNTilesXY(int &x, int &y) {
	y = mMap.size();
	x = mMap.at(0).size();
	return;
}
