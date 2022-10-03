#ifndef GAMEMAP_H
#define GAMEMAP_H

#pragma once

#include "MapCell.h"

class GameMap
{
public:
    GameMap();

    MapCell* PlayerCell;
    MapCell cells[15][10];

    void DrawIntro();
     void DrawVictory();
    
    void Draw();

    //This function gets player coordinates and updates the map

    bool SetPlayerCell(int PlayerX, int PlayerY);

    bool isGameOver;

    //bool PlayAgain;

protected:

    void LoadMapFromFile();

private:

};

#endif