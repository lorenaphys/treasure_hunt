#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{

    x = 2;
    y = 2;

}

int Player::PosX()
{
    return x;
}

int Player::PosY()
{
    return y;
}

void Player::CallInput()
{
    char UserInput = ' ';

    cin >> UserInput;

    switch (UserInput)
    {
    case 'w':
        lastY = y;
        y --;
        //cout << "The player moves upwards\n";
        break;

    case 's':
        lastY = y;
        y++;
        //cout << "The player moves downwards\n";
        break;

    case 'd':
        lastX = x;
        x++;
        //cout << "The player moves to the right\n";
        break;

    case 'a':
        lastX = x;
        x--;
        //cout << "The player moves to the left\n";
        break;

    default:
        break;
    }

    //cout << "The player is in the coordinates " << x << ", " << y << endl;
}

void Player::ResetToSafePosition()
{
    x = lastX;
    y = lastY;
}