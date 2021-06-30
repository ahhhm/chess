#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

#include "Player.h"
#include "Game.h"

std::map<size_t, Player> player_map;
std::vector<Game> game_vec;



void ReadPlayers(std::vector<std::string> str_vec)
{
    size_t do_stuff_counter = 0;

    size_t player_id;
    std::string player_name;
    size_t wins;
    size_t losses;
    size_t remis;
    size_t game_id;

    Player p1; // Constrictor doesnt work at the moment
    
    std::stringstream sstream;



    for(std::string str : str_vec)
    {
        
        if(do_stuff_counter == 0)
        {
            std::stringstream sstream(str);
            sstream >> player_id;
        }
        else if(do_stuff_counter == 1)
        {
            player_name = str;
        }
        else if(do_stuff_counter == 2)
        {
            std::stringstream sstream(str);
            sstream >> wins;
        }
        else if(do_stuff_counter == 3)
        {
            std::stringstream sstream(str);
            sstream >> losses;
        }
        else if(do_stuff_counter == 4)
        {
            std::stringstream sstream(str);
            sstream >> remis;
            
            p1.GiveStats(player_id, player_name, wins, losses, remis);
            player_map.insert(std::pair<size_t, Player>(player_id, p1));
        }            
        else
        {
            std::stringstream sstream(str);
            sstream >> game_id;
            p1.AddGame(game_id);
        }
    }
}


int ReadingFile()
{

    std::fstream file("data.txt");
    std::string str;
    

    if(!file)
        return -1;

    while(std::getline(file, str))
    {
        std::vector<std::string> word;
        size_t prev = 0, pos;
        while ((pos = str.find_first_of("-", prev)) != std::string::npos)
        {
            if(pos > prev)
            {
                word.push_back(str.substr(prev, pos - prev));
            }
            prev = pos + 1;
        }
        if(prev < str.length())
            word.push_back(str.substr(prev, std::string::npos));
        
        ReadPlayers(word);
        std::cout << std::endl;
    }

    return 0;
}


int main()
{
    ReadingFile();

    
    return 0;
}