#include "menu.hpp"
#include "game.hpp"

menu::menu() {
    srand(time(NULL));
}

void menu::draw() {
    cout << "Balance: " << this->get_balance() << endl << endl
    << "1. Start game" << endl
        << "2. Exit" << endl;
}

int menu::select() {
    cout << "> ";
    int res;
    cin >> res;
    return res;
}

void menu::main() {
    this->draw();
    int sel = this->select();
    switch (sel)
    {
    case 1:
        game{};
        break;
    case 2:
        exit(0);
        break;
    default:
        system("cls");
        cout << "Error" << endl << endl;
        break;
    }
}

int menu::get_balance() {
    ifstream money{"money.txt"};
    string mm;
    getline(money, mm);
    int cur_mon = stoi(mm);
    return cur_mon;
}