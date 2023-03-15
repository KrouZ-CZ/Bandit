#include "game.hpp"
#include <chrono>
#include <thread>

game::game() {
    system("cls");
    this->get_bid();
    if (this->verify()) {
        cout << "Money error" << endl;
        system("pause && cls");
        return;
    }
    int randomNumber = rand() % (999 + 1 - 100) + 100;

    this->draw(randomNumber);
    string print = std::to_string(randomNumber);

    cout << "\r" << print[0] << "  " << print[1] << "  " << print[2] << endl;
    this->status(print);

    system("pause && cls");
}

void game::draw(int randNum) {
    cout << "Your number: " << endl << endl;

    for (size_t i = 0; i < 25; i++)
    {
        string print = std::to_string(rand() % (999 + 1 - 100) + 100);

        cout << "\r" << print[0] << "  " << print[1] << "  " << print[2] << "   ";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void game::status(string reels) {
    if (reels[0] == reels[1] && reels[1] == reels[2])
    {
        cout << "JACKPOT!!!\n";
        this->update(100*bid);
    }
    else if (reels[0] == reels[1] || reels[1] == reels[2] || reels[0] == reels[2])
    {
        cout << "Winner!\n";
        this->update(10*bid);
    }
    else
    {
        cout << "Try again...\n";
        this->update((-1)*bid);
    }
}

void game::update(int mon) {
    ifstream money{"money.txt"};
    string mm;
    getline(money, mm);
    int cur_mon = stoi(mm);
    money.close();

    ofstream file{"money.txt"};
    file << to_string(cur_mon + mon);
    file.close();
}

void game::get_bid() {
    cout << "Your bid? ";
    cin >> bid;
}

int get_balance() {
    ifstream money{"money.txt"};
    string mm;
    getline(money, mm);
    int cur_mon = stoi(mm);
    return cur_mon;
}

bool game::verify() {
    if (bid > get_balance()) {
        return true;
    }
    return false;
}