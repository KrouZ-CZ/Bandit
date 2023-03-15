#include "menu.hpp"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
int main() {
    if (!fs::exists("money.txt")) {
        ofstream mon{"money.txt"};
        mon << "100";
        mon.close();
    }
    system("title BANDIT");

    menu game{};

    while (true)
    {
        game.main();
    }
}