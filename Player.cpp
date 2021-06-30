#include <iostream>
#include "Player.h"

Player::Player()
{
}

Player::Player(size_t player_ID, std::string player_name,
    size_t number_of_wins, size_t number_of_losses, size_t number_of_remis):
    player_ID_(player_ID), player_name_(player_name), number_of_wins_(number_of_wins), number_of_losses_(number_of_losses),
    number_of_remis_(number_of_remis)
{
}

void Player::GiveStats(size_t player_ID, std::string player_name, size_t number_of_wins, size_t number_of_losses, size_t number_of_remis)
{
    player_ID_ = player_ID;
    player_name_ = player_name;
    number_of_wins_ = number_of_wins;
    number_of_remis_ = number_of_remis;
    number_of_losses_ = number_of_losses;
}

void Player::AddGame(size_t game_ID)
{
    games_played_.push_back(game_ID);
}

