#include "utils.h"


bool keep_alive()
{
    char user_choice;
    std::cout << "Game ended. Press 'r' (and Enter) to restart or any other key to quit.\n\n";
    std::cin >> user_choice;
    if (user_choice == 'r') {
        return true;
    }
    return false;
}