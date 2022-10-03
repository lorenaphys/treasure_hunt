#include <iostream>
#include "Player.cpp"
#include "MapCell.cpp"
#include "GameMap.cpp"

using namespace std;

// primer paso: crear un jugador



int main()
{
    
    GameMap Map;
    Player Hero;

    Map.DrawIntro();
    Map.Draw();

    //cout << "The game begins\n";
    cout << "Enter the move command 'a''w''s''d': \n";
    while (Map.isGameOver == false)
    {
        
        //Here is the game loop
        Hero.CallInput();

        //Updating hero information to Map
        if (Map.SetPlayerCell(Hero.PosX(), Hero.PosY()))
        {
            //Here the map is drawn
            Map.Draw();
        }
        else
        {
            Hero.ResetToSafePosition();
            Map.Draw();
        }   
    }

    return 0;
}