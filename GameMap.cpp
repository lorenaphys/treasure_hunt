#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap()
{
 PlayerCell = NULL;
 LoadMapFromFile();
 isGameOver = false;
 //PlayAgain = true;
}

void GameMap::Draw()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cells[i][j].id;
        }
        cout << endl;
    }
    
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if (cells[PlayerY][PlayerX].IsBlocked() == false)
    {
        if (cells[PlayerY][PlayerX].id == 'X')
        {
            DrawVictory();
            isGameOver = true;
            return true;
        }
        else
        {
            if (PlayerCell != NULL)
            {
                PlayerCell -> id = ' ';
            }
            

            PlayerCell = &cells[PlayerY][PlayerX];
            PlayerCell -> id = 'H';
        }
        

        return true;
    }
    else
    {
        return false;
    }
    

    //cout << "The player coordinates are: " << PlayerX << ", " << PlayerY << endl;
}

void GameMap::DrawIntro()
{
    string line;

    ifstream MyFile("Intro.txt");

    if (MyFile.is_open())
    {
        
        while (getline(MyFile, line))
        {
            cout << line << endl;
        }
        cin >> line;
    }
    else
    {
        cout << "FATAL ERROR: INTRO COULD NOT BE LOADED\n"; 
    }
}

void GameMap::DrawVictory()
{
    string line;

    ifstream MyFile("Victory.txt");

    if (MyFile.is_open())
    {
        
        while (getline(MyFile, line))
        {
            cout << line << endl;
        }
        cin >> line;
    }
    else
    {
        cout << "FATAL ERROR: VICTORY COULD NOT BE LOADED\n"; 
    }
}

void GameMap::LoadMapFromFile()
{
/*     ofstream FileCreated("Map.txt");

    if (FileCreated.is_open())
    {
         
    }
    else
    {
            cout << "FATAL ERROR: MAP FILE COULD NOT BE CREATED\n";
    } */
    

    string line;
    int row = 0;

    ifstream MyFile("Map.txt");

    if (MyFile.is_open())
    {
        //cout << "Drawing test: \n"; 
        while (getline(MyFile, line))
        {
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0')
                {
                    cells[row][p].id = ' ';
                }
                else
                {
                    cells[row][p].id = line[p];
                }                
            }
            
            row ++;
        }
        //cout << "Drawing finished\n";
    }
    else
    {
        cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED\n"; 
    }
    
}