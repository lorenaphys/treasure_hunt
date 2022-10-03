#ifndef PLAYER_H
#define PLAYER_H

#pragma once

class Player
{
public:
    

    Player();

    void CallInput();
    //reset the position to the last one
    void ResetToSafePosition();
    //get the actual position of the player
    int PosX();
    int PosY();
    //last coordinates of the player
    int lastX, lastY;

protected:

    int x, y;    

private:


};

#endif