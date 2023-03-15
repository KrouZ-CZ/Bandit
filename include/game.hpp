#include <iostream>
#include <fstream>

using namespace std;
class game
{
private:
    void draw(int);
    void status(string);
    void update(int);
    void get_bid();
    bool verify();
    int bid;
public:
    game();
};