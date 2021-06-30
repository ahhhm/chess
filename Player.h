#include <string>
#include <vector>

class Player
{
    public:

        size_t player_ID_count_;

    private:

        size_t player_ID_;

        std::string player_name_;

        size_t number_of_games_played_;

        size_t number_of_wins_;

        size_t number_of_losses_;

        size_t number_of_remis_;

        float win_loss_ratio_;

        std::vector<size_t> games_played_; 

    public:

        Player();

        Player(size_t player_ID, std::string player_name, size_t number_of_wins, size_t number_of_losses, size_t number_of_remis);

        void GiveStats(size_t player_ID, std::string player_name, size_t number_of_wins, size_t number_of_losses, size_t number_of_remis);

        size_t GetPlayerID();

        void AddGame(size_t game_ID);
};