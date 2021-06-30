#include <string>

class Game
{
    public:

        size_t game_ID_count;

    private:

        size_t game_ID;

        size_t player_one_ID;

        size_t player_two_ID;

        enum Result {WIN_1, WIN_2, REMI};

        bool mate;

        bool surrender;

    public:


        Game(size_t game_ID, size_t player_one_ID, size_t player_two_ID, Result result, bool mate, bool surrender);

        size_t GetNewGameID();
};